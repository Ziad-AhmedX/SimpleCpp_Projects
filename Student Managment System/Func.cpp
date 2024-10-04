#include "Func.h"

/** 
 * @brief Displays the main menu of the Student Management System.
 * 
 * This function prints the available options for the user to 
 * interact with the system.
 */
void show()
{
    cout << "========================" << endl;
    cout << "Student Management System" << endl;
    cout << "========================" << endl;
    cout << "1. Display Students" << endl;
    cout << "2. Clear Students" << endl;
    cout << "3. Add Student" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Update Student" << endl;
    cout << "6. Search Student" << endl;
    cout << "7. Save Data" << endl;
    cout << "8. Load Data" << endl;
    cout << "9. Exit" << endl;
    cout << "========================" << endl;
}

/**
 * @brief Handles the user's choice and performs the corresponding action.
 * 
 * This function takes the user's op  and calls the corresponding 
 * function based on the choice. It uses a switch-case structure to 
 * determine the action to be taken.
 */
void handler()
{
    /** 
     * @brief Static variable to store the user's choice.
     */
     
    static int op = 0; 
    /**
     * @brief Static variable to track the number of incorrect attempts.
     */
    static int chances = 0;
    show();
    	cout << "Enter your choice (1, 2, or 3, ..., 9): ";
        cin >> op ;

    switch (op)
    {
    /** 
     * @brief Case 1: Display all students.
     */
    case 1 :
        op = 0  ;
        displayStudents();
        break;
    /** 
     * @brief Case 2: Clear all student records.
     */
    case 2:
        op = 0  ;
        clearAllStudents();
        break;
    /** 
     * @brief Case 3: Add a new student.
     */
    case 3:
        op = 0  ;
        addNewStudent();
        break;
    /** 
     * @brief Case 4: Remove a student by their ID.
     */
    case 4:
        op = 0  ;
        removeStudentById();
        break;
    /** 
     * @brief Case 5: Update a student's information.
     */
    case 5:
        op = 0  ;
        updateStudent();
        break;
    /** 
     * @brief Case 6: Search for a student by their ID.
     */
    case 6:
        op = 0  ;
        searchStudentById();
        break;
    /** 
     * @brief Case 7: Save all student data to a file.
     */
    case 7:
        op = 0  ;
        saveData();
        break;
    /** 
     * @brief Case 8: Load student data from a file.
     */
    case 8:
        op = 0  ;
        loadData();
        break;
    /** 
     * @brief Case 9: Exit the program.
     */
    case 9:
        op = 0  ;
        exitProgram();
        break;

    /** 
     * @brief Default case: Handle invalid op  from the user.
     */
    default:
Label:
    cout << "Invalid choice! You have " << 3 - chances << " chances left.\n";

    if (chances < 3) {
        ++chances;

        cout << "Enter your choice (1, 2, or 3, ..., 9): ";
        cin >> op ;

        /** 
         * @brief Check if the new op  is valid and call handler.
         */
        if (op >= 1 && op <= 9) {
            handler();
            break;
        } else {
            cout << "Please enter a valid choice between 1 and 9.\n";
            goto Label; // Retry if op  is out of range
        }
    } else {
        /** 
         * @brief Exits the program after three invalid attempts.
         */
        chances = 0;
        cout << "Please try again at another time. All chances have ended.\n";
        exitProgram();
    }

    }
}
/*--------------------------*/
/**
 * @brief Adds a new student to the system.
 * 
 * This function prompts the user to enter details for a new student, 
 * checks if the entered ID is already taken, and then adds the new 
 * student to the list of students.
 * 
 * If the ID is already taken, the user is prompted to enter another 
 * ID, with a maximum of 3 attempts before the program exits.
 */
void addNewStudent()
{
    /**
     * @brief The ID of the student.
     */
    int id;

    /**
     * @brief The name of the student.
     */
    string name;

    /**
     * @brief The age of the student.
     */
    int age;

    /**
     * @brief The department of the student.
     */
    string department;

    /**
     * @brief The academic year of the student.
     */
    string StudentYear;

    /**
     * @brief The phone number of the student.
     */
    string phonenumber;

    /**
     * @brief The GPA of the student.
     */
    double gpa;

    /**
     * @brief Static variable to track the number of attempts.
     */
    static int i = 0;

    cout << "Enter Your Id : ";
    cin >> id;

    /**
     * @brief Check if the ID is already taken by any existing student.
     * 
     * Loops through the list of students and compares their IDs to 
     * the newly entered one.
     */
    for (auto it = Students.begin(); it != Students.end(); ++it) {
        if (it->getId() == id) {
           i++;
            cout << "The ID is already taken. Please choose a different one.You have " << 3 - i <<" attempts." << endl;
            

            /**
             * @brief Recursive call if the ID is already taken, allowing up to 3 attempts.
             */
            if (i < 3)
                addNewStudent();
            else {
                cout << "Your attempts have ended" << endl;
                handler();
            }
        }
    }

    cout << "Enter Your Name : ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Your Age : ";
    cin >> age;

    cout << "Enter Your Department : ";
    cin.ignore();
    getline(cin, department);

    cout << "Enter StudentYear : ";
    getline(cin, StudentYear);

    cout << "Enter Your Phone Number : ";
    //cin.ignore();
    getline(cin, phonenumber);

    cout << "Enter Your Gpa : ";
    cin >> gpa;

    /**
     * @brief Create a new student object and add it to the list.
     */
    Student s1(id, name, age, department, StudentYear, phonenumber, gpa);
    Students.push_back(s1);

    cout << "Student added successfully!" << endl;

    /**
     * @brief Prompt the user to continue or exit the program.
     * 
     * If the user selects "Yes", the handler function is called. 
     * Otherwise, the program exits.
     */
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo;

    if (YesNo == 1)
    {
        YesNo = 0;
        handler();
    }
    else
    {
        exitProgram();
    }
}
/*--------------------------*/
/**
 * @brief Updates the details of an existing student.
 * 
 * This function allows the user to update the information of a student 
 * by their ID. The user can update individual fields (Name, Age, Department, 
 * etc.) or update all fields at once. The function continues to prompt 
 * the user for further updates until they choose to exit.
 */
void updateStudent()
{
    /**
     * @brief The name of the student to update.
     */
    string name;

    /**
     * @brief The age of the student to update.
     */
    int age;

    /**
     * @brief The department of the student to update.
     */
    string department;

    /**
     * @brief The academic year of the student to update.
     */
    string StudentYear;

    /**
     * @brief The phone number of the student to update.
     */
    string phonenumber;

    /**
     * @brief The GPA of the student to update.
     */
    double gpa;

    /**
     * @brief Iterator to traverse the list of students.
     */
    auto it = Students.begin();

    /**
     * @brief The ID of the student being searched for.
     */
    int searchId = -1;

    /**
     * @brief The user's choice of field to update.
     */
    int choice = -1;

    cout << "Id Must Be More Than 0, ";
    cout << "Enter Student ID to Update: ";
    cin >> searchId;

    /**
     * @brief Boolean to track if the student was found.
     */
    bool found = false;

    /**
     * @brief Loop through the list of students to find the matching ID.
     */
    for (auto it = Students.begin(); it != Students.end(); ++it) {
        if (it->getId() == searchId && searchId > 0) {
    LABEL:
            cout << "Select the data you want to update:" << endl;
            cout << "1. Name" << endl;
            cout << "2. Age" << endl;
            cout << "3. Department" << endl;
            cout << "4. StudentYear" << endl;
            cout << "5. Phone Number" << endl;
            cout << "6. GPA" << endl;
            cout << "7. All" << endl;
            cout << "Enter your choice (1-7): ";
            cin >> choice;

            /**
             * @brief Switch-case structure to handle the field selection and update.
             */
            switch (choice)
            {
            case 1:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter Your Name : ";
                cin.ignore();
                getline(cin, name);
                it->setName(name);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 2:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter Your Age : ";
                cin >> age;
                it->setAge(age);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 3:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter Your Department : ";
                cin.ignore();
                getline(cin, department);
                it->setDeparment(department);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 4:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter StudentYear : ";
                cin.ignore();
                getline(cin, StudentYear);
                it->setStudentYear(StudentYear);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 5:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter Your Phone Number : ";
                cin.ignore();
                getline(cin, phonenumber);
                it->setPhoneNumber(phonenumber);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 6:
                choice = 0;
                found = true;
                searchId = 0;
                cout << "Enter Your Gpa : ";
                cin >> gpa;
                it->setGpa(gpa);
                cout << "Do you want to update anything else? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            case 7:
                choice = 0;
                found = true;
                cout << "Enter Your Name : ";
                cin.ignore();
                getline(cin, name);
                it->setName(name);
                cout << "Enter Your Age : ";
                cin >> age;
                it->setAge(age);
                cout << "Enter Your Department : ";
                cin.ignore();
                getline(cin, department);
                it->setDeparment(department);
                cout << "Enter StudentYear : ";
                cin.ignore();
                getline(cin, StudentYear);
                it->setStudentYear(StudentYear);
                cout << "Enter Your Phone Number : ";
                cin.ignore();
                getline(cin, phonenumber);
                it->setPhoneNumber(phonenumber);
                cout << "Enter Your Gpa : ";
                cin >> gpa;
                it->setGpa(gpa);
                cout << "Do you want to update anything? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    choice = 0;
                    goto LABEL;
                }
                choice = 0;
                break;

            default :
                found = true;
                choice = -1;
                cout << "Invalid Choice\n";
                cout << "Do you want to update anything? (1. Yes / 2. No): ";
                cin >> choice;
                if (choice == 1)
                {
                    goto LABEL;
                }
               
            }

        }

    }

    /**
     * @brief After the update is done, print the student's updated details.
     */
    if (choice == 0) {
        cout << "--------------------------------------------------------------------------------\n";
        cout << "             Successfully Updated. Student Details After Update                 \n";
        cout << "--------------------------------------------------------------------------------\n";
        it->print();
        cout << "--------------------------------------------------------------------------------\n";
    }

    /**
     * @brief If the student with the given ID was not found, notify the user.
     */
    if (!found) {
        cout << "Student with ID \"" << searchId << "\" not found." << endl;
    }

    /**
     * @brief Prompt the user to process another operation or exit the program.
     */
 
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo;
    if (YesNo == 1)
    {
        YesNo = 0;
        handler();
    }
    else
    {
        exitProgram();
    }

}
/*-------------------------*/
/**
 * @brief This function searches for a student by their ID.
 * 
 * Prompts the user to enter a student ID, and then searches the list of students (Students)
 * to find a matching student. If found, it displays the student's details. If not found,
 * it informs the user. After that, the user is asked whether they want to perform another
 * operation or exit the program.
 * 
 * @param None
 * @return void
 */
void searchStudentById()
{
    int searchId; ///< Variable to store the student ID entered by the user.
    cout << "Enter Student ID to search: ";
    cin >> searchId;

    bool found = false; ///< Flag to track if the student is found.

    // Iterate through the list of students.
    for (auto &Student : Students) {
        // Check if the current student's ID matches the entered ID.
        if (Student.getId() == searchId) {
           cout << "--------------------------------------------------------------------------------\n";
           cout << "                    Successfully Founded. Student Details                       \n";
           cout << "--------------------------------------------------------------------------------\n";
           Student.print(); ///< Print student details if found.
           found = true;
           break;
        }
    }

    // If no student was found, print a message.
    if (!found) {
        cout << "Student with ID \"" << searchId << "\" not found." << endl;
    }

    // Ask if the user wants to perform another operation or exit.
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo;
    if (YesNo == 1)
    {
        YesNo = 0;
        handler(); ///< Call the handler function if user wants to continue.
    }
    else
    {
        exitProgram(); ///< Exit the program if user chooses to stop.
    }
}
/*--------------------------*/

/**
 * @brief This function removes a student by their ID.
 * 
 * Prompts the user to enter a student ID, then searches the list of students (Students)
 * and removes the student if found. If the student is removed, it confirms the removal.
 * If not found, it informs the user. Finally, it asks the user whether they want to perform
 * another operation or exit.
 * 
 * @param None
 * @return void
 */
void removeStudentById()
{
    int searchId; ///< Variable to store the student ID entered by the user.
    cout << "Enter Student ID to delete: ";
    cin >> searchId;

    bool found = false; ///< Flag to track if the student is found.

    // Iterate through the list of students to find and erase the student.
    for (auto it = Students.begin(); it != Students.end();++it) {
        // Check if the current student's ID matches the entered ID.
        if (it->getId() == searchId) {
            Students.erase(it); ///< Remove student from the list.
            cout << "Removed successfully\n";
            found = true;
            break;
        }
    }

    // If no student was found, print a message.
    if (!found)
    {
        cout << "Failed to remove the Student with ID \"" << searchId << "\". Not found." << endl;
    }

    // Ask if the user wants to perform another operation or exit.
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo;
    if (YesNo == 1)
    {
        YesNo = 0;
        handler(); ///< Call the handler function if user wants to continue.
    }
    else
    {
        exitProgram(); ///< Exit the program if user chooses to stop.
    }
}
/*--------------------------*/
/**
 * @brief This function displays the details of all students.
 * 
 * If there are no students in the list (Students), it informs the user that no students
 * are available to display. If there are students, it prints a table showing the ID,
 * Name, Age, Department, StudentYear, PhoneNumber, and GPA of each student. Finally,
 * it asks the user whether they want to perform another operation or exit.
 * 
 * @param None
 * @return void
 */
void displayStudents() {
    // Check if there are no students to display.
    if (Students.empty()) {
        cout << "No Students available to display." << endl;

        // Ask if the user wants to perform another operation or exit.
        cout << "Would you like to process another operation? (1. Yes/2. No): ";
        cin >> YesNo;
        if (YesNo == 1)
        {
            YesNo = 0;
            handler(); ///< Call the handler function if user wants to continue.
        }
        else
        {
            exitProgram(); ///< Exit the program if user chooses to stop.
        }
    }

    // Print the table header.
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "                              Displaying Student Data                               " << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    
    // Print the column titles for the student data.
    cout << left << setw(10) << "ID"
        << setw(20) << "Name"
        << setw(5) << "Age"
        << setw(15) << "Department"
        << setw(15) << "StudentYear"
        << setw(15) << "PhoneNumber"
        << setw(5) << "GPA" << endl;

    cout << string(84, '-') << endl;  ///< Print separator line.

    // Iterate through the students and display each student's details.
    for ( auto& Student : Students) {
        cout << setw(10) << Student.getId()
            << setw(20) << Student.getName()
            << setw(5) << Student.getAge()
            << setw(15) << Student.getDepartment()
            << setw(15) << Student.getStudentYear()
            << setw(15) << Student.GetPhoneNumber()
            << setw(5) << fixed << setprecision(2) << Student.getGpa() << endl;
    }

    // Ask if the user wants to perform another operation or exit.
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo;
    if (YesNo == 1)
    {
        YesNo = 0;
        handler(); ///< Call the handler function if user wants to continue.
    }
    else
    {
        exitProgram(); ///< Exit the program if user chooses to stop.
    }
}

/*--------------------------*/
/**
 * @brief Clears all students based on user selection.
 *
 * Provides three options for clearing students:
 * 1. Clear from memory only.
 * 2. Clear from the database only.
 * 3. Clear from both memory and the database.
 *
 * @param choice Variable to store the user's choice of action.
 * @param YesNo Variable to store user op  for processing another operation.
 * 
 * This function handles user op  and processes clearing students from memory and/or database.
 */
void clearAllStudents() {
    int choice; ///< Variable to store the user's choice.

    cout << "Select an option:" << endl;
    cout << "1. Clear Students from memory only" << endl;
    cout << "2. Clear Students from database only" << endl;
    cout << "3. Clear Students from both memory and database" << endl;
    cout << "Enter your choice (1, 2, or 3): "; 
    cin >> choice;

    switch (choice) {
    case 1:
        if (Students.empty()) {
            cout << "No Students available to delete from memory." << endl;
        } else {
            Students.clear();
            cout << "All Students have been successfully deleted from memory." << endl;
        }
        break;

    case 2: {
        ofstream outFile("data//Students.txt", ios::trunc);
        outFile.close();
        cout << "All Students have been successfully deleted from the database." << endl;
    }
        break;

    case 3:
        if (Students.empty()) {
            cout << "No Students available to delete from memory." << endl;
        } else {
            Students.clear();
            ofstream outFile("data//Students.txt", ios::trunc);
            outFile.close();
            cout << "All Students have been successfully deleted from both memory and database." << endl;
        }
        break;

    default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }

    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo; ///< Asks if the user wants to perform another operation.

    if (YesNo == 1) {
        YesNo = 0; ///< Resets the YesNo variable for future use.
        handler(); ///< Calls the handler function to process another operation.
    } else {
        exitProgram(); ///< Exits the program if the user selects "No".
    }
}
/*--------------------------*/
/**
 * @brief Saves all student data to a file.
 * 
 * This function writes all student information to a file located at "data//Students.txt".
 * If the file cannot be opened, it will display an error message.
 * 
 * @param exitStatus A status flag to track if the function should call saveHelper.
 */
void saveData() {
    ofstream outFile("data//Students.txt"); ///< Opens file to write student data.
    
    if (outFile.is_open()) {
        outFile << "ID,Name,Age,Department,StudentYear,Phone Number,GPA" << endl;
        
        // Writes student data in CSV format.
        for (auto& Student : Students) {
            outFile << Student.getId() << ","
                    << Student.getName() << ","
                    << Student.getAge() << ","
                    << Student.getDepartment() << ","
                    << Student.getStudentYear() << ","
                    << Student.GetPhoneNumber() << ","
                    << Student.getGpa() << endl;
        }

        outFile.close(); ///< Closes the file after writing.
        cout << "Data saved successfully!" << endl;
    } else {
        cout << "Error opening file for saving." << endl;
    }

    if (exitStatus != 0) {
        saveHelper(); ///< Calls helper function to ask if the user wants to perform another operation.
    }

    exitStatus = 1; ///< Updates the exit status flag.
}

/*--------------------------*/
/**
 * @brief Helper function to handle post-save operations.
 * 
 * Asks the user if they would like to perform another operation after saving data.
 * 
 * @param YesNo Variable to store the user's response.
 */
void saveHelper() {
    cout << "Would you like to process another operation? (1. Yes/2. No): ";
    cin >> YesNo; ///< Takes op  from the user.

    if (YesNo == 1) {
        YesNo = 0; ///< Resets the YesNo variable.
        handler(); ///< Calls the handler function for the next operation.
    } else {
        cout << "Exiting program. Goodbye!" << endl;
        exit(0); ///< Terminates the program.
    }
}

/*--------------------------------*/
/**
 * @brief Loads student data from a file.
 * 
 * This function reads student data from "data//Students.txt", parses the content,
 * and adds each student to the Students vector. The first line (header) is skipped.
 * 
 * @param loadNum A static counter to track if this function has been called before.
 * @param YesNo A variable to store the user's response for performing another operation.
 * 
 * If the file cannot be opened, an error message is displayed. 
 * After loading the data, the user is asked if they want to perform another operation 
 * if the function has been called more than once.
 */
void loadData() {

    static int loadNum = 0; ///< Static counter to track if loadData has been called before.

    ifstream inFile("data//Students.txt"); ///< op  file stream to read the data file.
    
    if (inFile.is_open()) {
      
        string line; ///< Temporary string to store each line of the file.
        
        getline(inFile, line); ///< Skip the header line.
        
        while (getline(inFile, line)) {
            stringstream ss(line); ///< String stream to parse each line.
            string idStr, name, ageStr, department, StudentYear, phoneNumber, gpaStr;

            // Extract individual attributes from the line separated by commas.
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, department, ',');
            getline(ss, StudentYear, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, gpaStr, ',');

            int id = stoi(idStr); ///< Convert id string to integer.
            int age = stoi(ageStr); ///< Convert age string to integer.
            double gpa = stod(gpaStr); ///< Convert GPA string to double.

            // Add a new Student object to the Students vector.
            Students.push_back(Student(id, name, age, department, StudentYear, phoneNumber, gpa));
        }
        inFile.close(); ///< Close the file after reading all data.
        cout << "========================" << endl;
        cout << "Data loaded successfully!" << endl;
        cout << "========================" << endl;
    }
    else {
        cout << "Error opening file for loading Data." << endl; ///< Error message if file can't be opened.
    }

    if (loadNum != 0) {
        cout << "Would you like to process another operation? (1. Yes/2. No): ";
        cin >> YesNo; ///< Ask if the user wants to perform another operation.

        if (YesNo == 1) {
            YesNo = 0; ///< Reset YesNo to 0 for future use.
            handler(); ///< Call handler to continue the program.
        }
        else {
            cout << "Exiting program. Goodbye!" << endl;
            exit(0); ///< Exit the program.
        }
    }

    ++loadNum; ///< Increment loadNum to indicate that loadData has been called.
}

/*--------------------------*/
/**
 * @brief Exits the program, optionally saving changes.
 * 
 * This function prompts the user to save any changes before exiting. 
 * If the user chooses to save, the saveData function is called.
 * 
 * @param YesNo A variable to store the user's choice to save or not.
 * @param exitStatus A flag to indicate the status before exiting.
 */
void exitProgram() {
    cout << "Do you want to save changes before exiting? (1. Yes/2. No): ";
    cin >> YesNo; ///< Prompt the user to save changes before exiting.

    if (YesNo == 1) {
        exitStatus = 0; ///< Set exit status to indicate that saveData should be called.
        YesNo = 0; ///< Reset YesNo after user op .
        saveData(); ///< Call saveData to save changes.
    }

    cout << "Exiting program. Goodbye!" << endl;
    exit(0); ///< Terminate the program.
}

/*--------------------------*/









