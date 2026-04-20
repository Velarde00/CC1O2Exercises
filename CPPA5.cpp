#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //Write words to original.txt
    ofstream outFile("original.txt");
    if (!outFile) {
        cout << "Error: Could not create original.txt" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;

    outFile.close();
    cout << "original.txt created successfully." << endl;

    //Read from original.txt into a vector
    ifstream inFile("original.txt");
    if (!inFile) {
        cout << "Error: Could not open original.txt" << endl;
        return 1;
    }

    vector<string> words;
    string line;
    while (getline(inFile, line)) {
words.push_back(line);
    }
    inFile.close();

    //Bubble sort alphabetically
    int n = words.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (words[j] > words[j + 1]) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    // Write sorted words to sorted.txt
    ofstream sortedFile("sorted.txt");
    if (!sortedFile) {
        cout << "Error: Could not create sorted.txt" << endl;
        return 1;
    }

    cout << "\nSorted contents written to sorted.txt:" << endl;
    for (int i = 0; i < n; i++) {
        sortedFile << words[i] << endl;
        cout << words[i] << endl;
    }
    sortedFile.close();

    cout << "\nsorted.txt created successfully." << endl;

    return 0;
}
