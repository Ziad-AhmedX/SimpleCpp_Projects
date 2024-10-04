#include "BasePerson.h"

/** 
 * @class BasePerson
 * @brief A base class representing a person with basic attributes like id, name, age, and phone number.
 */

/*-------------------------- Constructor ---------------------------*/

/**
 * @brief Default constructor that initializes the member variables to default values.
 */
BasePerson::BasePerson()
{
	this->id = 0;
	this->name = "unknown";
	this->age = 0;
	this->phoneNumber = "0";
}

//-------

/**
 * @brief Parameterized constructor that initializes the member variables with provided values.
 * @param idParam The ID of the person.
 * @param nameParam The name of the person.
 * @param ageParam The age of the person.
 * @param phoneNumberParam The phone number of the person.
 */
BasePerson::BasePerson(int idParam, string nameParam, int ageParam, string phoneNumberParam)
{
	this->id = idParam;
	this->name = nameParam;
	this->age = ageParam;
	this->phoneNumber = phoneNumberParam;
}

/*----------------------------- Setter -----------------------------*/

/**
 * @brief Sets the ID of the person.
 * @param idParam The ID to set.
 */
void BasePerson::setId(int idParam)
{
	this->id = idParam;
}

//-------

/**
 * @brief Sets the name of the person.
 * @param nameParam The name to set.
 */
void BasePerson::setName(string nameParam)
{
	this->name = nameParam;
}

//-------

/**
 * @brief Sets the age of the person.
 * @param ageParam The age to set.
 */
void BasePerson::setAge(int ageParam)
{
	this->age = ageParam;
}

//-------

/**
 * @brief Sets the phone number of the person.
 * @param phoneNumberParam The phone number to set.
 */
void BasePerson::setPhoneNumber(string phoneNumberParam)
{
	this->phoneNumber =phoneNumberParam;
}

//-------

/*----------------------------- Getter -----------------------------*/

/**
 * @brief Gets the ID of the person.
 * @return The ID of the person.
 */
int BasePerson::getId()
{
	return this->id;
}

//-------

/**
 * @brief Gets the name of the person.
 * @return The name of the person.
 */
string BasePerson::getName()
{
	return this->name;
}

//-------

/**
 * @brief Gets the age of the person.
 * @return The age of the person.
 */
int BasePerson::getAge()
{
	return this->age;
}

//-------

/**
 * @brief Gets the phone number of the person with the country code +20 prefixed.
 * @return The phone number of the person.
 */
string BasePerson::GetPhoneNumber()
{
	
	return  (this->phoneNumber);
}

//-------

/*----------------------------- General -----------------------------*/

/**
 * @brief Prints the details of the person.
 */
void BasePerson::print()
{
	cout << "Name is : " << name ;
	cout << "\nId is : " << id ;
	cout << "\nAge is : " << age ;
	cout << "\nPhoneNumber is : " << phoneNumber << endl;
}

//-------

/*------------------------------------------------------------------*/
