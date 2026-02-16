#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        double sales[5][4] = {0}; // 5 products, 4 salespeople
        int sp, prod;
        double amount;
        char more;

        // Input sales
        do {
            cout << "\nEnter salesperson number (1-4): ";
            cin >> sp;

            cout << "Enter product number (1-5): ";
            cin >> prod;

            cout << "Enter amount sold: ";
            cin >> amount;

            sales[prod-1][sp-1] += amount;

            cout << "Add another entry? (y/n): ";
            cin >> more;

        } while (more == 'y' || more == 'Y');
   // Display table
        cout << "\n\nProduct\t";
        for (int j = 0; j < 4; j++)
            cout << "SP" << j + 1 << "\t";
        cout << "Total\n";

        double grandTotal = 0;
        double colTotal[4] = {0};

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
                colTotal[j] += sales[i][j];
            }

            grandTotal += rowTotal;
            cout << rowTotal << endl;
        }

        // Column totals
        cout << "Total\t";
        for (int j = 0; j < 4; j++)
            cout << colTotal[j] << "\t";

        cout << grandTotal << endl;

        cout << "\nRun again? (y/n): ";
cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
