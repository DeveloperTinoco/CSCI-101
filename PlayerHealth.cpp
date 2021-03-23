/* 
   Purpose: Have a player spawn in with 100 health and allow the user to input damage values that will then proceed to remove the player health by the damage value that the user inputs
   until the player has 0 health left and dies. 
*/

#include <iostream>
using namespace std;

int main()
{
    double health = 100; // Sets the health for the player
    double damage = 0;   // Creates damage variable for user input
    bool isAlive = true; // Initializes flag that keeps track of player being alive vs being dead

    cout << "A player spawns with 100 health." << endl; // Player spawns in once, outside of the loop

    while (isAlive) // Begins flag controlled loop
    {
        cout << "Enter damage: "; // Asks user to input damage number
        cin >> damage;            // Sets the user input to the damage value
        health -= damage;         // Calculates how much health the player has left

        if (health <= 0) // Checks to see if player health is less than or equal to zero
        {
            cout << "The player is dead." << endl; // If player health is less than or equal to zero, the player is dead
            isAlive = false;                       // Since player is dead, flag variable bool value is flipped and we exit flag controlled loop
        }

        else                                                                                   // If player health is not less than or equal to 0, our program continues
            cout << "The player is still alive and has " << health << " health left." << endl; // Displays remaining player health to user
    }

    return 0;
}