#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

typedef char Elem; // Element type of the doubly linked list

// Class of a doubly linked list node
class DNode{
    private:
    Elem elem;
    DNode* prev;
    DNode* next;
friend class DLinkedList;
};

// Class of a doubly linked list
class DLinkedList{
public:
    DLinkedList(); // Constructor
    ~DLinkedList(); // Destructor
    bool isEmpty() const; // Check if the doubly linked list is empty
    const Elem& front() const throw(DequeEmpty); // Return the first element of the doubly linked list
    const Elem& back() const throw(DequeEmpty); // Return the last element of the doubly linked list
    void addFront(const Elem& element); // Add a new element at the front of the doubly linked list
    void addBack(const Elem& element); // Add a new element at the back of the doubly linked list
    void removeFront() throw(DequeEmpty); // Remove the first element from the front of the doubly linked list
    void removeBack(); throw(DequeEmpty); // Remove the last element from the back of the doubly linked list
private:
    DNode* header;
    DNode* trailer;
protected:
    void add(DNode* refNode, const Elem& element); // Insert a new node before the reference node
    void remove (DNode* refNode); // Remove the reference node
};

#endif