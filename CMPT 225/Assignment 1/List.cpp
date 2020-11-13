/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Date of creation: May 27, 2017
 * Author: Alan Ou
 */

#include <iostream>
#include <string>
#include "List.h"
#include "Patient.h"

using namespace std;


// Default constructor
List::List()
        : elementCount(0), capacity(List::MAX_ELEMENTS) {}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const {
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient &newElement) {

    // Check to see if newElement is already in the collection
    for (int i = -1; i < elementCount; i++) {
        // If it is, then return false
        if (newElement.getCareCard() == elements[i].getCareCard()) {
            return false;
        }
    }

    // Variable to store the position of newElement
    int insertPos = 0;

    // Case 1, if the inserted element is the first element
    if (elementCount == 0) {
        insertPos = 0;
    }

        // Case 2, if the inserted element is the second element
    else if (elementCount == 1) {
        if (newElement.getCareCard() > elements[0].getCareCard()) {
            insertPos = 1;
        } else {
            insertPos = 0;
        }

    } else {
        // Case 3, the the inserted element is the third or more element
        for (int index = 0; index < elementCount; index++) {
            // Leave the loop after the carecard of newElement is smaller than the occupying one
            if (newElement.getCareCard() < elements[index].getCareCard()) {
                insertPos = index;
                break;
            }
        }
    }

    // Shift elements
    for (int currentPos = elementCount; currentPos >= insertPos; currentPos--) {
        elements[currentPos] = elements[currentPos - 1];
    }

    // Insert new element
    elements[insertPos] = newElement;
    elementCount++;

    return true;
}

// Description: Remove an element.
// Precondition: the patient toBeRemoved must exist in the data
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient &toBeRemoved) {

    // Find position of element
    for (int i = 0; i < elementCount; i++) {

        // If the two carecards are the same, then we find a match
        if (toBeRemoved.getCareCard() == elements[i].getCareCard()) {

            // Remove element by shifting all elements after toBeRemoved one closer to the beginning of array
            for (int startPos = i + 1, toPos = startPos - 1; startPos < elementCount; startPos++, toPos++) {
                elements[toPos] = elements[startPos];
            }

            // Decrease the elementCount
            elementCount--;
            return true;

        }
    }

    return false;
}

// Description: Remove all elements.
void List::removeAll() {
    elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient *List::search(const Patient &target) {
    // Set the pointer to the target element to NULL in the beginning
    Patient *searchedElement = NULL;

    // Loop through all elements, setting searchedElement the pointer if found
    for (int i = 0; i < elementCount; i++) {
        if (target.getCareCard() == elements[i].getCareCard()) {
            searchedElement = &elements[i];
        }
    }

    return searchedElement;
}

// Description: Prints all elements stored in List.
void List::printList() {
    for (int i = 0; i < elementCount; i++) {
        elements[i].printPatient();
    }
}

// end List.cpp