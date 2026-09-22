# Heber Reynolds
# 10843438
# CS3450 - 002
# Program 1 - Strategy Pattern

## Language

C++17

## Description

This program implements a generic Queue using the Strategy Pattern.
The Queue class depends on the QueueStorage interface rather than a
specific container implementation. The storage implementation can be
changed at runtime while preserving the contents of the queue in FIFO
(First In First Out) order.

Two storage implementations are included:

-VectorStorage
-ListStorage

The test driver has both storage implementations using both
integers and strings.

## Build

Compile with:

bash

g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program1