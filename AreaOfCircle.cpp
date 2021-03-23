/* 
   Purpose: The purpose of this program is to allow the user to input the center point and another point of a circle which will then be used to calculate the radius, diameter, circumference and area of that circle. 
*/

#include <iostream>
#include <cmath>   // For pow() function
#include <iomanip> // For setprecision() function

using namespace std;

#define PI 3.1416 // Creates macro for the PI value of 3.1416
#define sq 2      // Creates macro for the sq value of 2

double calculateArea(double r);                                       // Initializes and declares the "area" function that takes 1 parameter
double calculateRadius(double x1, double x2, double y1, double y2);   // Initializes and declares the "radius" function that takes 4 parameters
double calculateDiameter(double x1, double x2, double y1, double y2); // Initializes and declares the "diameter" function that takes 4 parameters
double calculateCircumference(double r);                              // Initializes and declares the "circumference" function that takes 1 parameter

int main()
{
    double x1; // Creates the "x1" variable that takes the x value of the center point
    double x2; // Creates the "x2" variable that takes the x value of the second point
    double y1; // Creates the "y1" variable that takes the y value of the center point
    double y2; // Creates the "y2" variable that takes the y value of the second point

    cout << "Enter the x value of the center point of the circle: "; // Asks the user to input the x value of the center point
    cin >> x1;                                                       // Stores the user inputted value into the x1 variable
    cout << "Enter the y value of the center point of the circle: "; // Asks the user to input the y value of the center point
    cin >> y1;                                                       // Stores the user inputted value into the y1 variable

    cout << endl
         << "Enter the x value of another point on the circle: ";   // Asks the user to input the x value of the second point
    cin >> x2;                                                      // Stores the user inputted value into the x2 variable
    cout << "Enter the y value for the same point on the circle: "; // Asks the user to input the y value of the second point
    cin >> y2;                                                      // Stores the user inputted value into the y2 variable

    cout << endl
         << "Radius = " << fixed << setprecision(2) << calculateRadius(x1, x2, y1, y2) << endl; // Calls and displays the output of the "radius" function w/ the given parameters

    cout << "Diameter = " << calculateRadius(x1, x2, y1, y2) + calculateRadius(x1, x2, y1, y2) << endl; // Calls and displays the output of the "diameter" function w/ the given parameters

    cout << "Circumference = " << calculateCircumference(calculateRadius(x1, x2, y1, y2)) << endl; // Calls and displays the output of the "circumference" function w/ the given parameters

    cout << "Area = " << calculateArea(calculateRadius(x1, x2, y1, y2)) << endl; // Calls and displays the output of the "area" function w/ the given parameters

    return 0;
}

double calculateDiameter(double x1, double x2, double y1, double y2) // Allows the function to be executed and defined by the main function
{
    return sqrt(pow(x2 - x1, sq) + pow(y2 - y1, sq)); // Calculates the diameter of the circle given the center and a second point of a circle
}

double calculateRadius(double x1, double x2, double y1, double y2) // Allows the function to be executed and defined by the main function
{
    return calculateDiameter(x1, x2, y1, y2); // Calculates the radius of the circle given the center and a second point of a circle
}

double calculateCircumference(double r) // Allows the function to be executed and defined by the main function
{
    return sq * PI * r; // Calculates the circumference of the circle given the center and a second point of a circle
}

double calculateArea(double r) // Allows the function to be executed and defined by the main function
{
    return PI * pow(r, sq); // Calculates the area of the circle given the center and a second point of a circle
}
