/* 
   Purpose: The purpose of this program is to recreate the board game Sorry!
*/

#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int diceRoll(); // Lines 13 - 17 declare functions.
int CheckLowest();
int CheckHighest();
bool newGame();
bool CheckWinner(int i);

string choice; // Lines 19 - 27 create global variables.
int diceTotal;
int highest;
int lowest;
int switcher;
int players;
int playerPos[5];
bool live = true;
bool win = false;

int main()
{
    srand(time(0));

    int winner;

    newGame(); // Begins a new game.

    do // Plays the game while boolean "live" is set to true.
    {
        int i = 1;

        for (i = 1; i <= players; i++)
        {
            cout << "\nIt is Player " << i << "'s turn. Press ENTER to roll."; // Allows player to press enter to roll their dice
            cin.ignore();

            diceRoll(); // Calls the "diceRoll" function to simulate randomly generated dice roll.

            switch (diceTotal) // Uses the "diceTotal" variable to select the proper case.
            {

            case 2: // Case 2 moves the player forwards 2 spaces if allowable.
            {
                if (playerPos[i] + 2 < 51)
                {
                    cout << "Move forwards 2 spaces!\n";
                    playerPos[i] += 2;

                    for (int j = 1; j <= players; j++) // Skips current player so they won't send themselves back to the beginning.
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0) // Checks if the current player landed on another player's spot.
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i])) // Checks to see if the current player has landed on the winning spot.
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 2 > 50) // Creates the condition of the player winning with an exact roll.
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 3:
            {
                if (playerPos[i] + 3 < 51)
                {
                    cout << "Move forwards 3 spaces!\n";
                    playerPos[i] += 3;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 3 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 4: // Case 4 moves the player backwards 1 space if allowable.
            {
                if (playerPos[i] - 1 > 0) // Checks to see if the current player is beyond position 0 already.
                {
                    cout << "Move backwards 1 space!\n";
                    playerPos[i] -= 1; // If player is beyond 0, they are taken back by one space.

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }
                }
                else if (playerPos[i] == 0) // Checks to see if the player is at 0, is so nothing occurs.
                {
                    cout << "You are already at position 0.\n";
                }
                break;
            }

            case 5:
            {
                if (playerPos[i] + 5 < 51)
                {
                    cout << "Move forwards 5 spaces!\n";
                    playerPos[i] += 5;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 5 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 6:
            {
                if (playerPos[i] + 6 < 51)
                {
                    cout << "Move forwards 6 spaces!\n";
                    playerPos[i] += 6;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 6 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 7: // Case 7 swaps the current player with the player in first place or nothing occurs if player is already in lead.
            {
                int save = playerPos[i]; // The variable "save" holds the position of the current player.
                CheckHighest();          // The "CheckHighest" function is called to see what is the current highest/furthers position.

                cout << "Swap places with player in first place. If you are in the lead, stay in the same space.\n";

                playerPos[i] = highest; // Lines 229 - 230 swaps the current player with the further player in terms of position.
                playerPos[switcher] = save;

                break;
            }

            case 8:
            {
                if (playerPos[i] + 8 < 51)
                {
                    cout << "Move forwards 8 spaces!\n";
                    playerPos[i] += 8;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 8 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 9:
            {
                if (playerPos[i] + 9 < 51)
                {
                    cout << "Move forwards 9 spaces!\n";
                    playerPos[i] += 9;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 9 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 10:
            {
                if (playerPos[i] + 10 < 51)
                {
                    cout << "Move forwards 10 spaces!\n";
                    playerPos[i] += 10;

                    for (int j = 1; j <= players; j++)
                    {
                        if (i == j)
                        {
                            continue;
                        }

                        else if (playerPos[i] == playerPos[j] && playerPos[j] != 0)
                        {
                            playerPos[j] = 0;
                            cout << "Player " << i << " landed on Player " << j << "'s spot and sends them back to the beginning!\n";
                        }
                    }

                    if (CheckWinner(playerPos[i]))
                    {
                        win = true;
                        winner = i;
                        break;
                    }
                }
                else if (playerPos[i] + 10 > 50)
                {
                    cout << "Passes winning space! Stay in the same position.\n";
                }

                break;
            }

            case 11: // Case 11 swaps the current player with the player in last place or nothing occurs if player is already last.
            {
                int save = playerPos[i]; // The variable "save" holds the current player's position.
                CheckLowest();           // Calls the "CheckLowest" function to see what is the lowest/last current position.

                cout << "Swap places with player in last place. If you are in last place, stay in the same place.\n";

                playerPos[i] = lowest; // Lines 350 - 351 swaps the current player with the player in last place in terms of position.
                playerPos[switcher] = save;

                break;
            }

            case 12: // Case 12 sends the current player back to position 0 if allowable.
            {
                if (playerPos[i] == 0) // If the current player is already at 0, nothing happens.
                {
                    cout << "You are already at position 0!\n";
                }
                else if (playerPos[i] != 0) // If the current player is already beyond 0, sends them back to position 0.
                {
                    cout << "Move back to the beginning of the board and start over!\n";
                }

                playerPos[i] = 0;

                break;
            }
            }

            if (win == true) // Checks to see if a player has won.
            {
                for (int i = 1; i <= players; i++)
                {
                    if (playerPos[i] == 50) // If a player has won, they are congratulated and asked to play again.
                    {
                        cout << "\nCongratulations Player " << i << "! You are the winner!\n\n";
                        cout << "The final positions were as follows: \n\n";
                        for (int i = 1; i <= players; i++)
                        {
                            cout << "Player " << i << ": position " << playerPos[i] << "\n\n";
                        }

                        cout << "Would you like to play again? Y/N ";
                        cin >> choice;
                    }
                }
            }

            if (choice == "N" || choice == "n") // Ends the game.
            {
                live = false;
                break;
            }
            else if (choice == "Y" || choice == "y") // Starts another game by calling the function "newGame".
            {
                newGame();
            }

            if (playerPos[i] == 50) // If a player has won and the players choose not to play another game, the game is exited.
            {
                break;
            }

            if (players == i && live == true) // Displays the position of each player between sets of dice rolls.
            {
                for (i = 1; i <= players; i++)
                {
                    cout << endl
                         << "Player " << i << " is at position " << playerPos[i] << endl;
                }
            }
        }
    } while (live);

    return 0;
}

int diceRoll() // The "diceRoll" function that generates random dice rolls for each player.
{
    int die1;
    int die2;
    int dice;

    die1 = (rand() % 6) + 1;
    die2 = (rand() % 6) + 1;
    dice = die1 + die2;

    cout << "Player rolled a " << die1 << " and a " << die2 << ", which is " << dice << "." << endl;

    return diceTotal = dice;
}

bool CheckWinner(int i) // The "CheckWinner" function that checks to see if the current player has won.
{
    return (i == 50);
}

int CheckHighest() // The "CheckHighest" function that checks to see what is the current highest/furthest position.
{
    int i;
    int largest = 0;
    int switchPlayer;

    for (i = 1; i <= players; i++)
    {
        if (largest < playerPos[i])
        {
            largest = playerPos[i];
        }
    }

    for (i = 1; i <= players; i++)
    {
        if (largest == playerPos[i])
        {
            switchPlayer = i;
        }
    }

    return highest = largest,
           switcher = switchPlayer;
}

int CheckLowest() // The "CheckLowest" function that checks to see what is the current lowest/last position.
{
    int i;
    int smallest = 100;
    int switchPlayer;

    for (i = 1; i <= players; i++)
    {
        if (smallest > playerPos[i])
        {
            smallest = playerPos[i];
        }
    }

    for (i = 1; i <= players; i++)
    {
        if (smallest == playerPos[i])
        {
            switchPlayer = i;
        }
    }

    return lowest = smallest,
           switcher = switchPlayer;
}

bool newGame() // The "newGame" function that resets the game and starts a new one.
{
    int i = 1;
    players = 0;
    choice = "";

    cout << "\n\nWelcome to Sorry! How many players (2-4) will be playing today? ";
    cin >> players;
    cin.ignore();

    if ((players < 2) || (players > 4))
    {
        do
        {
            cout << "\nYou can only have between 2-4 players!\n\n";
            cout << "How many players (2-4) will be playing today? ";
            cin >> players;
            cin.ignore();
        } while ((players < 2) || (players > 4));
    }

    for (i = 1; i <= players; i++)
    {
        playerPos[i] = 0;
    }

    return live = true,
           win = false;
}