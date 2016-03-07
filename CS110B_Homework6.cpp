/*
Ryan Lim
Professor Giambattista
CS 110A Homework 6
*/
#include <iostream>
#include <string>
using namespace std;

string getString();
string mergeString(string, string);
void outputString(string);
                  
int main ()
{
    //setting up variables
    string input1, input2, output;
    //call getString function and ask user for input
    input1 = getString();
    input2 = getString();
    //call mergeString function with both user inputs and then return merged string
    output = mergeString(input1, input2);
    //call outputString function and output merged string
    outputString(output);
    return 0;
}

string getString()
{
    string userInput;
    cout << "Enter a string: ";
    cin >> userInput;
    return userInput;
}

string mergeString(string firstString, string secondString)
{
    //setting up variables
    double string1length = firstString.length(),
           string2length = secondString.length();
    string merger = " ", concactenation = " ";
    
    //check if firstString is equal to, less than, or greater than secondString
    if (string1length == string2length)
     {
         for (int a = 0; a < string1length; a++)
           {
               concactenation = firstString[a];
               concactenation += secondString[a];
               merger += concactenation;
           }
     }
    else if (string1length > string2length)
       {
           for (int b = 0; b < string2length; b++)
             {
                 concactenation = firstString[b];
                 concactenation += secondString[b];
                 merger += concactenation;
             }
           for (int c = string2length; c < string1length; c++)
             {
                 merger += firstString[c];
             }
       }
    else if (string1length < string2length)
       {
           for (int d = 0; d < string1length; d++)
             {
                 concactenation = firstString[d];
                 concactenation += secondString[d];
                 merger += concactenation;
             }
           for (int e = string1length; e < string2length; e++)
             {
                 merger += secondString[e];
             }
       }
    //return merged string
    return merger;
}

void outputString(string Output)
{
    cout << "Merged Output:";
    for (int f = 0; f < Output.length(); f++)
      {
          cout << Output[f];
      }
    cout << endl;
}