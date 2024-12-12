#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Step 1: Create an output file and write information to it
    ofstream outFile("example.txt");

    if (!outFile) {
        cerr << "Error creating the file." << endl;
        return 1;
    }

    outFile << "Hello, this is a test file.\n";
    outFile << "This file demonstrates file I/O operations in C++.\n";
    outFile << "End of file content." << endl;

    outFile.close();
    cout << "Data written to the file successfully." << endl;

    // Step 2: Open the file as an input file and read the information
    ifstream inFile("example.txt");

    if (!inFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    cout << "\nReading data from the file:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
