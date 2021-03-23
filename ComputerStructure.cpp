/* 
   Purpose: The purpose of this program is to allow user inputted data of a computer to be stored in a structure and then be displayed back to the user in an organized manner.
*/

#include <iostream>
#include <string>
using namespace std;

struct computerType // Creates structure for "computerType"
{
    string Manufacturer;
    string ModelType;
    string ProcessorType;
    int Ram_GB;
    int Storage_GB;
    int YearBuilt;
    double Price;

    computerType(string M, string MT, string PT, int R, int S, int Y, double P) // Creates "computerType" variable with parameters
    {
        Manufacturer = M;
        ModelType = MT;
        ProcessorType = PT;
        Ram_GB = R;
        Storage_GB = S;
        YearBuilt = Y;
        Price = P;
    }
};

void displayComputer(computerType); // Function prototype

int main()
{
    string Manufacturer; // Lines 37-43 create variables
    string ModelType;
    string ProcessorType;
    int Ram_GB;
    int Storage_GB;
    int YearBuilt;
    double Price;

    cout << "Enter the name of the manufacturer: "; // Lines 45-58 ask for user input and stores proper input into proper variables
    getline(cin, Manufacturer);
    cout << endl
         << "Enter the model of the computer: ";
    getline(cin, ModelType);
    cout << endl
         << "Enter the processor type: ";
    getline(cin, ProcessorType);
    cout << endl
         << "Enter the size of RAM (in GB): ";
    cin >> Ram_GB;
    cout << endl
         << "Enter the size of hard drive (in GB): ";
    cin >> Storage_GB;
    cout << endl
         << "Enter the year the computer was built: ";
    cin >> YearBuilt;
    cout << endl
         << "Enter the price: ";
    cin >> Price;

    computerType Computer(Manufacturer, ModelType, ProcessorType, Ram_GB, Storage_GB, YearBuilt, Price); // Passes info into computerType variable

    displayComputer(Computer); // Calls "displayComputer" function

    return 0;
}

void displayComputer(computerType C) // Allows main to execute "displayComputer" function
{
    cout << "\n\n           Computer Information\n" // Lines 69-77 display the information stored in the "computerType" structure
         << "-------------------------------------------\n";
    cout << "Manufacturer:                    " << C.Manufacturer << endl;
    cout << "Model Type:                      " << C.ModelType << endl;
    cout << "Processor Type:                  " << C.ProcessorType << endl;
    cout << "Ram (in GB):                     " << C.Ram_GB << endl;
    cout << "Storage (in GB):                 " << C.Storage_GB << endl;
    cout << "Year Built:                      " << C.YearBuilt << endl;
    cout << "Price:                           " << C.Price << endl;
}