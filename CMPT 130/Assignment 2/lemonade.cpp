#include <iostream>
#include <iomanip>
#include "ansiicodes.h"
using namespace std;

int main() {
    // displays the menu
    cout << ANSII_RED << "Menu: \n"
            "*******************\n" << ANSII_NORMAL <<
            "New-age lemonade sizes:\n"
            "  Small:  $1\n"
            "  Medium: $2\n"
            "  Large:  $8\n\n" ;

    // asks user for input
    int smallSize = 0;
    int mediumSize = 0;
    int largeSize = 0;
    cout << "Enter number of drinks purchased...\n";
    cout << "   # Small:  ";
    cin >> smallSize;
    cout << "   # Medium: ";
    cin >> mediumSize;
    cout << "   # Large:  ";
    cin >> largeSize;
    cout << endl;

    // declares the cost of each size
    const int SMALL_SIZE_COST = 1;
    const int MEDIUM_SIZE_COST = 2;
    const int LARGE_SIZE_COST = 8;

    // reprints the number of orders and costs
    const int SET_WIDTH_ORDER_SUMMARY = 3;
    cout << "Your order is: \n";
    cout << "   Small:  " << setw(SET_WIDTH_ORDER_SUMMARY) << smallSize << " @ $" << ANSII_MAGENTA << SMALL_SIZE_COST << ANSII_NORMAL << " each" << endl;
    cout << "   Medium: " << setw(SET_WIDTH_ORDER_SUMMARY) << mediumSize << " @ $" << ANSII_MAGENTA << MEDIUM_SIZE_COST << ANSII_NORMAL << " each" << endl;
    cout << "   Large:  " << setw(SET_WIDTH_ORDER_SUMMARY) << largeSize << " @ $" << ANSII_MAGENTA << LARGE_SIZE_COST << ANSII_NORMAL << " each" << endl << endl;

    // declares the constants for a dollar in cents
    const int HUNDRED_CENTS = 100;

    // calculates the total cost and changes the price into cents
    int price = ((smallSize * SMALL_SIZE_COST) + (mediumSize * MEDIUM_SIZE_COST) + (largeSize * LARGE_SIZE_COST)) * HUNDRED_CENTS;
    // calculates subtotal
    int subtotalDollars = price / HUNDRED_CENTS;
    int subtotalCents = price % HUNDRED_CENTS;
    // calculates the tax
    const int TAX = 12;
    int dollarsWithTax = (subtotalDollars * TAX) / HUNDRED_CENTS;
    int centsWithTax = (subtotalDollars * TAX) % HUNDRED_CENTS;

    cout << "Amount owing: \n";

    // prints out the calculated amounts
    const int SET_WIDTH_COLUMN_DOLLAR = 3;
    const int SET_WIDTH_COLUMN_CENTS = 2;
    cout << "   Subtotal: " << setw(SET_WIDTH_COLUMN_DOLLAR) << ANSII_BLUE << subtotalDollars << "." << setfill('0') << setw(SET_WIDTH_COLUMN_CENTS) << subtotalCents << ANSII_NORMAL << setfill(' ') << endl;
    cout << "   Tax:      " << setw(SET_WIDTH_COLUMN_DOLLAR) << ANSII_BLUE << dollarsWithTax << "." << setfill('0') << setw(SET_WIDTH_COLUMN_CENTS) << centsWithTax << ANSII_NORMAL << setfill(' ') << endl;
    cout << "   Total:    " << setw(SET_WIDTH_COLUMN_DOLLAR) << ANSII_BLUE << dollarsWithTax + subtotalDollars << "." << setfill('0') << setw(SET_WIDTH_COLUMN_CENTS) << subtotalCents + centsWithTax << ANSII_NORMAL << setfill(' ') << endl;

    return 0;
}