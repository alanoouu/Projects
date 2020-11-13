#include <iostream>
using namespace std;

int main() {
    // Asks user to input their age, habit and cost of the habit; and stores the values into their respective variables
    int age = 0;
    cout << "How old are you? ";
    cin >> age;

    string habit;
    cout << "What is your habit (one word)? ";
    cin >> habit;

    int habitCost = 0;
    cout << "How many $ per day does your habit cost? ";
    cin >> habitCost;

    cout << endl;

    const int DAYS_IN_A_YEAR = 365;
    const int PREDICTED_LIFE_EXPECTANCY = 90;
    const int MOVIE_TICKET_PRICE = 11;
    // calculate the cost of drinking coffee for 90 years
    int costOverTime = habitCost * DAYS_IN_A_YEAR * (PREDICTED_LIFE_EXPECTANCY - age);
    // prints out the calculated amounts
    cout << "This year your " << habit << " habit will cost you $" << habitCost * DAYS_IN_A_YEAR << "." << endl;
    cout << "Between now and when you are " << PREDICTED_LIFE_EXPECTANCY << ", it will cost you $" << costOverTime << "! " << endl;
    cout << "That's " << costOverTime / MOVIE_TICKET_PRICE << " \"free\" movies by when you are " << PREDICTED_LIFE_EXPECTANCY << "!" << endl;

    return 0;
}