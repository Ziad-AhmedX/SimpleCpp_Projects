#ifndef BasePerson_H
#define BasePerson_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @file basePerson.h
 * @brief Version 1.0
 *
 * This is the base class for managing Students, courses, and teachers.
 * Future versions may include inheritance for Course and Teacher classes.
 */

/**
 * @class BasePerson
 * @brief A base class representing a person with basic attributes like id, name, age, and phone number.
 */
class BasePerson
{
protected:
    int id;           /**< @brief ID of the person */
    string name;      /**< @brief Name of the person */
    int age;          /**< @brief Age of the person */
    string phoneNumber; /**< @brief Phone number of the person */

public:
    /*-------------------------- Constructor ---------------------------*/

    /**
     * @brief Default constructor that initializes the member variables to default values.
     */
    BasePerson();

    /**
     * @brief Parameterized constructor that initializes the member variables with provided values.
     * @param idParam The ID of the person.
     * @param nameParam The name of the person.
     * @param ageParam The age of the person.
     * @param phoneNumberParam The phone number of the person.
     */
    BasePerson(int idParam, string nameParam, int ageParam, string phoneNumberParam);

    /*----------------------------- Setter -----------------------------*/

    /**
     * @brief Sets the ID of the person.
     * @param idParam The ID to set.
     */
    void setId(int idParam);

    /**
     * @brief Sets the name of the person.
     * @param nameParam The name to set.
     */
    void setName(string nameParam);

    /**
     * @brief Sets the age of the person.
     * @param ageParam The age to set.
     */
    void setAge(int ageParam);

    /**
     * @brief Sets the phone number of the person.
     * @param phoneNumberParam The phone number to set.
     */
    void setPhoneNumber(string phoneNumberParam);

    /*----------------------------- Getter -----------------------------*/

    /**
     * @brief Gets the ID of the person.
     * @return The ID of the person.
     */
    int getId();

    /**
     * @brief Gets the name of the person.
     * @return The name of the person.
     */
    string getName();

    /**
     * @brief Gets the age of the person.
     * @return The age of the person.
     */
    int getAge();

    /**
     * @brief Gets the phone number of the person with the country code +20 prefixed.
     * @return The phone number of the person.
     */
    string GetPhoneNumber();

    /*----------------------------- General -----------------------------*/

    /**
     * @brief Prints the details of the person.
     */
    virtual void print();

    /*------------------------------------------------------------------*/
};

#endif
