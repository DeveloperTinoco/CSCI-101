/* 
   Purpose: Have the user input their weight in pounds and their height in inches in order to find their BMI 
   and display it to them as well as let the user know if they are indicated to be underweight, optimal weight or overweight.
*/

#include <iostream>

using namespace std;

int main()
{
    float weight, height, top, bottom, bmi; // Creates the variables that will be used to calculate the bmi

    cout << "Enter your weight in pounds: " << endl; // Asks the user to input their height and weight
    cin >> weight;
    cout << "Enter your height in inches: " << endl;
    cin >> height;

    top = weight * 703; // Uses the "top" and "bottom" variables to implement math in a cleaner manner as the result was not coming out as expected with just the variables
    bottom = height * height;

    bmi = top / bottom; // Calculates the individual's bmi

    // Checks to see the user's bmi in relation to what is considered underweight, optimal or overweight
    if (bmi < 18.5)
        cout << "Your body mass index is " << bmi << " which is less than 18.5, an indication of being underweight." << endl;

    else if (bmi >= 18.5 && bmi <= 25)
        cout << "Your body mass index is " << bmi << " which is in between 18.5 and 25, an indication of having optimal weight." << endl;

    else
        cout << "Your body mass index is " << bmi << " which is more than 25, an indication of being overweight." << endl;

    return 0;
}