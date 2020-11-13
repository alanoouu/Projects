//Code for calculaing the height inputted from the user into feet and inches

#include <iostream>
#include "ansiicodes.h"
using namespace std;

int main() {
    // Asks user for height input
    cout << "Enter your height" << ANSII_RED << " (inches): " << ANSII_NORMAL;
    int heightInInches;
    cin >> heightInInches;
    // Prints out the calculated height (inches/12) in feet and inches; also re-prints in just inches
    cout << "Write either: " << ANSII_CYAN << "I'm " << heightInInches/12 << "\'" << heightInInches%12 << "\"!\" \\ " << ANSII_GREEN <<
         "\"I\'m " << heightInInches << "\" tall!\"" << ANSII_NORMAL << endl;
    return 0;
}