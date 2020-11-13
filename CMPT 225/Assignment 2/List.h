/*
 * List.h
 *
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Creation Date: June 5, 2017
 * Author: Kevin Chen, Alan Ou
 */

#pragma once

#include <string>
#include "Patient.h"

using namespace std;

class List {

private:

    // Number of different integers
    static const int NUMBER_OF_DIGITS = 10;

    // Array meant to hold 10 dynamic arrays of patients sorted on their initial carecard number
    // ie. all carecards that start with '7' are listed under arrStore[7]
    Patient *arrStore[NUMBER_OF_DIGITS];

    // Parallel array meant to store the size of corresponding part of arrStore
    int arrElementCount[NUMBER_OF_DIGITS];

    // Parallel array meant to hold the capacities of dynamic arrays in arrStore
    int capacity[NUMBER_OF_DIGITS];

    // Description: Expands section of the array
    // Postcondition: New section of the array is created with double the original capacity,
    //                all elements are copied, and the old section is deleted, then replaced by the new section.
    void expand(int index);

    // Description: Returns the index of the patient in the array
    int findIndex(Patient pat);

public:

    // Default constructor
    List();

    // Destructor
    ~List();

    // Copy Constructor
    List(const List &other);

// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

    // Description: Returns the total element count currently stored in List.
    int getElementCount() const;

    // Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate
    //              a new element. This is done unbeknown to the client code.
    //              If the insertion is successful, true is returned otherwise, false is returned.
    // Precondition: newElement must not already be in data collection.
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    bool insert(const Patient &newElement);

    // Description: Remove an element.
    //              If the removal is successful, true is returned otherwise, false is returned.
    // Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.
    bool remove(const Patient &toBeRemoved);

    // Description: Remove all elements.
    void removeAll();

    // Description: Search for target element and returns a pointer to it if found,
    //              otherwise, returns NULL.
    Patient *search(const Patient &target);

    // Description: Prints all n elements stored in List in sort order and does so in O(n).
    void printList();

// *** End of Public Interface ***

}; // end List