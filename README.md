# Distributed Systems Project 2022-2023

You are to implement a distributed key-value store that accepts two operations from clients:
1) put(k, v) inserts/updates value v for key k;
2) get(k) returns the value associated with key k (or null if the key is not present).

The store is internally replicated across N nodes (processes) and offers sequential consistency using a quorum-based protocol. The read and write quorums are configuration parameters.

Assumption: processes and links are reliable (use TCP to approximate reliable links and assume no network partitions can occur).
