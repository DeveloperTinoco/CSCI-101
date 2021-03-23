/* Program Name: distance.cpp 
   Author: Esteban Tinoco
   Last Date Updated: 10/03/2020
   Purpose: This program allows a user to input the speed of a vehicle and how many hours it has traveled, which then will be used to show the user how much distance the car has traveled for each hour that it has been travelling.
*/

#include <iostream>
using namespace std;

int main()
{
    int speed, traveled_hours, distance = 0; // Creates and sets the speed, distance and traveled_hours variables to 0

    cout << "How fast is the vehicle moving? "; // Asks the user to input a speed for the vehicle

    while (!(cin >> speed) || (speed < 0)) // Creates the event controlled loop that validates input from the user
    {
        cout << "Speed input must be greater than 0!" << endl; // Tells user that the speed of the vehicle can not be negative
        cin.clear();                                           // Clears the input stream so that future inputs are properly read
        cin.ignore(100, '\n');                                 // Skips to next line (skips up to 100 characters from the user input)
    }

    cout << "For how many hours has this vehicle been traveling? "; // Asks the user to input the number of hours the vehicle has been travelling

    while (!(cin >> traveled_hours) || (traveled_hours < 1)) // Creates the event controlled loop that validates input from the user
    {
        cout << "Hours traveled must be more than 1!" << endl; // Tells user that hours traveled must be more than 1
        cin.clear();                                           // Clears the input stream so that future inputs are properly read
        cin.ignore(100, '\n');                                 // Skips to next line (skips up to 100 characters from the user input)
    }

    cout << "Hour  Traveled Distance" << endl; // Lines 34-35 label the following data output.
    cout << "-----------------------" << endl;

    for (int i = 0; i < traveled_hours; i++) // Creates a for loop that sets i to 0 and increments i until it equals the hours traveled
    {
        distance += speed;                                     // Sets the distance equal to the speed and for every loop, it adds the speed to it again
        cout << "   " << (i + 1) << "   " << distance << endl; // Shows the user the hour and the distance in relation to how far the vehicle has moved every hour
    }

    return 0;
}