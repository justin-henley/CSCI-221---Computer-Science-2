/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: Justin Henley
 * Version: 2020-02-04
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class CDAccount
{
public:
    CDAccount();
    // Postcondition:   Initializes all values of CDAccount object to zero

    CDAccount(double new_balance, double new_interest_rate, int new_term);
    // Precondition:    Each value defines the same account; interest rate is in decimal form
    // Postcondition:   Initializes dollar and cent using new_balance
    //                  Initializes interest_rate using new_interest_rate
    //                  Initializes term using new_term

    double get_initial_balance() const;
    // Postcondition:   Returns initial balance of the account

    double get_balance_at_maturity() const;
    // Postcondition:   Returns maturity balance at end of term

    double get_interest_rate() const;
    // Postcondition:   Returns the interest rate as FRACTION

    int get_term() const;
    // Postcondition:   Returns the term length in months

    void set_initial_balance(double inBalance);
    // Precondition:    inBalance is a positive number
    // Postcondition:   balance is set to inBalance

    void set_interest_rate(double inRate);
    // Precondition:    inRate is a positive number as a FRACTION
    // Postcondition:   interest_rate is set to inRate

    void set_term(int inTerm);
    // Precondition:    inTerm is positive, represents term length in months
    // Postcondition:   term is set to inTerm

    void input(istream& in);
    // Takes user input for member variables
    // Precondition:    in is a valid istream
    // Postcondition:   dollar, cent, interest_rate, and term are updated

    void output(ostream& out);
    // Precondition:    out is a valid ostream
    // Postcondition:   Writes account information to out

private:
    int dollar;
    int cent;
    double interest_rate; // stored in fraction form, not percent
    int term; // months until maturity

    double ftop(double fraction);
    // Precondition:    fraction is an number in fraction form
    // Postcondition:   Returns the number in percent form

    double ptof(double percent);
    // Precondition:    percent is a number in percent form
    // Postcondition:   Returns the number in fraction form
};

int testMenu();
// Postcondition:   Displays the menu for testing the CDAccount class
//                  Returns the users menu choice

int main()
{
    // Test code for the CDAccount class and member functions
    cout << "TEST OF CDAccount CLASS\n";

    int menu = 0; // Holds user menu choice

    // Loop for repeat interaction, with exit value
    do
    {
        menu = testMenu(); // Call to display the test options, returns users choice

        // Test Accounts
        CDAccount emptyAccount;  // Tests empty constructor
        CDAccount testAccount(123.45, .0695, 12);  // Tests constructor
        CDAccount userAccount;  // An empty account to be filled in by the user
        CDAccount setterAccount;  // An empty account for testing setter functions

        // Menu switch
        switch (menu)
        {
            case 1:
                // Test empty constructor with emptyAccount
                emptyAccount.output(cout);
                break;
            case 2:
                // Test output with three-value constructor for object testAccount
                testAccount.output(cout);
                break;
            case 3:
                // Test user input into an empty object userAccount
                // Display empty account first
                cout << "ACCOUNT BEFORE USER INPUT" << endl;
                userAccount.output(cout);

                // Take input
                cout << "Enter balance as DD.CC, rate as percent without the symbol, term in months: ";
                userAccount.input(cin);
                cin.ignore(100, '\n'); // input function leaves a newline character in the stream, this removes it

                // Display changes
                cout << "ACCOUNT AFTER USER INPUT" << endl;
                userAccount.output(cout);
                break;
            case 4:
                // Test setter functions
                // Displays empty account first
                cout << "ACCOUNT BEFORE SETTER TEST" << endl;
                setterAccount.output(cout);

                // Setter variables
                double inBalance, inRate;
                int inTerm;

                // Take input
                cout << "Enter balance as dollars and cents without dollar symbol,  DD.CC:  ";
                cin >> inBalance;
                setterAccount.set_initial_balance(inBalance);

                cout << "Enter rate as a percent:  ";
                cin >> inRate;
                setterAccount.set_interest_rate(inRate/100);

                cout << "Enter loan term in months:  ";
                cin >> inTerm;
                setterAccount.set_term(inTerm);

                // Display changes
                cout << "ACCOUNT AFTER SETTERS" << endl;
                setterAccount.output(cout);

                // Fix input stream issue where next menu choice is ignored
                cin.ignore(100, '\n'); // Ignores any extraneous input
                break;
            default:
                break;
        }

    } while (menu != 5); // The exit value

    cout << endl << "Tests completed.  Goodbye.";
}


// Defined by instructor; provides for user input to class
// Added checks against negative values, all set negatives to the zero of the data type
void CDAccount::input(istream& in)
{
    // Temporary variables
    double balance;
    double interest_as_percent;
    int term_entered;

    // Inputs
    in >> balance; // get initial balance from user
    in >> interest_as_percent;  // get interest rate from user
    in >> term_entered; // get term from user


    // Illegal values are set to $00.00
    //Negative balance rejected
    if (balance < 0)
        balance = 0.0;

    // Negative interest rate rejected
    if (interest_as_percent < 0)
        interest_as_percent = 0.0;

    // Negative term rejected and term member variable set
    if (term_entered < 0)
        term = 0;
    else
        term = term_entered;


    // Setting private member variable values
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the integer part of balance
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100

    interest_rate = ptof(interest_as_percent); // store interest rate as a decimal
}

// Displays account information to the specified ostream
void CDAccount::output(ostream& out)
{
    // Formatting for easy reading
    int fieldWidth = 23;
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    out.fill(' ');

    // Output account information
    out << endl << "**** CD Account Information ****\n";
    out << setw(fieldWidth)  <<  "Initial balance: " << "$" << get_initial_balance() << endl;
    // Display interest as a percent for readability
    out << setw(fieldWidth)  << "Interest rate (%): " << ftop(get_interest_rate()) << endl;
    out << setw(fieldWidth) << "Term (months): " << get_term() << endl;
    out << setw(fieldWidth)  << "Balance at maturity: " << "$" << get_balance_at_maturity() << endl;
    out.width(32);
    out.fill('*'); // Bottom bar of asterisks for account info display
    out << "" << endl;
}

// Empty constructor
CDAccount::CDAccount() : dollar(0), cent(0), interest_rate(0.0), term(0)
{
    // Intentionally left empty
}

// Constructor, takes three parameters
CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    // Checks for legal values
    if ((new_balance < 0) || (new_interest_rate < 0) || (new_term < 0))
    {
        cout << "Illegal values for one or more of balance, interest rate, or term.\n";
        exit(1);
    }

    dollar = (int) new_balance; // dollar is the integer part of new_balance
    cent = (int) ((new_balance - dollar) * 100);  // cent is the decimal part * 100
    interest_rate = new_interest_rate; // accepts interest rate as decimal, not percent
    term = new_term;
}

// Returns the initial balance
double CDAccount::get_initial_balance() const
{
    double balance = dollar + (cent/100.0);  // Combines dollar and cent into one value
    return balance;
}

// Returns the calculated balance at maturity based on term and interest rate
double CDAccount::get_balance_at_maturity() const
{
    double initial_balance = get_initial_balance();

    // Calculate simple interest, assuming percent rate is annual
    double mature_balance = initial_balance * (1 + ((interest_rate / 12) *  term));

    // Return the balance at maturity
    return mature_balance;
}

// Returns the interest rate as a fraction
double CDAccount::get_interest_rate() const
{
    return interest_rate;
}

// Returns the term length in months
int CDAccount::get_term() const
{
    return term;
}

// Sets the initial balance in the object
void CDAccount::set_initial_balance(double inBalance)
{
    if (inBalance >= 0)
    {
        dollar = static_cast<int>(inBalance);
        cent = static_cast<int>((inBalance - dollar) * 100);
    }
    else
        cout << "Illegal value entered, no change made.\n";
}

// Sets the interest rate of the object as a fraction
void CDAccount::set_interest_rate(double inRate)
{
    // Guard against illegal values
    if (inRate >= 0.0)
        interest_rate = inRate;
    else
        cout << "Illegal value entered, no change made.\n";
}

// Sets the term of the object
void CDAccount::set_term(int inTerm)
{
    // Guard against illegal values
    if (inTerm >= 0)
        term = inTerm;
    else
        cout << "Illegal value entered, no change made.\n";
}

// Converts from fraction to percent
double CDAccount::ftop(double fraction)
{
    return fraction*100;
}

// Converts from percent to fraction
double CDAccount::ptof(double percent)
{
    return percent/100;
}

// Displays the test menu and returns user choice
int testMenu()
{
    cout << endl << "TEST MENU: " << endl;
    cout << "1.  Test empty constructor\n";
    cout << "2.  Test constructor with three parameters\n";
    cout << "3.  Test input function\n";
    cout << "4.  Test setter functions\n";
    cout << "5.  Exit\n";

    // Prompt for menu choice
    // I used a char for input after discovering that a non-integer value caused the integer version to infinite loop
    char choice;
    do {
        cout << endl << "Choice:  ";
        cin.get(choice); // Takes a single character input
        cin.ignore(100, '\n'); // Ignores any extraneous input
    } while ((choice < '1') || (choice > '5'));  // Loops until a valid option is entered
    return static_cast<int>(choice) - 48;  // converts the numeric character to its integer equivalent
}