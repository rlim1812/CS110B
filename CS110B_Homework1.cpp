/*
Ryan Lim
CS 110B 
Homework Assignment #1
This program outputs as many asterisks as the user wants
1/26/2016
*/
#include <iostream>
using namespace std;

int main()
{
    //declare variable to hold the number of asterisks the user wants to output
    int user_input;
    char yes_or_no = 'y';
    
    while(yes_or_no != 'n')
    {
        //ask the user to input the number of asterisks they want to output
        cout << "How many asterisks? ";
        cin >> user_input;
        
        //use for loop to output number of asterisks equal to the number the user input
        for (int i = 1; i <= user_input; i++)
        {
            cout << "*";
        }
        cout << "\n";
        
        //ask user if they want to output more asterisks
        cout << "Go again? ";
        cin >> yes_or_no;
    }
    return 0;
}
/*
Sample output: 
How many asterisks? 10
**********
Go again? y
How many asterisks? 15
***************
Go again? n
*/