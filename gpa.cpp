#include <iostream>
#include <string>
using namespace std;

class Subject {
public:
    string name;
    int credits;
    char grade;

    Subject() {
        name = "";
        credits = 0;
        grade = 'F';
    }

    float getGradePoint() {
        if (grade == 'A' ) return 4.0;
        else if (grade == 'B' ) return 3.0;
        else if (grade == 'C' ) return 2.0;
        else if (grade == 'D') return 1.0;
        else return 0.0;
    }
};

class GPACalculator {
private:
    Subject subjects[10];  
    int n;                

public:
    GPACalculator() {
        n = 0;
    }

    void inputSubjects() {
        cout << "Enter number of subjects: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nEnter subjects " << i + 1 << ":\n";
            cout << "Subject Name: ";
            cin >> subjects[i].name;
            cout << "Credits: ";
            cin >> subjects[i].credits;
            cout << "Grade (A, B, C, D, F): ";
            cin >> subjects[i].grade;
        }
    }

    float calculateGPA() {
        float totalPoints = 0, totalCredits = 0;

        for (int i = 0; i < n; i++) {
            totalPoints += subjects[i].getGradePoint() * subjects[i].credits;
            totalCredits += subjects[i].credits;
        }

        if (totalCredits == 0) return 0.0;
        return totalPoints / totalCredits;
    }

    void displayResult() {
        cout << "\n--- GPA REPORT ---\n";
        for (int i = 0; i < n; i++) {
            cout << subjects[i].name 
                 << " (" << subjects[i].credits << " credits) - Grade: "
                 << subjects[i].grade << "\n";
        }

        float gpa = calculateGPA();
        cout << "\nFinal GPA: " << gpa << endl;
    }
};

int main() {
    GPACalculator calc;
    calc.inputSubjects();
    calc.displayResult();
    return 0;
}