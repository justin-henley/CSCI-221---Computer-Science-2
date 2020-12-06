// AUTHOR:   Justin Henley
// EMAIL: jahenley@mail.fhsu.edu
// COURSE:  FHSU CSCI 221 VB, Spring 2020
// FILE: HenleyJProj9.cpp
// VERSION: 2020-04-28
// A program to demonstrate a simple database of books.
// Each book has an author, a title, and a publication date.
// The sorted database of books can be printed out in alphabetical order.
// Demonstrates use of the STL vector container with a class type,
// the generic sort algorithm, and regular expressions

#include <regex>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

namespace fhsuhenleyj {
    void displayMenu(ostream &out);
    // Displays Menu to ostream
    // Precondition: If out is a file stream, the file has been opened for writing

    Book newBook(ostream &out, istream &in);
    // Prompts user for input for a new book
    // Precondition: If in and out are file streams, they have been connected appropriately
    // Postcondition: Returns a Book object initialized to the input values

    int menuSelection();
    // Prompts the user for a menu option
    // Postcondition: Returns an option within the range of available options

    void printList(ostream& out, vector<Book>& bookList);
    // Prints out sorted list of books in alphabetical order
    // Precondition: If out is a file stream, it has been connected appropriately
    // Postcondition: Prints a sorted list of the books stored in the list in alphabetical order
}

int main() {
    using namespace fhsuhenleyj;

    int choice;  // Stores the user menu choice
    vector<Book> bookList;  // Stores the list of books input to the program

    do{
        // Call the function that handles the menu, and store the choice returned
        choice = menuSelection();

        // Options from the menu
        switch (choice) {
            case 1:
                // Add a new book to the list
                bookList.push_back(newBook(cout, cin));
                break;
            case 2:
                // Sort and print the list
                printList(cout, bookList);
                break;
            default:
                // Only other option is 3, thus the default is to quit the program
                break;
        }
    } while (choice != 3); // Loops until "Quit" is chosen, option 3
}

namespace fhsuhenleyj {
    // Displays Menu to ostream
    // Precondition: If out is a file stream, the file has been opened for writing
    void displayMenu(ostream& out) {
        out << "Select from the following choices:\n";
        out << "1.    Add new book\n";
        out << "2.    Print listing sorted by author\n";
        out << "3.    Quit\n";
    }

    // Prompts the user for a menu option
    // Postcondition: Returns an option within the range of available options
    int menuSelection() {
        string choice;  // Holds the user's choice input
        string MenuPattern = R"([1-3])";  // Input must be a single integer [1-3]
        regex regMenu(MenuPattern); // Create the regex

        do{
            displayMenu(cout);
            cin >> choice;
        } while (!regex_match(choice, regMenu)); // Repeat while choice does not match the regex

        return stoi(choice);  // Return the valid choice as an integer
    }


    // Prompts user for input for a new book
    // Precondition: If in and out are file streams, they have been connected appropriately
    // Postcondition: Returns a Book object initialized to the input values
    Book newBook(ostream& out, istream& in) {
        string author, pubDate, title;

        out << "Enter title:\n";
        in.ignore(1, EOF);  // Necessary to avoid the endline character left in stream from the menu selection
        getline(in, title);
        out << "Enter author:\n";
        getline(in, author);
        out << "Enter publication date\n";
        getline(in, pubDate);

        return Book(author, pubDate, title);
    }

    // Prints out sorted list of books in alphabetical order
    // Precondition: If out is a file stream, it has been connected appropriately
    // Postcondition: Prints a sorted list of the books stored in the list in alphabetical order
    void printList(ostream& out, vector<Book>& bookList) {
        // Sort the list with the standard sort algorithm
        sort(bookList.begin(), bookList.end());

        // Print the list to out
        out << "The books entered so far, sorted alphabetically by author are:\n";
        // Iterate over the vector and print each book on a separate line
        for (const auto i : bookList){
            out << i.getAuthor() << ", " << i.getTitle() << ", " << i.getPubDate() << ".\n";
        }

        // End of list
        out << "*** End of List ***\n\n";
    }
}