// ComputerPlayer.h

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

#ifndef A5_COMPUTERPLAYER_H
#define A5_COMPUTERPLAYER_H

#include "Board.h"
#include "Player.h"
#include <vector>

class ComputerPlayer : public Player {
    int compRow;
    int compCol;

public:

    // Check if any possible moves are left
    bool possibleMove(Board board) {
        for (int row = 0; row < board.height(); row++) {
            for (int col = 0; col < board.width(); col++) {

                // Check if the spot is a empty spot
                if (board.board[row][col] == Tile::empty) {

                    // Check around the empty square
                    for (int rowAround = -1; rowAround <= 1; rowAround++) {
                        for (int colAround = -1; colAround <= 1; colAround++) {

                            // Check if out of bounds or if it is itself
                            if (!board.outOfBoard(row + rowAround, col + colAround) &&
                                !(rowAround == 0 && colAround == 0)) {

                                //Check around the current space for a player
                                if (board.board[row + rowAround][col + colAround] == Tile::player) {
                                    // If found, move towards player
                                    int moveRow = row + rowAround;
                                    int moveCol = col + colAround;

                                    for (;;) {
                                        // keep moving towards player
                                        moveRow = moveRow + rowAround;
                                        moveCol = moveCol + colAround;

                                        // If moved out of board or if next tile is empty, stop
                                        if (board.outOfBoard(moveRow, moveCol) ||
                                            board.board[moveRow][moveCol] == Tile::empty) {
                                            break;
                                        }

                                        // If computer is found
                                        if (board.board[moveRow][moveCol] == Tile::computer) {
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

    // Find the best move for the computer
    void bestMove(Board &board) {
        int highestScore = 0;

        for (int row = 0; row < board.height(); row++) {
            for (int col = 0; col < board.width(); col++) {

                // Check if the spot is a empty spot
                if (board.board[row][col] == Tile::empty) {

                    // Check around the empty square
                    for (int rowAround = -1; rowAround <= 1; rowAround++) {
                        for (int colAround = -1; colAround <= 1; colAround++) {

                            if (!board.outOfBoard(row + rowAround, col + colAround) &&
                                !(rowAround == 0 && colAround == 0)) {

                                //Check around the current space for a player
                                if (board.board[row + rowAround][col + colAround] == Tile::player) {
                                    // If found, move towards player
                                    int moveRow = row + rowAround;
                                    int moveCol = col + colAround;

                                    for (int i = 0;; i++) {
                                        // keep moving towards player
                                        moveRow = moveRow + rowAround;
                                        moveCol = moveCol + colAround;

                                        // If moved out of board or if next tile is empty, stop
                                        if (board.outOfBoard(moveRow, moveCol) ||
                                            board.board[moveRow][moveCol] == Tile::empty) {
                                            break;
                                        }

                                        // If computer is found, then it is a valid move
                                        if (board.board[moveRow][moveCol] == Tile::computer) {
                                            if (i >= highestScore) {
                                                compRow = row;
                                                compCol = col;
                                                highestScore = i;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        movePiece(board);
    }

    // Swap all pieces before
    void swap(int moveRow, int moveCol, int rowAround, int colAround, Board &board) {
        board.board[compRow][compCol] = Tile::computer;
        while (board.board[moveRow -= rowAround][moveCol -= colAround] == Tile::player) {
            board.board[moveRow][moveCol] = Tile::computer;
        }
    }

    // Add piece and change all player pieces in between
    void movePiece(Board &board) {
        // Check spaces around the player
        for (int rowAround = -1; rowAround <= 1; rowAround++) {
            for (int colAround = -1; colAround <= 1; colAround++) {

                // Keeping the checking within the board and not checking on the spot itself
                if (!board.outOfBoard(compRow + rowAround, compCol + colAround) &&
                    !(rowAround == 0 && colAround == 0)) {

                    //Check around the current space for a opponent
                    if (board.board[compRow + rowAround][compCol + colAround] == Tile::player) {
                        // If found, move towards opponent
                        int moveRow = compRow + rowAround;
                        int moveCol = compCol + colAround;

                        for (;;) {
                            // keep moving towards opponent
                            moveRow = moveRow + rowAround;
                            moveCol = moveCol + colAround;

                            // If moved out of board or if next tile is empty, stop
                            if (board.outOfBoard(moveRow, moveCol) || board.board[moveRow][moveCol] == Tile::empty) {
                                break;
                            }

                            // If current player is found, then swap all opponent pieces to current player
                            if (board.board[moveRow][moveCol] == Tile::computer) {
                                swap(moveRow, moveCol, rowAround, colAround, board);
                                break;
                            }
                        }
                    }
                }
            }
        }
        board.print();
    }
};

#endif //A5_COMPUTERPLAYER_H
