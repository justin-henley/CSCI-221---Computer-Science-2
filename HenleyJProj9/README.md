# CSCI_221_Proj9
### Practice Program 6, p.1031

In this project, you are to create a database of books that are stored using a vector.  

Keep track of:
- the author
- title
- publication date of each book.

Your program should have a main menu that allows the user to select from the following:
1. Add a book's author, title, and date
2. Print an alphabetical list of books sorted by author
3. Quit

You must use a class to hold the data for each book.  This class must hold three string fields:
- The author's name
- the publication date
- the title

Store the entire database of books in a vector in which each vector element is a book class object.

To sort the data, use the generic sort function from the '<algorithm>' library.  Note that this requires you to define the '<' operator to compare two objects of type Book so that the author field from the two books are compared.

