// Player.h

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

#ifndef A5_PLAYER_H
#define A5_PLAYER_H

class Player {
public:
    // Virtual destructor
    virtual ~Player() {}

    // Virtual move function
    virtual bool possibleMove(Board board) = 0;

};

#endif //A5_PLAYER_H
