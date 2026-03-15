#include <iostream>
using namespace std;

void aGrades(int *grades, int rows, int cols);

int main() {
    int rows, cols;

    cout << "Enter number of students: ";
    cin >> rows;
    cout << "Enter number of subjects: ";
    cin >> cols;

    int grades[rows][cols];

    cout << "\nEnter grades:\n";
    for (int i = 0; i < rows; i++) {
             cout << "Student " << i+1 <<endl;
        for (int j = 0; j < cols; j++) {
            cout<<"Subject " << j+1 << ": ";
            cin >> grades[i][j];
        }
    }

    aGrades(&grades[0][0], rows, cols);

    return 0;
}

void aGrades(int *grades, int rows, int cols) {

    // Display the grade matrix
    cout << "\n GRADE MATRIX \n";
    cout<<"\t";

    for (int j = 0; j < cols; j++)
        cout <<"\tSubject " << j+1;
        cout<<endl;

    for (int i = 0; i < rows; i++) {
        cout << "Student " << i+1 << ":";
            for (int j = 0; j < cols; j++) {
                cout << "\t" << *(grades + i *cols + j) << "\t";
        }
        cout <<endl;
    }

    //Compute average grade per student
    cout << "\n STUDENT AVERAGES \n";
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += *(grades + i *cols + j);
        }
        double avg = sum/cols;
        cout << "Student " << i+1 << " average: " << avg <<endl;
    }

    // highest grade in the entir matrix
    int highest = *(grades);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = *(grades + i *cols + j);
            if (current > highest)
                highest = current;
        }
    }
    cout << "\n HIGHEST GRADE \n";
    cout << "Highest grade in the matrix: " << highest <<endl;
}
