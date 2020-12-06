// AUTHOR:   Justin Henley
// EMAIL: jahenley@mail.fhsu.edu
// COURSE:  FHSU CSCI 221 VB, Spring 2020
// FILE: HenleyJProj7.cpp
// VERSION: 2020-04-09
// A short program to take in a time in HH:MM 24-hour time format, and
// print the time in 12-hour format.  Demonstrates exception
// handling for illegal inputs.

#include <iostream>
#include <string>
using namespace std;

// Used for exception handling.  Made to be thrown.
class TimeFormatMistake {
public:
    TimeFormatMistake(); // Has no values, so only default constructor needed
};

// Precondition: hour and minute have been given values
// Returns the time in 12-hour format HH:MM PM
string getTime12(int hour, int minute);

// Precondition: Time is in the 24-hour format HH:MM
// Postcondition: hour and minute have been set to represent the time in timeInput
// or throws an exception for illegal time
void timeParsing(const string &timeInput, int &hour, int &minute) throw(TimeFormatMistake);

int main() {
    // Variables
    int hour, minute;
    string timeInput;  // Holds user time input
    char again; // Holds user decision to repeat the program

    do{
        cout << "Enter time in 24-hour HH:MM notation:\n";
        cin >> timeInput;  // Takes user input for time

        // stoi will automatically throw an exception on a non-numerical input
        try {
            // Strip time input into hour and minute variables
            // May throw an exception for invalid input
            timeParsing(timeInput, hour, minute);

            // Display 12-hour time conversion
            cout << "This is the same as\n" << getTime12(hour, minute) << endl;

            // Prompt to repeat
            cout << "Again?(y/n)\n";
            cin >> again;
        }
        catch(TimeFormatMistake &e) { // Catches times that are outside the valid range of [00:00, 23:59]
            cout << "There is no such time as " << timeInput << endl;
            cout << "Try again:\n";

            // Set do-while loop to run again for new input
            again = 'y';
        }
    } while(again == 'Y' || again == 'y'); // Repeat if user chose to

    cout << "End of program\n";
}

// Default constructor for TimeFormatMistake
TimeFormatMistake::TimeFormatMistake() = default;


// Precondition: hour and minute have been given values
// Returns the time in 12-hour format HH:MM PM
string getTime12(int hour, int minute){
    // Variable to hold time
    string time, hourString, minuteString, AMPM;

    // Check if AM or PM and format hour and AMPM
    if (hour > 12) {
        hourString = to_string(hour - 12);
        AMPM = "PM";
    }
    else {
        hourString = to_string(hour);
        AMPM = "AM";
    }

    // Format minutes if a leading 0 is needed
    if (minute < 10)
        minuteString = "0" + to_string(minute);
    else
        minuteString = to_string(minute);

    // Return formatted time output
    time = hourString + ":" + minuteString + " " + AMPM;
    return time;
}

// Precondition: Time is in the 24-hour format HH:MM
// Postcondition: hour and minute have been set to represent the time in timeInput
// or throws an exception for illegal time
void timeParsing(const string &timeInput, int &hour, int &minute) throw (TimeFormatMistake){
    // Stores the index of the ':' in the time input for use in substr()
    size_t colonIndex;

    // stoi will automatically throw an exception on a non-numerical input
    try {
        // Strips out first digits for _hour
        hour = stoi(timeInput, &colonIndex);

        // Check if a colon was used to divide minutes and hours. Throw exception if not
        if (timeInput.substr(colonIndex, 1) != ":")
            throw TimeFormatMistake();

        // Skips ':' and reads next digits for _minute
        minute = stoi(timeInput.substr(colonIndex + 1));

        // Check range of _hour and _minute and throw exception for illegal values
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
            throw TimeFormatMistake();
    }
    catch(...){ // Catch all exceptions and rethrow as TimeFormatMistake object
        throw TimeFormatMistake();
    }
}
