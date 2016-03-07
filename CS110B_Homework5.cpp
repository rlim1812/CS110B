/*
Ryan Lim
CS 110A
Professor Giambattista
11.10.2015
*/

#include <iostream>
using namespace std;

void initializerFunction ();
void processFunction (int[], int);
void finalFunction (int[], int);

int main()
{
    //output program purpose
    cout << "This program accepts 10 integers,and outputs a list of values\n";
    cout << "that does not include duplicates of original values.\n";
    
    //call first function
    initializerFunction();
}

void initializerFunction()
{
    const int size = 10;
    int Array[size],
          freestyle;
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value: ";
        cin >> freestyle;
        Array[i] = freestyle;
    }
    processFunction(Array, size);
}

void processFunction(int pseudoFunction[], int num)
{
    int count = 0;
    
    //go through array, and remove duplicates of values
    for (int x = 0; x < num; x++)
    {
        int baseCase = pseudoFunction[x];
        for (int xyz = x + 1; xyz <= num; xyz++)
        {
            if(xyz == num)
            {
                break;
            }
            else if(pseudoFunction[xyz] == baseCase)
            {
                pseudoFunction[xyz] = -1;
            }
        }
    }
    
    for (int hello = 0; hello < num; hello++)
    {
        if (pseudoFunction[hello] != -1)
        {
            count++;
        }
    }
    
    int finalArray[count];
    for (int daBomb = 0; daBomb < count; daBomb++)
    {
        for (int helloWorld = 0; helloWorld < num; helloWorld++)
          {
            if (pseudoFunction[helloWorld] != - 1)
            {
                finalArray[daBomb] = pseudoFunction[helloWorld];
                pseudoFunction[helloWorld] = - 1;
                break;
            }
          }
    }
    finalFunction(finalArray, count);
}

void finalFunction(int outputArray[], int outputArraySize)
{
    cout << "Here is the list of the values with duplicates removed:";
    for (int Yoshi = 0; Yoshi < outputArraySize; Yoshi++)
    {
        cout << " ";
        cout << outputArray[Yoshi];
    }
    cout << "\n";
}