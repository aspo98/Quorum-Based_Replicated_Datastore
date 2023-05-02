#include <omnetpp.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <time.h>
#include <Message_m.h>
#include <string>

using namespace omnetpp;

class Client: public cSimpleModule {

public:
    int replicasNumber;
    int clientsNumber;
    int writeQuorumSize;
    int readQuorumSize;
    int proxy;
    int keyspaceSize;
    int putIdClientSide;
    int readIdClientSide;
    std::vector<int> usedKeys;
    simtime_t putInterval;
    simtime_t getInterval;
    simtime_t operationSimTimeLimit;
//    std::map<int, simtime_t> putRequestsStartTime;
//    std::map<int, simtime_t> readRequestsStartTime;
//    std::map<int, simtime_t> putRequestsCommitTime;
//    std::map<int, simtime_t> getRequestsArrivalTime;
//    cOutVector avgPutRequestTime;
//    cOutVector avgGetRequestTime;
    int putCounter;
    int abortCounter;
    int commitCounter;
    int getCounter;
    int getResponseCounter;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    std::vector<int> selectQuorum(int quorum_size);
    std::vector<int>::iterator randomUnique(std::vector<int>::iterator begin,
            std::vector<int>::iterator end, size_t num_random);
    int selectProxy(std::vector<int> quorum);
    void put(int key, int value, int id);
    void get(int key, int id);

};

Define_Module(Client);

void Client::initialize() {

    srand(time(NULL));

    this->replicasNumber = par("REPLICAS_NUMBER").intValue();
    this->clientsNumber = par("CLIENTS_NUMBER").intValue();
    this->writeQuorumSize = par("WRITE_QUORUM_SIZE").intValue();
    this->readQuorumSize = par("READ_QUORUM_SIZE").intValue();
    this->keyspaceSize = par("KEYSPACE_SIZE").intValue();
    this->putInterval = par("PUT_INTERVAL");
    this->getInterval = par("GET_INTERVAL");
    this->operationSimTimeLimit = par("OPERATION_SIM_TIME_LIMIT");
    this->putIdClientSide = 0;
    this->readIdClientSide = 0;
    this->putCounter = 0;
    this->abortCounter = 0;
    this->commitCounter = 0;
    this->getCounter = 0;
    this->getResponseCounter = 0;

    WATCH(this->putCounter);
    WATCH(this->abortCounter);
    WATCH(this->commitCounter);

//    avgPutRequestTime.setName("avarage put operation duration");
//    avgGetRequestTime.setName("avarage get operation duration");
    simtime_t time_counter = 0;
    while (time_counter < this->operationSimTimeLimit) {
        cMessage *clientTrigger = new cMessage("client-put-trigger");
        scheduleAt(
                1 + time_counter
                        + (double(double(rand() % 100 + 1) - 50) / 1000),
                clientTrigger);
        time_counter += this->putInterval;
    }
    time_counter = 0;
    while (time_counter < this->operationSimTimeLimit) {
        cMessage *clientTrigger = new cMessage("client-get-trigger");
        scheduleAt(1 + time_counter + (double(double(rand() % 100 + 1) - 50) / 1000),
                clientTrigger);
        time_counter += this->getInterval;
    }

}

void Client::handleMessage(cMessage *msg) {

    if (std::strcmp(msg->getName(), "client-put-trigger") == 0) {
        int id;
        id = this->putIdClientSide;
        this->putIdClientSide++;
        int key = rand() % this->keyspaceSize + 1;
        Client::put(key, rand() % 10000 + 1, id);
        this->putCounter++;
//        this->putRequestsStartTime.insert( { id, simTime() });
    }

    if (std::strcmp(msg->getName(), "client-get-trigger") == 0) {
        int id;
        id = this->readIdClientSide;
        this->readIdClientSide++;
        int key = rand() % this->keyspaceSize + 1;
        Client::get(key, id);
        this->getCounter++;
//        this->readRequestsStartTime.insert( { id, simTime() });
    }

    if (std::strcmp(msg->getName(), "abort-message") == 0) {
        AbortMessageToClient *abort_message = check_and_cast<
                AbortMessageToClient*>(msg);
        EV << "Client[" << this->getIndex()
                  << "]: received ABORT-MESSAGE from replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2
                  << "] on key: " << abort_message->getKey() << ". PutId: "
                  << abort_message->getPutIdClientSide() << endl;
        this->abortCounter++;
    }

    if (std::strcmp(msg->getName(), "commit-message") == 0) {
        CommitMessageToClient *commit_message = check_and_cast<
                CommitMessageToClient*>(msg);
        EV << "Client[" << this->getIndex()
                  << "]: received COMMIT-MESSAGE from replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2
                  << "] on key: " << commit_message->getKey() << ". PutId: "
                  << commit_message->getPutIdClientSide() << endl;
        this->commitCounter++;
//        avgPutRequestTime.record(
//                simTime()
//                        - this->putRequestsStartTime[commit_message->getPutIdClientSide()]);
    }

    if (std::strcmp(msg->getName(), "get-response") == 0) {
        GetResponse *get_response = check_and_cast<GetResponse*>(msg);
        EV << "Client[" << this->getIndex()
                  << "]: received GET-RESPONSE from replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2
                  << "]. GetId: " << get_response->getReadIdClientSide()
                  << " Data item: [ key: "
                  << get_response->getKeyValueItem().first << "; version: "
                  << get_response->getKeyValueItem().second.first << "; value: "
                  << get_response->getKeyValueItem().second.second << " ]"
                  << endl;
        this->getResponseCounter++;
//        avgGetRequestTime.record(
//                simTime()
//                        - this->readRequestsStartTime[get_response->getReadIdClientSide()]);
    }

    if (std::strcmp(msg->getName(), "empty-get-response") == 0) {
        GetResponse *get_response = check_and_cast<GetResponse*>(msg);
        EV << "Client[" << this->getIndex()
                  << "]: received EMPTY-GET-RESPONSE from replica["
                  << msg->getSenderModuleId() - this->clientsNumber - 2
                  << "]. GetId: " << get_response->getReadIdClientSide()
                  << " Key not found!" << endl;
        this->getResponseCounter++;
//        avgGetRequestTime.record(
//                simTime()
//                        - this->readRequestsStartTime[get_response->getReadIdClientSide()]);
    }

}

void Client::finish() {
    recordScalar("# of put requests", this->putCounter);
    recordScalar("# of get requests", this->getCounter);
    recordScalar("# of get responses", this->getResponseCounter);
    recordScalar("# of committed put", this->commitCounter);
    recordScalar("# of aborted put", this->abortCounter);
}

std::vector<int> Client::selectQuorum(int quorum_size) {

    std::vector<int> quorum;
    for (int i = 0; i < this->replicasNumber; i++)
        quorum.push_back(i);
    Client::randomUnique(quorum.begin(), quorum.end(), quorum_size);
    quorum.resize(quorum_size);
    return quorum;
}

std::vector<int>::iterator Client::randomUnique(

        std::vector<int>::iterator begin, std::vector<int>::iterator end,
        size_t num_random) {
    size_t left = std::distance(begin, end);
    while (num_random--) {
        std::vector<int>::iterator r = begin;
        std::advance(r, rand() % left);
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;

}

int Client::selectProxy(std::vector<int> quorum) {

    int random_pos = rand() % quorum.size();
    int proxy = quorum[random_pos];
    return proxy;

}

void Client::put(int key, int value, int id) {

    std::vector<int> write_quorum = Client::selectQuorum(this->writeQuorumSize);
    this->proxy = Client::selectProxy(write_quorum);
    PutRequest *request = new PutRequest("put");
    request->setWriteQuorum(write_quorum);
    request->setKey(key);
    request->setValue(value);
    request->setPutIdClientSide(id);
    send(request, "outToReplica", this->proxy);
    std::string write_quorum_to_print = "";
    for (int i = 0; i < write_quorum.size(); i++)
        write_quorum_to_print += (std::to_string(write_quorum.at(i)) + " ");
    EV << "Client[" << this->getIndex() << "]: sent PUT (id "
              << id << ") [ proxy: " << this->proxy
              << "; write quorum: [ " << write_quorum_to_print << "] , < key: "
              << key << ", value: " << value << " > ]" << endl;

}

void Client::get(int key, int id) {

    std::vector<int> read_quorum = Client::selectQuorum(this->readQuorumSize);
    this->proxy = Client::selectProxy(read_quorum);
    GetRequest *request = new GetRequest("get");
    request->setReadQuorum(read_quorum);
    request->setKey(key);
    request->setReadIdClientSide(id);
    send(request, "outToReplica", this->proxy);
    std::string read_quorum_to_print = "";
    for (int i = 0; i < read_quorum.size(); i++)
        read_quorum_to_print += (std::to_string(read_quorum.at(i)) + " ");
    EV << "Client[" << this->getIndex() << "]: sent GET (id "
              << id << ")  [ proxy: " << this->proxy
              << "; read quorum: [ " << read_quorum_to_print << "] , < key: "
              << key << " > ]" << endl;

}

