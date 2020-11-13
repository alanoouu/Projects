// TrueFalse.h

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
#include "Question.h"
#include <vector>

using namespace std;
using namespace a4;

namespace alano {
    class TrueFalse : public a4::Question {
    private:
        int mark;
        string statement;
        string answer;

    public:
        // default constructor
        TrueFalse()
                : mark(0), statement(""), answer("") {}

        // Fill constructor
        TrueFalse(int mark, string statement, string ans)
                : mark(mark), statement(statement), answer(ans) {
        }

        // Returns how many marks this question is out of.
        int out_of() const {
            return mark;
        }

        // Returns the questions "ask text".
        string ask_test() const {
            return statement;
        }

        // Prints the entire question
        void print_all() const {
            cout << "(" << out_of() << " mark(s)) " << ask_test();
        }

        // Checks if the answer is correct or not
        bool checkAns(string ans) {
            if (ans == answer) {
                cout << endl
                     << "CORRECT"
                     << endl << endl;
                return true;

                // Check if answer is valid
            } else if ((ans != "t") && (ans != "f")) {
                cout << endl
                     << "INCORRECT INPUT: RE-ENTER ";
                cin >> ans;
                checkAns(ans);
            } else {
                cout << endl
                     << "INCORRECT: CORRECT ANSWER IS \"" << answer << "\""
                     << endl << endl;
                return false;
            }
            return true;
        }
    };
}