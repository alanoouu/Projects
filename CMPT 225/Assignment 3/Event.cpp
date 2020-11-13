/*
* Event.cpp
*
* Class Description: A class that describes an event for bank customers.
* Class Invariant: the variable 'type' must hold a value of 0 or 1 to denote departure or arrival respectively.
*
* Creation Date: July 01, 2017
* Author: Kevin Chen, Alan Ou
*/

#include "Event.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors

// Default Constructor
Event::Event() {
    this->time = 0;
    this->type = 0;
    this->length = 0;
}

// Parametrized constructor
Event::Event(int time, int type, int length) {
    this->time = time;
    this->type = type;
    this->length = length;
}

// Copy Constructor
Event::Event(const Event &other) {
    this->time = other.time;
    this->type = other.type;
    this->length = other.length;
}

// Getters and setters

// Description: Returns the time of event
int Event::getTime() const {
    return time;
}

// Description: Returns the type of event
int Event::getType() const {
    return type;
}

// Description: Returns the length of event
int Event::getLength() const {
    return length;
}

// Description: Sets the time of event
void Event::setTime(int cTime) {
    time = cTime;
}

// Description: Sets the type of event
void Event::setType(int cType) {
    type = cType;
}

// Description: Sets the length of event
void Event::setLength(int cLength) {
    length = cLength;
}

// Overloaded operators

// Description: Compares "this" event time with "customer" event time and determines priority based on time and event
bool Event::operator<(const Event &customer) {
    if (this->time != customer.time) {
        return this->time < customer.time;
    } else {
        // Arrival events have higher priority than departure events when the times are the same
        return this->type < customer.type;
    }
}

// Description: Comparison operator. Compares "this" event object with "other" event object
Event &Event::operator=(const Event &other) {
    this->time = other.time;
    this->length = other.length;
    this->type = other.type;
}

// Description: Prints the content of event
ostream &operator<<(ostream &os, Event event) {
    if (event.getType()) {
        os << "Processing an arrival event at time: " << setw(4) << event.getTime();
    } else {
        os << "Processing a departure event at time:" << setw(4) << event.getTime();
    }
}

