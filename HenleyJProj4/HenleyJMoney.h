// Header file HenleyJMoney.h:  This is the INTERFACE for the class Money.
// Values of this type are amounts of money.  The values are input and output in standard dollar-and-cent
// notation, as in $12.34 for 12 dollars and 34 cents.  The dollar sign is required.
// For negative amounts of money, input is in the form -$12.34
// uses the namespace moneyhenley
// Created by justin on 2020-02-26.

#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

namespace moneyhenley
{
    class Money {
    public:
        // Constructors
        Money(long dollars, int cents);
        /* Initializes the object so its value represents an amount with the
         * dollars and cents given by the arguments.
         * If the amount is negative, then both dollars and cents must be negative. */

        explicit Money(long dollars);
        // Initializes the object so its value represents $dollars.00

        Money();
        // Initializes the object so its value represents $0.00

        // Friends
        friend Money operator +(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns the sum of the values of amount1 and amount2.

        friend Money operator -(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns the difference of amount1 and amount2.

        friend Money operator -(const Money& amount);
        // Precondition:  amount has been given a value
        // Returns the negation of the amount stored in amount

        friend bool operator ==(const Money& amount1, const Money& amount2);
        // Precondition: amount1 and amount2 have been given values.
        // Returns true if amount1 and amount2 have the same value;
        // otherwise, returns false.

        friend bool operator <(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns true if amount1 is less than amount2;
        // otherwise, returns false.

        friend bool operator <=(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns true if amount1 is less than or equal to amount2;
        // otherwise, returns false.

        friend bool operator >(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns true if amount1 is greater than amount2;
        // otherwise, returns false.

        friend bool operator >=(const Money& amount1, const Money& amount2);
        // Precondition:  amount1 and amount2 have been given values.
        // Returns true if amount1 is greater than or equal to amount2;
        // otherwise, returns false.

        friend istream& operator >>(istream& ins, Money& amount);
        /* Overloads the >> operator so it can be used to input values of type Money.
         * Notation for inputting negative amounts is as in -$100.00
         * Precondition: If ins is a file input stream, then ins has already been
         * connected to a file. */

        friend ostream& operator <<(ostream& outs, const Money& amount);
        /* Overloads the << operator so it can be used to output values of type Money.
         * Precedes each output value of type Money with a dollar sign.
         * Precondition:  If outs is a file output stream,
         * then outs has already been connected to a file. */

        // Accessor
        double getValue() const;
        // Precondition:  The calling object has been given a value.
        // Returns the amount of money recorded in the data of the calling object.

        Money percent(int percentFigure) const;
        // Returns a percentage of the money amount in the calling object.
        // For example, if percentFigure is 10, then the value returned
        //  is 10% of the amount of money represented by the calling object.
        // Can NOT accept the '%' symbol.


    private:
        long allCents = 0; //stores the dollar value represented by Money in cents
    };
} //end moneyhenley

#endif //MONEY_H
