/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Justin Henley
 * Version: 2020-01-29
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line followed by its index

int main()
{
    // write code to test reverse function.
    // make sure that you test it on at least two strings
    // one string has even length, another string has odd length


    // Test strings
    char oddString[6] = "hello", evenString[7] = "world!";

    // Print original strings
    cout << "--= Reverse test =--" << endl;
    cout << "Odd string:  " << oddString << endl;
    cout << "Even string: " << evenString << endl << endl;

    // Ugly arguments allow me to change the test string size without having to edit the function call
    reverse(&oddString[0], &oddString[sizeof(oddString) - 2]);
    reverse(&evenString[0], &evenString[sizeof(evenString) - 2]);

    // Print results
    cout << " --= Results =--" << endl << oddString << endl << evenString;
    // End of reverse function test

    // Add Entry test

    // Create test array and new entry
    string *dynamicArray = new string[1];
    int size = 1;
    dynamicArray[0] = "What";
    string newEntry = "0";

    // Prompt for add entry, enter '0' to quit adding entries
    cout << endl << "--= Add Entry Test =--" << endl;
    cout << "New entry: ";
    cin >> newEntry;
    do
    {
        // Call addEntry with newEntry to be added, assign dynamicArray to the new array
        dynamicArray = addEntry(dynamicArray, size, newEntry);

        // Print out new array
        print(dynamicArray, size);

        // Prompt for more entries
        cout << endl << "added! next:  ";
        cin >> newEntry;
    }
    while (newEntry != "0");


    // Testing delete function with previous array
    string entryToDelete = "0";

    // Prompt for deletion
    cout << endl << "--= Time to delete an entry! ==-" << endl;
    cout << endl << "Entry to delete (0 to exit): ";
    cin >> entryToDelete;

    // Loop to delete entries, "0" to exit
    while (entryToDelete != "0")
    {
        // Call deleteEntry with the entry to remove, reassign dynamicArray to the new array
        dynamicArray = deleteEntry(dynamicArray, size, entryToDelete);

        // Print out current array
        print(dynamicArray, size);

    // Prompt for further deletions
        cout << endl << "Entry to delete: ";
        cin >> entryToDelete;
    }

    return 0;
}

void reverse(char* front, char* rear)
{
    // Swaps the front and rear characters, then moves inward to the center

    // Check that rear is not before or equal to front
    // If rear is less than front, it is an even string that has passed center
    // If front == rear, it is an odd string that has reached center
    while (front < rear)
    {
        //Swap the values pointed to by front and rear
        char temp = *front;
        *front = *rear;
        *rear = temp;

        //Increment front and decrement rear, moving towards the center
        front++;
        rear--;
    }
}

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
    // Create new dynamic array, size + 1
    string *newArray = new string[size+1];

    // Copy existing array into new, larger array
    for (int i = 0; i < size; i++)
    {
        newArray[i] = dynamicArray[i];
    }

    // Copy newEntry into new array
    newArray[size] = newEntry;

    // Delete existing array
    delete [] dynamicArray;

    // size + 1
    size++;

    //return pointer to new array
    return newArray;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    // Search for entryToDelete within dynamicArray
    int foundIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (foundIndex != -1)
            break;
        else
        {
            if (dynamicArray[i] == entryToDelete)
                foundIndex = i;
        }
    }

    // If not found, display message and return dynamicArray
    if (foundIndex == -1)
    {
        cout << endl << "STRING NOT FOUND\n";
        return dynamicArray;
    }

    // If found, create new array with size - 1
    string *newArray = new string[size-1];

    // Copy array entries before entryToDelete to new, without the entry to ignore
    for(int i = 0; i != foundIndex; i++) // Steps through old array
    {
        newArray[i] = dynamicArray[i];
    }
    // Copy array entries after entryToDelete, effectively skipping the deleted entry
    for(int j = foundIndex+1; j < size; j++)
    {
        newArray[j-1] = dynamicArray[j];
    }

    // Delete old array
    delete [] dynamicArray;

    // Decrement size
    size--;

    // Return new array pointer
    return newArray;
}

void print(const string* dynamicArray, int size)
{
    // Variable to control line length for strings
    int length = 25;

    // Header for clarity
    cout << endl;
    cout.width(length);
    cout.setf(ios::left);
    cout << "CURRENT ARRAY ENTRIES" << " : INDEX" << endl;

    // Print each entry and index
    for (int i = 0; i < size; i++)
    {
        cout.width(length);
        cout.setf(ios::left);
        cout << dynamicArray[i] << " : " << i << endl;
    }

    // New line for cleanliness
    cout << endl;

}