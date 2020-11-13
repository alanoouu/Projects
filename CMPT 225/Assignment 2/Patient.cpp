/*
 * Patient.cpp
 *
 * Class Description: Walk-in clinic patient model implementation.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Creation Date: June 5, 2017
 * Author: Kevin Chen, Alan Ou
 */


#include "Patient.h"
#include <string>
#include <iostream>

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
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
    if (aCareCard.length() == 10) {
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

// Description: Returns patient's phone.
string Patient::getPhone() const {
    return phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const {
    return email;
}

// Description: Returns patient's care card.
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

// Description: Sets the patient's phone.
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
    return (this->careCard == rhs.careCard);
}

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient &rhs) {
    string a = this->careCard;
    string b = rhs.careCard;
    for (unsigned int i = 0; i < careCard.length(); i++) {
        if (a.at(i) == b.at(i)) { continue; }
        return (a.at(i) > b.at(i));
    }
    return false;
}

void Patient::printPatient() {
    cout << this->careCard << ", Patient: " << this->name
         << ", " << this->address << ", " << this->phone
         << ", " << this->email << endl;
}