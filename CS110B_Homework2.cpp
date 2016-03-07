/*
Ryan Lim
Professor Luttrell
CS 110B
1/30/2016
Multi-player Blackjack Game
This program gives each player two cards that each
correspond to numerical values. Each player tries to
get the value of their hands as close to 21.If their 
hand's value is greater than 21, they automagically 
lose the game. If their hand's value is less than 21 
but greater than all of the other players' hand values,
they win the game. Otherwise if their hand's value is 
less than 21 but also less than at least one of the 
other players' hands, they lose the game. Finally, if 
multiple people have hand values that are tied for the 
highest score, the game ends in a tie.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function prototypes
int hand(int);
void who_won(int[],int);

int main()
{
    //seed random number generator
    srand(time(0));
    
    int num_players,
    result;
    
    cout << "This is a multi-player game of Blackjack.\n";
    cout << "How many people are playing the game? ";
    cin >> num_players;
    //input validation
    while (num_players <= 0)
    {
        cout << "Error. There must be at least one player. How many people are playing the game? ";
        cin >> num_players;
    }
    //declare array to hold players' hand values
    int hand_values[num_players];

    //use for loop to get hand value for each player
    for (int i = 0; i < num_players; i++)
    {
        result = hand(i+1);
        hand_values[i] = result;
    }
    //pass array of players' hand values to who_won function to determine who won the game
    who_won(hand_values,num_players);
    return 0;
}

int hand(int player_num)
{
    int random_num_1,
    random_num_2,
    random_num_poly,
    total = 0;
    //declare magic number as 21 for blackjack maximum value
    const int blackjack = 21;
    //declare char variable to determine if user should get more cards
    char yes_or_no;
    
    //generate random numbers
    random_num_1 = (rand() % 10) + 1;
    random_num_2 = (rand() % 10) + 1;
    total = random_num_1 + random_num_2;
    cout << "Player " <<player_num<< ",your first two cards are: " << random_num_1 <<" and "<< random_num_2;
    cout << "\nYour hand total is: " << total << endl;
    
    /*
     ask user if they want more cards, if yes then enter a loop that continues
     to add more cards to their hand until the user wins the game, loses the game,
     or tells the computer to stop
     */
    cout << "Do you want another card? (Enter y or n): ";
    cin >> yes_or_no;
    tolower(yes_or_no);
    //input validation
    while(yes_or_no != 'y' && yes_or_no != 'n')
    {
        cout << "Do you want another card? (Enter y or n): ";
        cin >> yes_or_no;
    }
    
    while(yes_or_no == 'y')
    {
        random_num_poly = (rand() % 10) + 1;
        cout << "Your next card is: " << random_num_poly << endl;
        total = total + random_num_poly;
        cout << "Your hand total is: " << total << endl;
        
        /*
         determine if player got 21 or lost the game (got over 21),
         or neither - if neither, then ask the player if they want another card
         */
        
        if (total == blackjack)
        {
            cout << "Player " << player_num << " got Blackjack!\n";
            return blackjack;
        }
        else if(total > blackjack)
        {
            cout << "Player " << player_num << " busted and lost the game!\n";
            return 0;
        }
        
        /*
         ask user if they want more cards, if yes then enter a loop that continues
         to add more cards to their hand until the user wins the game, loses the game,
         or tells the computer to stop
         */
        
        cout << "Would you like another card?(Enter y or n): ";
        cin >> yes_or_no;
        tolower(yes_or_no);
        while(yes_or_no != 'y' && yes_or_no != 'n')
        {
            cout << "Do you want another card? (Enter y or n): ";
            cin >> yes_or_no;
        }
    }
    return total;
}

void who_won(int values[], int amount_of_players)
{
    /*
     declare a variable called highest_value to determine who won the game
     and a counter to count the number of people with highest scores
     */
    int highest_value = values[0],
                      counter = 0;
    
    //king of the hill - determine which value is the highest
    for (int a = 1; a < amount_of_players; a++)
    {
        if (values[a] > highest_value)
        {
            highest_value = values[a];
        }
    }
    
    //check to see if nobody won
    if (highest_value == 0)
    {
        cout << "Nobody won!\n";
    }
    //loop through array again to see if there are any ties for highest value
    else
    {
        //count the number of people with the highest score
        for (int b = 0; b < amount_of_players; b++)
        {
            if (values[b] == highest_value)
            {
                counter++;
            }
        }
        //check if there is a tie or only one winner
        if(counter > 1)
        {
            cout << "The game ended in a tie!\n";
        }
        else
        {
            for (int b = 0; b < amount_of_players; b++)
            {
                if (values[b] == highest_value)
                {
                    cout << "Player " << b + 1 << " won the game!\n";
                }
            }
        }
        
    }
}
/*
 Sample Output:
 This is a multi-player game of Blackjack.
 How many people are playing the game? 3
 Player 1,your first two cards are: 7 and 4
 Your hand total is: 11
 Do you want another card? (Enter y or n): y
 Your next card is: 7
 Your hand total is: 18
 Would you like another card?(Enter y or n): n
 Player 2,your first two cards are: 3 and 4
 Your hand total is: 7
 Do you want another card? (Enter y or n): y
 Your next card is: 7
 Your hand total is: 14
 Would you like another card?(Enter y or n): y
 Your next card is: 2
 Your hand total is: 16
 Would you like another card?(Enter y or n): y
 Your next card is: 3
 Your hand total is: 19
 Would you like another card?(Enter y or n): n
 Player 3,your first two cards are: 10 and 4
 Your hand total is: 14
 Do you want another card? (Enter y or n): y
 Your next card is: 2
 Your hand total is: 16
 Would you like another card?(Enter y or n): y
 Your next card is: 2
 Your hand total is: 18
 Would you like another card?(Enter y or n): y
 Your next card is: 3
 Your hand total is: 21
 Player 3 got 21 and won the game!
 */
