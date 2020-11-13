/*
 * WICPS.cpp
 *
 * Description: Patient database application.
 *
 * Creation Date: June 5, 2017
 * Author: Kevin Chen, Alan Ou
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;

// Description: Add a patient.
void add(List *patients) {
    string careCard;

    // Create a new patient
    cout << "Please enter a carecard: ";
    getline(cin >> ws, careCard);

    Patient pat(careCard);

    // Add patient into database
    if (patients->insert(pat)) {
        cout << endl << "Patient successfully entered" << endl;
    } else {
        cout << endl << "Patient unable to be entered" << endl;
    }
}

// Description: Remove a patient
void removePatient(List *patients) {
    string careCard;

    // Ensure that there is at least one element in the data
    if (patients->getElementCount() != 0) {

        // Create a new patient
        cout << "Please enter a carecard: ";
        getline(cin >> ws, careCard);

        // Remove patient from data
        if (patients->remove(careCard)) {
            cout << endl << "Patient successfully removed" << endl;
        } else {
            cout << endl << "Patient unable to be removed" << endl;
        }
    } else {
        cout << endl << "There are no patients in data collection" << endl;
    }
}

// Description: Remove all patients
void removeAllPatient(List *patients) {
    patients->removeAll();
    cout << endl << "All patients removed" << endl;
}

// Description: Search a patient.
void searchPatient(List *patients) {
    string careCard;

    // elementCount must greater than 0
    if (patients->getElementCount() != 0) {

        // Ask for a carecard entry
        cout << "Please enter a carecard: ";
        getline(cin >> ws, careCard);

        // Initialize search
        Patient *searched = patients->search(careCard);

        // Variable declaration
        char input = 0;

        // Loops menu
        bool done = false;

        if (searched != NULL) {
            cout << endl << "Patient entered, enter a command" << endl;
        } else {
            // If there does not exist any patients
            cout << endl << "This patient does not exist, please check and try again." << endl;
            done = true;
        }

        while (!done) {

            // Print menu
            cout << endl << "To search for the patient's name,         enter: n" << endl;
            cout << "To search for the patient's address,      enter: a" << endl;
            cout << "To search for the patient's phone,        enter: p" << endl;
            cout << "To search for the patient's email,        enter: e" << endl;
            cout << "To search for the patient's carecard,     enter: c" << endl;
            cout << "To go back to the main menu,              enter: x" << endl << endl;

            cout << "Your Choice: ";
            cin >> input;
            input = tolower(input);

            // Match choice, then print requested info
            if (input == 'n') {
                cout << "Name: " << searched->getName() << endl;
            } else if (input == 'a') {
                cout << "Address: " << searched->getAddress() << endl;
            } else if (input == 'p') {
                cout << "Phone: " << searched->getPhone() << endl;
            } else if (input == 'e') {
                cout << "Email: " << searched->getEmail() << endl;
            } else if (input == 'c') {
                cout << "Carecard: " << searched->getCareCard() << endl;
            } else if (input == 'x') {
                cout << "Returning to previous menu..." << endl;
                done = true;
            } else {
                cout << endl << "Invalid choice, please try again!" << endl;
            }
        }

    } else {
        // If there does not exist any patients
        cout << endl << "There are no patients, please add some before searching!" << endl;
    }
}

// Description: Modifies a patient.
void modify(List *patients) {
    string careCard;

    // Ensure there exists at least one patient
    if (patients->getElementCount() != 0) {

        // Ask for carecard and store into carecard variable
        cout << "Please enter a carecard: ";
        getline(cin >> ws, careCard);

        Patient *changPat = patients->search(careCard);

        // Variable declaration for the following menu
        char input = 0;

        // Loops menu
        bool done = false;

        cout << endl << "Patient entered, enter a command" << endl;

        while (!done) {

            // Print menu
            cout << endl << "To modify a patient's name,         enter: n" << endl;
            cout << "To modify a patient's address,      enter: a" << endl;
            cout << "To modify a patient's phone,        enter: p" << endl;
            cout << "To modify a patient's email,        enter: e" << endl;
            cout << "To go back to the main menu,        enter: x" << endl << endl;

            // Take in choice
            cout << "Your Choice: ";
            cin >> input;
            cout << endl << endl;
            input = tolower(input);

            // Match choice with corresponding method
            if (input == 'n') {
                string newName = "";
                cout << "Please enter the new name: ";
                getline(cin >> ws, newName);
                changPat->setName(newName);
                cout << endl << endl << "Name changed" << endl;
            } else if (input == 'a') {
                string newAddress = "";
                cout << "Please enter the new address: ";
                getline(cin >> ws, newAddress);
                changPat->setAddress(newAddress);
                cout << endl << endl << "Address changed" << endl;
            } else if (input == 'p') {
                string newPhone = "";
                cout << "Please enter the new phone: ";
                getline(cin >> ws, newPhone);
                changPat->setPhone(newPhone);
                cout << endl << endl << "Phone changed" << endl;
            } else if (input == 'e') {
                string newEmail = "";
                cout << "Please enter the new email: ";
                getline(cin >> ws, newEmail);
                changPat->setEmail(newEmail);
                cout << endl << endl << "Email changed" << endl;
            } else if (input == 'x') {
                cout << "Returning to previous menu..." << endl;
                done = true;
            } else {
                cout << "Invalid choice, please try again!" << endl;
            }
        }

    } else {
        cout << endl << "There are no patients, please add some before modifying!" << endl;
    }
}

// Prints all the patients
void print(List *patients) {
    cout << endl << "****** PATIENT LIST ****** " << endl << endl;
    if (patients->getElementCount() == 0) {
        cout << "There are no patients" << endl << endl;
    } else {
        patients->printList();
    }
}

int main() {
    // Declare variables
    List *patients = new List();
    bool done = false;
    char input = 0;

    // Print title
    cout << "Walk-in Clinic Patient System" << endl;

    // Loops menu
    while (!done) {

        // Print menu
        cout << endl << "To enter a new patient into the system, enter: e" << endl;
        cout << "To remove a patient from the system,    enter: r" << endl;
        cout << "To remove all patients from the system, enter: a" << endl;
        cout << "To search the information of a patient, enter: s" << endl;
        cout << "To modify a patient's record,           enter: m" << endl;
        cout << "To print all the patients,              enter: p" << endl;
        cout << "To exit,                                enter: x" << endl << endl;

        cout << "Your Choice: ";
        cin >> input;
        input = tolower(input);

        // Match choice with corresponding function
        if (input == 'e') {
            add(patients);
        } else if (input == 'r') {
            removePatient(patients);
        } else if (input == 'a') {
            removeAllPatient(patients);
        } else if (input == 's') {
            searchPatient(patients);
        } else if (input == 'm') {
            modify(patients);
        } else if (input == 'p') {
            print(patients);
        } else if (input == 'x') {
            cout << "Exiting..." << endl;
            done = true;
        } else {
            cout << "Invalid choice, please try again!" << endl;
        }
    }

    // Free memory when done
    delete patients;
    patients = NULL;

    return 0;
}