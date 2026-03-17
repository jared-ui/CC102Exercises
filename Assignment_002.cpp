#include <iostream>
#include <vector>
using namespace std;

void analyzeGrades(int *matrix, int rows, int cols) {
    cout << "\nGrade Matrix:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << *(matrix + i * cols + j) << "\t";
        }
        cout << endl;
    }

    cout << "\nAverage grade of each student:\n";
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += *(matrix + i * cols + j);
        }
        double avg = (double)sum / cols;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    int highest = *matrix;
    for(int i = 0; i < rows * cols; i++) {
        if(*(matrix + i) > highest) {
            highest = *(matrix + i);
        }
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[100][100];

    cout << "\nEnter grades:\n";
    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}