// main.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Alan Ou
// St.# : 301320642
// Email: alano@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

// Check if answer recieved from end of game is valid
bool checkValidAns(string &yOrN) {
    if (yOrN == "y" || yOrN == "Y") {
        return true;
    } else if (yOrN == "n" || yOrN == "N") {
        return false;
    } else {
        cout << endl << "INVALID RESPONSE: please re-enter. If yes, type \'y\', or if you want to quit type \'n\': ";
        cin >> yOrN;
        checkValidAns(yOrN);
    }
    return false;
}

int main() {

    // Run game if true
    bool play = true;

    while (play) {

        const int LINE_WORDS = 12;

        cout << "Reversi - The Simple Version" << endl;
        cout << "Enter a coordinate, for example \"2a\" to add a piece to the board" << endl;
        cout << "You are the X\'s" << endl << endl;

        // Create board
        Board board(8, 8);
        HumanPlayer humanPlayer;
        ComputerPlayer computer;
        board.print();

        // To figure out turn
        int moveNum = 0;

        // Game loop until no possible moves for both players
        while (computer.possibleMove(board) || humanPlayer.possibleMove(board)) {
            if (moveNum % 2 == 0) {
                if (humanPlayer.possibleMove(board)) {
                    // Player plays
                    humanPlayer.enterMove(board);
                    moveNum++;
                } else {
                    // If no moves are possible
                    cout << "You have no moves, your turn will be skipped" << endl << endl;
                    moveNum++;
                }

            } else {
                if (computer.possibleMove(board)) {
                    // Computer plays
                    computer.bestMove(board);
                    moveNum++;

                    int playerScore = board.playerScore();
                    int compScore = board.compScore();
                    cout << "SCORE SUMMARY" << endl << endl;
                    cout << setw(LINE_WORDS) << "COMPUTER: " << compScore << endl << setw(LINE_WORDS) << "PLAYER: "
                         << playerScore
                         << endl << endl;
                } else {
                    cout << "Computer has no moves, turn will be skipped" << endl << endl;
                    moveNum++;
                }

            }


        }

        cout << "No possible moves for either player" << endl
             << "GAME OVER" << endl << endl;

        // Calculate and print score
        int playerScore = board.playerScore();
        int compScore = board.compScore();
        cout << "SCORE SUMMARY" << endl << endl;
        cout << setw(LINE_WORDS) << "COMPUTER: " << compScore << endl << setw(LINE_WORDS) << "PLAYER: " << playerScore
             << endl << endl;

        // Checks and print the winner or tie
        if (compScore > playerScore) {
            cout << "COMPUTER WINS" << endl << endl;
        } else if (compScore == playerScore) {
            cout << "IT\'S A TIE" << endl << endl;
        } else {
            cout << "YOU WIN" << endl << endl;
        }

        // Determine if game should repeat or not
        string playOrNot;

        cout << "Do you want to play again? If yes, type \'y\', or if you want to quit type \'n\' ";
        cin >> playOrNot;

        if (checkValidAns(playOrNot) == true) {
            play = true;
            cout << endl << endl;
        } else if (checkValidAns(playOrNot) == false) {
            play = false;
            return 0;
        }

    }
}