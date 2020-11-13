/*
 * Queue.cpp
 *
 * Class Definition: A link-based ADT implementation of a queue
 *
 * Created on: July 01, 2017
 * Author: Kevin Chen, Alan Ou
 */

#include "Queue.h"
#include "Node.h"
#include "Node.cpp"
#include <cstdio>

// Constructors and Destructor

using namespace std;

// Default constructor
// Description: Create a empty queue
// Postcondition: A empty queue is created with the front and back pointers set to nullptr
template<class ElementType>
Queue<ElementType>::Queue() {
    frontPtr = NULL;
    backPtr = NULL;
    elementCount = 0;
};

// Copy constructor
// Description: Create a copy of the queue
// Postcondition: A copy of the queue is produced
template<class ElementType>
Queue<ElementType>::Queue(const Queue &aQueue) {
    frontPtr = aQueue.frontPtr;
    backPtr = aQueue.backPtr;
    elementCount = aQueue.elementCount;
}

// Destructor
// Description: All elements in the queue are deleted
// Postcondition: The queue is empty and all nodes are set to nullptr, elementCount is set to 0
template<class ElementType>
Queue<ElementType>::~Queue() {
    while (frontPtr != NULL) {
        Node<ElementType> *ptrNodeToDelete = frontPtr;
        frontPtr = frontPtr->getNext();

        // Return node
        ptrNodeToDelete->setNext(NULL);
        delete (ptrNodeToDelete);
        ptrNodeToDelete = NULL;
    }

    elementCount = 0;
}

/******* Public Interface - START - *******/

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template<class ElementType>
int Queue<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Adds newElement to the "back" of this Queue
//              (not necessarily the "back" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
// Method idea from P.403 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
bool Queue<ElementType>::enqueue(const ElementType &newElement) {
    Node<ElementType> *newNodePtr = new Node<ElementType>(newElement);

    // Insert new node
    if (isEmpty()) {
        frontPtr = newNodePtr;
    } else {
        backPtr->setNext(newNodePtr);
    }

    backPtr = newNodePtr;
    elementCount++;
    return true;
}

// Description: Removes the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
// Method idea from P.403 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
bool Queue<ElementType>::dequeue() {
    bool result = false;
    if (!isEmpty()) {
        // If queue is not empty, remove front
        Node<ElementType> *ptrNodetoDelete = frontPtr;
        if (frontPtr == backPtr) {
            frontPtr = NULL;
            backPtr = NULL;
        } else {
            frontPtr = frontPtr->getNext();
        }

        ptrNodetoDelete->setNext(NULL);
        delete (ptrNodetoDelete);
        ptrNodetoDelete = NULL;

        elementCount--;
        result = true;
    }

    return result;
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
// Method idea from P.400 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
template<class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    if (isEmpty()) {
        throw EmptyDataCollectionException("peek() called with empty queue");
    }
    return frontPtr->getData();
}

/******* Public Interface - END - *******/