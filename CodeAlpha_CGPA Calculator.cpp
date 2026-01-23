#include<iostream>
using namespace std;
int main() {
    int numCourses;
    int totalCredits = 0.0;
    int totalGradePoints = 0.0;
    cout << "-----------------------" << endl;
    cout << "--- CGPA Calculator ---" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter the total number of courses: ";
    cin >> numCourses;

    // We use a loop to handle one course at a time
// We use a loop to handle one course at a time
for (int i = 1; i <= numCourses; i++) {
    int currentGrade;
    int currentCredits;

    cout << "\n Course #" << i << ":" << endl;

    cout << "  Enter Grade scored (out of 10): ";
    cin >> currentGrade;

    cout << "  Enter Credits: ";
    cin >> currentCredits;

    // Calculate and add to the running totals immediately
    totalGradePoints += (currentGrade * currentCredits);
    totalCredits += currentCredits;

    // Displaying the individual course grade right after input
    cout << "  >> Course " << i << " Grade: " << currentGrade << endl;
}

    // Final Calculation
    cout << "\n----------------------------" << endl;
    if (totalCredits > 0) {
        float cgpa = totalGradePoints / totalCredits;
        cout << "Total Credits Earned: " << totalCredits << endl;
        cout << "Final Semester CGPA:  " << cgpa << endl;
    } else {
        cout << "Enter Again. Total credits cannot be zero." << endl;
    }
    cout << "----------------------------" << endl;

    return 0;
}