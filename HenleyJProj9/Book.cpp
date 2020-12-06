// Implementation file Book.cpp:  This is the IMPLEMENTATION of the Book class.
// The interface for the class is in the header file Book.h
// VERSION: 2020-04-28.

#include "Book.h"
#include <cctype>

using namespace std;

namespace fhsuhenleyj {
    // Initializes a new Book object with empty strings for all members
    Book::Book() : _author(""), _publicationDate(""), _title("") {}

    // Initializes a new Book object with the given author, publication date, and title.
    Book::Book(const string& author, const string& publicationDate, const string& title){
        _author = author;
        _publicationDate = publicationDate;
        _title = title;
    }

    // Postcondition: Returns the author stored in the book object
    string Book::getAuthor() const{
        return _author;
    }

    // Postcondition: Returns the publication date stored in the book object
    string Book::getPubDate() const{
        return _publicationDate;
    }

    // Postcondition: Returns the title stored in the book object
    string Book::getTitle() const{
        return _title;
    }

    // Compares two book objects based on the Authors name in alphabetical order
    // Not case-sensitive
    // Postcondition: Returns true if bookLeft appears before bookRight in alphabetical order.
    bool operator <(const Book& bookLeft, const Book& bookRight){
        //return ((bookLeft._author).toLower() < bookRight._author);

        // Convert to lowercase strings to avoid case sensitivity affecting ordering
        string leftLower = bookLeft.authorToLower();
        string rightLower = bookRight.authorToLower();

        return leftLower < rightLower;
    }

    // Postcondition: Returns the author converted to lowercase
    string Book::authorToLower() const{
        string lower = "";
        for (int i = 0; i < _author.size(); i++){
               lower += tolower(_author[i]);
        }

        return lower;
    }
}
