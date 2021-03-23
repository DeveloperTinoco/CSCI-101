/* 
   Purpose: The purpose of this program is to take user input that is the data of the highest and lowest temperatures for each month and calculate the average highest temperature and lowest temperature and display these temperatures with the index value of where the lowest and highest overall temperature is stored.
*/

#include <iostream>
using namespace std;

const int MONTHS = 12; // Creates and sets constant variable "MONTHS" to 12

void getData(double[][2], int); // Lines 14-18 create the function prototypes
double averageHigh(double[][2], int);
double averageLow(double[][2], int);
int indexHighTemp(double[][2], int);
int indexLowTemp(double[][2], int);

int main()
{
    double temperatures[MONTHS][2]; // Creates "temperatures" variable with 2D array

    getData(temperatures, MONTHS); // Calls the "getData" function

    cout << "\n\n The average high temperature for the year is " << averageHigh(temperatures, MONTHS); // Lines 27-31 display the calculated data
    cout << "\n The average low temperature for the year is " << averageLow(temperatures, MONTHS);

    cout << "\n Index of highest temperature for the year is " << indexHighTemp(temperatures, MONTHS);
    cout << "\n Index of lowest temperature for the year is " << indexLowTemp(temperatures, MONTHS);

    return 0;
}

void getData(double t[][2], int m) // Allows "getData" to be defined and executed in main
{
    for (int i = 0; i < m; i++) // Starts an incremental loop
    {
        cout << "\nEnter the highest temperature for month " << (i + 1) << " : "; // Asks user for input that is then stored into an array
        cin >> t[i][0];

        cout << "Enter the lowest temperature for month " << (i + 1) << " : "; // Asks user for input that is then stored into an array
        cin >> t[i][1];
    }
}

double averageHigh(double t[][2], int m) // Allows "averageHigh" to be defined and executed in main
{
    double sum = 0; // Creates and sets "sum" variable to 0

    for (int i = 0; i < m; i++) // Loops through the highest temperatures and adds them all together
        sum += t[i][0];

    return (sum / m); // Returns the average of the highest temperatures
}

double averageLow(double t[][2], int m) // Allows "averageLow" to be defined and executed in main
{
    double sum = 0; // Creates and sets "sum" variable to 0

    for (int i = 0; i < m; i++) // Loops through the lowest temperatures and adds them all together
        sum += t[i][1];

    return (sum / m); // Returns the average of the lowest temperatures
}

int indexHighTemp(double t[][2], int m) // Allows "indexHighTemp" to be defined and executed in main
{
    int ind = 0;              // Creates and sets "ind" variable to 0
    double highest = t[0][0]; // Creates and sets "highest" variable to first element of the highest temperature row in array

    for (int i = 1; i < m; i++) // Loops through the array, comparing values to see which index holds highest value
        if (t[i][0] > highest)
        {
            highest = t[i][0]; // Sets "highest" to temperature value that is the highest
            ind = i;           // Sets "ind" to the value of the index that this highest value is stored in
        }

    return ind; // Returns the index value of the highest temperature
}

int indexLowTemp(double t[][2], int m) // Allows "indexLowTemp" to be defined and executed in main
{
    int ind = 0;             // Creates and sets "ind" variable to 0
    double lowest = t[0][1]; // Creates and sets "lowest" variable to first element of the lowest temperature row in array

    for (int i = 1; i < m; i++) // Loops through the array, comparing values to see which index holds lowest value
        if (t[i][1] < lowest)
        {
            lowest = t[i][1]; // Sets "lowest" to temperature value that is the lowest
            ind = i;          // Sets "ind" to the value of the index that this lowest value is stored in
        }

    return ind; // Returns the index value of lowest temperature
}