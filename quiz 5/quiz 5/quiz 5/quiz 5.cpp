#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 10;   //total names in file

//Passing three arrays as a reference to read the file values.
bool readInfo(string filename, string(&firstNames)[SIZE], string(&lastNames)[SIZE], int(&ages)[SIZE]) {
    fstream ifile(filename);
    if (ifile.is_open() != true) {
        return false;
    }
    for (int i = 0; i < SIZE; ++i) {
        ifile >> firstNames[i];
        string lastname;
        ifile >> lastname;
        lastNames[i] = lastname.substr(0, lastname.size() - 1);
        ifile >> ages[i];
    }
    return true;
}

//Print value given in index of the arrays.
void PrettyPrintName(int index, string(&firstNames)[SIZE], string(&lastNames)[SIZE], int(&ages)[SIZE]) {
    cout << right << setfill(' ') << setw(7) << firstNames[index];
    cout << setfill('.') << setw(15) << lastNames[index];
    cout << setfill('.') << setw(10) << ages[index] << endl;
}

int main() {
    cout << "************* Welcome to my Names Program *************" << endl;
    cout << "*******************************************************" << endl;
    string filename = "NamesAndAges.txt";
    string firstNames[10];
    string lastNames[10];
    int ages[10];

    if (readInfo(filename, firstNames, lastNames, ages) != true) {
        cout << "Can't read file: " << filename << endl;
        return -1;
    }

    // printing forward
    cout << endl;
    for (int i = 0; i < SIZE; ++i) {
        PrettyPrintName(i, firstNames, lastNames, ages);
    }

    //print reverse
    cout << endl;
    for (int i = SIZE - 1; i >= 0; --i) {
        PrettyPrintName(i, firstNames, lastNames, ages);
    }
    return 0;
}