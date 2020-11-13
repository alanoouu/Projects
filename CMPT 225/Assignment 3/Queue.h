/*
 * Queue.h
 *
 * Class Definition: A link-based ADT implementation of a queue
 *
 * Created on: July 01, 2017
 * Author: Kevin Chen, Alan Ou
 */

#pragma once
#include "Node.h"
#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {

private:
    // Number of elements in the link-list
    int elementCount;

    // Pointers to the front and back nodes
    Node<ElementType> *frontPtr;
    Node<ElementType> *backPtr;

public:

    // Default constructor
    // Description: Create a empty queue
    // Postcondition: A empty queue is created with the front and back pointers set to nullptr
    Queue();

    // Copy constructor
    // Description: Create a copy of the queue
    // Postcondition: A copy of the queue is produced
    Queue(const Queue& aQueue);

    // Destructor
    // Description: All elements in the queue are deleted
    // Postcondition: The queue is empty and all nodes are set to nullptr, elementCount is set to 0
    ~Queue();

/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    // Method idea from P.403 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    bool enqueue(const ElementType &newElement);

    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    // Method idea from P.403 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    bool dequeue();

    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    // Method idea from P.400 of Data Abstractions & Problem Solving with C++, Walls and Mirrors(6th edition), Frank M.Carrano and Timothy Henry
    ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Queue class.

}; // end Queue
