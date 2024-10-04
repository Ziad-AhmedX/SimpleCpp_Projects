#include "Student.h"

/*-------------------------- Constructor ---------------------------*/
/**
 * @brief Default constructor for the Student class.
 * 
 * This constructor initializes a Student object with default values.
 */
Student::Student() :BasePerson()
{
	this->department = "unknown";
	this->StudentYear= "unknown";
	this->gpa = 0.0;
}

//------- 
/**
 * @brief Parameterized constructor for the Student class.
 * 
 * This constructor initializes a Student object with specified values.
 * 
 * @param idParam The Student's ID.
 * @param nameParam The Student's name.
 * @param ageParam The Student's age.
 * @param departmentParam The Student's department.
 * @param StudentYearParam The year of study for the Student.
 * @param phoneNumberParam The Student's phone number.
 * @param gpaParam The Student's GPA.
 */
Student::Student(int idParam, string nameParam, int ageParam, string departmentParam, string StudentYearParam, string phoneNumberParam, double gpaParam)
	:BasePerson(idParam, nameParam, ageParam, phoneNumberParam)
{
	this->department = departmentParam;
	this->StudentYear = StudentYearParam;
	this->gpa = gpaParam;
}

//------- 
/*----------------------------- Setter -----------------------------*/
/**
 * @brief Sets the GPA of the Student.
 * 
 * @param gpaParam The GPA to set.
 */
void Student::setGpa(double gpaParam)
{
	this->gpa = gpaParam;
}

//------- 
/**
 * @brief Sets the department of the Student.
 * 
 * @param departmentParam The department to set.
 */
void Student::setDeparment(string departmentParam)
{
	this->department = departmentParam;
}

/**
 * @brief Sets the year of study for the Student.
 * 
 * @param StudentYearParam The year of study to set.
 */
void Student::setStudentYear(string StudentYearParam)
{
	this->StudentYear = StudentYearParam;
}

/*----------------------------- Getter -----------------------------*/
/**
 * @brief Gets the GPA of the Student.
 * 
 * @return The Student's GPA.
 */
double Student::getGpa()
{
	return this->gpa;
}

//------- 
/**
 * @brief Gets the department of the Student.
 * 
 * @return The Student's department.
 */
string Student::getDepartment()
{
	return this->department;
}

//------- 
/**
 * @brief Gets the year of study for the Student.
 * 
 * @return The year of study.
 */
string Student::getStudentYear()
{
	return this->StudentYear;
}

//------- 
/*----------------------------- General -----------------------------*/
/**
 * @brief Prints the details of the Student.
 * 
 * This function prints the Student's personal details along with GPA, department, 
 * and year of study.
 */
void Student::print()
{
	BasePerson::print();
	cout << "Gpa is : " << this->gpa << endl;
	cout << "Department is : " << this->department << endl;
	cout << "The Student is now in StudentYear: " << this->StudentYear << endl;
}

//------- 
/*------------------------------------------------------------------*/

