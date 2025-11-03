#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int numOfStudent = 4;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void assign(studentType students[], int numOfStudent);
void read(string, string, int, char);
int calculateGrade(int score);
studentType findHighestScore(studentType students[], int total);
void printHighestScore(studentType x);

// Add error checking function
float errorChecker();


int main(){

    studentType students[numOfStudent];

    assign(students, numOfStudent);

    cout << endl <<"-----Student Records:-----" << endl;
    for(int i = 0; i < numOfStudent; i++){
        read(students[i].studentFName, students[i].studentLName, students[i].testScore, students[i].grade);
    }

    studentType x = findHighestScore(students, numOfStudent);
    printHighestScore(x);

    return 0;
}


void assign(studentType students[], int numOfStudent){
    for(int i = 0; i < numOfStudent; i++){
        cout << "Student-" << i + 1 << endl;
        cout << "First Name: ";
        cin >> students[i].studentFName;
        cout << "Last Name: ";
        cin >> students[i].studentLName;
        cout << "Test Score: ";
        students[i].testScore = errorChecker();
        students[i].grade = calculateGrade(students[i].testScore);
        cout << "------------------------" << endl;
    }
}

void read(string f, string l, int s, char g){
    cout << "Name: " << f << " " << l << endl;
    cout << "Test Score: " << s << endl;
    cout << "Grade: " << g << endl;
    cout << "------------------------" << endl;
}

int calculateGrade(int score){
    if(score >= 90) return 'A';
    else if(score >= 80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 60) return 'D';
    else return 'F';
}

float errorChecker(){
    float score;
    bool digitCheck;
    
    while(true){
        cin >> score;

        if(cin.fail() || score < 0 || score > 100){
            cin.clear();
            cin.ignore();
            cout << "Invalid, Please enter a number (0 - 100): ";
        } else {
            return score;
        }
    }
}

studentType findHighestScore(studentType students[], int total){
    int highest = students[0].testScore;
    int index = 0;
    for (int i = 1; i < total; i++) {
        if (highest < students[i].testScore) {
            highest = students[i].testScore;
            index = i;
        }
    }
    return students[index];
}

void printHighestScore(studentType x){
    cout << "---------Highest Score---------" << endl;
    cout << "Name: " << x.studentFName << "\tScore: " << x.testScore << endl;
}