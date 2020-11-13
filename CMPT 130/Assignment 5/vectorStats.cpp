#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Read the floats that the user enters and store them into vectorOfFloats
vector<float> readVectorOfFloats() {
    vector<float> vectorOfFloats;

    // Sentinel - the number the user enters for the program to stop asking for input
    const int SENTINEL = 0;
    for (int i = 0;; i++) {
        float number = 0;
        if (i == 0) {
            cout << "Enter value (0 to end): ";
        }
        cin >> number;

        if (number == SENTINEL) {
            break;
        }
        vectorOfFloats.push_back(number);
    }
    return vectorOfFloats;
}

// Display numbers
void displayNumbers(vector<float> vectorOfFloats) {
    for (int i = 0; i < vectorOfFloats.size(); i++) {

        // Print out a new row after the eighth number
        const int NEW_ROW = 8;
        if ((i % NEW_ROW) == 0) {
            // Print out two tabs every new line
            cout << endl << "\t\t";
        }
        // Set the amount of decimal points to 2
        const int SET_PRECISION_DECIMAL_TO = 2;
        const int SET_WIDTH_VALUES = 7;
        cout << fixed << setprecision(SET_PRECISION_DECIMAL_TO) << setw(SET_WIDTH_VALUES) << vectorOfFloats.at(i);

        // Do not print comma after the last number
        if (i != vectorOfFloats.size() - 1) {
            cout << ",";
        }
    }
}

// Detect order of vector of floats
bool isAscending(vector<float> vectorOfFloats) {
    int currentFloatIndex = 0;
    if (vectorOfFloats.size() == 0){
        return true;
    }
    for (int i = 1; i < vectorOfFloats.size(); i++) {
        if (vectorOfFloats.at(i) > vectorOfFloats.at(currentFloatIndex)) {
            currentFloatIndex = i;
        } else {
            return false;
        }
    }
    return true;
}

bool isDescending(vector<float> vectorOfFloats) {
    int currentFloatIndex = 0;
    if (vectorOfFloats.size() == 0){
        return true;
    }
    for (int i = 1; i < vectorOfFloats.size(); i++) {
        if (vectorOfFloats.at(i) < vectorOfFloats.at(currentFloatIndex)) {
            currentFloatIndex = i;
        } else {
            return false;
        }
    }
    return true;
}

// Calculate the average of all floats
double calcAverageOfFloats(vector<float> vectorOfFloats) {
    double sum = 0;
    if (vectorOfFloats.size() == 0){
        return 0;
    }
    for (int i = 0; i < vectorOfFloats.size(); i++) {
        sum = sum + vectorOfFloats.at(i);
    }
    return sum / vectorOfFloats.size();
}

// Find the minimum float in the vector
double findMinimumFloat(vector<float> vectorOfFloats) {
    double minimum = 0;
    if (vectorOfFloats.size() == 0){
        return 0;
    }
    for (int i = 1; i < vectorOfFloats.size(); i++) {
        if (vectorOfFloats.at(i) < vectorOfFloats.at(minimum)) {
            minimum = i;
        }
    }
    return vectorOfFloats.at(minimum);
}

// Find the maximum float in the vector
double findMaximumFloat(vector<float> vectorOfFloats) {
    double maximum = 0;
    if (vectorOfFloats.size() == 0){
        return 0;
    }
    for (int i = 1; i < vectorOfFloats.size(); i++) {
        if (vectorOfFloats.at(i) > vectorOfFloats.at(maximum)) {
            maximum = i;
        }
    }
    return vectorOfFloats.at(maximum);
}

// Count # of times a value appears
int calcNumTimesValueAppears(vector<float> vectorOfFloats, double value) {
    int numTimes = 0;
    for (int i = 0; i < vectorOfFloats.size(); i++) {
        if (vectorOfFloats.at(i) == value) {
            numTimes++;
        }
    }
    return numTimes;
}

// Find the value in the vector that appears the most times
double findMostCommonValue(vector<float> vectorOfFloats) {
    double mostCommonValueIndex = 0;
    for (double i = 0; i < vectorOfFloats.size(); i++) {
        // Check the number of times each value shows up in the vector
        int numTimes = calcNumTimesValueAppears(vectorOfFloats, vectorOfFloats.at(i));
        // If the number of times a value shows up is greater than the original most shown value, replace the most common value index with the new one
        if (numTimes > mostCommonValueIndex) {
            mostCommonValueIndex = i;
        }
    }
    if (vectorOfFloats.size() == 0) {
        return 0;
    }
    return vectorOfFloats.at(mostCommonValueIndex);
}

void removeDuplicatesFromVector(vector<float> &vectorOfFloats) {
    // Check the first value in the vector, then the second, third....
    for (int index = 0; index < vectorOfFloats.size(); index++) {
        for (int i = vectorOfFloats.size() - 1; i < vectorOfFloats.size(); i--) {
            //cout << vectorOfFloats.size() << endl;
            if (index == i) {
                // Do nothing if the index is the same as i
            }
                // Compare to see if any of the values in the vector are the same
            else if (vectorOfFloats.at(i) == vectorOfFloats.at(index)) {
                // If there is, remove them
                vectorOfFloats.erase(vectorOfFloats.begin() + i);
            }
        }
    }
}

// Display the functions and titles/user interface
void displayStatistics(vector<float> vectorOfFloats) {
    cout << endl << "***********************************" << endl;
    cout << "Analysis of the numbers :" << endl;
    cout << "***********************************" << endl;
    cout << endl;

    // Display the values
    cout << "Values: " << endl;
    cout << "------- ";

    displayNumbers(vectorOfFloats);

    cout << endl << endl;
    cout << "Statistics on those numbers: " << endl;
    cout << "---------------------------- " << endl;

    const int SET_WIDTH_CALCULATIONS = 9;
    const int SET_WIDTH_STATISTICS_DESCRIPTION = 20;
    const int SET_WIDTH_BOOL = 8;

    const int SET_PRECISION_DECIMALS = 2;

    // Print average, minimum and maximum of float
    cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Maximum: " << fixed << setprecision(SET_PRECISION_DECIMALS)
         << setw(SET_WIDTH_CALCULATIONS) << findMaximumFloat(vectorOfFloats) << endl;
    cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Minimum: " << fixed << setprecision(SET_PRECISION_DECIMALS)
         << setw(SET_WIDTH_CALCULATIONS) << findMinimumFloat(vectorOfFloats) << endl;
    cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Average: " << setw(SET_WIDTH_CALCULATIONS)
         << calcAverageOfFloats(vectorOfFloats) << endl;
    cout << endl;

    // Print whether the floats are ascending/descending
    if (isAscending(vectorOfFloats) == 1) {
        cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Is ascending: " << setw(SET_WIDTH_BOOL) << "Yes" << endl;
    } else {
        cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Is ascending: " << setw(SET_WIDTH_BOOL) << "No" << endl;
    }

    if (isDescending(vectorOfFloats) == 1) {
        cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Is descending: " << setw(SET_WIDTH_BOOL) << "Yes" << endl;
    } else {
        cout << setw(SET_WIDTH_STATISTICS_DESCRIPTION) << "Is descending: " << setw(SET_WIDTH_BOOL) << "No" << endl;
    }
    cout << endl;

    cout << "Data with duplicates remove: " << endl;
    cout << "---------------------------- " << endl;

    // Make copy of original vector
    vector<float> copyVectorOfFloats = vectorOfFloats;

    // Remove the duplicates inside of the copied version of the original vector
    removeDuplicatesFromVector(copyVectorOfFloats);

    // Prints the values without duplicates
    displayNumbers(copyVectorOfFloats);
    cout << endl << endl;

    cout << "Repetition counts in user data: " << endl;
    cout << "------------------------------- " << endl;

    // Print the most common value to the screen
    cout << "\tMost common value is " << findMostCommonValue(vectorOfFloats) << "!" << endl;
    cout << endl;

    // Print to the screen the number of times a value appears
    const int SET_WIDTH_VALUES = 9;
    const int SET_WIDTH_NUM_TIMES = 3;

    for (int i = 0; i < copyVectorOfFloats.size(); i++) {
        cout << "\tThe value " << setw(SET_WIDTH_VALUES) << copyVectorOfFloats.at(i) << " occurs "
             << setw(SET_WIDTH_NUM_TIMES)
             << calcNumTimesValueAppears(vectorOfFloats, copyVectorOfFloats.at(i)) << " time(s). " << endl;
    }
}

int main() {
    // Read in the values:
    vector<float> userNumbers = readVectorOfFloats();

    // Display the output
    displayStatistics(userNumbers);

    return 0;
}