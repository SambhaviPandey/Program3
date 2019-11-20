/*
 * Child.h
 * HW 3: CSS342
 *
 * Last modified by Sambhavi Pandey on 5/19/2019
 *
 * This file is a interface (.h file) that contains declarations
 * of the functions and variables that exist in the Child.cpp
 * file.
 */

//Header guards to prevent duplicate definitions
#ifndef child_h
#define child_h

#include <string>
#include <iostream>

using namespace std;

class Child
{
public:
    //Constructors
    Child();
    Child(string first, string last, int age);
    Child(const Child &childchildInformation);
    
    //Destructor
    ~Child();
    
    //Getter functions
    int getAge() const;
    string getFirstName() const;
    string getLastName() const;
    
    //Setter functions
    void setFirstName(string first);
    void setLastName(string last);
    void setAge (int age);
    
    //Overloading operators
    bool operator==(const Child &childInformation) const;
    bool operator!=(const Child &childInformation) const;
    
    bool operator>=(const Child &childInformation) const;
    bool operator<=(const Child &childInformation) const;
    
    bool operator<(const Child &childInformation) const;
    bool operator>(const Child &childInformation) const;
    
    friend ostream &operator<<(ostream &outStream,
                               const Child &childInformation);
    friend istream &operator>>(istream &inStream,
                               Child &childInformation);
    
private:
    //Declaring private variables
    string firstName;
    string lastName;
    int childAge;
};
#endif
