#include "Deque.hpp"

// Check if the deque is empty or not
bool Deque::isEmpty() const{
    return DList.isEmpty();
}

// Return the first element
const Elem& Deque::front(){
    return DList.front();
}

// Return the last element
const Elem& Deque::back(){
    return DList.back();
}

// Return the number of items in the deque
int Deque::size()const{
    return n;
}

// Insert a new element at the beginning of the deque
void Deque::insertFront(const Elem& e){
    DList.addFront(e);
    n++;
}

// Insert a new element at the end of the deque
void Deque::insertBack(const Elem& e){
    DList.addBack(e);
    n++;
}

// Remove the first element of the deque
void Deque::eraseFront() throw(DequeEmpty){
    if(isEmpty()){ throw DequeEmpty("Empty deque");}
    DList.eraseFront();
    n--;
}

// Remove the last element of the deque
void Deque::eraseBack(){
    if(isEmpty()){ throw DequeEmpty("Empty deque");}
    DList.eraseBack();
    n--;
}