# Quorum-Based Replicated Datastore

You are to implement a distributed key-value store that accepts two operations from clients:
1) put(k, v) inserts/updates value v for key k;
2) get(k) returns the value associated with key k (or null if the key is not present).

The store is internally replicated across N nodes (processes) and offers sequential consistency using a quorum-based protocol. The read and write quorums are configuration parameters.

Assumption: processes and links are reliable (use TCP to approximate reliable links and assume no network partitions can occur).

We decided to simulate the network by means of OMNeT++, making use of the knowledge gained from the Distributed Systems course and our own understanding of leaderless protocols to implement the requested quorum-based distributed datastore.
