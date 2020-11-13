/*
* PriorityQueue.h
*
* Class Description: An array-based priority queue data collection ADT.
* Class Invariant: Data collection with the following characteristics:
*                   - The highest priority value is located at [elementCount - 1] when not empty.
*                   - Its data structure is not expandable.
*
* Creation Date: July 01, 2017
* Author: Kevin Chen, Alan Ou
*/
#include "EmptyDataCollectionException.h"
#include <iostream>

#pragma once

template<class ElementType>

class PriorityQueue {

private:

    static const int MAX_ELEMENTS = 100;

    ElementType elements[MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
    int elementCount;                  // Current element count in element array

public:

    // Default Constructor
    PriorityQueue();


/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Priority Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType &newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/
}; // end PriorityQueue
