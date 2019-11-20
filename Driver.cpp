/*
 * Driver.cpp
 * HW 3: CSS 342
 * Last modified by Sambhavi Pandey on 5/19/2019
 *
 * This file contains a driver that tests functions in
 * order to ensure they are working properly. 
 */

#include "Child.h"
#include "List342.h"
#include <iostream>
using namespace std;

int main()
{
    //Testing the code provided in the driver
    Child c1 ("Angie", "Ham", 7), c2 ("Pradnya", "Dhala", 8),
    c3 ("Bill", "Vollmann", 13), c4 ("Cesar", "Ruiz", 6);
    Child c5 ("Piqi", "Tangi", 7), c6 ("Pete", "Rose", 13),
    c7 ("Hank", "Aaron", 3), c8 ("Madison", "Fife", 7);
    Child c9 ("Miles", "Davis", 65), c10 ("John", "Zorn",4), c11;
    List342 <Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
    
    //Testing insert function
    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);
    cout << "class1: " << class1 << endl;
    
    if (class1.Insert(&c1))
    {
        cout << "ERROR::: Duplicate" << endl;
    }
    
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);
    cout << "Class2: " << class2 << endl;
   
    //Testing merge function
    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);
    cout << "class1 and 2 Merged: " << class1 << endl;

    //Testing isEmpty function
    if (!class2.isEmpty())
    {
        cout << "ERROR:: Class2 should be empty empty" << endl;
    }
    
    //Testing remove function
    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);
    if (class1.Remove(c1, c11))
    {
        cout << "Removed from class1, student " << c11 << endl;
    }
    cout << "class1: " << class1 << endl;

    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    cout << "soccer: " << soccer << endl;
    
    //Testing += operator
    soccer += class1;
    cout << "soccer += class1 : " << soccer << endl;
    
    List342<Child> football;
    //Testing = operator
    football = soccer;
    //Testing == operator
    if (football == soccer)
    {
        cout << "football: " << football << endl;
    }

    //Testing Peek function
    if (football.Peek (c6, c11))
    {
        cout << c11 << " is on the football team" << endl;
    }
    
    //Testing DeleteList function
    soccer.DeleteList();
    //Testing isEmpty function
    if (!soccer.isEmpty())
    {
        cout << "ERROR: soccer should be empty" << endl;
    }
    
    List342 <int> numbers;
    //Testing insert function
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: " << numbers << endl;
    //Testing DeleteList function
    numbers.DeleteList();
    return 0;
    
    /*
     //I wrote this code to test the BuildList function
     string fileName;
     cout << "File name: ";
     cin >> fileName;
     List342<Child> kids;
     kids.BuildList(fileName);
    */
}
