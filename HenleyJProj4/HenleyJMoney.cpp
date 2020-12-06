// Implementation file HenleyJMoney.cpp:  This is the IMPLEMENTATION of the ADT Money.
// The interface for the class is in the header file HenleyJMoney.h
// Created by justin on 2020-02-26.

#include <iostream>
#include <cctype>
#include <cstdlib>
#include "HenleyJMoney.h"

using namespace std;

namespace {
//  Used in the definition of the overloaded input operator >>.
// Precondition:  c is one of the digits '0' through '9'.
// Returns the integer for the digit.
// Example:  digitToInt('3') returns 3;
    int digitToInt(char c);
} // unnamed namespace

namespace moneyhenley {
    // CONSTRUCTORS

    // Expects both dollars and cents to be negative for negative dollar values
    Money::Money(long dollars, int cents) {
        allCents = (dollars * 100) + cents;
    }

    Money::Money(long dollars) {
        allCents = dollars * 100;
    }

    // Defaults to $0.00
    Money::Money() : allCents(0) {}

    // FRIEND FUNCTIONS

    // adds the value of two Money objects
    Money operator+(const Money &amount1, const Money &amount2) {
        Money temp;
        temp.allCents = amount1.allCents + amount2.allCents;
        return temp;
    }

    // subtracts the value of the second Money object from the value of the first
    Money operator-(const Money &amount1, const Money &amount2) {
        Money temp;
        temp.allCents = amount1.allCents - amount2.allCents;
        return temp;
    }

    // negates the value of the Money object
    Money operator-(const Money &amount) {
        Money temp;
        temp.allCents = -amount.allCents;
        return temp;
    }

    // Checks for equality between the value of two Money objects
    bool operator==(const Money &amount1, const Money &amount2) {
        return (amount1.allCents == amount2.allCents);
    }

    // Checks if the first Money object is less than the second
    bool operator<(const Money &amount1, const Money &amount2) {
        return (amount1.allCents < amount2.allCents);
    }

    // Checks if the first Money object is less than or equal to the second
    bool operator<=(const Money &amount1, const Money &amount2) {
        return (amount1.allCents <= amount2.allCents);
    }

    // Checks if the first Money object is greater than the second
    bool operator>(const Money &amount1, const Money &amount2) {
        return (amount1.allCents > amount2.allCents);
    }

    // Checks if the first Money object is greater than or equal to the second
    bool operator>=(const Money &amount1, const Money &amount2) {
        return (amount1.allCents >= amount2.allCents);
    }

    // Allows the insertion operator to accept an amount of money, and convert it into allCents
    // Requires the dollar sign to be entered by the user
    // Format of input:  $dollars.cent or -$dollars.cents
    // Exits the program if input does not match the required format
    istream &operator>>(istream &ins, Money &amount) {
        char oneChar, decimalPoint, digit1, digit2; // digits for the amount of cents
        long dollars;
        int cents;
        bool negative; // set to true if input is negative

        ins >> oneChar;

        // Check if the input is negative
        if (oneChar == '-') {
            negative = true;
            ins >> oneChar; // read '$'
        } else
            negative = false; // If input is legal, then oneChar == '$'

        ins >> dollars >> decimalPoint >> digit1 >> digit2;

        // Check for illegal input
        if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)) {
            cout << "Error: illegal form of money input\n";
            exit(1);
        }

        cents = digitToInt(digit1) * 10 + digitToInt(digit2);

        amount.allCents = dollars * 100 + cents;
        if (negative)
            amount.allCents = -amount.allCents;

        // Must return the istream to allow repeated use of >>
        return ins;
    }


    // Allows the extraction operator to display the value of the Money object
    // in the form $dollars.cents or -$dollars.cents
    ostream &operator<<(ostream &outs, const Money &amount) {
        long positiveCents, dollars, cents;
        positiveCents = labs(amount.allCents); // Negative sign is added back in during output
        dollars = positiveCents / 100;
        cents = positiveCents % 100;

        // Checking if the value is negative
        if (amount.allCents < 0)
            outs << "-$" << dollars << ".";
        else
            outs << "$" << dollars << ".";

        // Prints the missing zero if cents is less than 10
        if (cents < 10)
            outs << "0";
        outs << cents;

        // Must return the ostream to allow repeated use of <<
        return outs;
    }

    // PUBLIC MEMBER FUNCTIONS

    // Returns the amount represented by value
    // Does NOT return the dollar sign, must use the extraction operator for better formatting
    double Money::getValue() const {
        return static_cast<double>(allCents) / 100;
    }

    // Returns a percentage amount of the current object.  Does NOT set the current object to that amount,
    // only returns the amount.
    Money Money::percent(int percentFigure) const {
        Money temp;
        //The following drops any fractions of cents, always rounding down to nearest whole cent
        temp.allCents = allCents * (static_cast<double>(percentFigure) / 100); // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
        return temp;
    }
} //end moneyhenley

namespace
{
    //  Used in the definition of the overloaded input operator >>.
    // Precondition:  c is one of the digits '0' through '9'.
    // Returns the integer for the digit.
    // Example:  digitToInt('3') returns 3;
    int digitToInt(char c){
        return static_cast<int>(c - '0');
    }
} // unnamed namespace