#ifndef DEQUE_H
#define DEQUE_H
#include "DLinkedList.hpp"

// Class of a linked deque
class Deque{
public:
    int size() const; // Return number of elements in the deque
    bool isEmpty() const; // Check if the deque is empty or not
    const Elem& front(); // Return first element of the deque
    const Elem& back(); // Return last element of the deque

    void insertFront(const Elem& element); // Insert new first element
    void insertBack(const Elem& element); // Insert new last element
    void removeFront(); // Remove first element
    void removeBack(); // Remove last element
private:
    DLinkedList DList; // Doubly linked list of elements
    int n = 0; // Count for the number of elements in the deque
friend class NotationConverter;
};

#endif