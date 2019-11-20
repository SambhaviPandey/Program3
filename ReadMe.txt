
Coding Style:
Some of the code is on separate lines in the program. For instance:
List342<ItemType>& List342<ItemType>::
operator+=(const List342<ItemType> &list)
 
I did this because the length was getting over 80 characters in each line, so I split each line so that it was less than 80 characters. 




In List342.h
I tested the BuildList function by creating a .txt file called TestFile.txt that contained the following:
George Washington 12 
Lyndon Johnson 12 
Joseph Smith 4 
Thomas Paine 17 
Thomas Paine 17

I attached the results of the output of the test to this zip file. Below is more detail on how I tested TestFile.txt.

I put this TestFile.txt in the same folder as where the other program 3 files were located. Then I decided to test the BuildList function to ensure it works. 
I wrote the following in main:

    string fileName;
    cout << “Please enter the file name: “;
    cin >> fileName;
    List342<Child> kids;
    kids.BuildList(fileName);
    return 0;

And I wrote the following in the BuildList function:

template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
    ItemType temp;
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        while (inFile.good())
        {
            inFile >> temp;
            if (!inFile.eof())
            {
                Insert(&temp);
                cout << “Inserted: ” << temp << endl;
            }
        }
    }
    else
    {
        cout << "File: " << fileName << " could not be opened" << endl;
        return false;
    }
    inFile.close();
    return true;
}

When I executed this I wrote the full file name. In my case it was located in a folder. So I typed the following when I was prompted to enter the full file name. 
/Users/sambhavi/Desktop/CSS/332/CSS342/TestFile.txt

This function read the file I created (titled TestFile.txt) then it inserted the elements. After I successfully executed it, it printed the following:

Inserted:GeorgeWashington12
Inserted:LyndonJohnson12
Inserted:JosephSmith4
Inserted:ThomasPaine17
Inserted:ThomasPaine17

I only printed out each individual element that was inserted (inside the while loop) and did not actually create a list of multiple elements. If I was to create a list then it would remove the duplicates because I do have code in my insert function to remove duplicates. 

After testing this, I commented it out from main. And I also commented out the following in the BuildFunction: 
cout << "Inserted: " << temp << endl;
