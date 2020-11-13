/*
* SimulationApp.cpp
*
* File Description: Main file that handles and runs the event loop.
*
* Creation Date: July 01, 2017
* Author: Kevin Chen, Alan Ou
*/

#include <iostream>
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Queue.cpp"
#include "PriorityQueue.cpp"

using namespace std;

// Constants for initializing the Event class to ensure the class invariant of event is followed
const int ARRIVAL_EVENT = 1;
const int DEPARTURE_EVENT = 0;


// Description: Function to handle arrival of customer
void processArrival(PriorityQueue<Event> &eventQueue, bool &tellerAvailable, Queue<Event> &bankLine, int currentTime) {
    try {
        Event customer = eventQueue.peek();
        eventQueue.dequeue();
        cout << customer << endl;
        if (bankLine.isEmpty() && tellerAvailable) {
            int departureTime = customer.getLength() + currentTime;
            Event departureEvent(departureTime, DEPARTURE_EVENT, 0);
            eventQueue.enqueue(departureEvent);
            tellerAvailable = false;
        } else {
            bankLine.enqueue(customer);
        }
    } catch (EmptyDataCollectionException e) {
        cout << e.what() << endl;
    }
}

// Description: Function to handle departure of customer and handle customer wait time in line
void processDeparture(PriorityQueue<Event> &eventQueue, bool &tellerAvailable, Queue<Event> &bankLine, int currentTime,
                      double &waitTime) {
    cout << eventQueue.peek() << endl;
    eventQueue.dequeue();
    if (!bankLine.isEmpty()) {
        try {
            Event customer = bankLine.peek();
            waitTime += currentTime - customer.getTime();
            bankLine.dequeue();
            int departureTime = customer.getLength() + currentTime;
            Event departureEvent(departureTime, DEPARTURE_EVENT, 0);
            eventQueue.enqueue(departureEvent);
        } catch (EmptyDataCollectionException e) {
            cout << e.what() << endl;
        }
    } else {
        tellerAvailable = true;
    }
}

int main() {

    Queue<Event> bankLine;
    PriorityQueue<Event> eventQueue;

    int arrivalTime = 0;
    int length = 0;
    int numberOfCustomers = 0;
    bool tellerAvailable = true;
    double waitTime = 0;

    // Loop to handle data input from plain text
    while (cin >> arrivalTime) {
        cin >> length;
        Event event(arrivalTime, ARRIVAL_EVENT, length);
        eventQueue.enqueue(event);
    }

    // Main event loop
    cout << "Simulation Begins" << endl;
    while (!eventQueue.isEmpty()) {
        Event newEvent = eventQueue.peek();
        int currentTime = newEvent.getTime();
        if (newEvent.getType() == ARRIVAL_EVENT) {
            numberOfCustomers++;
            processArrival(eventQueue, tellerAvailable, bankLine, currentTime);
        } else {
            processDeparture(eventQueue, tellerAvailable, bankLine, currentTime, waitTime);
        }
    }
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl;

    cout << "\tTotal Number of people processed:  " << numberOfCustomers << endl;
    cout << "\tAverage amount of time spent waiting: " << waitTime / static_cast<double>(numberOfCustomers) << endl;

    return 0;
}



