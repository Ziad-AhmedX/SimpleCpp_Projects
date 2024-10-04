#include <iostream> // Include the I/O stream library
#include <string> // Include the string library
#include <vector> // Include the vector library
#include "BasePerson.h" // Include the BasePerson header file
#include "Student.h" // Include the Student header file
#include "Func.h" // Include the Func header file

using namespace std; // Use the standard namespace

vector<Student> Students; // Global vector to Store Student objects
int YesNo = 0; // Variable to store user choice 

/**
 * @brief A global status variable to manage program exit status.
 *
 * This variable prevents the program from prompting the user for another operation
 * after saving data when you terminate the program. When set to zero, it indicates that data has been successfully  
 * saved, and the program should exit immediately without asking the user if they
 * want to perform another operation.
 */
bool exitStatus = 1; 


/**
 * @brief Main function to load data and handle operations.
 *
 * This function serves as the entry point of the program. It calls the
 * `loadData()` function to load Student data and then calls the `handler()`
 * function to manage further operations based on user input.
 */
int main()
{
	loadData(); // Load Student data from file
	handler(); // Start handling operations
}
