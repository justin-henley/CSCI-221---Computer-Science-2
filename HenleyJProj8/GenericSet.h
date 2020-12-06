// Provided by:    Justin Henley
// FILE: GenericSet.h
// VERSION: 2020-04-21
// REQUIRES: None
// PROVIDES: A header-only template class to represent sets of similar types.
// Each GenericSet is defined by the datatype of its members, and contains a set of members.
// All members appear only once, and the members are unordered.
// Provided as header-only to avoid compiler issues as mentioned in the text.
//
// CONSTRUCTORS in the class GenericSet:
//    GenericSet()
//        Initializes a new object of type GenericSet with no members
//
// FUNCTIONS in the class GenericSet:
//    void add(ItemType newItem);
//        // Adds an item to the set
//        // Precondition:  The set is not full
//        // Post-condition: The newItem is a member of the list
//
//    void remove(ItemType removeItem)
//        // Removes an item from the set
//        // Post-condition: The removeItem is not a member of the set
//
//    int getSize() const
//        // Returns the number of items in the set
//
//    bool isMember(const ItemType &target)
//        // Determines if an item is a member of the set
//        // Postcondition:  Returns true if the target is a member of the set.
//
//    ItemType *exportArray() const
//        // Returns a pointer to a dynamically created array containing each item in the set.
//        // NOTE: The caller of this function is responsible for de-allocating the memory!
//
//    friend bool operator== (const GenericSet<ItemType>& a, const GenericSet<ItemType>& b)
//        Checks if all elements of two GenericSets are equal
//        Defined within the class definition for simplicity, I spent hours trying to do this
//            outside the class definition!
//        Postcondition: Returns true if all elements are the same. Returns false if the sets have
//            different sizes or members.  Sets do not need to be sorted.

#ifndef CSCI_221_PROJ8_GENERICSET_H
#define CSCI_221_PROJ8_GENERICSET_H

#include <vector>


namespace fhsuhenleyj {
    template<class ItemType>
    class GenericSet {
    public:
        GenericSet();
        // Initializes an empty set

        void add(ItemType newItem);
        // Adds an item to the set
        // Precondition:  The set is not full
        // Post-condition: The newItem is a member of the list

        void remove(ItemType removeItem);
        // Removes an item from the set
        // Post-condition: The removeItem is not a member of the set

        int getSize() const;
        // Returns the number of items in the set

        bool isMember(const ItemType &target);
        // Determines if an item is a member of the set
        // Postcondition:  Returns true if the target is a member of the set.

        ItemType *exportArray() const;
        // Returns a pointer to a dynamically created array containing each item in the set.
        // NOTE: The caller of this function is responsible for de-allocating the memory!

        friend bool operator== (const GenericSet<ItemType>& a, const GenericSet<ItemType>& b){
            // Check that both sets are the same size
            if (a.getSize() != b.getSize())
                return false;

            // Check for any members of set a that are not members of set b
            // Assumes that all members appear exactly once within each set
            for (int i = 0; i < a.getSize(); i++){ // Iterate over set a
                bool found = false;  // bool to track whether a[i] has been found in set b
                for (int j = 0; j < b.getSize(); j++) { // Iterate over set b
                    if (a.set[i] == b.set[i])  // If a[i] has been found in set b, found = true
                        found = true;
                }
                if (!found)
                    return false;
            }

            // If both checks have been passed, the sets must be equal
            return true;
        }
        // Checks if all elements of two GenericSets are equal
        // Defined within the class definition for simplicity, I spent hours trying to do this
        // outside the class definition!
        // Postcondition: Returns true if all elements are the same. Returns false if the sets have
        // different sizes or members.  Sets do not need to be sorted.

    private:
        std::vector<ItemType> set; // Vector holding the set
    };
}

namespace fhsuhenleyj{
    // Initializes an empty set
    template<class ItemType>
    GenericSet<ItemType>::GenericSet() = default;

    // Adds an item to the set
    // Precondition:  The set is not full
    // Post-condition: The newItem is a member of the list
    template<class ItemType>
    void GenericSet<ItemType>::add(ItemType newItem) {
        // Check is the new item already exists in the set.
        if (!isMember(newItem)){
            // If newItem is not a member, add it to the set
            set.push_back(newItem);
        }
    }

    // Removes an item from the set
    // Post-condition: The removeItem is not a member of the set
    template<class ItemType>
    void GenericSet<ItemType>::remove(ItemType removeItem) {
        // Check if removeItem is a member of the set
        for(int i = 0; i < getSize(); i++){
            if (set[i] == removeItem){
                // If removeItem is found, erase it and return
                set.erase(set.begin()+i);
                return;
            }
        }

        // If not found, just return
        return;
    }

    // Returns the number of items in the set
    template<class ItemType>
    int GenericSet<ItemType>::getSize() const {
        return set.size();
    }

    // Determines if an item is a member of the set
    // Postcondition:  Returns true if the target is a member of the set.
    template<class ItemType>
    bool GenericSet<ItemType>::isMember(const ItemType &target) {
        // Search the set for the target
        for (ItemType i : set){
            if (i == target)
                return true;
        }
        // Return false if target not found
        return false;
    }

    // Returns a pointer to a dynamically created array containing each item in the set.
    // NOTE: The caller of this function is responsible for de-allocating the memory!
    template<class ItemType>
    ItemType* GenericSet<ItemType>::exportArray() const{
        // Get the size of the set
        int sizeSet = getSize();

        // Create a dynamic array with the same size as the set
        auto* newArray = new ItemType[sizeSet];

        // Copy the set values into the array
        for (int i = 0; i < sizeSet; i++){
            newArray[i] = set[i];
        }

        return newArray;
    }
}
	

#endif //CSCI_221_PROJ8_GENERICSET_H
