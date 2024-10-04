#include <iostream>
#include <cstdlib>
using namespace std;

/** \brief Current account balance */
int balance = 1000;
/** \brief Amount to deposit */
int deposit = 0;
/** \brief Amount to withdraw */
int withdDraw = 0;
/** \brief The real password for verification */
int real_password = 1;
/** \brief User's input password */
int input_password = 0;
/** \brief User's menu choice */
int choice = 0;
/** \brief Status to continue or exit the process */
int status = 0;

/**
 * \brief Displays the main menu options
 * 
 * This function prints out the available options for the user to select from.
 */
void show()
{
    cout << "***** Menu *****\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit" << endl;
    cout << "\n";
}

/**
 * \brief Processes the user's choice and executes the corresponding actions
 * 
 * This function is responsible for handling user input and performing actions
 * such as checking balance, depositing money, withdrawing money, or exiting.
 * 
 * \param show_ptr A pointer to the 'show' function
 */
void process(void (*show_ptr)())
{
    show_ptr(); ///< Display the main menu

    void (*call_process)(void (*)()) = process; ///< Pointer to the 'process' function

    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            // Display current balance
            cout << "Your Balance is " << balance << "$\n";
            cout << "Would you like to continue? [1. Yes / 2. No]: ";
            cin >> status;
            if (status == 1)
            {
                status = 0;
                call_process(show_ptr); ///< Re-call process
            }
            else
            {
                cout << "The process will now exit.";
                exit(0);
            }
            break;

        case 2:
            // Deposit money
            cout << "Note: Your balance is " << balance << endl;
            cout << "Please enter the amount you would like to deposit: ";
            cin >> deposit;

            if (deposit > 0)
            {
                balance += deposit; ///< Update balance
                cout << "Successfully processed.\nNow: Your balance is " << balance << "$" << endl;
                cout << "Would you like another process? [Yes / No]: ";
                cin >> status;
                if (status == 1)
                {
                    status = 0;
                    call_process(show_ptr); ///< Re-call process
                }
                else
                {
                    cout << "The process will now exit.";
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "Invalid deposit amount.\n";
                cout << "Please enter a number greater than 0$.\n";
                cout << "Would you like to continue? [1. Yes / 2. No]: ";
                cin >> status;
                if (status == 1)
                {
                    status = 0;
                    call_process(show_ptr); ///< Re-call process
                }
                else
                {
                    cout << "The process will now exit.";
                    exit(0);
                }
                break;
            }

        case 3:
            // Withdraw money
            cout << "Note: Your balance is " << balance << endl;
            cout << "Enter amount to withdraw: ";
            cin >> withdDraw;
            if (withdDraw > 0 && withdDraw <= balance)
            {
                balance -= withdDraw; ///< Update balance after withdrawal
                cout << "Successfully withdrew " << withdDraw << "$" << endl;
                cout << "Now: Your balance is " << balance << "$\n";
                cout << "Would you like another process? [1. Yes / 2. No]: ";
                cin >> status;
                if (status == 1)
                {
                    call_process(show_ptr); ///< Re-call process
                }
                else
                {
                    cout << "The process will now exit.";
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "Invalid withdrawal amount.\n";
                cout << "Please enter a number more than 0$ and less than " << balance << "$.\n";
                cout << "Would you like to continue? [1. Yes / 2. No]: ";
                cin >> status;
                if (status == 1)
                {
                    status = 0;
                    call_process(show_ptr); ///< Re-call process
                }
                else
                {
                    cout << "The process will now exit.";
                    exit(0);
                }
                break;
            }

        case 4:
            // Exit the program
            cout << "The process will now exit........." << endl;
            exit(0);

        default:
            // Invalid choice handling
            cout << "Invalid choice. Please try again." << endl;
            call_process(show_ptr); ///< Re-call process
            break;
    }
}

/**
 * \brief Verifies the user's password before proceeding
 * 
 * This function prompts the user to enter a password and validates it against the stored real password.
 * It allows up to 3 attempts before terminating the program.
 * 
 * \param func A pointer to the 'process' function
 */
void verify(void (*func)(void (*)()))
{
    cout << "Enter Your password: ";
    cin >> input_password;
    if (input_password == real_password)
    {
        func(show); ///< Call the process function
    }
    else
    {
        static int i = -1;
        i++;
        if (i < 3)
        {
            cout << "Invalid password.\n";
            cout << "You have " << 3 - i << " chances remaining.\n";
            cout << "Please try again\n";
            verify(func); ///< Re-call verification
        }
        else
        {
            cout << "Maximum chances reached. The process will now exit.\n";
            exit(0);
        }
    }
}

/**
 * \brief The main entry point of the program
 * 
 * This function initiates the program by calling the 'verify' function.
 * 
 * \return int Returns 0 upon successful completion
 */
int main(void)
{
    //show();
    void (*func)(void (*)()) = process;

    // Start password verification
    verify(func);

    return 0;
}
