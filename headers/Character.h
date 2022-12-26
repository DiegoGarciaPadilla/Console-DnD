/**
 * @file Character.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a character.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CHARACTER_H // If the preprocessor CHARACTER_H is not defined
#define CHARACTER_H // Define the preprocessor CHARACTER_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams

#include "Race.h"        // Include races class
#include "Class.h"       // Include classes class
#include "Stats.h"       // Include statistics class
#include "Weapon.h"      // Include weapons class
#include "Armor.h"       // Include armor class
#include "Initializer.h" // Include initializer class

class Character
{
private:
    // Attributes
    std::string name;
    std::string gender;
    int age;
    std::string alignment;
    Race race;
    Class clss;
    Stats stats;
    Weapon weapon;
    Armor armor;

public:
    // Constructors
    Character();

    // Getters
    std::string getName();
    std::string getGender();
    int getAge();
    std::string getAlignment();
    Race getRace();
    Class getClass();
    Stats getStats();
    Weapon getWeapon();
    Armor getArmor();

    // Setters
    void setName(std::string name);
    void setGender(std::string gender);
    void setAge(int age);
    void setAlignment(std::string alignment);
    void setWeapon(Weapon weapon);
    void setArmor(Armor armor);

    // Methods
    std::string toString();
    void defineRace(int option);
    void defineStats();
    void defineClass(int option);
};

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
    weapon = clss.getInitialWeapon();
    armor = clss.getInitialArmor();
}

// Getters

/**
 * @brief Get the Name attribute
 *
 * @return std::string
 */

std::string Character::getName()
{
    return name;
}

/**
 * @brief Get the Gender attribute
 *
 * @return std::string
 */

std::string Character::getGender()
{
    return gender;
}

/**
 * @brief Get the Age attribute
 *
 * @return int
 */

int Character::getAge()
{
    return age;
}

/**
 * @brief Get the Alignment attribute
 *
 * @return std::string
 */

std::string Character::getAlignment()
{
    return alignment;
}

/**
 * @brief Get the Race attribute
 * 
 * @return Race
 */

Race Character::getRace()
{
    return race;
}

/**
 * @brief Get the Class attribute
 * 
 * @return Class
 */

Class Character::getClass()
{
    return clss;
}

/**
 * @brief Get the Stats attribute
 * 
 * @return Stats
 */

Stats Character::getStats()
{
    return stats;
}

/**
 * @brief Get the Weapon attribute
 * 
 * @return Weapon
 */

Weapon Character::getWeapon()
{
    return weapon;
}

/**
 * @brief Get the Armor attribute
 * 
 * @return Armor
 */

Armor Character::getArmor()
{
    return armor;
}

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
 * @param option 
 */

void Character::setAlignment(int option)
{
    // Create the array of alignments
    std::vector<std::string> alignments = listAlignments();

    // Set the alignment
    alignment = alignments[option];
}

/**
 * @brief Set the Weapon attribute
 * 
 * @param weapon 
 */

void Character::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}

/**
 * @brief Set the Armor attribute
 * 
 * @param armor 
 */

void Character::setArmor(Armor armor)
{
    this->armor = armor;
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

    ss << "WEAPON" << std::endl;
    ss << weapon.toString() << std::endl;

    ss << "ARMOR" << std::endl;
    ss << armor.toString() << std::endl;

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
}

#endif // End of PERSONAJE_H preprocessor