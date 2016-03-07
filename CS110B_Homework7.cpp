/*
 Ryan Lim (Product Engineer)
 Fiona Gallagher (Quality Assurance Engineer)
 Professor Giambattista
 CS 110A
 Homework 7
 12/9/2016
 */
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

//function prototypes
void input();
void process(string);
void output(bool, string);

int main()
{
    //create filestream object
    ifstream inputFile;
    //attempt to open palindromes.text file
    inputFile.open("palindromes.text");
    //initial to check to see if palindromes.text is open
    if (inputFile)
    {
        //close palindromes.text and then call input function
        inputFile.close();
        input();
    }
    else //if the file did not open, output error message
    {
        cout << "Error. The file did not open\n";
    }
}

void input()
{
    //reopen palindromes.text
    string inputString;
    ifstream pull;
    pull.open("palindromes.text");
    while (getline (pull, inputString))
    {
        process(inputString);
    }
}

void process(string processString)
{
    //set initial flag value to 0
    bool flag = true;
    const int length = processString.length();
    int incrementer = 0,
        decrementer = length - 1;
    
    string lowerCaseVersionString;
    for (int i = 0; i < length; i++)
    {
        lowerCaseVersionString[i] = tolower(processString[i]);
    }
    while (incrementer < decrementer)
    {
        //if there is a blank space, increment or decrement to next value
        while (lowerCaseVersionString[incrementer] == ' ')
        {
            incrementer++;
        }
        while (lowerCaseVersionString[decrementer] == ' ')
        {
            decrementer--;
        }
        //if the two characters are not equal, set flag to false to signify that the string is not a palindrome
        if (lowerCaseVersionString[incrementer] != lowerCaseVersionString[decrementer])
        {
            flag = false;
            incrementer = decrementer;
        }
    }
    output(flag, processString);
}

void output(bool TrueOrFalse, string outputString)
{
    if (TrueOrFalse)
    {
        cout << "\"" << outputString << " is a palindrome\"" << endl;
    }
    else
    {
        cout << "\"" << outputString << " is not a palindrome\"" << endl;
    }
}
