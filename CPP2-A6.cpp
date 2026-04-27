#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return -1;
    }

    int num, count = 0;
    cout << "\nNumbers read from " << filename << ":" << endl;
    while (file >> num) {
        cout << "  " << num;
        if (isPrime(num))
            cout << " (prime)";
        cout << endl;
        if (isPrime(num))
count++;
    }

    file.close();
    return count;
}

int main() {
    string filename = "NUMS.TXT";

    cout << "  Prime Counter from NUMS.TXT " << endl;

    cout << "\nReading directly from " << filename << "..." << endl;

    int result = countPrimes(filename);

    if (result != -1) {
        cout << "Total prime numbers found: " << result << endl;
    }

    return 0;
}
