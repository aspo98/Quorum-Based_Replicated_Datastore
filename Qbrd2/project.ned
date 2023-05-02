//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

import ned.DelayChannel;

simple Replica
{
    parameters:
        int REPLICAS_NUMBER;
        int CLIENTS_NUMBER;
        int WRITE_QUORUM_SIZE;
        int READ_QUORUM_SIZE;



    gates:
        input in[];
        output out[];
        input inFromClient[];
        output outToClient[];


}


simple Client
{
    parameters:
        int REPLICAS_NUMBER;
        int CLIENTS_NUMBER;
        int WRITE_QUORUM_SIZE;
        int READ_QUORUM_SIZE;
        int KEYSPACE_SIZE;
        double PUT_INTERVAL @unit(s);
        double GET_INTERVAL @unit(s);
        double OPERATION_SIM_TIME_LIMIT @unit(s);

    gates:
        input inFromReplica[];
        output outToReplica[];

}

channel C extends ned.DatarateChannel
{
//    delay = uniform(90ms,110ms);
	delay = 100ms;
    datarate = 1024kbps;
}

//
// A network with full graph topology for replicas + clients that can contact every replica.
//
network QBRD
{
    parameters:
        int REPLICAS_NUMBER;
        int CLIENTS_NUMBER;
        int WRITE_QUORUM_SIZE;
        int READ_QUORUM_SIZE;



    submodules:
        client[CLIENTS_NUMBER]: Client {
            @display("i=abstract/person");
        }
        replica[REPLICAS_NUMBER]: Replica {
            @display("i=abstract/db");
        }

    connections:
        for i=0..REPLICAS_NUMBER-1, for j=0..CLIENTS_NUMBER-1 {
            client[j].outToReplica++ --> C --> replica[i].inFromClient++;
            replica[i].outToClient++ --> C --> client[j].inFromReplica++;
        }


        for i=0..REPLICAS_NUMBER-2, for j=i+1..REPLICAS_NUMBER-1 {
            replica[i].out++ --> C --> replica[j].in++;
            replica[j].out++ --> C --> replica[i].in++;
        }

}
