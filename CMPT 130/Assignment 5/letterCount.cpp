#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include "ansiicodes.h"

using namespace std;

vector<int> letterCount(string inString);
void printLetterCounts(vector<int> letterCount);

int main() {
    // Ask for a string input
    cout << "Enter your string. " << endl << ":";
    string userString;
    getline(cin, userString);

    // Re-print the entered string
    cout << "You entered: " << userString << endl << endl;

    // Run letterCount function using the entered string
    letterCount(userString);

    return 0;
}

vector<int> letterCount(string inString) {
    // Create vector of alphabet
    vector<int> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                            'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Create vector to store number of times each character appears
    vector<int> numTimesCharAppears;

    // Start checking from the letter A, then B ...
    for (int index = 0; index < alphabet.size(); index++) {
        int numTimes = 0;

        // Check if A is a character is in any part of the string, then B....
        for (int u = 0; u < inString.size(); u++) {
            if (toupper(inString.at(u)) == alphabet.at(index)) {
                numTimes++;
            }
        }
        numTimesCharAppears.push_back(numTimes);
    }
    printLetterCounts(numTimesCharAppears);
    return numTimesCharAppears;
}

// Print character count
void printLetterCounts(vector<int> letterCount) {
    cout << "Character Count:" << endl;
    cout << "----------------" << endl;

    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    const int SET_WIDTH = 3;

    //Constants for ANSII colouring
    const int COLOUR_BLUE = 3;
    const int COLOUR_CYAN = 6;
    const int COLOUR_BOLD_CYAN = 10;
    const int COLOUR_BOLD_YELLOW = 11;

    // Print the letters
    for (int i = 0; i < alphabet.size(); i++) {
        cout << setw(SET_WIDTH) << alphabet.at(i);
    }
    cout << endl;

    // Print the number of times each letter shows up with colour
    for (int i = 0; i < alphabet.size(); i++) {
        if (letterCount.at(i) <= COLOUR_BLUE) {
            cout << ANSII_BLUE << setw(SET_WIDTH) << letterCount.at(i) << ANSII_NORMAL;
        } else if (letterCount.at(i) <= COLOUR_CYAN) {
            cout << ANSII_CYAN << setw(SET_WIDTH) << letterCount.at(i) << ANSII_NORMAL;
        } else if (letterCount.at(i) <= COLOUR_BOLD_CYAN) {
            cout << ANSII_CYAN << ANSII_BOLD << setw(SET_WIDTH) << letterCount.at(i) << ANSII_NORMAL;
        } else if (letterCount.at(i) >= COLOUR_BOLD_YELLOW) {
            cout << ANSII_YELLOW << ANSII_BOLD << setw(SET_WIDTH) << letterCount.at(i) << ANSII_NORMAL;
        }
    }
}
