#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Write color names to color.txt
    ofstream outFile("color.txt");
    if (!outFile) {
        cout << "Error: Could not create color.txt" << endl;
        return 1;
    }

    outFile << "Red" << endl;
    outFile << "Blue" << endl;
    outFile << "Green" << endl;
    outFile << "Yellow" << endl;
    outFile << "Purple" << endl;

    outFile.close();
    cout << "color.txt created successfully." << endl;

    // Read from color.txt and copy to color_copy.txt
    ifstream inFile("color.txt");
    if (!inFile) {
        cout << "Error: Could not open color.txt" << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");
    if (!copyFile) {
        cout << "Error: Could not create color_copy.txt" << endl;
        return 1;
    }
string line;
    cout << "\nContents of color.txt:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;   // display to console
        copyFile << line << endl; // write to copy
    }

    inFile.close();
    copyFile.close();

    cout << "\ncolor_copy.txt created successfully." << endl;

    return 0;
}
