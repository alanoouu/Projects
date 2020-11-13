#include <iostream>
#include <iomanip>
#include "ansiicodes.h";

using namespace std;

int main() {
    // Prints title
    cout << "Battery Voltage to State Of Charge (SoC) Generator" << endl;
    cout << ANSII_BOLD << "--------------------------------------------------" << ANSII_NORMAL << endl;

    // Asks for the minimum voltage
    int minimumVoltage = 0;
    cout << "Enter minimum voltages to show in table [mV]: ";
    cin >> minimumVoltage;

    // Asks for the maximum voltage
    int maximumVoltage = 0;
    cout << "Enter maximum voltages to show in table [mV]: ";
    cin >> maximumVoltage;

    // Asks for the step size
    int voltageStepSize = 0;
    cout << "Enter voltage step size [mV]: ";
    cin >> voltageStepSize;
    cout << endl;

    // Declares the constants for setw()
    const int SET_WIDTH_COLUMN_1 = 8;
    const int SET_WIDTH_COLUMN_2 = 6;
    const int SET_WIDTH_COLUMN_3 = 2;

    // Prints out headings
    cout << ANSII_BOLD << setw(SET_WIDTH_COLUMN_1) << "   Voltage"
         << setw(SET_WIDTH_COLUMN_2) << "    SoC"
         << setw(SET_WIDTH_COLUMN_3) << " Description" << ANSII_NORMAL << endl;
    cout << ANSII_BOLD << setw(SET_WIDTH_COLUMN_1) << "   -------"
         << setw(SET_WIDTH_COLUMN_2) << "  -----"
         << setw(SET_WIDTH_COLUMN_3) << " -----------" << ANSII_NORMAL << endl;

    // Declares the constants for a empty battery, how much it takes for the battery to reach full charge, and the percentage at full charge
    const int EMPTY_CELL = 3000;
    const int EMPTY_TO_FULL = 1200;
    const int TO_PERCENT = 100;

    // Declares the pecentage where the battery is over/under charged
    const int SOC_OVER = 100;
    const int SOC_UNDER = 0;

    // Formula to calculate the percentage of battery
    int SoC = (minimumVoltage - EMPTY_CELL) * TO_PERCENT / EMPTY_TO_FULL;

    int minimumIncrease = minimumVoltage;

    // Declares the percentages
    const int EMPTY_PERCENTAGE = 0;
    const int FIFTEEN_PERCENT = 15;
    const int THIRTY_FIVE_PERCENT = 35;
    const int NINTY_FIVE_PERCENTAGE = 95;
    const int FULL_PERCENTAGE = 100;

    // While the condition is true, the following statements check what the percentage is and prins out the corresponding voltage, SoC, and the description
    while (maximumVoltage >= minimumVoltage) {
        if (SoC < EMPTY_PERCENTAGE){
            cout << ANSII_RED << ANSII_BOLD << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SOC_UNDER << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "Too low!" << ANSII_NORMAL << endl;
            minimumVoltage += voltageStepSize;
        }else if (SoC < FIFTEEN_PERCENT) {
            cout << ANSII_RED << ANSII_BOLD << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SoC << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "Too low!" << ANSII_NORMAL << endl;
            minimumVoltage += voltageStepSize;
        }else if (SoC >= FIFTEEN_PERCENT and SoC < THIRTY_FIVE_PERCENT){
            cout << ANSII_BLUE << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SoC << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "Low" << ANSII_NORMAL << endl;
            minimumVoltage += voltageStepSize;
        }else if (SoC >= THIRTY_FIVE_PERCENT and SoC < NINTY_FIVE_PERCENTAGE) {
            cout << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SoC << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "OK\n";
            minimumVoltage += voltageStepSize;
        }else if (SoC >= NINTY_FIVE_PERCENTAGE and SoC <= FULL_PERCENTAGE){
            cout << ANSII_GREEN << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SoC << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "Full" << ANSII_NORMAL << endl;
            minimumVoltage += voltageStepSize;
        }else if (SoC > FULL_PERCENTAGE){
            cout << ANSII_RED << ANSII_BOLD << setw(SET_WIDTH_COLUMN_1) << minimumVoltage << "mV" << setw(SET_WIDTH_COLUMN_2) << SOC_OVER << "%" << " "
                 << setw(SET_WIDTH_COLUMN_3) << "CAUTION: OVERCHARGED!" << ANSII_NORMAL << endl;
            minimumVoltage += voltageStepSize;
        }
        minimumIncrease += voltageStepSize;
        SoC = (minimumVoltage - EMPTY_CELL) * TO_PERCENT / EMPTY_TO_FULL;
    }

    return 0;
}