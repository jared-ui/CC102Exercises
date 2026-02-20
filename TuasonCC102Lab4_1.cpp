#include <iostream>
using namespace std;

int main() {

    char choice;

    do {
        
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        int scores[100][100];
        double average[100];

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << endl;

            int sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cout << "Enter score for Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            average[i] = (double)sum / quizzes;
        }

        cout << "\nOutput\n";

        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " scores: ";

            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << " ";
            }
            cout << "Average: " << average[i] << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}