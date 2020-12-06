//  CSCI 221 VB Spring 2020
//  Project 4
//  Created by Justin Henley
//  Version:  2020-02-27
//  This program is to test the Money class defined in HenleyJMoney.h/.cpp

#include <iostream>
#include "HenleyJMoney.h"

using namespace std;
using namespace moneyhenley; // class Money from HenleyJMoney.h requires the moneyhenley namespace

// Test the Money class
int main() {
    char repeat;

    // Test menu in loop for repeated tests
    do{
        Money emptyMoney; // Calls the empty constructor, will take no value
        Money extractedMoney;  // Calls the empty constructor, will take input from the user directly
        long dollars;
        int cents;  // Take user input for testing non-default constructors

        // Prompts for user input, will be used to construct all Money objects in the test except emptyMoney
        cout << endl << "Please enter an amount of dollars as an integer: ";
        cin >> dollars;
        cout << "Please enter an amount of cents as an integer: ";
        cin >> cents;
        cout << "Please enter an amount of money in $0.00 form: ";
        cin >> extractedMoney; //Extracts the user input and stores it in extractedMoney

        // Creates two new Money objects using the user input
        Money dollarsMoney(dollars);
        Money dollarsAndCentsMoney(dollars, cents);

        // Display the value of each object
        cout << endl << "The value of each Money object is:\n";

        // Testing the getValue() member function of Money
        cout << "emptyMoney: $" << emptyMoney.getValue() << endl;

        // Testing the extraction operator overloading for Money
        cout << "dollarsMoney: " << dollarsMoney << endl;
        cout << "dollarsAndCentsMoney: " << dollarsAndCentsMoney << endl;
        cout << "extractedMoney: " << extractedMoney << endl;

        // Use arithmetic operations on dollarsAndCentsMoney and extractedMoney
        Money temp;
        cout << endl << "Using dollarsAndCentsMoney as the first argument, and extractedMoney as the second:" << endl;

        temp = dollarsAndCentsMoney + extractedMoney;
        cout << "Addition = " << temp << endl;

        temp = dollarsAndCentsMoney - extractedMoney;
        cout << "Subtraction = " << temp << endl;

        temp = -dollarsAndCentsMoney;
        cout << "Negation = " << temp << endl << endl;

        // Use boolean comparison operations on dollarsAndCentsMoney and extractedMoney
        bool result;
        string sayResult;

        result = (dollarsAndCentsMoney > extractedMoney);
        sayResult = (result) ? "true" : "false";
        cout << "dollarsAndCentsMoney > extractedMoney = " << sayResult << endl;

        result = (dollarsAndCentsMoney >= extractedMoney);
        sayResult = (result) ? "true" : "false";
        cout << "dollarsAndCentsMoney >= extractedMoney = " << sayResult << endl;

        result = (dollarsAndCentsMoney < extractedMoney);
        sayResult = (result) ? "true" : "false";
        cout << "dollarsAndCentsMoney < extractedMoney = " << sayResult << endl;

        result = (dollarsAndCentsMoney <= extractedMoney);
        sayResult = (result) ? "true" : "false";
        cout << "dollarsAndCentsMoney <= extractedMoney = " << sayResult << endl;

        result = (dollarsAndCentsMoney == extractedMoney);
        sayResult = (result) ? "true" : "false";
        cout << "dollarsAndCentsMoney == extractedMoney = " << sayResult << endl;

        // Testing the percent member function of class Money
        int percentFigure;
        cout << endl << "Enter a percent as an integer WITHOUT the % symbol: ";
        cin >> percentFigure;  // Take input for the percent

        temp = dollarsAndCentsMoney.percent(percentFigure); // Display percentage for dollarsAndCentsMoney
        cout << endl << percentFigure << "% of dollarsAndCentsMoney is " << temp;

        temp = extractedMoney.percent(percentFigure); // Display percentage for extractedMoney
        cout << endl << percentFigure << "% of extractedMoney is " << temp;

        // Prompt for repeat
        cout << endl << "Repeat? Y/N: ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y'); // Loop exits for any answer except Y/y

    return 0;
}