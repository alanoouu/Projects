// a1.cpp

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

#include "a1.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;

// make an empty array
// Idea from http://www.cs.sfu.ca/CourseCentral/135/tjd/dynamic_array_functions_cpp.html
// By: Toby Donaldson
//
str_array make_empty(int cap = 10){
    str_array arr = str_array{new string[cap], 0, cap};
    return arr;
}

// Deallocate memory and set pointer to nullptr
void deallocate(str_array& arr) {
    delete[] arr.arr;
    arr.arr = nullptr;
}

// Return the percentage of the array used
double pct_used(const str_array& arr) {
    return static_cast<double>(arr.size) / arr.capacity;
}

// Convert arr's underlying array to a string
string to_str(const str_array& arr) {
    string all_strings = "{";
    for (int i = 0; i < arr.size; ++i) {
        if (i > 0) {
            all_strings += ", ";
        }
        all_strings += arr.arr[i];
    }
    all_strings += "}";
    return all_strings;
}

// prints to_str(arr)
void print(const str_array& arr) {
    string all_strings = to_str(arr);
    cout << all_strings;
}

//  prints to_str(arr) but also with a new line
void println(const str_array& arr) {
    print(arr);
    cout << "\n";
}

// Get string at location i in the array
string get(const str_array& arr, int i) {
    if (i < 0 || i >= arr.size) {
        cmpt::error("index out of bounds");
    }
    return arr.arr[i];
}

// Replace the string in the i'th space to the string s
void set(str_array& arr, int i, const string& s) {
    if (i < 0 || i >= arr.size) {
        cmpt::error("index out of bounds");
    }
    arr.arr[i] = s;
}

// Add a new element to the first unused spot to the right of arr, resizing if needed
// Function idea from http://www.cs.sfu.ca/CourseCentral/135/tjd/dynamic_array_functions_cpp.html
// By: Toby Donaldson
//
void append(str_array& arr, const string& s){
    if(arr.size >= arr.capacity){
        string* temp = new string[arr.capacity * 2];
        for(int i = 0; i < arr.size; i++){
            temp[i] = arr.arr[i];
        }
        delete[] arr.arr;

        arr.arr = temp;
        arr.capacity = arr.capacity * 2;
    }
    arr.arr[arr.size] = s;
    arr.size = arr.size + 1;
}

// Check if two strings are equal
bool operator==(str_array a, str_array b) {
    if (a.size == b.size) {
        for (int i = 0; i < a.size; i++) {
            if (a.arr[i] == b.arr[i]) {
                // Do nothing
            } else {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Set the size of the array to be 0
void clear(str_array& arr) {
    arr.size = 0;
}

// Add a new element to the first unused spot to the left of arr, resizing if needed
// Function idea from http://www.cs.sfu.ca/CourseCentral/135/tjd/dynamic_array_functions_cpp.html
// By: Toby Donaldson
// 
void prepend(str_array& arr, const string& s){
    string* temp = new string[2 * arr.capacity];
    if(arr.size >= arr.capacity){
        arr.capacity = 2 * arr.capacity;
    }

    for(int i = 1; i < arr.size + 1; i++){
        temp[i] = arr.arr[i - 1];
    }
    delete[] arr.arr;

    arr.arr = temp;
    arr.arr[0] = s;
    arr.size = arr.size + 1;
}

// make the size and capacity of arr the same
void shrink_to_fit(str_array& arr) {
    if (arr.size == arr.capacity) {
        // don't do anything
    } else {
        arr.capacity = arr.size;
        string *temp = new string[arr.size];
        for (int i = 0; i < arr.size; ++i) {
            temp[i] = arr.arr[i];
        }
        delete[] arr.arr;
        arr.arr = temp;
    }
}

int main() {
    cout << "Hello, world!\n" << endl;

    // FUNCTION TESTINGS

    // Create an empty array with capacity of 10
    str_array arr = make_empty();

    arr.size = 10;

    // Print out the size of the newly created array
    cout << "Array size = " << arr.size;

    // Fill array
    for (int i = 0; i < arr.size; i++) {
        arr.arr[i] = "cat";
    }
    cout << endl << endl;

    // Print array
    for (int i = 0; i < arr.size; i++) {
        cout << arr.arr[i] << " ";
    }
    cout << endl << endl;

    // Print the percentage of the array used to six decimal points
    const int SET_DECIMAL_POINTS = 6;
    double pct = pct_used(arr);
    cout << "Percentage of array in use: " << fixed << setprecision(SET_DECIMAL_POINTS) << pct << endl;
    cout << endl;

    // Change arr to string and print
    to_str(arr);
    print(arr);

    cout << endl;

    // Print with a new line feed
    println(arr);
    cout << endl;

    // Get the i'th object in the array
    const int ITH_ELEMENT = 3;
    string arr_obj = get(arr, ITH_ELEMENT);
    cout << "I'th element: " << arr_obj << endl;
    cout << endl;

    // Set the i'th element in the array to "panda" and print to test
    set(arr, ITH_ELEMENT, "panda");
    println(arr);
    cout << endl;

    // Set the last element in the array to "dog" and print
    append(arr, "dog");
    println(arr);
    cout << endl;

    // Check if two arrays are equal
    bool equal = operator==(arr, arr);
    cout << "Are the two strings equal: " << boolalpha << equal << endl;
    cout << endl;

    // Set the first element in the array to "turtle" and print
    prepend(arr, "turtle");
    println(arr);
    cout << endl;

    // make array capacity the same as size and show by using pct_used, which should return 1.0
    shrink_to_fit(arr);
    double pct2 = pct_used(arr);
    cout << "Percentage of array in use (should show 1.0 if size and capacity are equal): " << fixed << setprecision(SET_DECIMAL_POINTS) << pct2 << endl;
    cout << endl;

    // set array size to 0; first printing the array size before calling clear(arr) and afterwards, the size after
    cout << "Array size before calling clear(arr): " << arr.size << endl;
    clear(arr);
    cout << "Array size after calling clear(arr): " << arr.size << endl;

    // Delete the array to prevent any memory leakage
    deallocate(arr);
}
