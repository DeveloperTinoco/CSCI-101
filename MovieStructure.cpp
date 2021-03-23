/* 
   Purpose: The purpose of this program is to create a structure and store user inputted data about a movie that will then be displayed back to the user.
*/

#include <iostream>
#include <string>
using namespace std;

struct MovieData // Creates structure for "MovieData"
{
    string Title;
    string Genre;
    string Director;
    int YrReleased;
    int RunningTime;

    MovieData(string T, string G, string D, int YR, int RT) // Creates "MovieData" variable with parameters
    {
        Title = T;
        Genre = G;
        Director = D;
        YrReleased = YR;
        RunningTime = RT;
    }
};

void displayMovie(MovieData); // Function prototype

int main()
{
    string Title; // Creates 'Title', 'Genre', 'Director', 'YrReleased' & 'RunningTime' variables
    string Genre;
    string Director;
    int YrReleased;
    int RunningTime;

    cout << "\nEnter the title of the movie: "; // Call for user input and stores the proper information into the proper variables
    getline(cin, Title);                        
    cout << "\nEnter the genre of the movie: ";
    getline(cin, Genre);
    cout << "\nEnter the director's name of the movie: ";
    getline(cin, Director);
    cout << "\nEnter the release year of the movie: ";
    cin >> YrReleased;
    cout << "\nEnter the running time, in minutes, of the movie: ";
    cin >> RunningTime;

    MovieData Movie(Title, Genre, Director, YrReleased, RunningTime); // Passes information into 'MovieData' variable

    displayMovie(Movie); // Calls displayMovie() function and passes the "Movie" variable into it w/ the given parameters

    return 0;
}

void displayMovie(MovieData M) // Allows main to execute displayMovie() function
{
    cout << "\n\n       Movie information\n"         // Displays the information from the "MovieData" structure
         << "-----------------------------------\n"; 
    cout << "Title:                  " << M.Title << endl;
    cout << "Genre:                  " << M.Genre << endl;
    cout << "Director:               " << M.Director << endl;
    cout << "Year Released:          " << M.YrReleased << endl;
    cout << "Running Time (Minutes): " << M.RunningTime << endl;
}