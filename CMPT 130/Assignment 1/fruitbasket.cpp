#include <iostream>
#include "ansiicodes.h"
#include <iomanip>
using namespace std;

int main() {
    // Prints out the Welcome Title
    cout << ANSII_CYAN << ANSII_BOLD << "**************************" << ANSII_NORMAL << endl;
    cout << ANSII_CYAN << ANSII_BOLD << "Local Fruit Box Calculator" << ANSII_NORMAL << endl;
    cout << ANSII_CYAN << ANSII_BOLD << "**************************" << ANSII_NORMAL << endl << endl;

    // Declares the variables
    int numApples = 0;
    int numOranges = 0;
    int fruitPiecesPerBasket = 0;

    // Asks the user for an input and stores the value into their respective variables
    cout << "Enter the number of " << ANSII_MAGENTA << "apples donated: " << ANSII_NORMAL;
    cin >> numApples;
    cout << "Enter the number of " << ANSII_MAGENTA << "oranges donated: " << ANSII_NORMAL;
    cin >> numOranges;
    cout << "Enter the number of " << ANSII_MAGENTA << "fruit pieces per basket: " << ANSII_NORMAL;
    cin >> fruitPiecesPerBasket;
    cout << endl;

    // Prints out the values that the user inputted
    cout << ANSII_CYAN << ANSII_BOLD << "Input Values:" << ANSII_NORMAL << endl;
    cout << ANSII_CYAN << ANSII_BOLD << "-------------" << ANSII_NORMAL << endl;
    cout << "# Apples Donated:          " << ANSII_YELLOW << setw(4) << numApples << ANSII_NORMAL << endl;
    cout << "# Oranges Donated:         " << ANSII_YELLOW << setw(4) << numOranges << ANSII_NORMAL << endl;
    cout << "# Fruit Pieces per Basket: " << ANSII_YELLOW << setw(4) << fruitPiecesPerBasket << ANSII_NORMAL << endl << endl;

    // Declares the variable totalFruitBaskets and calculates the number of baskets the donated fruits can make
    int totalFruitBaskets = (numApples + numOranges) / fruitPiecesPerBasket;

    cout << ANSII_CYAN << ANSII_BOLD << "Basket Creation Numbers:" << ANSII_NORMAL << endl;
    cout << ANSII_CYAN << ANSII_BOLD << "-----------------------" << ANSII_NORMAL << endl;
    // Prints out the calculated amounts
    cout << "# Baskets to create:           " << ANSII_YELLOW << setw(4) << totalFruitBaskets << ANSII_NORMAL << endl;
    cout << "Min # apples per basket:       " << ANSII_YELLOW << setw(4) << numApples / totalFruitBaskets << ANSII_NORMAL << endl;
    cout << "Min # oranges per basket:      " << ANSII_YELLOW << setw(4) << numOranges / totalFruitBaskets << ANSII_NORMAL << endl;
    cout << "# Ribbons to tie baskets:      " << ANSII_YELLOW << setw(4) << totalFruitBaskets * 3 << ANSII_NORMAL << endl;
    cout << "# Pieces needed to complete one more basket:   " << ANSII_YELLOW << setw(4) << fruitPiecesPerBasket - (numApples + numOranges) % fruitPiecesPerBasket << ANSII_NORMAL;

    return 0;
}