#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <fstream>   
#include <sstream> 
#include <iomanip>
#include <limits>
#include "Student.h"

/**
 * @file Func.h
 * @brief Provides declarations for functions related to Student management.
 */

/*---------------------------------- Student ----------------------------------*/

/** 
 * @brief A global vector to store all Student objects.
 */
extern vector<Student> Students;

/**
 * @brief A global variable to capture Yes/No responses.
 */
extern int YesNo;

/**
 * @brief A global status variable to manage program exit status.
 *
 * This variable prevents the program from prompting the user for another operation
 * after saving data when you terminate the program. When set to zero, it indicates that data has been successfully  
 * saved, and the program should exit immediately without asking the user if they
 * want to perform another operation.
 */

extern bool exitStatus;

/**
 * @brief Displays the main menu options for the Student management system.
 */
void show();

/**
 * @brief Handles the user's input and processes the respective functions.
 */
void handler();

/**
 * @brief Adds a new Student to the system.
 */
void addNewStudent();

/**
 * @brief Updates an existing Student's information.
 */
void updateStudent();

/**
 * @brief Searches for a Student using their ID.
 */
void searchStudentById();

/**
 * @brief Removes a Student from the system using their ID.
 */
void removeStudentById();

/**
 * @brief Displays all Students currently in the system.
 */
void displayStudents();

/**
 * @brief Clears all Student records from the system.
 */
void clearAllStudents();

/**
 * @brief Saves the current Student data to a file.
 */
void saveData();

/**
 * @brief A helper function used during the data saving process.
 */
void saveHelper();

/**
 * @brief Loads Student data from a file.
 */
void loadData();

/**
 * @brief Handles the process of exiting the program.
 */
void exitProgram();

#endif /* FUNC_H */
