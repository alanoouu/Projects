/*
* PriorityQueue.cpp
*
* Class Description: An array-based priority queue data collection ADT.
* Class Invariant: Data collection with the following characteristics:
*                   - The highest priority value is located at [elementCount - 1] when not empty.
*                   - Its data structure is not expandable.
*
* Creation Date: July 01, 2017
* Author: Kevin Chen, Alan Ou
*/

#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

// Default Constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    elementCount = 0;
}

// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template<class ElementType>
int PriorityQueue<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType &newElement) {
    if (elementCount == MAX_ELEMENTS) {
        return false;
    }
    if (elementCount == 0) {
        elements[0] = newElement;
        elementCount++;
        return true;
    }
    for (int i = 0; i < elementCount; i++) {
        if (elements[i] < newElement) {
            for (int j = elementCount - 1; j >= i; j--) {
                elements[j + 1] = elements[j];
            }
            elements[i] = newElement;
            elementCount++;
            break;
        } else if (i == elementCount - 1) {
            i++;
            elements[i] = newElement;
            elementCount++;
            break;
        }
    }
    return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::dequeue() {
    if (elementCount != 0) {
        elementCount--;
        return true;
    } else {
        return false;
    }
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    if (elementCount == 0) {
        throw (EmptyDataCollectionException("peek() called with empty queue"));
    } else {
        return elements[elementCount - 1];
    }
}


