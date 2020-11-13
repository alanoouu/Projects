#include <iostream>
#include <iomanip>
using namespace std;
#include "ansiicodes.h"
#include <cstdlib>
#include <ctime>

// Display a welcome message to the screen
void displayWelcome() {
    cout << ANSII_CYAN << ANSII_BOLD << "********************************************\n";
    cout << "Welcome to Roller's Un-Random house of dice!\n";
    cout << "********************************************\n" << ANSII_NORMAL;
}

// Asks user for their first name
string getUserName(){
    string name;
    cout << "What is your first name? ";
    cin >> name;
    return name;
}

// Asks user to either pick a random game based on the time, or choose their own un-random game
void seedGame() {
    cout << "Would you like to pick an un-random game, or let the timer pick?";
    cout << endl;
    int pickOrRandom = 0;
    cout << "Enter " << ANSII_BLUE << "O" << ANSII_NORMAL << " for timer, or pick your own un-random game: ";
    cin >> pickOrRandom;

    if (pickOrRandom == 0){
        cout << "THE TIMER! A daring choice!\n";
        srand(time(nullptr));
    }else {
        cout << pickOrRandom << "! A wise and safe choice.\n";
        srand(pickOrRandom);
    }
    cout << endl;
}

// Declare the the max number the dice can have
const int MAX_ROLL = 6;

// Generates a random number
int getRandomRoll() {
    int randomValue = rand();
    randomValue %= MAX_ROLL;
    randomValue ++;
    return randomValue;
}

// Asks the user for a maximum bet that is greater than or equal to 1
int getMaxBet(){
    int maxBet = 0;
    cout << "What would you like to be the maximum bet? :";
    cin >> maxBet;
    while (maxBet <= 0){
        cout << ANSII_RED << "The maximum bet must be greater than or equal to 1." << ANSII_NORMAL << endl;
        cout << "What would you like to be the maximum bet? :";
        cin >> maxBet;
    }
    return maxBet;
}

// Declares the minimum bet one can enter
const int MINIMUM_BET = 1;

// Asks the user to input their bet that is at least 1, less than the maximum bet, and less than their current score
int getUserBet(int currentScore, int maxBet){
    int userBet = 0;
    cout << "Enter your bet: ";
    cin >> userBet;
    while (userBet < MINIMUM_BET || (userBet > maxBet && userBet < currentScore) || userBet > currentScore){
        if (userBet < MINIMUM_BET) {
            cout << ANSII_RED << "Your bet must be at least 1." << ANSII_NORMAL << endl;
            cout << "Enter your bet: ";
            cin >> userBet;
        } else if (userBet > maxBet && userBet < currentScore) {
            cout << ANSII_RED << "Your bet must not be more than the maximum bet (" << maxBet << ")." << ANSII_NORMAL << endl;
            cout << "Enter your bet: ";
            cin >> userBet;
        } else if (userBet > currentScore) {
            cout << ANSII_RED << "Your bet must not be more than your score (" << currentScore << ")." << ANSII_NORMAL << endl;
            cout << "Enter your bet: ";
            cin >> userBet;
        }
    }
    return userBet;
}

// Declares the constant for the width of the getUserBet() function
const int BET_WIDTH = 33;
const int ROLL_WIDTH = 1;
const int SCORE_WIDTH = 2;

int main(){
    const int MAX_SCORE = 100;
    const int MIN_SCORE = 0;

    // Displays welcome, asks for the user to input a name and the type of seed for their random game
    displayWelcome();
    string name = getUserName();
    seedGame();

    int roundNumber = 1;
    int currentScore = 50;

    // Asks for a maximum bet and stores the value in an int
    int maxBet = getMaxBet();

    // Roll dice for each round and checks if sum of player's rolls are greater, less than, or equal to the
    // dealer's rolls; continues until the user either gets over 100 points or loses all points
    while (currentScore > MIN_SCORE && currentScore < MAX_SCORE) {
        // Call the getRandomRoll() and adds up the sums of the 2 numbers
        int num1 = getRandomRoll();
        int num2 = getRandomRoll();
        int dealerSum = num1 + num2;

        int num3 = getRandomRoll();
        int num4 = getRandomRoll();
        int playerSum = num3 + num4;

        // prints the round number and rolls
        cout << endl << "Round " << ANSII_CYAN << roundNumber << ANSII_NORMAL << " You have " << ANSII_MAGENTA << currentScore << ANSII_NORMAL << " points." << endl;
        cout << "Dealer rolls: " << ANSII_BLUE << setw(ROLL_WIDTH) << num1 << " + " << num2 << ANSII_NORMAL << " = " << ANSII_MAGENTA << dealerSum << ANSII_NORMAL << setw(BET_WIDTH);

        // Asks the user for a bet
        int userBet = getUserBet(currentScore , maxBet);

        cout << "You roll:     " << ANSII_BLUE << setw(ROLL_WIDTH) << num3 << " + " << num4 << ANSII_NORMAL << " = " << ANSII_MAGENTA << playerSum << ANSII_NORMAL << "." << endl;

        // checks through the conditions and prints out the corresponding message; changes points according to win/tie/lose
        if (playerSum > dealerSum){
            cout << ANSII_GREEN << name << ", you won! :-)" << ANSII_NORMAL << endl;
            currentScore = currentScore + userBet;
        }else if (playerSum == dealerSum){
            cout << ANSII_BLUE << name << ", you tied." << ANSII_NORMAL << endl;
        }else {
            cout << ANSII_RED << name << ", you lost. :-(" << ANSII_NORMAL << endl;
            currentScore = currentScore - userBet;
        }

        // prints current score after calculations
        cout << "Current score: " << ANSII_YELLOW << setw(SCORE_WIDTH) << currentScore << ANSII_NORMAL << "." << endl;
        roundNumber ++;
   }

    // Prints end of game statement depending on score
    if (currentScore <= MIN_SCORE){
        cout << ANSII_RED << ANSII_BOLD << "I'm sorry, " << name << "; you are out of points so you lose." << ANSII_NORMAL << endl;
    }else if (currentScore >= MAX_SCORE) {
        cout << ANSII_GREEN << ANSII_BOLD << "Congratulations " << name << "! You win the game with a score of " << currentScore << "." << ANSII_NORMAL << endl;
    }
    return 0;
}