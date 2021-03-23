/* 
   Purpose: The purpose of this program is to allow the user to input two numbers and a function will add these two numbers together and display it to the user.
 */

#include <iostream>
using namespace std;

int Addition(int A, int B); // This initializes and declares the function "Addition" with the two parameters "A" and "B".

int main()
{
    int number_1; // Stores first number.
    int number_2; // Stores second number.
    int add;      // Stores the "addition."

    cout << "Enter first number: ";  // Asks user for first number.
    cin >> number_1;                 // Stores user input into "number_1" variable.
    cout << "Enter second number: "; // Asks user for second number.
    cin >> number_2;                 // Stores user input into "number_2" variable.

    add = Addition(number_1, number_2); // Calls the function and passes the two user inputted numbers into the Addition() function

    cout << "The two numbers added together is: " << add << endl; // Displays the "Addition" value.

    return 0;
}

int Addition(int A, int B) // Allows the Addition function to be defined and executed within the main function.
{
    return (A + B);
}