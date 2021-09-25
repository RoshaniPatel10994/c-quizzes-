#include <iostream>
#include <string>
#include <iomanip>  
#include <fstream>
using namespace std;

//read file and fill the data into two arrays
int readFile(string filename, int(&rowSeats)[150], int(&rowSpaces)[150]) {
    fstream iFile(filename);
    if (!iFile.is_open()) return -1;
    int seats = 0;
    int spaces = 0;
    char colon;
    int totalRows = 0;
    while (!iFile.eof()) {
        iFile >> seats;
        iFile >> colon;
        iFile >> spaces;
        rowSeats[totalRows] = seats;
        rowSpaces[totalRows] = spaces;
        ++totalRows;
    }
    return totalRows;
}

//pretty print the title
void printTitle() {
    cout << setw(20) << setfill('*') << setw(60) << "\n";
    string s0 = " Welcome to the Separation Stadium program ";
    cout << setw(51) << setfill('*') << s0 << setw(9) << "\n";
    cout << setw(20) << setfill('*') << setw(60) << "\n";
    cout << endl;
    cout << endl;
}

//Display seating arrangements of the stadium
void displaySeatingArrangements(int totalRows, int(&rowSeats)[150], int(&rowSpaces)[150]) {
    int offset = 0;
    for (int i = 0; i < totalRows; ++i) {
        for (int s = 0; s < offset; ++s) cout << " ";  //inital spaces
        ++offset;
        cout << "I-";  //Start of row
        for (int j = 0; j < rowSeats[i]; ++j) {
            if (j % rowSpaces[i] == 0) {  //if it divides then put person else its a space
                cout << "o";
            }
            else {
                cout << ".";
            }
        }
        cout << "-I" << endl;   //End of row
    }
}

//Print Occupied and Unoccupied seat counts with ratio
void printAndCalculateSeatCounts(int totalRows, int(&rowSeats)[150], int(&rowSpaces)[150]) {
    int totalOccupied = 0;
    int totalUnOccupied = 0;
    double ratio = 0;
    for (int i = 0; i < totalRows; ++i) {
        int occupied = 0;
        int unOccupied = 0;
        if (rowSeats[i] % rowSpaces[i] == 0) {
            occupied = (rowSeats[i] / rowSpaces[i]);
        }
        else {
            occupied = (rowSeats[i] / rowSpaces[i]) + 1;
        }
        unOccupied = rowSeats[i] - occupied;
        totalOccupied = totalOccupied + occupied;
        totalUnOccupied = totalUnOccupied + unOccupied;
    }
    cout << endl;
    cout << endl;

    ratio = (double(totalOccupied) / totalUnOccupied) * 100;    //ratio of occupied to unoccupied
    cout << "The total occupied seat count is: " << totalOccupied << endl;
    cout << "The total unoccupied seat count is: " << totalUnOccupied << endl;
    cout << "The ratio of occupation is: " << fixed << setprecision(2) << ratio << "%" << endl;
}
int main(int argc, char* argv[]) {
    printTitle();
    string filename = argv[1];
    int rowSeats[150];
    int rowSpaces[150];
    int totalRows = readFile(filename, rowSeats, rowSpaces);
    if (totalRows == -1) {
        cout << "Error in reading file." << endl;
    }
    displaySeatingArrangements(totalRows, rowSeats, rowSpaces);
    printAndCalculateSeatCounts(totalRows, rowSeats, rowSpaces);
    return 0;
}
