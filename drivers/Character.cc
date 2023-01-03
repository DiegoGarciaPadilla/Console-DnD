/**
 * @file Character.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Character class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CHARACTER_CC // If the file is not defined
#define CHARACTER_CC // Define the file

#include <string>  // Include string library
#include <sstream> // Include string stream library
#include <vector>  // Include vector library

#include "../headers/Character.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Character:: Character object
 *
 */

Character::Character()
{
    name = "Character";
    gender = "Male";
    age = 18;
    alignment = "True Neutral";
    race = Race();
    clss = Class();
    stats = Stats(race);
    equippedWeapon = clss.getInitialWeapon();
    equippedArmor = clss.getInitialArmor();
}

// Getters

// There are no getters for this class because the attributes are going to be set in the constructor and change only when the player picks up or drops an item.

// Setters

/**
 * @brief Set the Name attribute
 *
 * @param name
 */

void Character::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Gender attribute
 *
 * @param gender
 */

void Character::setGender(std::string gender)
{
    this->gender = gender;
}

/**
 * @brief Set the Age attribute
 *
 * @param age
 */

void Character::setAge(int age)
{
    this->age = age;
}

/**
 * @brief Set the Alignment attribute
 *
 * @param alignment
 */

void Character::setAlignment(std::string alignment)
{
    this->alignment = alignment;
}

// Methods

/**
 * @brief Get the string representation of the object
 *
 * @return std::string
 */

std::string Character::toString()
{
    std::stringstream ss;

    ss << "CHARACTER" << std::endl;
    ss << "Name: " << name << std::endl;
    ss << "Gender: " << gender << std::endl;
    ss << "Age: " << age << std::endl;
    ss << "Alignment: " << alignment << std::endl;
    ss << "Race: " << race.getName() << std::endl;
    ss << "Class: " << clss.getName() << std::endl;
    ss << std::endl;

    ss << "STATS" << std::endl;
    ss << stats.toString() << std::endl;
    ss << std::endl;

    ss << "EQUIPPED WEAPON" << std::endl;
    ss << equippedWeapon.toString() << std::endl;
    ss << std::endl;

    ss << "EQUIPPED ARMOR" << std::endl;
    ss << equippedArmor.toString() << std::endl;
    ss << std::endl;

    return ss.str();
}

/**
 * @brief Define the race of the character
 *
 * @param option
 * @return
 */

void Character::defineRace(int option)
{
    // Initialize races vector
    std::vector<Race> races = initRaces();

    // Set race
    race = races[option];
}

/**
 * @brief Define the stats of the character
 *
 * @return
 */

void Character::defineStats()
{
    stats = Stats(race);
}

/**
 * @brief Define the class of the character
 *
 * @param option
 * @return
 */

void Character::defineClass(int option)
{
    // Initialize classes vector
    std::vector<Class> classes = initClasses();

    // Set class
    clss = classes[option];

    // Set initial weapon
    equippedWeapon = clss.getInitialWeapon();

    // Set initial armor
    equippedArmor = clss.getInitialArmor();
}

/**
 * @brief Method to open the inventory
 * 
 */

void Character::openInventory()
{
    std::cout << "INVENTORY" << std::endl;
    std::cout << std::endl;
    std::cout << inventory.toString() << std::endl;
}

#endif // End of the preprocessor CHARACTER_CC