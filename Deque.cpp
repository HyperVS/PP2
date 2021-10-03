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
int Deque::size() const{
    return n;
}

// Insert a new element at the beginning of the deque
void Deque::insertFront(const Elem& element){
    DList.addFront(element);
    n++;
}

// Insert a new element at the end of the deque
void Deque::insertBack(const Elem& element){
    DList.addBack(element);
    n++;
}

// Remove the first element of the deque
void Deque::removeFront(){
    if(isEmpty()){ throw("Empty deque");}
    DList.removeFront();
    n--;
}

// Remove the last element of the deque
void Deque::removeBack(){
    if(isEmpty()){ throw("Empty deque");}
    DList.removeBack();
    n--;
}