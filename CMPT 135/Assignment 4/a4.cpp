// a4.cpp

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
#include "MC.h"
#include "TrueFalse.h"
#include "IntegerQ.h"
#include "Question.h"

using namespace std;
using namespace alano;

int main() {

    cout << "***************"
         << "   Quiz Time   "
         << "***************";
    cout << endl << endl;
    cout << "True or False: Type t for true or f for false (CASE SENSITIVE)" << endl << endl;

    // Stores the answer
    string ans;

    // Keep track of score
    int score = 0;

    // Count the correct number of questions
    int correctQ = 0;

    // the number of marks, the statement, and the answer
    TrueFalse tf1{1, "Humans cannot breathe and swallow at the same time ", "t"};
    tf1.print_all();
    cin >> ans;

    // if answer is correct, increase score by 1
    if (tf1.checkAns(ans)) {
        score += tf1.out_of();
        correctQ++;
    }

    TrueFalse tf2{1, "There are nearly 300 different flavors of Kit Kat in Japan ", "t"};
    tf2.print_all();
    cin >> ans;

    if (tf2.checkAns(ans)) {
        score += tf2.out_of();
        correctQ++;
    }

    TrueFalse tf3{1, "C++ was created by Guido van Rossum ", "f"};
    tf3.print_all();
    cin >> ans;

    if (tf3.checkAns(ans)) {
        score += tf3.out_of();
        correctQ++;
    }

    TrueFalse tf4{1, "La La Land was the Best Picture winner at the 2017 Oscars ", "f"};
    tf4.print_all();
    cin >> ans;

    if (tf4.checkAns(ans)) {
        score += tf4.out_of();
        correctQ++;
    }

    cout << endl << "Integer Questions: Enter a number (INTEGERS ONLY)" << endl << endl;

    // the number of marks, the statement, and the answer
    IntegerQ iq1{2,
                 "In what year did Walt Disney Studios released its first fully animated feature film, Snow White and the Seven Dwarfs? ",
                 "1937"};
    iq1.print_all();
    cin >> ans;

    if (iq1.checkAns(ans)) {
        score += iq1.out_of();
        correctQ++;
    }

    IntegerQ iq2{2, "In the Chinese culture, what number is considered to be terribly unlucky? ", "4"};
    iq2.print_all();
    cin >> ans;

    if (iq2.checkAns(ans)) {
        score += iq2.out_of();
        correctQ++;
    }

    IntegerQ iq3{2, "How many chromosomes do people have? ", "46"};
    iq3.print_all();
    cin >> ans;

    if (iq3.checkAns(ans)) {
        score += iq3.out_of();
        correctQ++;
    }

    cout << endl << "Multiple Choice: Choose from a,b,c,d (CASE SENSITIVE)" << endl << endl;

    // The choices for multiple choice
    vector<string> q1 = {"Ikura Gunkan", "Sake Nigiri", "Kappa Maki", "Beni shouga"};

    // the number of marks, the statement, the choice set, and the answer
    MC mc1{1, "Which of the following is NOT a type of sushi?", q1, "d"};

    mc1.print_all();
    cin >> ans;

    if (mc1.checkAns(ans)) {
        score += mc1.out_of();
        correctQ++;
    }

    vector<string> q2 = {"Frozen", "Snow White and the Seven Dwarfs", "Tinker Bell: Secret of the Wings",
                         "The Search for Santa Paws"};
    MC mc2{1, "In what movie is the character Olaf from? ", q2, "a"};
    mc2.print_all();
    cin >> ans;

    if (mc2.checkAns(ans)) {
        score += mc2.out_of();
        correctQ++;
    }


    vector<string> q3 = {"1973", "1976", "1978", "1979"};
    MC mc3{1, "In what year was the SFU School of Criminology founded? ", q3, "a"};
    mc3.print_all();
    cin >> ans;

    if (mc3.checkAns(ans)) {
        score += mc3.out_of();
        correctQ++;
    }

    const int NUM_QUESTIONS = 10;

    cout << "Your results: " << endl << endl <<
         setw(15) << "CORRECT: " << correctQ << endl << setw(15) << "INCORRECT: " << NUM_QUESTIONS - correctQ << endl
         << endl;
    cout << "Your final score is " << score << "!" << endl;

    return 0;
};

