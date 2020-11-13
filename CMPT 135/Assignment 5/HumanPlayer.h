// HumanPlayer.h

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

#ifndef A5_HUMANPLAYER_H
#define A5_HUMANPLAYER_H

#include <iostream>
#include "Player.h"
#include "Board.h"

using namespace std;

class HumanPlayer : public Player {
    int moveRow;
    int moveCol;

public:

    const int CHANGE_TO_NUM_ROW = 49;
    const int CHANGE_TO_NUM_COL = 97;

    // Change entered coordinate to row and column
    void changeToCoordinate(string move) {
        moveRow = move.at(0) - CHANGE_TO_NUM_ROW;
        moveCol = move.at(1) - CHANGE_TO_NUM_COL;
    }

    // Check if entered coordinate is valid
    bool checkValid(int row, int col, Board board) {
        // Check around the empty square
        for (int rowAround = -1; rowAround <= 1; rowAround++) {
            for (int colAround = -1; colAround <= 1; colAround++) {

                // Ensure in board bounds
                if (!board.outOfBoard(row + rowAround, col + colAround) && !(rowAround == 0 && colAround == 0)) {

                    //Check around the current space for a computer
                    if (board.board[row + rowAround][col + colAround] == Tile::computer) {
                        // If found, move towards computer
                        int moveRow = row + rowAround;
                        int moveCol = col + colAround;

                        for (;;) {
                            // keep moving towards computer
                            moveRow = moveRow + rowAround;
                            moveCol = moveCol + colAround;

                            // If moved out of board or if next tile is empty, stop
                            if (board.outOfBoard(moveRow, moveCol) || board.board[moveRow][moveCol] == Tile::empty) {
                                break;
                            }

                            // If player is found, then it is a valid move
                            if (board.board[moveRow][moveCol] == Tile::player) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isEmpty (int row, int col, Board &board) {
        if (board.get(row, col) == Tile::empty){
            return true;
        }
        return false;
    }

    void swap(int moveRow, int moveCol, int row, int col, int rowAround, int colAround, Board &board){
        board.board[row][col] = Tile::player;
        while (board.board[moveRow -= rowAround][moveCol -= colAround] == Tile::computer) {
            board.set(moveRow, moveCol, Tile::player);
        }
    }

    // Move and replace the pieces
    void movePiece(int row, int col, Board &board) {
        // Check spaces around the player
        for (int rowAround = -1; rowAround <= 1; rowAround++) {
            for (int colAround = -1; colAround <= 1; colAround++) {

                // Keeping the checking within the board and not checking on the spot itself
                if (!board.outOfBoard(row + rowAround, col + colAround) && !(rowAround == 0 && colAround == 0)) {

                    //Check around the current space for a opponent
                    if (board.board[row + rowAround][col + colAround] == Tile::computer) {
                        // If found, move towards opponent
                        int moveRow = row + rowAround;
                        int moveCol = col + colAround;

                        for (;;) {
                            // keep moving towards opponent
                            moveRow = moveRow + rowAround;
                            moveCol = moveCol + colAround;

                            // If moved out of board or if next tile is empty, stop
                            if (board.outOfBoard(moveRow, moveCol) || board.board[moveRow][moveCol] == Tile::empty) {
                                break;
                            }

                            // If current player is found, then swap all opponent pieces to current player
                            if (board.board[moveRow][moveCol] == Tile::player) {
                                swap (moveRow, moveCol, row, col, rowAround, colAround, board);
                                break;
                            }
                        }
                    }
                }
            }
        }
        board.print();
    }

    // Check if any possible moves are left
    bool possibleMove(Board board) {
        for (int row = 0; row < board.height(); row++) {
            for (int col = 0; col < board.width(); col++) {

                // Check if the spot is a empty spot
                if (board.board[row][col] == Tile::empty) {

                    // Check around the empty square
                    for (int rowAround = -1; rowAround <= 1; rowAround++) {
                        for (int colAround = -1; colAround <= 1; colAround++) {

                            if (!board.outOfBoard(row + rowAround, col + colAround) && !(rowAround == 0 && colAround == 0)) {

                                //Check around the current space for a opponent
                                if (board.board[row + rowAround][col + colAround] == Tile::computer) {
                                    // If found, move towards opponent
                                    int moveRow = row + rowAround;
                                    int moveCol = col + colAround;

                                    for (;;) {
                                        // keep moving towards opponent
                                        moveRow = moveRow + rowAround;
                                        moveCol = moveCol + colAround;

                                        // If moved out of board or if next tile is empty, stop
                                        if (board.outOfBoard(moveRow, moveCol) || board.board[moveRow][moveCol] == Tile::empty) {
                                            break;
                                        }

                                        // If current player is found
                                        if (board.board[moveRow][moveCol] == Tile::player) {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    // Ask for move
    void enterMove(Board &board) {

        string move;
        cout << "Enter a coordinate (Case Sensitive): ";
        cin >> move;
        cout << endl;

        // Checks if the coordinate is valid
        if (move.size() == 2) {
        changeToCoordinate(move);

            if (checkValid(moveRow, moveCol, board) && isEmpty(moveRow, moveCol, board)) {
                movePiece(moveRow, moveCol, board);
            } else {
                cout << "Please enter a valid coordinate" << endl << endl;
                enterMove(board);
            }

        } else {
            cout << "Please enter a valid coordinate" << endl << endl;
            enterMove(board);
        }
    }
};


#endif //A5_HUMANPLAYER_H