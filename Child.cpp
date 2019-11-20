/*
 * Child.cpp
 * HW 3: CSS342
 *
 * Last modified by Sambhavi Pandey on 5/19/2019
 *
 * The purpose of the code in this file is to implement
 * the interface that was defined in child.h.
 */

#include "Child.h"
#include <iostream>
using namespace std;

/*
 * Constructor does not take any parameters. The purpose of this
 * constructor is to intialize the first name, last name, and the age.
 */
Child :: Child()
{
    setFirstName("");
    setLastName("");
    setAge(-1);
}

/*
 * This constructor takes in two strings, corresponding to the child's
 * first and last name and one int corresponding to the child's age.
 * The purpose of this constructor is to initialize the variables.
 */
Child :: Child(string first, string last, int age)
{
    setFirstName(first);
    setLastName(last);
    setAge(age);
}

/*
 * This constructor has a function parameter that is a reference.
 * The purpose of this constructor is to initialize lastName,
 * firstName, and childAge variables.
 */
Child :: Child(const Child &childInformation)
{
    setFirstName(childInformation.firstName);
    setLastName(childInformation.lastName);
    setAge(childInformation.childAge);
}

//Destructor does not take any parameters and is empty.
Child :: ~Child()
{
    
}

/*
 * getFirstName function returns the first name of the child
 * as a string. It does not take any parameters.
 */
string Child :: getFirstName() const
{
    return firstName;
}

/*
 * getLastName function returns the last name of the child
 * as a string. It does not take any parameters.
 */
string Child :: getLastName() const
{
    return lastName;
}

/*
 * getAge function returns the age of the child
 * as an int. It does not take any parameters.
 */
int Child :: getAge() const
{
    return childAge;
}

/*
 * setFirstName function sets the first name
 * of the child. It takes in a string parameter
 * that corresponds to the child's first name. It
 * does not return anything.
 */
void Child :: setFirstName(string first)
{
    firstName = first;
}

/*
 * setLastName function sets the last name
 * of the child. It takes in a string parameter
 * that corresponds to the child's last name. It does
 * not return anything.
 */
void Child :: setLastName(string last)
{
    lastName = last;
}

/*
 * setAge function sets the age of the child.
 * It takes in a int parameter that corresponds to
 * the child's age. It does not return anything.
 */
void Child :: setAge (int age)
{
    childAge = age;
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator >= (const Child &childInformation) const
{
    return!(*this < childInformation);
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator <= (const Child &childInformation) const
{
    return!(*this > childInformation);
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator < (const Child &childInformation) const
{
    //Determines if last name < last name passed by reference
    if (lastName < childInformation.lastName)
    {
        return true;
    }
    //If information is equal to the information passed by reference
    else if (lastName == childInformation.lastName)
    {
        if (firstName == childInformation.firstName)
        {
            //If age is less than child age passed by reference
            if (childAge < childInformation.childAge)
            {
                return true;
            }
        }
        //If first name is less than first name passed by reference
        else if (firstName < childInformation.firstName)
        {
            return true;
        }
    }
    return false;
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator > (const Child &childInformation) const
{
     //Determines if last name > last name passed by reference
    if (lastName > childInformation.lastName)
    {
        return true;
    }
    //If information is equal to the information passed by reference
    else if (lastName == childInformation.lastName)
    {
        if (firstName == childInformation.firstName)
        {
            //If age is greater than child age passed by reference
            if (childAge > childInformation.childAge)
            {
                return true;
            }
        }
        //If first name is greater than first name passed by reference
        else if (firstName > childInformation.firstName)
        {
            return true;
        }
    }
    return false;
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator == (const Child &childInformation) const
{
    return (childInformation.getAge() == getAge() &&
            childInformation.getFirstName() == getFirstName() &&
            childInformation.getLastName() == getLastName());
}

/*
 * Boolean function takes in a reference corresponding to
 * the information about the child and returns either true
 * or false.
 */
bool Child :: operator != (const Child &childInformation) const
{
    return!(*this == childInformation);
}

/*
 * Function takes in two references, one corresponding to the information
 * about the child and one corresponding to ostream. The purpose of this
 * function is to print the child's first name, last name, and age to
 * the screen.
 */
ostream &operator << (ostream &outStream, const Child &childInformation)
{
    return outStream << childInformation.getFirstName()
            << childInformation.getLastName()
            << childInformation.getAge();
}

/*
 * Function takes in two references, one corresponding to the information
 * about the child and one corresponding to instream. The purpose of this
 * function is to take in information about the child's first name,
*  last name, and age.
 */
istream &operator >> (istream &inStream, Child &childInformation)
{
    inStream >> childInformation.firstName >>
    childInformation.lastName >>
    childInformation.childAge;
    return inStream;
}
