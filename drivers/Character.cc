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
 * @param alignment
 */

void Character::setAlignment(std::string alignment)
{
    this->alignment = alignment;
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

#endif // End of the preprocessor CHARACTER_CC