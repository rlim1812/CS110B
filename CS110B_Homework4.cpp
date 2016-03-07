/*
 Ryan Lim
 Professor Luttrell
 CS 110B
 2/20/2016
 Poker Hands:
 This program allows the user to enter
 poker hand values and determines what
 type of hand (high card, pair, two pair
 three of a kind, straight, full house,
 or four of a kind) the user has. The
 program will assume that there are no
 aces, face values, or suits
 */
#include <iostream>
using namespace std;

//function prototypes
bool  contains_pair(int hand[]);
bool  contains_two_pair(int hand[]);
bool  contains_three_of_a_kind(int hand[]);
bool  contains_straight(int hand[]);
bool  contains_full_house(int hand[]);
bool  contains_four_of_a_kind(int hand[]);

//declare magic number, 5, the number of cards in a hand
const int size_of_hand = 5;

int main ()
{
    //declare variables and array
    int temp;
    bool flag;
    int hand[size_of_hand];
    
    //output purpose of the program to user
    cout << "This program accepts 5 card values for a hand, then determines what type of hand it is\n";
    
    //use for loop to ask user for card values, then save card values in hand array
    for (int i = 0; i < size_of_hand; i++)
    {
        cout << "Enter a card value: ";
        cin >> hand[i];
        while (hand[i] < 2 || 9 < hand[i])
        {
            cout << "Error. Please enter a card value between 2 and 9: ";
            cin >> hand[i];
        }
    }
    
    //sort array from lowest to highest card values
    do
    {
        flag = true;
        for (int a = 0; a < size_of_hand; a++)
        {
            if (hand[a] > hand[a+1])
            {
                temp = hand[a];
                hand[a] = hand[a+1];
                hand[a+1] = temp;
                flag = false;
            }
        }
    }
    while (flag == false);
    
    //determine what type of hand the user has
    if (contains_four_of_a_kind(hand))
    {
        cout << "Your hand is a four of a kind hand\n";
    }
    else if (contains_full_house(hand))
    {
        cout << "Your hand is a full house hand\n";
    }
    else if (contains_straight(hand))
    {
        cout << "Your hand is a straight hand\n";
    }
    else if (contains_three_of_a_kind(hand))
    {
        cout << "Your hand is a three of a kind hand\n";
    }
    else if (contains_two_pair(hand))
    {
        cout << "Your hand is a two pair hand\n";
    }
    else if(contains_pair(hand))
    {
        cout << "Your hand is a pair hand\n";
    }
    else
    {
        cout << "Your hand is a high card hand\n";
    }
    return 0;
}

bool contains_pair(int hand[])
{
    int subscript,
    value,
    counter = 0;
    const int BINGO = 2;
    bool pair_or_not = false;
    
    //iterate through hand array and count the number of times each card value shows up in the hand
    for (int i = 0; i < size_of_hand; i++)
    {
        subscript = i;
        value = hand[subscript];
        
        while(hand[subscript] == value)
        {
            counter++;
            subscript++;
        }
        
        //if the number of times a card shows up is equal to 2, the hand is a pair hand
        if (counter == BINGO)
        {
            pair_or_not = true;
            break;
        }
        else
        {
            counter = 0;
        }
    }
    return pair_or_not;
}

bool contains_two_pair(int hand[])
{
    int subscript_1,
    subscript_2,
    value_1,
    value_2,
    counter_1 = 0,
    counter_2 = 0;
    bool two_pair_or_not = false;
    
    for (int i = 0; i < size_of_hand; i++)
    {
        subscript_1 = i;
        value_1 = hand[subscript_1];
        subscript_2 = i;
        //set value_2 equal to first element in array that is not equal to value_1
        while (hand[subscript_2] == value_1)
        {
            subscript_2++;
            if (subscript_2 == size_of_hand - 1)
            {
                break;
            }
        }
        value_2 = hand[subscript_2];
        
        //loop through array and count the number of times value_1 and value_2 show up
        for (;subscript_1 < size_of_hand; subscript_1++)
        {
            if (hand[subscript_1] == value_1)
            {
                counter_1++;
            }
        }
        for (;subscript_2 < size_of_hand; subscript_2++)
        {
            if (hand[subscript_2] == value_2)
            {
                counter_2++;
            }
        }
        
        //check to see if the hand is a full house hand
        if ((counter_1 == 2) && (counter_2 == 2))
        {
            two_pair_or_not = true;
            i = size_of_hand;
        }
        else
        {
            counter_1 = 0;
            counter_2 = 0;
        }
    }
    return two_pair_or_not;
}

bool contains_three_of_a_kind(int hand[])
{
    int subscript,
    value,
    counter = 0;
    const int BINGO = 3;
    bool three_of_a_kind_or_not = false;
    
    //iterate through hand array and count the number of times each card value shows up in the hand
    for (int i = 0; i < size_of_hand; i++)
    {
        subscript = i;
        value = hand[subscript];
        
        while(hand[subscript] == value)
        {
            counter++;
            subscript++;
        }
        
        //if the number of times a card shows up is equal to 3, the hand is a three of a kind hand
        if (counter == BINGO)
        {
            three_of_a_kind_or_not = true;
            break;
        }
        else
        {
            counter = 0;
        }
    }
    return three_of_a_kind_or_not;
}

bool contains_straight(int hand[])
{
    bool straight_or_not = true;
    
    for (int i = 0; i < size_of_hand - 1; i++)
    {
        if (hand[i] + 1 != hand[i+1])
        {
            straight_or_not = false;
            i = size_of_hand;
        }
    }
    return straight_or_not;
}

bool contains_full_house(int hand[])
{
    int subscript_1,
    subscript_2,
    value_1,
    value_2,
    counter_1 = 0,
    counter_2 = 0;
    bool full_house_or_not = false;
    
    for (int i = 0; i < size_of_hand; i++)
    {
        subscript_1 = i;
        value_1 = hand[subscript_1];
        subscript_2 = i;
        //set value_2 equal to first element in array that is not equal to value_1
        while (hand[subscript_2] == value_1)
        {
            subscript_2++;
            if (subscript_2 == size_of_hand - 1)
            {
                break;
            }
        }
        value_2 = hand[subscript_2];
        
        //loop through array and count the number of times value_1 and value_2 show up
        for (;subscript_1 < size_of_hand; subscript_1++)
        {
            if (hand[subscript_1] == value_1)
            {
                counter_1++;
            }
        }
        for (;subscript_2 < size_of_hand; subscript_2++)
        {
            if (hand[subscript_2] == value_2)
            {
                counter_2++;
            }
        }
        
        //check to see if the hand is a full house hand
        if ((counter_1 == 3 && counter_2 == 2) || (counter_1 == 2 && counter_2 == 3))
        {
            full_house_or_not = true;
            i = size_of_hand;
        }
        else
        {
            counter_1 = 0;
            counter_2 = 0;
        }
    }
    return full_house_or_not;
}

bool contains_four_of_a_kind(int hand[])
{
    int subscript,
    value,
    counter = 0;
    const int BINGO = 4;
    bool four_of_a_kind_or_not = false;
    
    //iterate through hand array and count the number of times each card value shows up in the hand
    for (int i = 0; i < size_of_hand; i++)
    {
        subscript = i;
        value = hand[subscript];
        
        while(hand[subscript] == value)
        {
            counter++;
            subscript++;
        }
        
        //if the number of times a card shows up is equal to 4, the hand is a four of a kind hand
        if (counter == BINGO)
        {
            four_of_a_kind_or_not = true;
            break;
        }
        else
        {
            counter = 0;
        }
    }
    return four_of_a_kind_or_not;
}

/*
 Sample Output:
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 4
 Enter a card value: 5
 Enter a card value: 6
 Enter a card value: 5
 Enter a card value: 6
 Your hand is a pair hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 2
 Enter a card value: 2
 Enter a card value: 3
 Enter a card value: 5
 Enter a card value: 6
 Your hand is a pair hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 2
 Enter a card value: 3
 Enter a card value: 2
 Enter a card value: 3
 Enter a card value: 4
 Your hand is a two pair hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 4
 Enter a card value: 5
 Enter a card value: 6
 Enter a card value: 4
 Enter a card value: 4
 Your hand is a three of a kind hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 5
 Enter a card value: 7
 Enter a card value: 6
 Enter a card value: 8
 Enter a card value: 9
 Your hand is a straight hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 4
 Enter a card value: 4
 Enter a card value: 5
 Enter a card value: 5
 Enter a card value: 4
 Your hand is a full house hand
 
 This program accepts 5 card values for a hand, then determines what type of hand it is
 Enter a card value: 3
 Enter a card value: 5
 Enter a card value: 3
 Enter a card value: 3
 Enter a card value: 3
 Your hand is a four of a kind hand
 */
