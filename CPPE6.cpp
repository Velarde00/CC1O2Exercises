#include <iostream>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    double gpa;
};

string Standing(double gpa) {
    if (gpa>=90) return "Excellent";
    else if (gpa >=80) return "Very Good";
    else if (gpa >=70) return "Good";
    else if (gpa >=60) return "Paasing";
    else return "Failed";
}

int main () {
    char choice;

    do {
            int n;

            cout<< "Enter number of Students: ";
            cin>>n;

            student students[n];

            for(int i=0; i<n; i++){
                cout<< "\n Student " << i+1 << ":"<<endl;


            bool idTaken;
            do {
                idTaken = false;
                cout<< "Enter Student ID: ";
                cin>>students[i].studentID;

                for(int j=0; j<i; j++){
                    if(students[j].studentID == students[i].studentID){
                        cout<< "ID already exists! Please enter a different ID"<<endl;
                        idTaken = true;
                        break;
                    }
                }
            } while (idTaken);

            cin.ignore();
            cout<< "Enter name: ";
            getline(cin,students[i].name);

            cout<< "Enter Course: ";
            getline(cin, students[i].course);

            do{
                cout<< "Enter GPA (0-100): ";
                cin>>students[i].gpa;

                if(students[i].gpa<0 || students[i].gpa >100)
                    cout<< "Invalid GPA! Must be between 0 and 100."<<endl;
            } while(students[i].gpa < 0 || students[i].gpa > 100);
    }

    cout<< "\nStudent ID\tName\t\tCourse\t\tGPA\t\tStanding"<<endl;
    cout<< "-------------------------------------------------------------------------"<<endl;

    for(int i=0; i<n; i++) {
        cout<< students[i].studentID <<"\t\t"
            << students[i].name     << "\t\t"
            << students[i].course   << "\t\t"
            << students[i].gpa      << "\t\t"
            << Standing(students[i].gpa) <<endl;
    }

    cout<<endl;


            cout<< "Run again?";
            cin>>choice;
    } while (choice == 'y' || choice == 'Y');


return 0;

}


