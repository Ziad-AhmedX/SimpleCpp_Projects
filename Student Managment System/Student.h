#ifndef Student_H // Include guard to prevent multiple inclusions
#define Student_H

#include <string> // Include the string library
#include "BasePerson.h" // Include the BasePerson header file
using namespace std; // Use the standard namespace

/**
 * @brief Represents a Student, derived from BasePerson.
 *
 * This class contains information about a Student, including their 
 * department, year of study, and GPA.
 */
class Student : public BasePerson
{
private:
	string department; ///< The Student's department.
	string StudentYear; ///< The year of study for the Student.
	double gpa; ///< The Student's GPA.
	
public:
	/*-------------------------- Constructor ---------------------------*/
	/**
	 * @brief Default constructor for the Student class.
	 *
	 * Initializes a Student object with default values.
	 */
	Student();
	
	/**
	 * @brief Parameterized constructor for the Student class.
	 *
	 * Initializes a Student object with specified values.
	 *
	 * @param idParam The Student's ID.
	 * @param nameParam The Student's name.
	 * @param ageParam The Student's age.
	 * @param departmentParam The Student's department.
	 * @param StudentYearParam The year of study for the Student.
	 * @param phoneNumberParam The Student's phone number.
	 * @param gpaParam The Student's GPA.
	 */
	Student(int idParam, string nameParam, int ageParam,string departmentParam,string StudentYearParam, string phoneNumberParam, double gpaParam);
	
	/*----------------------------- Setter -----------------------------*/
	/**
	 * @brief Sets the GPA for the Student.
	 *
	 * @param gpaParam The GPA to set for the Student.
	 */
	void setGpa(double gpaParam);
	
	/**
	 * @brief Sets the department for the Student.
	 *
	 * @param departmentParam The department to set for the Student.
	 */
	void setDeparment(string departmentParam);
	
	/**
	 * @brief Sets the year of study for the Student.
	 *
	 * @param StudentYearParam The year of study to set for the Student.
	 */
	void setStudentYear(string StudentYearParam);
	
	/*----------------------------- Getter -----------------------------*/
	/**
	 * @brief Gets the GPA of the Student.
	 *
	 * @return The GPA of the Student.
	 */
	double getGpa();
	
	/**
	 * @brief Gets the department of the Student.
	 *
	 * @return The department of the Student.
	 */
	string getDepartment();
	
	/**
	 * @brief Gets the year of study for the Student.
	 *
	 * @return The year of study of the Student.
	 */
	string getStudentYear();
	
	/*----------------------------- General -----------------------------*/
	/**
	 * @brief Prints the details of the Student.
	 *
	 * This function prints the Student's GPA, department, and year of study,
	 * along with the base person details.
	 */
	void print();
	/*------------------------------------------------------------------*/
};

#endif /* Student_H */ // End of include guard
