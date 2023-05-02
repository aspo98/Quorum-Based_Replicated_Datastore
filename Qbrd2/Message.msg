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

cplusplus {{
#include <vector>
typedef std::vector<int> Vector;
}}
class Vector { @existingClass; };

cplusplus {{
#include <utility>
typedef std::pair<int,std::pair<int,int>> DataItem;
}}
class DataItem { @existingClass; };

//
// TODO generated message class
//
message PutRequest {
    Vector writeQuorum;
    int key;
    int value;
    int putIdClientSide;
}

message UpdatePacket {
    DataItem keyValueItem;   
}

message AbortMessage{
    int key;
    int putIdClientSide;
    int clientId; 
}

message AbortMessageToClient{
    int key;
    int putIdClientSide;
}

message CommitMessageToClient{
    int key;
    int putIdClientSide;
}

message UpdateRequest {
	int key;
	int putIdClientSide;
	int clientId;
}

message UpdateResponse{
	int key;
	int version;
	bool abortRequest = false;
}

message GetRequest {
    Vector readQuorum;
	int key;
	int readIdClientSide;
}

message ValueRequest {
    int key;
    int readId;
}

message ValueResponse {
    DataItem keyValueItem; 
    int readId;
}

message GetResponse{
    DataItem keyValueItem;
    int readIdClientSide;
}