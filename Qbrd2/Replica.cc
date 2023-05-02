/*
 * Replica.cc
 *
 *  Created on: Apr 7, 2023
 *      Author: oem
 */

#include <omnetpp.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <time.h>
#include <Message_m.h>
#include <string>

using namespace omnetpp;

enum State {
    IDLE, BUSY
};

struct WriteUtility {

    int clientId = -1;
    int putIdClientSide;
    int msgCounter;
    bool receivedAbortRequest;
    State state;
    std::vector<int> versionContainer;
    std::vector<int> writeQuorum;
    std::pair<int, int> tempVersionValue;

};

struct ReadUtility {

    int readCounter;
    int readIdClientSide;
    int clientGate;
    std::pair<int, int> versionValueContainer;

};

class Replica: public cSimpleModule {

public:
    int replicasNumber;
    int clientsNumber;
    int writeQuorumSize;
    int readQuorumSize;
    int readId;
    std::map<std::pair<int, int>, bool> putIdSentAbortRequest; // <put_id, client_id>
    std::map<int, WriteUtility> keyWriteUtility;
    std::map<int, ReadUtility> readIdReadUtility;
    std::map<int, std::pair<int, int>> keyValueDatastore;
    //std::map<int, int> watchLocks;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void managePutRequest(cMessage *msg);
    void manageUpdateRequest(cMessage *msg);
    void manageUpdateResponse(cMessage *msg);
    void replicaCommit(cMessage *msg);
    void replicaAbort(cMessage *msg);
    void manageGetRequest(cMessage *msg);
    void manageValueRequest(cMessage *msg);
    void manageValueResponse(cMessage *msg);
};

Define_Module(Replica);

void Replica::initialize() {

    this->replicasNumber = par("REPLICAS_NUMBER").intValue();
    this->clientsNumber = par("CLIENTS_NUMBER").intValue();
    this->writeQuorumSize = par("WRITE_QUORUM_SIZE").intValue();
    this->readQuorumSize = par("READ_QUORUM_SIZE").intValue();
    this->readId = 0;
//    WATCH_MAP(watchLocks);

}

//Functions for PUT operation.

void Replica::managePutRequest(cMessage *msg) {

    // Proxy receive PUT from the client and send UPDATE-REQUEST to the write quorum (only if it is IDLE on the requested key). Key's state become BUSY.
    // If the key is busy, the proxy sends back and ABORT-MESSAGE to the client specifying the id of the put.
    PutRequest *p = check_and_cast<PutRequest*>(msg);
    if ((this->keyWriteUtility.find(p->getKey()) != this->keyWriteUtility.end())
            && (this->keyWriteUtility[p->getKey()].state == BUSY)) { // if the key exists and is BUSY.
        EV << "Replica[" << this->getIndex() << "]: received PUT from Client["
                  << p->getSenderModuleId() - 2 << "]" << endl;
        EV << "Key " << p->getKey() << " on Replica[" << this->getIndex()
                  << "]: is BUSY. Cannot perform PUT!" << endl;
        AbortMessageToClient *abort_message = new AbortMessageToClient(
                "abort-message");
        abort_message->setPutIdClientSide(p->getPutIdClientSide());
        abort_message->setKey(p->getKey());
        send(abort_message, "outToClient", p->getSenderModuleId() - 2);
        EV << "Replica[" << this->getIndex()
                  << "]: ABORTED and sent ABORT-MESSAGE to Client["
                  << p->getSenderModuleId() - 2 << "]" << endl;
    } else {
        EV << "Replica[" << this->getIndex() << "]: received PUT from Client["
                  << p->getSenderModuleId() - 2 << "]" << endl; // if the key is not already stored in the map or its state is IDLE.
        if (this->keyWriteUtility.find(p->getKey())
                != this->keyWriteUtility.end()) {
//            this->watchLocks[p->getKey()] = 1;
            this->keyWriteUtility[p->getKey()].state = BUSY;
            this->keyWriteUtility[p->getKey()].clientId = p->getSenderModuleId()
                    - 2; // if the key is already stored and its state is IDLE then
            this->keyWriteUtility[p->getKey()].putIdClientSide = // sets the state BUSY and the various member variables of the struct WriteUtility.
                    p->getPutIdClientSide();
        } else {
//            this->watchLocks.insert(std::pair<int, int>(p->getKey(), 1));
            std::vector<int> temp_vector1; // if the key is not already been used then insert a new pair <key, WriteUtility> in
            std::vector<int> temp_vector2; // keyWriteUtility.
            std::pair<int, int> temp_pair(0, 0);
            WriteUtility temp_resource = { p->getSenderModuleId() - 2,
                    p->getPutIdClientSide(), 0, false, BUSY, temp_vector1,
                    temp_vector2, temp_pair };
            this->keyWriteUtility.insert(
                    std::pair<int, WriteUtility>(p->getKey(), temp_resource));
            this->keyWriteUtility[p->getKey()].putIdClientSide =
                    p->getPutIdClientSide();
        }
        EV << "Key " << p->getKey() << " on Replica[" << this->getIndex()
                  << "]: is now BUSY." << endl;
        this->keyWriteUtility[p->getKey()].writeQuorum = p->getWriteQuorum();
        this->keyWriteUtility[p->getKey()].tempVersionValue.second =
                p->getValue();
        UpdateRequest *message_to_duplicate = new UpdateRequest(
                "update-request");
        message_to_duplicate->setKey(p->getKey());
        message_to_duplicate->setPutIdClientSide(p->getPutIdClientSide());
        message_to_duplicate->setClientId(p->getSenderModuleId() - 2);
        for (int i = 0; i < this->writeQuorumSize; i++) {
            if (this->keyWriteUtility[p->getKey()].writeQuorum[i]
                    > this->getIndex()) {
                UpdateRequest *update_request = message_to_duplicate->dup();
                send(update_request, "out",
                        this->keyWriteUtility[p->getKey()].writeQuorum[i] - 1); //Proxy sends UPDATE-REQUEST to the write quorum.
                EV << "Replica[" << this->getIndex()
                          << "]: sent UPDATE-REQUEST for key " << p->getKey()
                          << " to Replica["
                          << this->keyWriteUtility[p->getKey()].writeQuorum[i]
                          << "]" << endl;
            } else if (this->keyWriteUtility[p->getKey()].writeQuorum[i]
                    < this->getIndex()) {
                UpdateRequest *update_request = message_to_duplicate->dup();
                send(update_request, "out",
                        this->keyWriteUtility[p->getKey()].writeQuorum[i]);
                EV << "Replica[" << this->getIndex()
                          << "]: sent UPDATE-REQUEST for key " << p->getKey()
                          << " to Replica["
                          << this->keyWriteUtility[p->getKey()].writeQuorum[i]
                          << "]" << endl;
            }
        }
    }

}

void Replica::manageUpdateRequest(cMessage *msg) {

    //Replica receives UPDATE-REQUEST from proxy and sends back UPDATE-RESPONSE (if the requested key is IDLE). Key's state become BUSY.

    UpdateRequest *update_request = check_and_cast<UpdateRequest*>(msg);
    if ((this->keyWriteUtility.find(update_request->getKey())
            != this->keyWriteUtility.end())
            && (this->keyWriteUtility[update_request->getKey()].state == BUSY)) { // Same mechanism above (used in the proxy) to understand if the key's state is BUSY
        EV << "Key " << update_request->getKey() << " on Replica["
                  << this->getIndex()
                  << "]: is BUSY. Cannot perform put operation!" << endl;
        UpdateResponse *update_response = new UpdateResponse("update-response");
        update_response->setAbortRequest(true);
        update_response->setKey(update_request->getKey());
        int proxy_gate = msg->getSenderModuleId() - this->clientsNumber - 2;
        if (msg->getSenderModuleId() > msg->getArrivalModuleId()) {
            proxy_gate--;
        }
        send(update_response, "out", proxy_gate);
        this->putIdSentAbortRequest.insert(
                std::pair<std::pair<int, int>, bool>(
                        std::pair<int, int>(
                                update_request->getPutIdClientSide(),
                                update_request->getClientId()), true));
        EV << "Replica[" << this->getIndex()
                  << "]: sent ABORT-REQUEST to Proxy (Replica[" // If the state of the key for the update is BUSY then in the UPDATE-RESPONSE
                  << msg->getSenderModuleId() - this->clientsNumber - 2 << "])" // the bool variable abortRequest = true
                  << endl;
    } else {
        EV << "Replica[" << this->getIndex()
                  << "]: received UPDATE-REQUEST from Replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2
                  << "] for key " << update_request->getKey() << endl;
        if (this->keyWriteUtility.find(update_request->getKey())
                != this->keyWriteUtility.end()) {
//            this->watchLocks[update_request->getKey()] = 1;
            this->keyWriteUtility[update_request->getKey()].state = BUSY;
            this->keyWriteUtility[update_request->getKey()].clientId =
                    update_request->getClientId();
            this->keyWriteUtility[update_request->getKey()].putIdClientSide =
                    update_request->getPutIdClientSide();
        } else {
//            this->watchLocks.insert(
//                    std::pair<int, int>(update_request->getKey(), 1));
            std::vector<int> temp_vector1;
            std::vector<int> temp_vector2;
            std::pair<int, int> temp_pair(0, 0);
            WriteUtility temp_resource = { update_request->getClientId(),
                    update_request->getPutIdClientSide(), 0, false, BUSY,
                    temp_vector1, temp_vector2, temp_pair };
            this->keyWriteUtility.insert(
                    std::pair<int, WriteUtility>(update_request->getKey(),
                            temp_resource));
        }
        EV << "Key " << update_request->getKey() << " on Replica["
                  << this->getIndex() << "]: is now BUSY." << endl;
        int proxy_gate = msg->getSenderModuleId() - this->clientsNumber - 2;
        if (msg->getSenderModuleId() > msg->getArrivalModuleId()) {
            proxy_gate--;
        }
        UpdateRequest *update_request = check_and_cast<UpdateRequest*>(msg);
        int version;
        int key = update_request->getKey(); // Replica sends back to the proxy UPDATE-RESPONSE with the related version of the key
        if (this->keyValueDatastore.find(key) // stored. If the key is not already stored in the replica then version = 0.
        != this->keyValueDatastore.end()) {
            version = this->keyValueDatastore[key].first;
            UpdateResponse *update_response = new UpdateResponse(
                    "update-response");
            update_response->setKey(key);
            update_response->setVersion(version);
            send(update_response, "out", proxy_gate);
            EV << "Replica[" << this->getIndex()
                      << "]: sent UPDATE-RESPONSE for key " << key
                      << " to Replica["
                      << msg->getSenderModuleId() - this->clientsNumber - 2
                      << "]" << endl;
        } else {
            UpdateResponse *update_response = new UpdateResponse(
                    "update-response");
            version = 0;
            update_response->setKey(key);
            update_response->setVersion(version);
            send(update_response, "out", proxy_gate);
            EV << "Replica[" << this->getIndex()
                      << "]: sent UPDATE-RESPONSE for key " << key
                      << " to Replica["
                      << msg->getSenderModuleId() - this->clientsNumber - 2
                      << "]" << endl;
        }
    }

}

void Replica::manageUpdateResponse(cMessage *msg) {

    // Proxy receive UPDATE-RESPONSE.
    // When as many UPDATE-RESPONSEs as the number of replicas belonging to the write quorum (except the proxy) have been received FOR A SPECIFIC KEY,
    // the proxy sends COMMIT message to the write quorum. Then the proxy commit the write operation and the state of the key is set IDLE.
    // If proxy received ABORT-REQUEST from a replica belonging to the the write quorum.
    // It sends ABORT to the write quorum.
    // If in a UPDATE-RESPONSE received the abortRequest is setted to true, when all the UPDATE-RESPONSES from the write quorum have been collected, ABORT and send the
    // ABORT-MESSAGE to the client.

    UpdateResponse *update_response = check_and_cast<UpdateResponse*>(msg);
    this->keyWriteUtility[update_response->getKey()].msgCounter++;
    if (update_response->getAbortRequest()) {
        this->keyWriteUtility[update_response->getKey()].receivedAbortRequest =
                true;
        EV << "Replica[" << this->getIndex()
                  << "]: received ABORT-MESSAGE for key "
                  << update_response->getKey() << " from Replica ["
                  << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
                  << endl;
    } else {
        EV << "Replica[" << this->getIndex()
                  << "]: received UPDATE-RESPONSE for key "
                  << update_response->getKey() << " from Replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
                  << endl;
    }
    int response_version = update_response->getVersion();
    this->keyWriteUtility[update_response->getKey()].versionContainer.push_back(
            response_version);
    if (this->keyWriteUtility[update_response->getKey()].msgCounter
            == (this->writeQuorumSize - 1)) {
        if (this->keyWriteUtility[update_response->getKey()].receivedAbortRequest) {
            AbortMessage *message_to_duplicate = new AbortMessage("abort");
            message_to_duplicate->setKey(update_response->getKey());
            message_to_duplicate->setClientId(
                    this->keyWriteUtility[update_response->getKey()].clientId);
            message_to_duplicate->setPutIdClientSide(
                    this->keyWriteUtility[update_response->getKey()].putIdClientSide);
            for (int i = 0; i < this->writeQuorumSize; i++) {
                if (this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                        > this->getIndex()) {
                    AbortMessage *abort = message_to_duplicate->dup();
                    send(abort, "out",
                            this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                                    - 1);
                    EV << "Replica[" << this->getIndex()
                              << "]: sent ABORT for key "
                              << update_response->getKey() << " to Replica["
                              << this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                              << "]" << endl;
                } else if (this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                        < this->getIndex()) {
                    AbortMessage *abort = message_to_duplicate->dup();
                    send(abort, "out",
                            this->keyWriteUtility[update_response->getKey()].writeQuorum[i]);
                    EV << "Replica[" << this->getIndex()
                              << "]: sent ABORT for key "
                              << update_response->getKey() << " to Replica["
                              << this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                              << "]" << endl;
                }
            }
            AbortMessageToClient *abort_message = new AbortMessageToClient(
                    "abort-message");
            abort_message->setPutIdClientSide(
                    this->keyWriteUtility[update_response->getKey()].putIdClientSide);
            abort_message->setKey(update_response->getKey());
            send(abort_message, "outToClient",
                    this->keyWriteUtility[update_response->getKey()].clientId);
            EV << "Replica[" << this->getIndex()
                      << "]: ABORTED and sent ABORT-MESSAGE to Client["
                      << keyWriteUtility[update_response->getKey()].clientId
                      << "]" << endl;
//            this->watchLocks[update_response->getKey()] = 0;
            this->keyWriteUtility[update_response->getKey()].msgCounter = 0;
            this->keyWriteUtility[update_response->getKey()].clientId = -5;
            this->keyWriteUtility[update_response->getKey()].putIdClientSide =
                    -5;
            this->keyWriteUtility[update_response->getKey()].receivedAbortRequest =
                    false;
            this->keyWriteUtility[update_response->getKey()].versionContainer.clear();
            this->keyWriteUtility[update_response->getKey()].writeQuorum.clear();
            this->keyWriteUtility[update_response->getKey()].tempVersionValue.first =
                    0;
            this->keyWriteUtility[update_response->getKey()].tempVersionValue.second =
                    0;
            this->keyWriteUtility[update_response->getKey()].state = IDLE;
            EV << "Key " << update_response->getKey() << " on Replica["
                      << this->getIndex() << "]: is now IDLE." << endl;
        } else {
            int last_version =
                    *max_element(
                            this->keyWriteUtility[update_response->getKey()].versionContainer.begin(),
                            this->keyWriteUtility[update_response->getKey()].versionContainer.end());
            if (this->keyValueDatastore.find(update_response->getKey())
                    != this->keyValueDatastore.end()) {
                if (last_version
                        <= this->keyValueDatastore[update_response->getKey()].first) {
                    last_version =
                            this->keyValueDatastore[update_response->getKey()].first;
                }
            }
            last_version++;
            UpdatePacket *message_to_duplicate = new UpdatePacket("commit");
            std::pair<int, std::pair<int, int> > key_value_item;
            key_value_item.first = update_response->getKey();
            key_value_item.second.first = last_version;
            key_value_item.second.second =
                    this->keyWriteUtility[update_response->getKey()].tempVersionValue.second;
            message_to_duplicate->setKeyValueItem(key_value_item);
            for (int i = 0; i < this->writeQuorumSize; i++) {
                if (this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                        > this->getIndex()) {
                    UpdatePacket *commit = message_to_duplicate->dup();
                    send(commit, "out",
                            this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                                    - 1);
                    EV << "Replica[" << this->getIndex()
                              << "]: sent COMMIT for key "
                              << update_response->getKey() << " to Replica["
                              << this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                              << "]" << endl;
                } else if (this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                        < this->getIndex()) {
                    UpdatePacket *commit = message_to_duplicate->dup();
                    send(commit, "out",
                            this->keyWriteUtility[update_response->getKey()].writeQuorum[i]);
                    EV << "Replica[" << this->getIndex()
                              << "]: sent COMMIT for key "
                              << update_response->getKey() << " to Replica["
                              << this->keyWriteUtility[update_response->getKey()].writeQuorum[i]
                              << "]" << endl;
                }
            }
            if (this->keyValueDatastore.find(
                    this->keyWriteUtility[update_response->getKey()].tempVersionValue.first)
                    != this->keyValueDatastore.end()) {
                this->keyValueDatastore[this->keyWriteUtility[update_response->getKey()].tempVersionValue.first].first =
                        last_version;
                this->keyValueDatastore[this->keyWriteUtility[update_response->getKey()].tempVersionValue.first].second =
                        this->keyWriteUtility[update_response->getKey()].tempVersionValue.second;
            } else {
                this->keyValueDatastore.insert(key_value_item);
            }
            EV << "Replica[" << this->getIndex() << "]: COMMITED [ key: "
                      << key_value_item.first << "; version: "
                      << key_value_item.second.first << "; value: "
                      << key_value_item.second.second << " ]. Put Id ( client["
                      << this->keyWriteUtility[update_response->getKey()].clientId
                      << "] ): "
                      << this->keyWriteUtility[update_response->getKey()].putIdClientSide
                      << endl;
            CommitMessageToClient *commit_message = new CommitMessageToClient(
                    "commit-message");
            commit_message->setPutIdClientSide(
                    this->keyWriteUtility[update_response->getKey()].putIdClientSide);
            commit_message->setKey(update_response->getKey());
            send(commit_message, "outToClient",
                    this->keyWriteUtility[update_response->getKey()].clientId);
            EV << "Replica[" << this->getIndex()
                      << "]: sent COMMIT-MESSAGE to Client["
                      << keyWriteUtility[update_response->getKey()].clientId
                      << "]" << endl;
//            this->watchLocks[update_response->getKey()] = 0;
            this->keyWriteUtility[update_response->getKey()].state = IDLE;
            EV << "Key " << update_response->getKey() << " on Replica["
                      << this->getIndex() << "]: is now IDLE." << endl;
            this->keyWriteUtility[update_response->getKey()].msgCounter = 0;
            this->keyWriteUtility[update_response->getKey()].clientId = -2;
            this->keyWriteUtility[update_response->getKey()].putIdClientSide =
                    -2;
            this->keyWriteUtility[update_response->getKey()].receivedAbortRequest =
                    false;
            this->keyWriteUtility[update_response->getKey()].versionContainer.clear();
            this->keyWriteUtility[update_response->getKey()].writeQuorum.clear();
            this->keyWriteUtility[update_response->getKey()].tempVersionValue.first =
                    0;
            this->keyWriteUtility[update_response->getKey()].tempVersionValue.second =
                    0;
        }
    }

}

void Replica::replicaCommit(cMessage *msg) {

    //Replica receives COMMIT from proxy and commit the write operation. Key's state become IDLE.

    UpdatePacket *commit = check_and_cast<UpdatePacket*>(msg);
    std::pair<int, std::pair<int, int> > key_value_item =
            commit->getKeyValueItem();
    EV << "Replica[" << this->getIndex() << "]: received COMMIT for key "
              << key_value_item.first << " from Replica["
              << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
              << endl;
    if (this->keyValueDatastore.find(key_value_item.first)
            != this->keyValueDatastore.end()) {
        this->keyValueDatastore[key_value_item.first].first =
                key_value_item.second.first;
        this->keyValueDatastore[key_value_item.first].second =
                key_value_item.second.second;
    } else {
        this->keyValueDatastore.insert(key_value_item);
    }
//    this->watchLocks[commit->getKeyValueItem().first] = 0;
    EV << "Replica[" << this->getIndex() << "]: COMMITED [ key: "
              << key_value_item.first << "; version: "
              << key_value_item.second.first << "; value: "
              << key_value_item.second.second << " ]. Put id ( client ["
              << this->keyWriteUtility[commit->getKeyValueItem().first].clientId
              << "] ): "
              << this->keyWriteUtility[commit->getKeyValueItem().first].putIdClientSide
              << endl;
    this->keyWriteUtility[commit->getKeyValueItem().first].state = IDLE;
    this->keyWriteUtility[commit->getKeyValueItem().first].clientId = -3;
    this->keyWriteUtility[commit->getKeyValueItem().first].putIdClientSide = -3;
    EV << "Key " << commit->getKeyValueItem().first << " on Replica["
              << this->getIndex() << "]: is now IDLE." << endl;

}

void Replica::replicaAbort(cMessage *msg) {

    //Replica received ABORT. Here there is an important check on the map putIdsentAbortRequest. The replica stores in a map all the put operations
    //for which it has sent an abort request to the proxy in order to have a correct mutual exclusion.

    AbortMessage *abort = check_and_cast<AbortMessage*>(msg);
    EV << "Replica[" << this->getIndex() << "]: received ABORT-MESSAGE for key "
              << abort->getKey() << " from Replica["
              << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
              << endl;
    EV << "Replica[" << this->getIndex() << "]: ABORTED. Put id ( client["
              << abort->getClientId() << "] ): " << abort->getPutIdClientSide()
              << endl;
    if (this->putIdSentAbortRequest.find(
            std::pair<int, int>(abort->getPutIdClientSide(),
                    abort->getClientId())) != this->putIdSentAbortRequest.end()
            && this->putIdSentAbortRequest[std::pair<int, int>(
                    abort->getPutIdClientSide(), abort->getClientId())]
                    == true) {
        this->putIdSentAbortRequest[std::pair<int, int>(
                abort->getPutIdClientSide(), abort->getClientId())] = false;
        this->putIdSentAbortRequest.erase(
                std::pair<int, int>(abort->getPutIdClientSide(),
                        abort->getClientId()));
    } else {
//        this->watchLocks[abort->getKey()] = 0;
        this->keyWriteUtility[abort->getKey()].state = IDLE;
        this->keyWriteUtility[abort->getKey()].clientId = -4;
        this->keyWriteUtility[abort->getKey()].putIdClientSide = -4;
        EV << "Key " << abort->getKey() << " on Replica[" << this->getIndex()
                  << "]: is now IDLE." << endl;
    }
}

//Functions for GET operation

void Replica::manageGetRequest(cMessage *msg) {

    //Proxy receive GET from the client and sends VALUE-REQUEST to the read quorum.

    GetRequest *g = check_and_cast<GetRequest*>(msg);
    EV << "Replica[" << this->getIndex() << "]: received GET from Client["
              << msg->getSenderModuleId() - 2 << "]" << endl;
    int id = this->readId;
    ReadUtility temp =
            { 0, g->getReadIdClientSide(), g->getSenderModuleId() - 2 };
    std::pair<int, ReadUtility> read_id_read_utility_item(id, temp);
    this->readId++;
    this->readIdReadUtility.insert(read_id_read_utility_item);
    std::vector<int> read_quorum = g->getReadQuorum();
    ValueRequest *message_to_duplicate = new ValueRequest("value-request");
    message_to_duplicate->setKey(g->getKey());
    message_to_duplicate->setReadId(id);
    for (int i = 0; i < this->readQuorumSize; i++) {
        if (read_quorum[i] > this->getIndex()) {
            ValueRequest *value_request = message_to_duplicate->dup();
            send(value_request, "out", read_quorum[i] - 1);
            EV << "Replica[" << this->getIndex()
                      << "]: sent VALUE-REQUEST to Replica[" << read_quorum[i]
                      << "]" << endl;
        } else if (read_quorum[i] < this->getIndex()) {
            ValueRequest *value_request = message_to_duplicate->dup();
            send(value_request, "out", read_quorum[i]);
            EV << "Replica[" << this->getIndex()
                      << "]: sent VALUE-REQUEST to Replica[" << read_quorum[i]
                      << "]" << endl;
        }
    }

}

void Replica::manageValueRequest(cMessage *msg) {

    //Replica receives VALUE-REQUEST from Proxy and sends back the value if it is stored in the replica, otherwise 0.

    ValueRequest *value_request = check_and_cast<ValueRequest*>(msg);
    EV << "Replica[" << this->getIndex()
              << "]: received VALUE-REQUEST from Replica["
              << msg->getSenderModuleId() - this->clientsNumber - 2
              << "] for key " << value_request->getKey() << endl;
    int key = value_request->getKey();
    int read_id = value_request->getReadId();
    int proxy_gate = msg->getSenderModuleId() - this->clientsNumber - 2;
    if (msg->getSenderModuleId() > msg->getArrivalModuleId()) {
        proxy_gate--;
    }
    if (this->keyValueDatastore.find(key) != this->keyValueDatastore.end()) {
        ValueResponse *value_response = new ValueResponse("value-response");
        std::pair<int, std::pair<int, int> > key_value_item;
        key_value_item.first = key;
        key_value_item.second.first = this->keyValueDatastore[key].first;
        key_value_item.second.second = this->keyValueDatastore[key].second;
        value_response->setKeyValueItem(key_value_item);
        value_response->setReadId(read_id);
        send(value_response, "out", proxy_gate);
        EV << "Replica[" << this->getIndex() << "]: VALUE-RESPONSE for key "
                  << key << " to Replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
                  << endl;
    } else {
        ValueResponse *value_response = new ValueResponse("value-response");
        std::pair<int, std::pair<int, int> > key_value_item;
        key_value_item.first = key;
        key_value_item.second.first = 0;
        key_value_item.second.second = 0;
        value_response->setReadId(read_id);
        value_response->setKeyValueItem(key_value_item);
        send(value_response, "out", proxy_gate);
        EV << "Replica[" << this->getIndex()
                  << "]: sent VALUE-RESPONSE for key " << key << " to Replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
                  << endl;
    }

}

void Replica::manageValueResponse(cMessage *msg) {

    //Proxy collect the VALUE-RESPONSEs and sends to the client the latest version of a specific key.

    ValueResponse *value_response = check_and_cast<ValueResponse*>(msg);
    EV << "Replica[" << this->getIndex()
              << "]: received VALUE-RESPONSE for key "
              << value_response->getKeyValueItem().first << " from Replica["
              << msg->getSenderModuleId() - this->clientsNumber - 2 << "]"
              << endl;
    if (value_response->getKeyValueItem().second.first
            >= this->readIdReadUtility[value_response->getReadId()].versionValueContainer.first) {
        this->readIdReadUtility[value_response->getReadId()].versionValueContainer.first =
                value_response->getKeyValueItem().second.first;
        this->readIdReadUtility[value_response->getReadId()].versionValueContainer.second =
                value_response->getKeyValueItem().second.second;
    }
    this->readIdReadUtility[value_response->getReadId()].readCounter++;
    if (this->readIdReadUtility[value_response->getReadId()].readCounter
            == this->readQuorumSize - 1) {
        if (this->keyValueDatastore.find(
                value_response->getKeyValueItem().first)
                != this->keyValueDatastore.end()) {
            if (this->readIdReadUtility[value_response->getReadId()].versionValueContainer.first
                    <= this->keyValueDatastore[value_response->getKeyValueItem().first].first) {
                this->readIdReadUtility[value_response->getReadId()].versionValueContainer.first =
                        this->keyValueDatastore[value_response->getKeyValueItem().first].first;
                this->readIdReadUtility[value_response->getReadId()].versionValueContainer.second =
                        this->keyValueDatastore[value_response->getKeyValueItem().first].second;
            }
        }

        if (this->readIdReadUtility[value_response->getReadId()].versionValueContainer.first
                == 0) {
            GetResponse *empty_get_response = new GetResponse(
                    "empty-get-response");
            empty_get_response->setKeyValueItem(
                    value_response->getKeyValueItem());
            empty_get_response->setReadIdClientSide(
                    this->readIdReadUtility[value_response->getReadId()].readIdClientSide);
            send(empty_get_response, "outToClient",
                    this->readIdReadUtility[value_response->getReadId()].clientGate);
            EV << "Replica[" << this->getIndex()
                      << "]: sent GET-RESPONSE to Client["
                      << this->readIdReadUtility[value_response->getReadId()].clientGate
                      << "]" << endl;
        } else {
            GetResponse *get_response = new GetResponse("get-response");
            std::pair<int, std::pair<int, int>> temp_kvi(
                    value_response->getKeyValueItem().first,
                    this->readIdReadUtility[value_response->getReadId()].versionValueContainer);
            get_response->setKeyValueItem(temp_kvi);
            get_response->setReadIdClientSide(
                    this->readIdReadUtility[value_response->getReadId()].readIdClientSide);
            send(get_response, "outToClient",
                    this->readIdReadUtility[value_response->getReadId()].clientGate);
            EV << "Replica[" << this->getIndex()
                      << "]: sent GET-RESPONSE to Client["
                      << this->readIdReadUtility[value_response->getReadId()].clientGate
                      << "]" << endl;
        }
        this->readIdReadUtility.erase(value_response->getReadId());
    }

}

void Replica::handleMessage(cMessage *msg) {

    if (std::strcmp(msg->getName(), "put") == 0) {
        Replica::managePutRequest(msg);
    }

    if (std::strcmp(msg->getName(), "update-request") == 0) {
        Replica::manageUpdateRequest(msg);
    }

    if (std::strcmp(msg->getName(), "update-response") == 0) {
        Replica::manageUpdateResponse(msg);
    }

    if (std::strcmp(msg->getName(), "commit") == 0) {
        Replica::replicaCommit(msg);
    }

    if (std::strcmp(msg->getName(), "abort") == 0) {
        Replica::replicaAbort(msg);
    }

    if (std::strcmp(msg->getName(), "get") == 0) {
        Replica::manageGetRequest(msg);
    }

    if (std::strcmp(msg->getName(), "value-request") == 0) {
        Replica::manageValueRequest(msg);
    }

    if (std::strcmp(msg->getName(), "value-response") == 0) {
        Replica::manageValueResponse(msg);
    }

}

