#include <iostream>
#include <string>
using namespace std;

struct student {
    string studentID;
    string name;
    string course;
    float gpa;
};

string Standing(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

string dash(string text, int width) {
    do {
        text += " ";
    } while (text.length() < width);
    return text;
}

// input function
void input(student students[], int n) {
    int i = 0;
    do {
        cout << "\n Student " << i + 1 << endl;

        bool idTaken;
        do {
            idTaken = false;
            cout << "Enter Student ID: ";
            cin >> students[i].studentID;

            int j = 0;
            do {
                if (j < i && students[j].studentID == students[i].studentID) {
                    cout << "ID already exists! Please enter a different ID." << endl;
                    idTaken = true;
                    break;
                }
                j++;
            } while (j < i);
        } while (idTaken);

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, students[i].name);
        cout << "Enter Course: ";
        getline(cin, students[i].course);

        do {
            cout << "Enter GPA (0-100): ";
            cin >> students[i].gpa;
            if (students[i].gpa < 0 || students[i].gpa > 100)
                cout << "Invalid GPA! Must be between 0 and 100." << endl;
        } while (students[i].gpa < 0 || students[i].gpa > 100);

        i++;
    } while (i < n);
}

// dispaly function
void display(student students[], int n) {
    cout << "\n"
         << dash("Student ID", 15)
         << dash("Name", 25)
         << dash("Course", 15)
         << dash("GPA", 8)
         << dash("Standing", 12)
         << endl;
    cout << "-----------------------------------------------------------------------\n";

    int k = 0;
    do {
        string standing = Standing(students[k].gpa);
        string gpaStr   = to_string((int)students[k].gpa);
        cout << dash(students[k].studentID, 15)
             << dash(students[k].name, 25)
             << dash(students[k].course, 15)
             << dash(gpaStr, 8)
             << dash(standing, 12)
             << endl;
        k++;
    } while (k < n);
}

int main() {
    char choice;
    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student obj[n]; 

        input(obj, n);   //structure as an arg
        display(obj, n); // structure as an arhg

        cout << "\nRun the program again?: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
