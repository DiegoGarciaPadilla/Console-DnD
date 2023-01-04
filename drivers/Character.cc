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
#include "Initializer.cc"         // Include the Initializer file

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
 * @brief Function to create a character with the data entered by the user
 *
 * @param character
 * @return
 */

void Character::createCharacter()
{
    // Variables
    std::string name;
    std::string gender;
    int age;
    std::string alignment;
    Race race;
    int option;

    // Vectors
    std::vector<std::string> genders = listGenders();
    std::vector<std::string> alignments = listAlignments();
    std::vector<std::string> races = listRaces();
    std::vector<std::string> classes = listClasses();

    // Clear the screen
    cleanScreen();

    // Introduction
    std::cout << "Hello adventurer! Welcome to the world of D&D!" << std::endl;
    std::cout << "I'm going to ask you some questions to create your character." << std::endl;
    std::cout << "Are you ready? " << std::endl;
    pause();

    // Clear the screen
    cleanScreen();

    // Set the name
    std::cout << "What is your name? ";
    getline(std::cin >> std::ws, name);
    std::cout << std::endl;
    this->name = name;

    // Set the gender
    std::cout << "What gender do you identify with? " << std::endl;
    printStringVector(genders);
    std::cin >> option;
    while (option < 1 || option > 3)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    // If the user chooses the option 3, it will ask for the specific gender
    if (option == 3)
    {
        std::string specificGender;
        std::cout << "Can you specify it? " << std::endl;
        getline(std::cin >> std::ws, specificGender);
        this->gender = specificGender;
    }
    else
    {
        this->gender = genders[option - 1];
    }
    std::cout << std::endl;

    // Set the age
    std::cout << "Age: ";
    std::cin >> age;
    while (age < 0)
    {
        std::cout << "Invalid age" << std::endl;
        std::cin >> age;
    }
    std::cout << std::endl;
    this->age = age;

    // Set the alignment
    std::cout << "Alignment: " << std::endl;
    printStringVector(alignments);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    this->alignment = alignments[option - 1];

    // Set the race
    std::cout << "Race: " << std::endl;
    printStringVector(races);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    this->defineRace(option - 1);

    // Set the class
    std::cout << "Class: " << std::endl;
    printStringVector(classes);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    this->defineClass(option - 1);

    // Set the stats
    std::cout << "Stats:" << std::endl;
    std::cout << "The stats are generated randomly." << std::endl;
    this->defineStats();
    std::cout << std::endl;
}

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

void Character::showInventory()
{
    inventory.showInventory();
}

/**
 * @brief Method to add a weapon to the inventory
 *
 */

void Character::addWeaponToInventory(Weapon weapon)
{
    inventory.addWeapon(weapon);
}

/**
 * @brief Method to add an armor to the inventory
 *
 */

void Character::addArmorToInventory(Armor armor)
{
    inventory.addArmor(armor);
}

/**
 * @brief Method to add a consumable to the inventory
 *
 */

void Character::addConsumableToInventory(Consumable consumable)
{
    inventory.addConsumable(consumable);
}

/**
 * @brief Method to add a quest item to the inventory
 *
 */

void Character::addQuestItemToInventory(QuestItem questItem)
{
    inventory.addQuestItem(questItem);
}

/**
 * @brief Method to remove a weapon from the inventory
 *
 */

void Character::removeWeaponFromInventory(Weapon weapon)
{
    inventory.removeWeapon(weapon);
}

/**
 * @brief Method to remove an armor from the inventory
 *
 */

void Character::removeArmorFromInventory(Armor armor)
{
    inventory.removeArmor(armor);
}

/**
 * @brief Method to remove a consumable from the inventory
 *
 */

void Character::removeConsumableFromInventory(Consumable consumable)
{
    inventory.removeConsumable(consumable);
}

/**
 * @brief Method to remove a quest item from the inventory
 *
 */

void Character::removeQuestItemFromInventory(QuestItem questItem)
{
    inventory.removeQuestItem(questItem);
}

#endif // End of the preprocessor CHARACTER_CC