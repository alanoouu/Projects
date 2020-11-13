/*
* List.cpp
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

#include "List.h"
#include <string>
#include "Patient.h"

using namespace std;

// Description: Expands section of the array
// Postcondition: New section of the array is created with double the original capacity,
//                all elements are copied, and the old section is deleted, then replaced by the new section.
void List::expand(int index) {
    const int DOUBLE_SIZE = 2;

    Patient *newArr = new Patient[capacity[index] * DOUBLE_SIZE];
    capacity[index] *= DOUBLE_SIZE;
    for (int i = 0; i < arrElementCount[index]; i++) {
        newArr[i] = arrStore[index][i];
    }
    delete[] arrStore[index];
    arrStore[index] = newArr;
}

// Description: Returns the index of the patient in the array
int List::findIndex(Patient pat) {
    return pat.getCareCard().at(0) - '0';
}

// Default constructor
List::List() {
    // The current maximum capacity
    const int MAX_CAPACITY = 3;

    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        capacity[i] = MAX_CAPACITY;
        arrStore[i] = new Patient[MAX_CAPACITY];
        arrElementCount[i] = 0;
    }
}

// Destructor
List::~List() {
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        delete[] arrStore[i];
    }
} // end of destructor

// Copy Constructor
List::List(const List &other) {
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        capacity[i] = other.capacity[i];
        arrStore[i] = new Patient[capacity[i]];
        arrElementCount[i] = other.arrElementCount[i];
    }

    // Copy the elements
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        for (int j = 0; j < arrElementCount[i]; j++) {
            arrStore[i][j] = other.arrStore[i][j];
        }
    }
} // end of copy constructor

// *** Start of Public Interface ***

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const {
    int count = 0;
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        count += arrElementCount[i];
    }
    return count;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool List::insert(const Patient &newElement) {
    int index = findIndex(newElement);

    if (arrElementCount[index] == 0) {
        arrStore[index][0] = newElement;
        arrElementCount[index]++;
        return true;
    }

    // If newElement already exists, return false
    if (search(newElement)) {
        return false;
    }

    if (arrElementCount[index] == capacity[index]) {
        expand(index);
    }

    for (int i = 0; i < arrElementCount[index]; i++) {
        if (arrStore[index][i] > newElement) {
            for (int j = arrElementCount[index] - 1; j >= i; j--) {
                arrStore[index][j + 1] = arrStore[index][j];
            }
            arrStore[index][i] = newElement;
            arrElementCount[index]++;
            break;
        }
        if (i == (arrElementCount[index] - 1)) {
            arrStore[index][i + 1] = newElement;
            arrElementCount[index]++;
            break;
        }
    }

    return true;
}

// Description: Remove an element.
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.
bool List::remove(const Patient &toBeRemoved) {
    int index = findIndex(toBeRemoved);
    for (int i = 0; i < arrElementCount[index]; i++) {
        if (arrStore[index][i] == toBeRemoved) {
            arrStore[index][i] = arrStore[index][arrElementCount[index] - 1];
            arrElementCount[index]--;
            return true;
        }
    }

    return false;
}

// Description: Remove all elements.
void List::removeAll() {
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        arrElementCount[i] = 0;
    }
}

// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
Patient *List::search(const Patient &target) {
    string careCard = target.getCareCard();
    int index = careCard.at(0) - '0';
    for (int i = 0; i < arrElementCount[index]; i++) {
        if (arrStore[index][i] == target) {
            return &arrStore[index][i];
        }
    }
    return NULL;
}

// Description: Prints all n elements stored in List in sort order and does so in O(n).
void List::printList() {
    for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
        for (int j = 0; j < arrElementCount[i]; j++) {
            arrStore[i][j].printPatient();
        }
    }
}

// *** End of Public Interface ***