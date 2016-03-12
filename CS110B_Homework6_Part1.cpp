/*
 Ryan Lim
 Professor Luttrell
 CS 110B
 3/12/2016
 Assignment #6:
 Pointer Tasks/The League with DMA
 */
#include <iostream>
using namespace std;

//function prototypes
void noNegatives (int *);
void swap(int *, int *);

int main()
{
    /*
     Program 1
     Pointer Practice
     */
    
    //declare variables
    int x,
        y;
    
    //declare pointer that points to variable x
    int *p1 = NULL;
    p1 = &x;
    
    //deference p1 in order to change value of variable x to 99
    *p1 = 99;
    
    //output value of the variable x
    cout << x << endl;
    cout << *p1 << endl;
    
    //re-direct p1 to point to variable y
    p1 = &y;
    *p1 = -300;
    
    //declare temporary variable and another pointer
    int temp,
    *p2 = NULL;
    p2 = &x;
    
    //swap values in p1 and p2
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    //call noNegatives function, passing x and y as arguments
    noNegatives(&x);
    noNegatives(&y);
    
    //use p2 to output values of x and y
    p2 = &x;
    cout << "x is: " << *p2 << endl;
    p2 = &y;
    cout << "y is: " << *p2 << endl;
    
    //declare an array to hold 2 int values
    const int SIZE = 2;
    int a[SIZE];
    
    //use p2 to initialize the values of array a
    p2 = &x;
    a[0] = *p2;
    p2 = &y;
    a[1] = *p2;
    
    //output the address of the first and second elements in the array
    cout << a << endl;
    cout << a + 1 << endl;
    
    //swap elements in the array using pointers p1 and p2
    p1 = &a[0];
    p2 = &a[1];
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    //output array elements
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Value " << i + 1 << " is: " << *(a + i) << endl;
    }
    
    swap(&x, &y);
    cout << "x is: " << x << endl;
    cout << "y is: " << y << endl;
    
    swap(&a[0], &a[1]);
    cout << "The first element of the array is now: " << *a << endl;
    cout << "The second element of the array is now: " << *(a + 1) << endl;
    //end of program 1
    return 0;
}

void noNegatives (int *x)
{
    if (*x < 0)
    {
        *x = 0;
    }
}

void swap (int *pointer1, int *pointer2)
{
    int temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

 /*
 Sample Output
 99
 99
 x is: 0
 y is: 99
 0x7976feedc6c0
 0x7976feedc6c4
 Value 1 is: 99
 Value 2 is: 0
 x is: 99
 y is: 0
 The first element of the array is now: 0
 The second element of the array is now: 99
 */