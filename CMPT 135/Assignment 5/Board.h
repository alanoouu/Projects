// Board.h

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

#ifndef A5_BOARD_H
#define A5_BOARD_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Class idea from
//http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
//
enum class Tile : char {
    computer = 'O',
    player = 'X',
    empty = '.'
};

class Board {
public:
    vector<vector<Tile>> board;

    // Board constructor
    Board(int w, int h)
            : board(h) {

        // Method idea from
        // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
        //
        // Set all tiles to empty '.'
        for (int i = 0; i < board.size(); i++) {
            board[i] = vector<Tile>(w, Tile::empty);
        }

        fill_board();
    }

    // Method idea from
    // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
    //
    // get width
    unsigned long width() const {
        return board[0].size();
    }

    // Method idea from
    // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
    //
    // get height
    unsigned long height() const {
        return board.size();
    }

    // Method idea from
    // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
    //
    // set the location at board[r][c] to be t
    void set(int r, int c, const Tile &t) {
        board[r][c] = t;
    }

    // Method idea from
    // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
    //
    // return the value at row r, column c
    Tile get(int r, int c) const {
        return board[r][c];
    }

    // Constant to space out board
    const int SET_SPACING = 2;

    // Method idea from
    // http://www.cs.sfu.ca/CourseCentral/135/tjd/maze.html
    //
    // print the board to the screen
    void print() const {

        // Display top coordinates
        cout << " ";
        for (int k = 0; k < width(); k++) {
            cout << setw(3) << char('a' + k);
        }
        cout << endl;

        for (int i = 0; i < height(); ++i) {
            // Display left Coordinates
            cout << char(i + '0' + 1) << " ";
            // Print board
            for (int j = 0; j < width(); ++j) {
                cout << setw(SET_SPACING) << char(board[i][j]) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void fill_board() {

        board[3][3] = Tile::player;
        board[3][4] = Tile::computer;
        board[4][3] = Tile::computer;
        board[4][4] = Tile::player;

    }

    // Check the number of pieces the player has
    int playerScore() {
        int playerScore = 0;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (get(row, col) == Tile::player) {
                    playerScore++;
                }
            }
        }
        return playerScore;
    }

    // Check the number of pieces the computer has
    int compScore() {
        int compScore = 0;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (get(row, col) == Tile::computer) {
                    compScore++;
                }
            }
        }
        return compScore;
    }

    // Check for out of bounds
    bool outOfBoard(int row, int col) {
        if (row < 0 || row >= height() || col < 0 ||
            col >= width()) {
            return true;
        } else {
            return false;
        }
    }

};

#endif //A5_BOARD_H
