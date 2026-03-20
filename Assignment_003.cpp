#include <iostream>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    double gpa;
};

void input(int num, student s[]) {
    for(int i = 0; i < num; i++) {
        do{
            cout << "StudentID: ";
            cin >> s[i].studentID;
            cin.ignore();

            bool duplicate = false;
            for (int j = 0; j < i; j++) {
                if (s[j].studentID == s[i].studentID) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) cout << "Student already exists! Try again.\n";
            else break;

        } while (true);

        cout << "Name: ";
        getline(cin, s[i].name);

        cout << "Course: ";
        getline(cin, s[i].course);

        do{
            cout << "GPA: ";
            cin >> s[i].gpa;
            cin.ignore();
            if (s[i].gpa < 0 || s[i].gpa > 100)
                cout << "GPA must be 0 to 100 only.\n";
        } while (s[i].gpa < 0 || s[i].gpa > 100);

        cout << endl;
    }
}

void display(int num, student s[]) {
    cout << "StudentID\tName\t\tCourse\t\tGPA\t\tStanding\n";
    cout << "==========================================================================\n";

    for (int i = 0; i < num; i++) {
        cout << s[i].studentID << "\t\t";
        cout << s[i].name     << "\t\t";
        cout << s[i].course   << "\t\t";
        cout << s[i].gpa      << "\t\t";

        if      (s[i].gpa >= 90) cout << "Excellent\n";
        else if (s[i].gpa >= 80) cout << "Very Good\n";
        else if (s[i].gpa >= 70) cout << "Good\n";
        else if (s[i].gpa >= 60) cout << "Passing\n";
        else                     cout << "Failed\n";

        cout << endl;
    }
    cout << "==========================================================================\n";
}

int main() {
    char choice;

    do{
        int num;
        cout << "How many students: ";
        cin >> num;
        cin.ignore();

        student s[num];

        input(num, s);
        display(num, s);

        cout << "Try again? (y/n): ";
        cin >> choice;

    }while (choice == 'y' || choice == 'Y');

    return 0;
}