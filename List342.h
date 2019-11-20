/*
 * List342.h
 * HW 3: CSS342
 *
 * Last modified by Sambhavi Pandey on 5/19/2019
 *
 * This file is a interface (.h file) that contains declarations
 * of the functions and variables that exist in the List342.cpp
 * file. This file also includes the List.cpp part of the file
 * end of the declarations. This is done so that it is easier to factor
 * the code into files that can be tested regardless of the different
 * IDEs used to test it.
 */

//header guards to prevent duplicate definitions
#ifndef list342_h
#define list342_h

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Forward declarations
template <class ItemType> class List342;
template <class ItemType> ostream& operator <<
(ostream &outStream, const List342<ItemType> &source);

template <class ItemType>
class List342
{
public:
    //Constructors
    List342();
    List342(const List342 &list);
    
    //Destructor
    ~List342();
    
    //Public functions
    bool BuildList(string fileName);
    bool Insert(ItemType *obj);
    bool Remove(ItemType target, ItemType &result);
    bool Peek(ItemType target, ItemType &result) const;
    bool isEmpty() const;
    void DeleteList();
    bool Merge(List342 &list1);
    
    //Operator overloading
    friend ostream& operator<< <>
    (ostream &outStream, const List342<ItemType> &information);
    
    List342<ItemType>& operator+=(const List342<ItemType> &list);
    List342<ItemType> operator+(const List342<ItemType> &list) const;
    
    bool operator==(const List342 <ItemType> &list) const;
    bool operator!=(const List342 <ItemType> &list) const;
    List342 &operator=(const List342 &list);
    
private:
    //Private struct
    struct Node
    {
        ItemType *data;
        Node *next = NULL;
    };
    Node *head;
};
#endif

//Starting the implementation of the above declarations
#include <iostream>

//Constructor to initialize head to null
template <class ItemType>
List342<ItemType>::List342()
{
    head = NULL;
}

/*
 * This function takes in a reference of type List342.
 * The purpose of this constructor is to initialize head to
 * null and initialize *this to list.
 */
template <class ItemType>
List342<ItemType>::List342(const List342 &list)
{
    head = NULL;
    *this = list;
}

/*
 * BuildList function takes in a string that corresponds to the name
 * of the file that is meant to be read in. The purpose of this
 * constructor is to open the file, read from the file, and insert
 * the elements of the file to build a list. This function returns a
 * boolean value.
 */
template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
    //Create a temp variable
    ItemType temp;
    
    //Opening the file
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        //Checks if state of the stream is good
        while (inFile.good())
        {
            //Reads in the elements from file
            inFile >> temp;
            //Until end of the file is reached
            if (!inFile.eof())
            {
                //Inserts elements into temp variable
                Insert(&temp);
                //Uncomment this to print the results
                //of the inserted variables
                //cout << "Inserted: " << temp << endl;
            }
        }
    }
    //Otherwise, the file cannot be opened
    else
    {
        cout << "File: " << fileName << " could not be opened" << endl;
        return false;
    }
    //Closing the file
    inFile.close();
    return true;
}

/*
 * Insert function takes in a pointer of ItemType. The purpose of
 * this function is to insert an object in a list. This function
 * returns true or false depending on whether the insert was succesful.
 * It removes duplicates and returns a boolean value.
 */
template <class ItemType>
bool List342<ItemType>::Insert(ItemType *obj)
{
    //Declaring pointer variables
    Node *tempNode = new Node;
    Node *frontNode;
    Node *previousNode;
    
    //If the pointer is null
    if (obj == NULL)
    {
        return false;
    }
    
    //If the head is null and the obj pointer is equal to head pointer
    if (head != NULL && *obj == *head->data)
    {
        return false;
    }
    tempNode->next = NULL;
    tempNode->data = new ItemType(*obj);
    
    //If the head is null
    if (head == NULL)
    {
        //Setting the position
        tempNode->next = head;
        head = tempNode;
        //Setting to null
        tempNode = NULL;
        return true;
    }
    
    //If the data at the pointer is less than the data at the head
    if (*tempNode->data < *head->data)
    {
        //Setting the position
        tempNode->next = head;
        head = tempNode;
        //Setting to null
        tempNode = NULL;
        return true;
    }
    //Setting the position
    frontNode = head->next;
    previousNode = head;
    
    //While the front is not equal to null and the data is less than
    //or equal to than the data that the temp node points to
    while (frontNode != NULL && *frontNode-> data <= *tempNode->data)
    {
        previousNode = frontNode;
        frontNode = frontNode->next;
    }
    
    //Checks if there are duplicates
    if (*previousNode->data == *tempNode->data)
    {
        //Deletes duplicates
        delete tempNode;
        tempNode = NULL;
        return false;
    }
    //Setting the position
    tempNode->next = frontNode;
    previousNode->next  = tempNode;
    //Setting them all to null
    frontNode = NULL;
    previousNode = NULL;
    tempNode = NULL;
    return true;
}

/*
 * Remove function has two parameters of ItemType and one of the
 * parameters is a reference. This function returns a value of
 * type boolean. The purpose of this function is to remove the
 * target item from the list and return the item using the
 * second parameter that is passed by reference. If the item is
 * found and removed, it returns true. Otherwise, it returns false.
 */
template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType &result)
{
    //Declares a pointer variable of type Node
    Node *currentNode;
    //If the list is empty
    if (isEmpty())
    {
        return false;
    }
    //If the data that head is pointing to is the target
    if (*head->data == target)
    {
        //Sets current node to head
        currentNode = head;
        //Sets head to the next node
        head = head->next;
        result = *currentNode->data;
        //Deletes currentNode and sets to null
        delete currentNode;
        currentNode = NULL;
        return true;
    }
    //Declares a pointer variable of type Node and sets to head
    Node *previousNode = head;
    //Checks previousNode
    while (previousNode->next != NULL &&
           *previousNode->next->data < target)
    {
        //Sets previousNode to the next node
        previousNode = previousNode->next;
    }
    //Checks if next node is null
    if (previousNode->next == NULL)
    {
        return false;
    }
    //Checks if the next node is the target
    if (*previousNode->next->data == target)
    {
        //Sets currentNode, result, and previousNode
        currentNode = previousNode->next;
        result = *currentNode->data;
        previousNode->next = previousNode->next->next;
        //Deletes currentNode and sets it to null
        delete currentNode;
        currentNode = NULL;
        return true;
    }
    return false;
}

/*
 * Peek function has two parameters of ItemType and one of the
 * parameters is a reference. This function returns a value of
 * type boolean. The purpose of this function is the same as the
 * Remove function except the item is not removed from the list.
 */
template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result) const
{
    //Ensures that head is not null
    if (head != NULL)
    {
        //Declares pointer variable that is of type Node
        Node *frontNode;
        //Initializes variable to head
        frontNode = head;
        
        //While the front node is not null
        while(frontNode != NULL)
        {
            //If the target is not found
            if(*(frontNode->data) != target)
            {
                //Sets the variable to the next node
                frontNode = frontNode->next;
            }
            //Otherwise if the target is found
            else
            {
                //Sets the result and returns true
                result = *(frontNode->data);
                return true;
            }
        }
        return false;
    }
    //Otherwise it prints null
    else
    {
        cout << "Null" << endl;
        return false;
    }
}

/*
 * isEmpty function determines if the list is empty. If it
 * is empty it returns true, if it is not empty it returns
 * false.
 */
template <class ItemType>
bool List342<ItemType>::isEmpty() const
{
    //If list is empty returns true
    if (head == NULL)
    {
        return true;
    }
    //If list is not empty returns false
    else
    {
        return false;
    }
}

/*
 * DeleteList function does not take any parameters and is
 * a void function. The purpose of this function is to remove all
 * items from the list and deallocate memory.
 */
template <class ItemType>
void List342<ItemType>::DeleteList()
{
    //Deallocates memory while head is not null
    while (head != NULL)
    {
        Node*temp = head;
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
}

/*
 * Merge function takes in a reference and returns a boolean
 * value. The purpose of this function is to take a sorted list
 * and merge into the calling sorted list. This function also
 * checks for duplicates and removes them.
 */
template <class ItemType>
bool List342<ItemType>::Merge(List342<ItemType> &list1)
{
    //Checks the condition
    if (this == &list1 || list1.head == NULL)
    {
        return false;
    }
    if (head == NULL && list1.head == NULL)
    {
        head = list1.head;
        list1.head = NULL;
        
        return true;
    }
    
    //Declaring variables of type Node and initializing them
    Node* firstList = head;
    Node* secondList = list1.head;
    head = NULL;
    list1.head = NULL;
    
    //Declaring temporary list
    Node tempList;
    Node* current = &tempList;
    
    //Ensuring that the lists are not null
    while (firstList != NULL && secondList != NULL)
    {
        //If the data that the pointers point to are equal (duplicate)
        if (*firstList->data == *secondList->data)
        {
            //Goes to next node
            current->next = firstList;
            firstList = firstList->next;
            Node* duplicate = secondList;
            secondList = secondList->next;
            
            //Deletes the duplicates
            delete duplicate->data;
            duplicate->data = NULL;
            delete duplicate;
            duplicate = NULL;
        }
        //If the data pointed to by the pointer in the first list
        //is less than the second list
        else if (*firstList->data < *secondList->data)
        {
            //Sets the position
            current->next = firstList;
            firstList = firstList->next;
        }
        //Otherwise, if the data in the first list is greater than the
        //data in the second list
        else
        {
            current->next = secondList;
            secondList = secondList->next;
        }
        current = current->next;
    }
    //If the first and second list are not equal to null,
    //position goes to the next node in the list
    if (firstList != NULL)
    {
        current->next = firstList;
    }
    if (secondList != NULL)
    {
        current->next = secondList;
    }
    //Head is set
    head = tempList.next;
    //First and second list are set to null
    firstList = NULL;
    secondList = NULL;
    return true;
}

/*
 * Overloading the += operator. This function takes in a reference and
 * returns a value of type List342<ItemType>.
 */
template <class ItemType>
List342<ItemType>& List342<ItemType>::
operator+=(const List342<ItemType> &list)
{
    if (list.head == NULL)
    {
        //Sets to the pointer
        return *this;
    }
    //Declares pointer variable of type node and initializes it
    Node* current = list.head;
    
    while (current != NULL)
    {
        //Calls insert function and goes through the list
        Insert(current->data);
        current = current->next;
    }
    current = NULL;
    return *this;
}

/*
 * Overloading the + operator. This function takes in a reference
 * and returns a value of type List342<ItemType>.
 */
template <class ItemType>
List342<ItemType> List342<ItemType>::
operator+(const List342<ItemType> &list) const
{
    //Temp variable is declared
    List342 temp = *this;
    //Added to the list
    temp += list;
    //Return the variable
    return temp;
}

/*
 * Overloading == operator. This function takes in a reference
 * and returns a boolean value.
 */
template <class ItemType>
bool List342<ItemType>::operator==(const List342<ItemType> &list) const
{
    //Declaring pointer variables of type Node
    Node *leftNode, *rightNode;
    
    //As long as head is not null
    if(head != NULL && list.head != NULL)
    {
        //Sets variables to head
        leftNode = head;
        rightNode = list.head;
        
        //As long as pointer variables are not null
        while(leftNode != NULL && rightNode != NULL)
        {
            //If it is not equal
            if(leftNode->data != rightNode->data)
            {
                return false;
            }
            //If it is equal
            else
            {
                leftNode = leftNode->next;
                rightNode = rightNode->next;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Overloading != operator. This function takes in a reference
 * and returns a boolean value.
 */
template <class ItemType>
bool List342<ItemType>::operator!=(const List342<ItemType> &list) const
{
    return!(*this == list);
}

/*
 * Overloading = operator. This function takes in a reference
 * and returns a value of type List342<ItemType>.
 */
template <class ItemType>
List342<ItemType> &List342<ItemType>::
operator=(const List342<ItemType> &list)
{
    //Declaring pointer variables
    Node *leftNode;
    Node *rightNode;
    Node *insert;
    //Declaring variable of type ItemType
    ItemType *newValue;
    
    //If it is not null
    if (this != &list || list.head != NULL)
    {
        //Deletes list
        this->DeleteList();
        
        //Sets it to null
        this->head = NULL;
        
        //Initializes head and newValue
        head = new Node;
        newValue = new ItemType;
        
        //Sets variables
        newValue = list.head->data;
        head->data = newValue;
        
        //Assigns nodes to head and next node
        leftNode = head;
        rightNode = list.head->next;
        
        //While right node is not null
        while(!(rightNode == NULL))
        {
            //Setting to new position
            insert = new Node;
            newValue = rightNode->data;
            insert->data = newValue;
            insert->next = NULL;
            leftNode->next = insert;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        //Return the ItemType
        return *this;
    }
    else
    {
        return *this;
    }
}

/*
 * Overloading << operator. It takes in two reference values,
 * one of type List342<ItemType> and one of type ostream. This
 * function returns a value of ostream.
 */
template <class ItemType>
ostream &operator <<
(ostream &outStream, const List342<ItemType> &information)
{
    //Assigns value to Node
    typename List342<ItemType> :: Node *currentNode = information.head;
    
    //As long as head is not null
    while (currentNode != NULL)
    {
        //Assigns temp variable a value
        ItemType temp = *(currentNode->data);
        //Prints to screen
        outStream << temp;
        //Goes to next node
        currentNode = currentNode->next;
    }
    return outStream;
}

/*
 * Destructor does not take any parameters. It's purpose is to
 * delete the list and deallocate memory.
 */
template <class ItemType>
List342<ItemType>::~List342()
{
    this->DeleteList();
}
