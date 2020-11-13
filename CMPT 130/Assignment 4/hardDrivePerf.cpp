#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void testTrackFunction();
void testSeekTime();
void testRotationTimes();
void testAccessTimes();
int enterRPMValue();
void displayHardDriveStats(int rpm);

// Main function
int main() {
    testTrackFunction();
    testSeekTime();
    testRotationTimes();
    testAccessTimes();
    int rpm = enterRPMValue();
    displayHardDriveStats(rpm);
    return 0;
}

const int TOTAL_NUM_OF_TRACKS = 22;

// returns the number of sectors in the given track
int calcNumSec(int trackNum){

    // TRACK_NUM_TO_GROUP - To find the track's track group, the track number is divided by 4
    const int TRACK_NUM_TO_GROUP = 4;
    const int ADDITIONAL_SECTORS_PER_TRACK_GROUP = 2;
    const int TRACKS_GROUP_NUMBER = trackNum / TRACK_NUM_TO_GROUP;
    const int BASE_SECTORS_PER_TRACK = 8;

    int numSectorsPerTrack = (ADDITIONAL_SECTORS_PER_TRACK_GROUP * TRACKS_GROUP_NUMBER) + BASE_SECTORS_PER_TRACK;
    return numSectorsPerTrack;
}

// calculates the total number of sectors on the disk
int calcTotalNumSec() {
    int currentTrack = 0;
    int sum = 0;
    while (currentTrack < TOTAL_NUM_OF_TRACKS){
        sum = calcNumSec(currentTrack) + sum;
        currentTrack++;
    }
    return sum;
}

// Calculate a track number from a sector number
int calcTrackNumFromSecNum(int secNum) {
    int sum = 0;
    int trackNum = 0;
    for (; trackNum < TOTAL_NUM_OF_TRACKS; trackNum++){
        sum += calcNumSec(trackNum);
        if (sum > secNum){
            return trackNum;
        }
    }
}

// Test the functions calcNumSec(int trackNum), calcTotalNumSec(), and calcTrackNumFromSecNum(int secNum)
void testTrackFunction() {
    const int SET_WIDTH = 11;

    cout << "TESTING: TRACK FUNCTIONS" << endl;
    cout << "------------------------" << endl;

    // Prints the number of sectors in the given track
    cout << "Now displaying the [track #] to [sectors per track] mapping:" << endl;
    int trackNum = 0;
    cout << setw(SET_WIDTH) << "Track#" << setw(SET_WIDTH) << "#Sectors" << endl;
    while (trackNum < TOTAL_NUM_OF_TRACKS) {
        cout << setw(SET_WIDTH) << trackNum << setw(SET_WIDTH) << calcNumSec(trackNum) << endl;
        trackNum ++;
    }
    cout << endl;

    // Prints the total # of sectors
    cout << "Total # Sectors: " << calcTotalNumSec() << endl << endl;

    // Prints track number from a sector number
    cout << "Now displaying the [sector number] to [track number] mapping: " << endl << "Checking every sector at start." << endl;
    cout << setw(SET_WIDTH) << "Sector" << setw(SET_WIDTH) << "Track" << endl;

    // Constant to limit the calcTrackNumFromSecNum(secNum) to only display the first 25 sectors
    const int FIRST_25_SECTORS = 25;

    int secNum = 0;
    while (secNum < FIRST_25_SECTORS) {
        cout << setw(SET_WIDTH) << secNum << setw(SET_WIDTH) << calcTrackNumFromSecNum(secNum) << endl;
        secNum ++;
    }
    cout << endl;

    // Print the result for every 13th sector
    cout << "Checking every 13th sector." << endl;
    cout << setw(SET_WIDTH) << "Sector" << setw(SET_WIDTH) << "Track" << endl;

    // Constant to make the remainingSecNums increase and check every 13th sector
    const int CHECK_EVERY_13 = 13;

    int remainingSecNums = FIRST_25_SECTORS;
    int sum = calcTotalNumSec();
    while (remainingSecNums <= sum) {
        cout << setw(SET_WIDTH) << remainingSecNums << setw(SET_WIDTH) << calcTrackNumFromSecNum(remainingSecNums) << endl;
        remainingSecNums = remainingSecNums + CHECK_EVERY_13;
    }
    cout << endl;
}

// Calculate and return seek time of the head
double calcSeekTimeOfHead(int trackStart, int trackEnd){
    const double RATE_OF_HEAD = 0.002;
    double seekTime = abs(trackStart - trackEnd) * RATE_OF_HEAD;
    return seekTime;
}

// Test calcSeekTimeOfHead(int trackStart, int trackEnd)
void testSeekTime() {
    cout << "TESTING: Seek Times" << endl;
    cout << "-------------------" << endl;

    const int SET_WIDTH = 6;

    cout << "Now displaying the [track #] to [track #] seek times." << endl
         << "Starting track shown down left most column; ending track "
                 "in first row." << endl;

    int trackRowNum = 0;
    cout << setw(SET_WIDTH) << "From: ";
    while (trackRowNum < TOTAL_NUM_OF_TRACKS){
        cout << setw(SET_WIDTH) << trackRowNum;
        trackRowNum ++;
    } cout << endl;

    // Set the number of digits to 3 decimal points
    const int SET_PRECISION = 3;

    for (int trackStart = 0; trackStart < TOTAL_NUM_OF_TRACKS; trackStart ++){
        cout << setw(SET_WIDTH) << trackStart;
        for (int trackEnd = 0 ;trackEnd < TOTAL_NUM_OF_TRACKS; trackEnd ++){
            cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << calcSeekTimeOfHead(trackStart, trackEnd);
        } cout << endl;
    } cout << endl;
}

// Calculate rotations per second from rotations per minute
double convertRPMToRPS(int rpm){
    // RPS = RPM / 60
    const double RPM_TO_RPS = 60;
    return rpm / RPM_TO_RPS;
}

// calculate average rotational delay time (in seconds)
double calcAvgRotationalDelayTime(int rpm){
    // Rotational delay is about half (1/2) the time of disk rotation
    const int HALF_TIME_FOR_DISK_ROTATION = 2;
    return 1/convertRPMToRPS(rpm)/HALF_TIME_FOR_DISK_ROTATION;
}

// calculate time to read one sector (in units of seconds)
double calcTimeToReadOneSector(int trackNum , int rpm){
    return 1/convertRPMToRPS(rpm)/ calcNumSec(trackNum);
}

// Test convertRPMToRPS(int rpm), calcAvgRotationalDelayTime(int rpm), calcTimeToReadOneSector(int trackNum , int rpm)
void testRotationTimes() {
    cout << "TESTING: Rotation Times" << endl;
    cout << "-----------------------" << endl;
    cout << "Now displaying the [rotation delay] per [track]." << endl;

    const int MIN_RPM = 4000;
    const int MAX_RPM = 15000;

    // Set the width for individual columns
    const int SET_WIDTH_RPM_COLUMN = 6;
    const int SET_WIDTH_RPS_COLUMN = 9;
    const int SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS = 18;

    cout << setw(SET_WIDTH_RPM_COLUMN) << "RPM"
         << setw(SET_WIDTH_RPS_COLUMN) << "RPS"
         << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << "Rotational Delay"
         << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << "Read Track 1"
         << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << "Read Max Track"
         << endl;

    int rpm = MIN_RPM;
    const int FIRST_TRACK = 0;
    const int LAST_TRACK = TOTAL_NUM_OF_TRACKS - 1;
    const int RPM_INCREMENT = 1000;
    const int SET_PRECISION_COLUMN_RPS = 2;
    const int SET_PRECISION_COLUMN_TIMES_AND_ROTATIONAL_DELAY = 6;
    while (rpm <= MAX_RPM) {
        cout << setw(SET_WIDTH_RPM_COLUMN) << rpm
             << setw(SET_WIDTH_RPS_COLUMN) << fixed << setprecision(SET_PRECISION_COLUMN_RPS)
             << convertRPMToRPS(rpm)
             << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << fixed << setprecision(SET_PRECISION_COLUMN_TIMES_AND_ROTATIONAL_DELAY)
             << calcAvgRotationalDelayTime(rpm)
             << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << fixed << setprecision(SET_PRECISION_COLUMN_TIMES_AND_ROTATIONAL_DELAY)
             << calcTimeToReadOneSector(FIRST_TRACK , rpm)
             << setw(SET_WIDTH_TIME_AND_ROTATIONAL_DELAY_COLUMNS) << fixed << setprecision(SET_PRECISION_COLUMN_TIMES_AND_ROTATIONAL_DELAY)
             << calcTimeToReadOneSector(LAST_TRACK , rpm)
             << endl;
        rpm = rpm + RPM_INCREMENT;
    } cout << endl;
}

// Calculate the average time to access and read a specific sector
double calcAvgTimeToAccessAndReadSector(int trackStart, int secToRead, int rpm){
    int trackEnd = calcTrackNumFromSecNum(secToRead);
    return calcSeekTimeOfHead(trackStart, trackEnd) + calcAvgRotationalDelayTime(rpm) + calcTimeToReadOneSector(calcTrackNumFromSecNum(secToRead),rpm);
}

// calculate the average access and read time for all possible situations
double calcAvgAccessAndReadOfAllSec(int rpm){
    double average = 0;
    double sum = 0;
    double counter = 0;
    for (int currentTrack = 0; currentTrack < TOTAL_NUM_OF_TRACKS ; currentTrack++) {
        for (int currentSector = 0; currentSector < calcTotalNumSec(); currentSector++) {
            sum += calcAvgTimeToAccessAndReadSector(currentTrack, currentSector, rpm);
            counter++;
        }
    }
    average = sum / counter;
    return average;
}

// calculate the average access and read time using a randomized approach
double calcAvgAccessAndReadTimeRandom(int rpm){
    srand(time(nullptr));
    double average = 0;
    double sum = 0;
    const int NUMBER_OF_TRIALS = 1000000;
    for (int i = 0; i < NUMBER_OF_TRIALS; i++){
        int track = rand() % (TOTAL_NUM_OF_TRACKS - 1);
        int sector = rand() % (calcTotalNumSec() - 1);
        sum += calcAvgTimeToAccessAndReadSector(track,sector,rpm);
    }
    average = sum / NUMBER_OF_TRIALS;
    return average;
}

// test calcAvgTimeToAccessAndReadSector(int trackStart, int secToRead, int rpm), calcAvgAccessAndReadOfAllSec(int rpm), calcAvgAccessAndReadTimeRandom(int rpm)
void testAccessTimes(){
    cout << "TESTING: Access & Read Times" << endl;
    cout << "----------------------------" << endl;
    cout << "Now displaying time to [access and read] for some sectors for specific" << endl
         << "[RPM], [start track #] and [target sector #]." << endl;

    // chart #1: Displaying access and read time for specific sectors
    const int SET_WIDTH = 10;
    cout << setw(SET_WIDTH) << "RPM" << setw(SET_WIDTH) << "Track" << setw(SET_WIDTH) << "Sector" << setw(SET_WIDTH) << "Time" << endl;

    const int START_RPM = 4000;
    const int MAX_RPM = 15000;
    const int MULTIPLE_RPM_INCREMENT = 2000;
    const int TRACK_INCREMENT = 8;

    const int SET_PRECISION_TIME = 6;

    for (int rpm = START_RPM; rpm < MAX_RPM; rpm += MULTIPLE_RPM_INCREMENT) {
        for (int trackNum = 0; trackNum <= TOTAL_NUM_OF_TRACKS ; trackNum += TRACK_INCREMENT){
            const int MAX_SECTOR = calcTotalNumSec();
            const int SECTOR_INCREMENT = 123;
            for (int secNum = 0; secNum <= MAX_SECTOR; secNum += SECTOR_INCREMENT) {
                cout << setw(SET_WIDTH) << rpm << setw(SET_WIDTH) << trackNum << setw(SET_WIDTH) << secNum << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION_TIME)
                     << calcAvgTimeToAccessAndReadSector(trackNum, secNum, rpm) << endl;
            }
        }
    }
    cout << endl;

    // chart #2: displaying access and read times for each rpm
    cout << "Now displaying access and read times" << endl;
    const int SET_WIDTH_TIME = 17;
    cout << setw(SET_WIDTH) << "RPM" << setw(SET_WIDTH_TIME) << "Read Time" << setw(SET_WIDTH_TIME) << "Rand Read Time" << endl;

    const int SINGLE_RPM_INCREMENT = 1000;
    for (int rpm = START_RPM; rpm <= MAX_RPM; rpm += SINGLE_RPM_INCREMENT) {
        cout << setw(SET_WIDTH) << rpm << fixed << setprecision(SET_PRECISION_TIME) << setw(SET_WIDTH_TIME) << calcAvgAccessAndReadOfAllSec(rpm) << setw(SET_WIDTH_TIME) << calcAvgAccessAndReadTimeRandom(rpm) << endl;
    }
    cout << endl;
}

// Asks user to input a RPM value
int enterRPMValue(){
    int rpm = 0;
    cout << "Enter HD rotations per minute (RPM): ";
    cin >> rpm;

    // Checks for rpm values over 50000 and under 1
    const int MAX_RPM = 50000;
    const int MIN_RPM = 1;
    while ((rpm > MAX_RPM) || (rpm < MIN_RPM)){
        cout << "Error: Value must be between 1 and 50000." << endl;
        cout << "Enter HD rotations per minute (RPM): ";
        cin >> rpm;
    }
    cout << endl;
    return rpm;
}

// Prints out all statistics
void displayHardDriveStats(int rpm){
    cout << "Hard Drive Statistics:" << endl;
    cout << "----------------------" << endl;

    int firstTrack = 0;
    int lastTrack = TOTAL_NUM_OF_TRACKS - 1;
    const int SET_PRECISION_RPS_COLUMN = 1;
    const int SET_PRECISION_TIME_COLUMNS = 6;

    cout << "Number of tracks:             " << TOTAL_NUM_OF_TRACKS << endl
         << "Total number of sectors:      " << calcTotalNumSec() << endl
         << "Revolutions per minute (RPM): " << rpm << endl
         << "Revolutions per second (RPS): " << fixed << setprecision(SET_PRECISION_RPS_COLUMN) << convertRPMToRPS(rpm) << endl
         << "Rotational delay (seconds):   " << fixed << setprecision(SET_PRECISION_TIME_COLUMNS) << calcAvgRotationalDelayTime(rpm) << endl
         << "Time to read first sector:    " << fixed << setprecision(SET_PRECISION_TIME_COLUMNS) << calcTimeToReadOneSector(firstTrack , rpm) << " seconds" << endl
         << "Time to read last sector:     " << fixed << setprecision(SET_PRECISION_TIME_COLUMNS) << calcTimeToReadOneSector(lastTrack , rpm) << " seconds" << endl
         << "Average read time:            " << fixed << setprecision(SET_PRECISION_TIME_COLUMNS) << calcAvgAccessAndReadOfAllSec(rpm) << " seconds" << endl
         << "Average (random) read time:   " << fixed << setprecision(SET_PRECISION_TIME_COLUMNS) << calcAvgAccessAndReadTimeRandom(rpm) << " seconds" << endl;
}