/*
* Event.h
*
* Class Description: A class that describes an event for bank customers.
* Class Invariant: the variable 'type' must hold a value of 0 or 1 to denote departure or arrival respectively.
*
* Creation Date: July 01, 2017
* Author: Kevin Chen, Alan Ou
*/
#include<iostream>

using namespace std;

class Event {
private:
    int time;       // Time of event
    int type;       // Type of event, either 1(arrival) or 0(departure)
    int length;     // Length of event

public:
    // Constructors

    // Default Constructor
    Event();

    // Parametrized constructor
    Event(int time, int type, int length);

    // Copy Constructor
    Event(const Event& other);


    // Getters and setters

    // Description: Returns the time of event
    int getTime() const;

    // Description: Returns the type of event
    int getType() const;

    // Description: Returns the length of event
    int getLength() const;

    // Description: Sets the time of event
    void setTime(const int cTime);

    // Description: Sets the type of event
    void setType(const int cType);

    // Description: Sets the length of event
    void setLength(const int cLength);

    // Overloaded operators

    // Description: Compares "this" event time with "customer" event time and determines priority based on time and event
    bool operator<(const Event &customer);

    // Description: Comparison operator. Compares "this" event object with "other" event object
    Event& operator=(const Event& other);
};

// Description: Prints the content of event
ostream& operator<<(ostream& os, Event event);

//end Event