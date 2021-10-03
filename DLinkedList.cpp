#include "DLinkedList.hpp"

// Constructor
DLinkedList::DLinkedList(){
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

// Destructor
DLinkedList::~DLinkedList(){
    while(!isEmpty()) removeFront();
    delete header;
    delete trailer;
}

// Check if the doubly linked list is empty
bool DLinkedList::isEmpty() const{
    return (header->next == trailer);
}

// Return the first element of the doubly linked list
const Elem& DLinkedList::front() const{
    return header->next->elem;
}

// Return the last element of the doubly linked list
const Elem& DLinkedList::back() const{
    return trailer->prev->elem;
}

// Add a new element at the front of the doubly linked list
void DLinkedList::addFront(const Elem& element){
    add(header->next, element);
}

// Add a new element at the back of the doubly linked list
void DLinkedList::addBack(const Elem& element){
    add(trailer, element);
}

// Remove the first element from the front of the doubly linked list
void DLinkedList::removeFront(){
    remove(header->next);
}

// Remove the last element from the back of the doubly linked list
void DLinkedList::removeBack(){
    remove(trailer->prev);
}

// Insert a new node before the reference node
void DLinkedList::add(DNode* refNode, const Elem& element){
    DNode* newNode = new DNode;
    newNode->elem = element;
    newNode->next = refNode;
    newNode->prev = refNode->prev;
    refNode->prev->next = refNode->prev = newNode;
}

// Remove the reference node
void DLinkedList::remove(DNode* refNode){
    DNode* predecessor = refNode->prev;
    DNode* successor = refNode->next;
    predecessor->next = successor;
    successor->prev = predecessor;
    delete refNode;
}

