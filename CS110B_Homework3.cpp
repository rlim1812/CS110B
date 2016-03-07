/*
Ryan Lim
Professor Luttrell
CS 110B
2/5/2016
This program is a number guessing game.
The program asks the user to pick a number
between 1 and 100 and keep it a secret. The
computer will then proceed to keep guessing
values until the computer's value matches the
user's value. At that point, the game will end.
The game will repeat as many times as the user wants.
*/
#include <iostream>
using namespace std;

//function prototypes
void playOneGame();
bool shouldPlayAgain();
int getMidpoint(int, int);
char getUserResponseToGuess(int);

int main()
{
    //this loop contains all of the different parts of the program, which are broken up into functions
    do
    {
        playOneGame();
    }
    while(shouldPlayAgain());
    return 0;
}

void playOneGame()
{
    int lowerLimit,
    upperLimit,
    midpoint;
    char userResponse;
    
    //set up initial values of lowerLimit, upperLimit, and midpoint variables then guess the user's number
    lowerLimit = 1;
    upperLimit = 100;
    midpoint = getMidpoint(lowerLimit, upperLimit);
    userResponse = getUserResponseToGuess(midpoint);
    
    //set up a loop that continues to guess numbers until the user's number is found
    while (userResponse != 'c' && userResponse != 'C')
    {
        if (userResponse == 'l' || userResponse == 'L' )
        {
            upperLimit = midpoint - 1;
            midpoint = getMidpoint(lowerLimit, upperLimit);
        }
        else if (userResponse == 'h' || userResponse == 'H')
        {
            lowerLimit = midpoint + 1;
            midpoint = getMidpoint(lowerLimit, upperLimit);
        }
        
        //if there are only two values left, ask user if either the lower or higher value is their number
        if ((upperLimit - lowerLimit) == 1)
        {
            cout << "Is " << lowerLimit << " your number? (Enter y or n): ";
            cin >> userResponse;
            //input validation
            while(userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N')
            {
                cout << "Error. Is " << lowerLimit << " your number? (Enter y or n): ";
                cin >> userResponse;
            }
            
            if (userResponse == 'y' || userResponse == 'Y')
            {
                return;
            }
            else
            {
                cout << "Your number is: " << upperLimit << endl;
                return;
            }
            
        }
        
        userResponse = getUserResponseToGuess(midpoint);
    }
    
}

int getMidpoint(int low, int high)
{
    int mid = (low + high)/2;
    return mid;
}

char getUserResponseToGuess (int guess)
{
    char userInput;
    
    cout << "Is " << guess << " your number?\n";
    cout << "Enter l if your number is lower, h if your number is higher, or c if the guess is correct: ";
    cin >> userInput;
    //input validation
    while (userInput != 'l' && userInput != 'L' && userInput != 'h' && userInput != 'H' && userInput != 'c' && userInput != 'C')
    {
        cout << "Error. Enter l if your number is lower, h if your number is higher, or c if the guess is correct: ";
        cin >> userInput;
    }
    return userInput;
}

bool shouldPlayAgain()
{
    char yesOrNo;
    
    cout << "Would you like to play again? Enter(y or n): ";
    cin >> yesOrNo;
    //input validation
    while (yesOrNo != 'Y' && yesOrNo != 'N'  && yesOrNo != 'y'  &&  yesOrNo != 'n')
    {
        cout << "Error. Would you like to play again? Enter(y or n): ";
        cin >> yesOrNo;
    }
    
    if (yesOrNo == 'Y' || yesOrNo == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 Sample Output
 Is 50 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: l
 Is 25 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: l
 Is 12 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: h
 Is 18 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: l
 Is 15 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: c
 Would you like to play again? Enter(y or n): y
 Is 50 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: h
 Is 75 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: l
 Is 62 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: h
 Is 68 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: h
 Is 71 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: h
 Is 73 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: l
 Is 72 your number?
 Enter l if your number is lower, h if your number is higher, or c if the guess is correct: c
 Would you like to play again? Enter(y or n):
 */

