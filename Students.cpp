/* 
  Purpose: The purpose of this program is to allow the information of students to be inputted into the program, in this case 3 students, and have their information stored and then displayed back when the user is finished inputting data.
*/

#include <iostream>
#include <string>
using namespace std;

struct NAME // Creates structure "NAME"
{
    string First;
    string MiddleInitial;
    string Last;
};

struct Student // Creates structure "Student" with an array of 4 'students'
{
    struct NAME Name;
    int Identification;
    string Email;
    int SSN;
    string Program;
} students[4];

void displayInfo(Student S); // Function prototype

int main()
{
    int i;

    for (i = 1; i <= 3; i++) // For loop that loops through for 3 different student information inputs. Skips over the "0" student as to allow the students to be numbered correctly.
    {
        cout << "\nEnter information for Student " << i << "." << endl;
        cout << "\nFirst name: ";
        getline(cin, students[i].Name.First);
        cout << "\nMiddle Initial: ";
        getline(cin, students[i].Name.MiddleInitial);
        cout << "\nLast Name: ";
        getline(cin, students[i].Name.Last);
        cout << "\nEmail: ";
        getline(cin, students[i].Email);
        cout << "\nSchool Program: ";
        getline(cin, students[i].Program);
        cout << "\nID Number: ";
        cin >> students[i].Identification;
        cout << "\nSocial Security Number: ";
        cin >> students[i].SSN;
        cin.ignore();
    }

    for (i = 1; i <= 3; i++) // For loop that iterates through each student and displays their information.
    {
        cout << "\n\n       Student " << i;
        cout << "\n----------------------";
        displayInfo(students[i]);
    }

    return 0;
}

void displayInfo(Student S) // Function that displays information of each student.
{
    cout << "\nName: " << S.Name.First << " " << S.Name.MiddleInitial << " " << S.Name.Last;
    cout << "\nEmail: " << S.Email;
    cout << "\nSchool Program: " << S.Program;
    cout << "\nID: " << S.Identification;
    cout << "\nSSN: " << S.SSN;
}