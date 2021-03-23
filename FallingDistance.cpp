/* 
   Purpose: This program allows the user to input a total time, in seconds, that will then be put into a function to determine the distance that on object has fallen over that period of time, shown in 5 second intervals. 
*/

#include <iostream>
#include <math.h> // for the pow() function
using namespace std;

int t;                             // Creates "t" variable for time
double fallingDistance(int t = 0); // Initializes and declares the "fallingDistance" function

int main()
{
    int seconds = 0;    // Creates and sets "seconds" variable that will be changed by user to 0
    float distance = 0; // Creates and sets "distance" variable that will be manipulated by program to 0

    cout << "Enter the total time (in seconds) that the object was falling: "; // Asks user for total time input
    cin >> seconds;                                                            // Stores input into "seconds" variable

    cout << "\n \n"; // Lines 22-24 format the headers for labeling
    cout << "Time (Seconds)         Distance (Meters) \n";
    cout << "---------------------------------------- \n";

    for (int i = 0; i <= seconds; i += 5) // Creates a for loop that will increment by 5 second intervals
    {
        distance = fallingDistance(i);                              // Passes the value of seconds into the fallingDistance function
        cout << i << "                       " << distance << endl; // Displays the end results of the time and distance
    }

    return 0;
}

double fallingDistance(int t) // Allows for the function to be executed and defined by the main function
{
    float distance = 0;
    const double g = 9.8; // Creates and sets the constant value of gravity "g" to 9.8

    distance = (0.5 * g) * (pow(t, 2)); // Calculates the distance for the current amount of seconds
    return distance;                    // Returns the distance when the function is called
}