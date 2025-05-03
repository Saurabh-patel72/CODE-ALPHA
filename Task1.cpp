#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// Function to convert letter grade to grade point
double gradeToPoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    else if (grade == "B" || grade == "b") return 3.0;
    else if (grade == "C" || grade == "c") return 2.0;
    else if (grade == "D" || grade == "d") return 1.0;
    else if (grade == "F" || grade == "f") return 0.0;
    else return -1.0; // Invalid grade
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<int> creditHours(numCourses);
    vector<string> grades(numCourses);
    vector<double> gradePoints(numCourses);

    double totalCredits = 0, totalGradePoints = 0;

    // Input course information
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";

        cout << "Course Name: ";
        cin.ignore(); // To consume newline character from previous input
        getline(cin, courseNames[i]);

        cout << "Credit Hours: ";
        cin >> creditHours[i];

        cout << "Grade (A, B, C, D, F): ";
        cin >> grades[i];

        double point = gradeToPoint(grades[i]);
        if (point == -1.0) {
            cout << "Invalid grade entered. Exiting program.\n";
            return 1;
        }

        gradePoints[i] = point * creditHours[i];
        totalCredits += creditHours[i];
        totalGradePoints += gradePoints[i];
    }

    // Display individual course grades and grade points
    cout << "\n--- Course Summary ---\n";
    cout << left << setw(20) << "Course"
         << setw(10) << "Credits"
         << setw(10) << "Grade"
         << setw(15) << "Grade Points" << endl;

    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(20) << courseNames[i]
             << setw(10) << creditHours[i]
             << setw(10) << grades[i]
             << setw(15) << fixed << setprecision(2) << gradePoints[i] << endl;
    }

    // Calculate and display CGPA
    double cgpa = totalGradePoints / totalCredits;
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nYour CGPA is: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
