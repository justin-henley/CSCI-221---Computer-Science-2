#include <iostream>
#include "CSCI221Proj5.h"

namespace FHSULINKEDLIST
{
    // Sets NodePtr type.  Placed here instead of header in fear that only this file will be graded/run.
    typedef Node* NodePtr;

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: The value returned is the number of nodes in the linked
    // list. The list itself is unaltered.
    size_t list_length(const Node* head_ptr){
        size_t listSize = 0;

        while (head_ptr != nullptr)  // Stops when the list reaches the end
        {
            listSize++;  // Count this item
            head_ptr = head_ptr->link;  // Advance to the next item in the list
        }

        return listSize;
    }

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: A new node containing the given entry has been added at
    // the head of the linked list; head_ptr now points to the head of the new,
    // longer linked list.
    void list_head_insert(Node*& head_ptr, const Node::Item& entry){
        head_ptr = new Node{entry, head_ptr};  // Creates a new node which points to the old head
    }

    // Precondition: previous_ptr points to a node in a linked list.
    // Postcondition: A new node containing the given entry has been added
    // after the node that previous_ptr points to.
    void list_insert(Node* previous_ptr, const Node::Item& entry){
        NodePtr next_ptr = previous_ptr->link;  // Stores the pointer to the next node in the list
        previous_ptr->link = new Node{entry, next_ptr}; // Inserts a new node that points to the next node
    }

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: The pointer returned points to the first node containing
    // the specified target in its data member. If there is no such node, the
    // null pointer is returned. The list itself is unaltered.
    Node* list_search(Node* head_ptr, const Node::Item& target){
        NodePtr currentPosition = head_ptr; // Tracks the current node

        while ((currentPosition != nullptr) && (currentPosition->data != target)){  // Loops until the end of list
            currentPosition = currentPosition->link;  // If target not found, advance to next node
        }

        return currentPosition; // Returns target pointer, or nullptr if target not found
    }

    // Precondition: head_ptr is the head pointer of a linked list, and
    // position > 0.
    // Postcondition: The pointer returned points to the node at the specified
    // position in the list. (The head node is position 1, the next node is
    // position 2, and so on). If there is no such position, then the null
    // pointer is returned. The list itself is unaltered.
    Node* list_locate(Node* head_ptr, size_t position){
        NodePtr currentNode = head_ptr;  // Tracks the current node
        size_t currentPosition = 1;  // Tracks the position of the current node in the list

        while((currentPosition != position) && (currentNode != nullptr)){  // Iterates until position has been reached
            currentNode = currentNode->link;  // Move to next node
            currentPosition++;  // Increment the position of the current node
        }

        return currentNode;  // Returns the pointer to the node in the specified position
    }

    // Precondition: head_ptr is the head pointer of a linked list, with at
    // least one node.
    // Postcondition: The head node has been removed and returned to the heap;
    // head_ptr is now the head pointer of the new, shorter linked list.
    void list_head_remove(Node*& head_ptr){
        NodePtr temp = head_ptr;  // Stores the old head for deletion
        head_ptr = head_ptr->link;  // Makes the next node the new head
        delete temp;  // Deletes the old head
    }

    // Precondition: previous_ptr points to a node in a linked list, and this
    // is not the tail node of the list.
    // Postcondition: The node after previous_ptr has been removed from the
    // linked list.
    void list_remove(Node* previous_ptr){
        NodePtr nextPtr = previous_ptr->link;  // Stores the next node
        previous_ptr->link = nextPtr->link;  // Sets the pointer to the node after the next node
        delete nextPtr;  // Deletes the next node
    }

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: All nodes of the list have been returned to the heap,
    // and the head_ptr is now NULL.
    void list_clear(Node*& head_ptr){
        NodePtr temp;  // Stores the current node for deletion

        while (head_ptr != nullptr)  // Stops at end of list
        {
            temp = head_ptr; // Stores the current node
            head_ptr = head_ptr->link;  // Advances to the next node
            delete temp;  // deletes the current node
        }
    }

    // Precondition: source_ptr is the head pointer of a linked list.
    // Postcondition: head_ptr is the head pointer for
    // a new list that contains the same items as the list pointed to by
    void list_copy(Node* source_ptr, Node*& head_ptr){
        // Check if the list is empty
        if (source_ptr == nullptr)  // If the list is empty
            head_ptr = nullptr;  // The new list is empty too
        else{  // If the list is not empty
            list_head_insert(head_ptr, source_ptr->data);  //The head is now a new node, with data copied from source
            NodePtr currentNode = head_ptr;  // Tracks the current node so that head_ptr doesn't change
            source_ptr = source_ptr->link;  // Source_ptr advances to the next node

            for (source_ptr; source_ptr != nullptr; source_ptr = source_ptr->link)  // Iterates until end of source list
            {
                currentNode->link = new Node{source_ptr->data, nullptr};  // Creates a new node at end of list
                currentNode = currentNode->link;  // Advance to the new node
            }
        }

    }

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: The return value is the count of the number of times
    // target appears as the data portion of a node on the linked list.
    // The linked list itself is unchanged.
    size_t list_occurrences(Node* head_ptr, const Node::Item& target){
        NodePtr currentPosition = head_ptr;  // Tracks current position, starting at head of list
        size_t occurences = 0;  // Tracks number of occurences of the target in the list

        for (currentPosition; currentPosition != nullptr; currentPosition = currentPosition->link){  // Iterate until end of list
            if (currentPosition->data == target)
                occurences++;  // If target is found in the current node, increment occurences counter
        }

        return occurences;  // Return the number of occurences of target in the list
    }

    // Precondition: head_ptr is the head pointer of a linked list.
    // Postcondition: A new node containing the given entry has been added at
    // the tail of the linked list; if this happens to be the first node of
    // the linked list, then head_ptr now points to this node (otherwise
    // head_ptr is unchanged).
    void list_tail_attach(Node*& head_ptr, const Node::Item& entry){
        if (head_ptr == nullptr)  // Checks if this is the first node of the linked list
            head_ptr = new Node{entry, nullptr};  // Sets head_ptr to this node
        else{  // If this is not the first node in the linked list
            NodePtr currentNode = head_ptr;  // Tracks the current node in the list
            while (currentNode->link != nullptr) // Iterate until tail node of list
            {
                currentNode = currentNode->link;  // Advance to next node
            }
            currentNode->link = new Node{entry, nullptr};  // Point the tail node to the new node
        }

    }

    // Precondition: head_ptr is the head pointer of a linked list, with at
    // least one node.
    // Postcondition: The tail node has been removed and returned to the heap;
    // if the list is now empty, then head_ptr is null; otherwise head_ptr
    // is unchanged.
    void list_tail_remove(Node*& head_ptr){
        //  If list has only one node
        if (head_ptr->link == nullptr){
            delete head_ptr;  // delete the node
            head_ptr = nullptr;  // Set head_ptr to nullptr
        }
        //  If list has more than one node
        else{
            NodePtr currentNode = head_ptr;  // track the current node
            NodePtr nextNode = currentNode->link;  // track the next node

            while (nextNode->link != nullptr) {  // iterate until nextNode is the last node in the list
                currentNode = nextNode;  // Advance position to next node
                nextNode = nextNode->link;  // Advance position to next next node
            }

            delete nextNode;  // Once nextNode points to the final node, delete the node
            currentNode->link = nullptr;  // Set the link in the new final node to nullptr
        }
    }

    // Precondition: source_ptr is the head pointer of a linked list
    // Postcondition: The value returned is the head pointer for
    // a new list that contains copies of the first n nodes from the list
    // that source_ptr points to. If there less than n nodes in source list,
    // just copy all nodes and done
    Node* list_copy_front(Node* source_ptr, size_t n){
        NodePtr newListPtr = nullptr;  // Head pointer for the new list

        // Check if there are enough nodes in source list
        if (n == 0)
            return nullptr;  // Return an empty list if n is 0
        else if (list_length(source_ptr) <= n)  // if not enough nodes in list, then copy whole list
            list_copy(source_ptr, newListPtr);  // Copy the whole list
        else{
            list_head_insert(newListPtr, source_ptr->data);  //The head is now a new node, with data copied from source
            NodePtr currentNode = newListPtr;  // Tracks the current node so that head_ptr doesn't change
            source_ptr = source_ptr->link;  // Source_ptr advances to the next node

            for (size_t currentNodeNumber = 1;  currentNodeNumber < n; currentNodeNumber++){  // Check if enough nodes have been copied
                list_insert(currentNode, source_ptr->data);  // Creates a new node pointed to by currentNode
                currentNode = currentNode->link;  // Advance to new node
                source_ptr = source_ptr->link;  // Advance to next node;
            }
        }
        return newListPtr;  // Returns the head of the new list
    }
}
