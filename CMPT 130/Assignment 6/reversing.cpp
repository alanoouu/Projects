#include <iostream>
#include <cassert>

using namespace std;

// Prototypes
bool isPermutation(int arr[], int n);
void reverseArray(int arr[], int n);
void initializePermutation(int arr[], int n);
bool nextPermutation(int arr[], int n);
void demoPermutations();
void printOptimalPermutations(int low, int high);

int main()
{
    // Demo the use of nextPermutation() and nextPermutation(int arr[], int n).
    demoPermutations();

    // Simple tests for isPermutation()
    int arr1[] = {4, 2, 3, 1, 5};
    cout << "isPerm 1? " << isPermutation(arr1, 5) << endl;
    int arr2[] = {4, 2, 3, 5, 5};
    cout << "isPerm 2? " << isPermutation(arr2, 5) << endl;
    int arr3[] = {4, 2, 0, 1};
    cout << "isPerm 3? " << isPermutation(arr3, 4) << endl;
    int arr4[] = {34, 2, 34, 1};
    cout << "isPerm 4? " << isPermutation(arr4, 4) << endl;
    int arr5[] = {4, 2, 10, 1};
    cout << "isPerm 5? " << isPermutation(arr5, 4) << endl;
    int arr6[] = {4, 2, 3, 1};
    cout << "isPerm 6? " << isPermutation(arr6, 4) << endl;
    int arr7[] = {4, 3, 1, 2, 5};
    cout << "isPerm 7? " << isPermutation(arr7, 5) << endl;
    cout << endl;

    // Constants for the min and max of n
    const int LOW = 1;
    const int HIGH = 11;
    printOptimalPermutations(LOW, HIGH);

    return (0);
}

// Returns 1 if arr is a permutation of 1, ..., n, and 0 otherwise.
bool isPermutation(int arr[], int n)
{
    // Starting from number 1, check if the array contains each number upto n
    for (int i = 1; i <= n; i++){
        for(int u = 0; u < n; u++){
            // Break out of loop after number is found
            if (arr[u] == i){
                break;
            }
            // Return false if number is not found in the array
            else if ((u == n - 1) && (arr[u] != i)){
                return false;
            }
        }
    }
    return true;
}

// Initialize arr[] to hold the values 1 to n, in order.
void initializePermutation(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
}

// Reverse the array arr, changing the original array.
void reverseArray(int arr[], int m)
{
    const int HALF = 2;
    for(int i = 0; i < (m/HALF) ; i++){
        int p = m - 1 - i;
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
}

// Copy all elements from source[] to destination[]
void copyArray(int destination[], int source[], int size){
    for (int i = 0; i < size; i++){
        destination[i] = source[i];
    }
}

// Returns the number of reversals needed to make arr[0] == 1 when the reversal game is played on arr.
int scorePermutation(int arr[], int n){
    int score = 1;
    // Create copy of original array
    int arrayCopy[n];
    copyArray(arrayCopy, arr, n);
    // Reverse the copy of the array
    reverseArray(arrayCopy, arrayCopy[0]);
    while(arrayCopy[0] != 1){
        reverseArray(arrayCopy, arrayCopy[0]);
        score++;
    }
    if (arr[0] == 1){
        return 0;
    }
    return score;
}

// Prints the size, its permutation, and score
void printPermutationAndScore(int arr[], int n){
    int score = scorePermutation(arr, n);
    cout << "[n = " << n << "]" << " Score of {";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if (i != (n-1)){
            cout << ",";
        }
    }
    cout << "} = " << score << endl;
}

// Given a permutation, advance it to the next permutation in lexicographic order. Algorithm discussed here:
// http://stackoverflow.com/questions/352203/generating-permutations-lazily
bool nextPermutation(int arr[], int n)
{
    // Check that arr[] is already a valid permutation.
    // This will crash the program if arr() is not a valid permutation.
    assert(isPermutation(arr, n));

    // Ensure the permutation is large enough to support re-ordering.
    if (n <= 1) {
        return 0;
    }

    // Find the longest tail
    int tailStartIdx = n - 1;
    while (arr[tailStartIdx - 1] > arr[tailStartIdx]) {
        tailStartIdx --;
        if (tailStartIdx == 0) {
            return 0;
        }
    }
    int swapFrontIdx = tailStartIdx - 1;

    // Find the element in the sorted tail which is the smallest element
    // larger than the element before the tail.
    int swapInTailIdx = n - 1;
    while (arr[swapInTailIdx] < arr[swapFrontIdx]) {
        swapInTailIdx --;
    }

    // Swap the elements:
    int temp = arr[swapInTailIdx];
    arr[swapInTailIdx] = arr[swapFrontIdx];
    arr[swapFrontIdx] = temp;

    // Reverse the tail:
    reverseArray(arr + tailStartIdx, n - tailStartIdx);

    return 1;
}

// Display all permutations of a specific size.
// Demonstrates how to use the permutation functions.
void demoPermutations()
{
    // Create the first permutation
    const int SIZE = 4;
    int perm[SIZE];
    initializePermutation(perm, SIZE);

    // Create all possible permutations
    int counter = 1;
    bool moreToGo = true;
    while (moreToGo) {
        // Display the permutation
        cout << counter << ": ";
        for (int i = 0; i < SIZE; i++) {
            cout << perm[i] << ", ";
        }
        cout << endl;

        moreToGo = nextPermutation(perm, SIZE);
        counter++;
    }
    cout << endl;
}

// Find an optimal permutation (of size n) and copy it into arr[].
void findOptimalPermutation(int arr[], int n){
    int currentScore = 0;

    // Create the first permutation
    int perm[n];
    initializePermutation(perm, n);

    // Create all possible permutations and copy the permutation with the greatest score into arr[]
    int counter = 1;
    bool moreToGo = true;
    while (moreToGo) {
        moreToGo = nextPermutation(perm, n);
        int newScore = scorePermutation(perm, n);
        if (newScore > currentScore){
            currentScore = newScore;
            copyArray(arr, perm, n);
        }
        counter++;
    }
}

// Test all permutations of sizes between low and high (inclusive).
// For each size, print one permutation which maximizes it score.
void printOptimalPermutations(int low, int high){
    for (int i = low; i <= high; i++) {
        int arr[i];
        // Generate the numbers from 1 to n
        initializePermutation(arr, i);
        // Find the permutation with the highest score
        findOptimalPermutation(arr, i);
        // Print the permutation
        printPermutationAndScore(arr, i);
    }
}