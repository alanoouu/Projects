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
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "cmpt_error.h"

using namespace std;

// Movie class
class Movies {
public:
    string movieName;
    string movieMPAA;
    string movieRating;
    double avgMovieRating;

// Sort the movies according to their averages
// Function idea by Shruthi Mohan
    bool operator()(Movies a, Movies b) {
        return (a.avgMovieRating > b.avgMovieRating);
    }

} movie;

// Read in movie data from file and calculate the average, then put into vector
void readCalcMovieData(ifstream &file, vector<Movies> &movies) {
    Movies movie;

    // Read in from file
    while (file >> movie.movieName) {
        file >> movie.movieMPAA;
        file >> movie.movieRating;

        double sum = 0;
        double counter = 0;

        // Calculate average movie rating
        for (int i = 0; i < movie.movieRating.size(); i++) {
            if ((movie.movieRating.at(i) == '1') || (movie.movieRating.at(i) == '2') ||
                (movie.movieRating.at(i) == '3') || (movie.movieRating.at(i) == '4') ||
                (movie.movieRating.at(i) == '5')) {
                sum = sum + movie.movieRating.at(i) - '0';
                counter = counter + 1;
                if (i == movie.movieRating.size() - 1) {
                    movie.avgMovieRating = (sum / counter);

                }
            }
                // The special case where there is no correct rating entry
            else {
                if (counter == 0 && i == movie.movieRating.size() - 1){
                    movie.avgMovieRating = 0;
                }
            }
        }

        // Get rid of underscore from movie name
        for (int i = 0; i < movie.movieName.size(); i++) {
            string temp = movie.movieName;
            if (temp.at(i) == '_') {
                temp.at(i) = ' ';
            }
            movie.movieName = temp;
        }
        movies.push_back(movie);
    }
}

int main() {

    // Open file, check for errors
    ifstream movieData("movie_data.txt");
    if (movieData.fail()) {
        cmpt::error("Failed to open");
    }

    vector<Movies> movies;

    readCalcMovieData(movieData, movies);
    sort(movies.begin(), movies.end(), movie);

    // Print out the results
    cout << "-------------------------------------------------" << endl
         << "Top 3 Movies with the Highest Average User Rating" << endl
         << "-------------------------------------------------" << endl;

    const int SET_WIDTH = 17;
    const int SET_DECIMAL_POINTS = 3;

    cout << fixed << setprecision(SET_DECIMAL_POINTS);

    for (int i = 0; i < 3; i++) {
        cout << movies.at(i).movieName << ", Rated " << movies.at(i).movieMPAA << endl;
        cout << setw(SET_WIDTH) << "Average Score: " << movies.at(i).avgMovieRating << endl;
        cout << setw(SET_WIDTH) << "Terrible: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '1') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Bad: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '2') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Ok: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '3') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Good: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '4') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Great: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '5') {
                cout << "*";
            }
        }
        cout << endl << endl;
    }

    cout << "---------------------------------------------------" << endl
         << "Bottom 3 Movies with the Lowest Average User Rating" << endl
         << "---------------------------------------------------" << endl;

    const int FIRST_THREE = 3;

    for (int i = movies.size() - FIRST_THREE; i < movies.size(); i++) {
        cout << movies.at(i).movieName << ", Rated " << movies.at(i).movieMPAA << endl;
        cout << setw(SET_WIDTH) << "Average Score: " << movies.at(i).avgMovieRating << endl;
        cout << setw(SET_WIDTH) << "Terrible: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '1') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Bad: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '2') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Ok: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '3') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Good: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '4') {
                cout << "*";
            }
        }
        cout << endl << setw(SET_WIDTH) << "Great: ";
        for (int k = 0; k < movies.at(i).movieRating.size(); k++) {
            if (movies.at(i).movieRating.at(k) == '5') {
                cout << "*";
            }
        }
        cout << endl << endl;
    }

    return 0;
}