// Provided by: Justin Henley
// FILE: Book.h
// VERSION: 2020-04-28
// REQUIRES: None
// PROVIDES: A class to represent books.
// Each Book contains an author, publication date, and title.
//
// CONSTRUCTORS in the class Book:
//    Book()
//        Initializes a new Book object with empty strings for all members
//
//    Book(const string& author, const string& publicationDate, const string& title)
//        Initializes a new Book object with the given author, publication date, and title.
//
// FUNCTIONS in the class Book:
//    string getAuthor();
//        Postcondition: Returns the author stored in the book object
//
//    string getPubDate();
//        Postcondition: Returns the publication date stored in the book object
//
//    string getTitle();
//        Postcondition: Returns the title stored in the book object
//
//    string authorToLower();
//        Postcondition: Returns the author converted to lowercase

//    friend bool operator <(const Book& bookLeft, const Book& bookRight)
//        Compares two book objects based on the Authors name in alphabetical order
//        Not case-sensitive
//        Postcondition: Returns true if bookLeft appears before bookRight in alphabetical order.


#ifndef CSCI_221_PROJ9_BOOK_H
#define CSCI_221_PROJ9_BOOK_H

#include <string>
using std::string;

namespace fhsuhenleyj {
    class Book {
    public:
        Book();
        Book(const string& author, const string& publicationDate, const string& title);
        string getAuthor() const;
        string getPubDate() const;
        string getTitle() const;
        friend bool operator <(const Book& bookLeft, const Book& bookRight);
    private:
        string _author;
        string _publicationDate;
        string _title;
        string authorToLower() const;
    };
}

#endif //CSCI_221_PROJ9_BOOK_H
