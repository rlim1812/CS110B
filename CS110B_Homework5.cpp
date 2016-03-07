/*
 Ryan Lim
 Professor Luttrell
 CS 110B
 2/27/2016
 Assignment: The League
 */
#include <iostream>
using namespace std;

//function prototypes
void initialize_arrays(string[], int[], int);
void sort_data(string[], int[], int);
void display_data(string[], int[], int);

int main()
{
    //declare arrays to hold team names and amount of wins
    const int SIZE = 5;
    string team_names[SIZE];
    int team_wins[SIZE];
    
    //call function to initialize arrays
    initialize_arrays(team_names, team_wins, SIZE);
    
    //call function to sort arrays
    sort_data(team_names, team_wins, SIZE);
    
    //call function to output array information
    display_data(team_names, team_wins, SIZE);
    return 0;
}

void initialize_arrays(string teams[], int wins[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << "Enter team name #" << i+1 << ": ";
        cin >> teams[i];
        cout << "Enter amount of wins for team #" << i+1 << ": ";
        cin >> wins[i];
    }
}

void sort_data(string teams[], int wins[], int array_size)
{
    string string_temp;
    int int_temp;
    bool swapped;
    
    do
    {
        swapped = false;
        for (int c = 0; c < array_size - 1; c++)
        {
            if (wins[c] < wins[c+1])
            {
                //sort integer array
                int_temp = wins[c];
                wins[c] = wins[c+1];
                wins[c+1] = int_temp;
                
                //sort string array
                string_temp = teams[c];
                teams[c] = teams[c+1];
                teams[c+1] = string_temp;
                
                //set flag variable to true
                swapped = true;
            }
        }
    }
    while (swapped == true);
}

void display_data (string teams[], int wins[], int array_size)
{
    cout << "\nLeague Standings:\n";
    for (int d = 0; d < array_size; d++)
    {
        cout << teams[d] << ": " << wins[d] << endl;
    }
    cout << endl;
}

/*
 Sample Output
 Enter team name #1: Dodgers
 Enter amount of wins for team #1: 92
 Enter team name #2: Padres
 Enter amount of wins for team #2: 74
 Enter team name #3: Diamondbacks
 Enter amount of wins for team #3: 79
 Enter team name #4: Rockies
 Enter amount of wins for team #4: 68
 Enter team name #5: Giants
 Enter amount of wins for team #5: 84
 
 League Standings:
 Dodgers: 92
 Giants: 84
 Diamondbacks: 79
 Padres: 74
 Rockies: 68
 */