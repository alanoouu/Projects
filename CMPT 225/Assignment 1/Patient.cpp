/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Date of creation: May 27, 2017
 * Author: Alan Ou
 */

#include <string>
#include <iostream>
#include "Patient.h"

using namespace std;

// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient() {
    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
    careCard = "0000000000";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
// All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";

    // Number of digits a carecard entry must have
    const int carecardNumDigits = 10;

    if (aCareCard.size() == carecardNumDigits) {
        careCard = aCareCard;
    } else {
        careCard = "0000000000";
    }
}

// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const {
    return name;
}

// Description: Returns patient's address.
string Patient::getAddress() const {
    return address;
}

// Description: Returns patient's phone number.
string Patient::getPhone() const {
    return phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const {
    return email;
}

// Description: Returns patient's care card number.
string Patient::getCareCard() const {
    return careCard;
}

// Description: Sets the patient's name.
void Patient::setName(const string aName) {
    name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress) {
    address = anAddress;
}

// Description: Sets the patient's phone number.
void Patient::setPhone(const string aPhone) {
    phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail) {
    email = anEmail;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient &rhs) {
    if (careCard == rhs.getCareCard()) {
        return true;
    } else {
        return false;
    }
}

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient &rhs) {
    if (careCard > rhs.getCareCard()) {
        return true;
    } else {
        return false;
    }
}

// Description: Prints the content of "this" patient.
void Patient::printPatient() {
    cout << careCard << ", Patient: " << name << ", " << address << ", " << phone << ", " << email << endl;
}

// end of Patient.cpp