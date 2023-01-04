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
 * @brief Show the inventory
 *
 */

void Character::showInventory()
{
    // Variables
    int option = 0;
    int itemNum = 1;

    do
    {
        // Reset the item number
        itemNum = 1;

        // Clear the screen
        cleanScreen();

        // Title
        std::cout << readAsciiArt("ascii/inventory.txt") << std::endl;

        // Gold
        std::cout << "Gold: " << inventory.getGold() << std::endl;
        std::cout << std::endl;

        // Current and max weight
        std::cout << "Current Weight: " << inventory.getCurrentWeight() << std::endl;
        std::cout << "Max Weight: " << inventory.getMaxWeight() << std::endl;
        std::cout << std::endl;

        // Weapons
        if (inventory.getWeapons().size() > 0)
        {
            std::cout << "Weapons: " << std::endl;
            for (int i = 0; i < inventory.getWeapons().size(); i++)
            {
                std::cout << itemNum << ". " << inventory.getWeapons()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Armors
        if (inventory.getArmors().size() > 0)
        {
            std::cout << "Armors: " << std::endl;
            for (int i = 0; i < inventory.getArmors().size(); i++)
            {
                std::cout << itemNum << ". " << inventory.getArmors()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Consumables
        if (inventory.getConsumables().size() > 0)
        {
            std::cout << "Consumables: " << std::endl;
            for (int i = 0; i < inventory.getConsumables().size(); i++)
            {
                std::cout << itemNum << ". " << inventory.getConsumables()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Quest Items
        if (inventory.getQuestItems().size() > 0)
        {
            std::cout << "Quest Items: " << std::endl;
            for (int i = 0; i < inventory.getQuestItems().size(); i++)
            {
                std::cout << itemNum << ". " << inventory.getQuestItems()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Exit
        std::cout << itemNum << ". Exit" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter an option: ";
        std::cin >> option;
        std::cout << std::endl;

        // Check the option
        if (option != itemNum)
        {
            // Clear the screen
            cleanScreen();

            // Variables
            int itemOption = 0;

            // Check the option
            if (option <= inventory.getWeapons().size())
            {
                // Show the weapon
                std::cout << inventory.getWeapons()[option - 1].toString() << std::endl;
            }
            else if (option <= inventory.getWeapons().size() + inventory.getArmors().size())
            {
                // Show the armor
                std::cout << inventory.getArmors()[option - inventory.getWeapons().size() - 1].toString() << std::endl;
            }
            else if (option <= inventory.getWeapons().size() + inventory.getArmors().size() + inventory.getConsumables().size())
            {
                // Show the consumable
                std::cout << inventory.getConsumables()[option - inventory.getWeapons().size() - inventory.getArmors().size() - 1].toString() << std::endl;
            }
            else if (option <= inventory.getWeapons().size() + inventory.getArmors().size() + inventory.getConsumables().size() + inventory.getQuestItems().size())
            {
                // Show the quest item
                std::cout << inventory.getQuestItems()[option - inventory.getWeapons().size() - inventory.getArmors().size() - inventory.getConsumables().size() - 1].toString() << std::endl;
            }

            // Get the item option
            std::cout << "1. Use / Equip" << std::endl;
            std::cout << "2. Drop" << std::endl;
            std::cout << "3. Return" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter an option: ";
            std::cin >> itemOption;
            std::cout << std::endl;

            // Clear the screen
            cleanScreen();

            // Check the item option
            switch (itemOption)
            {
            case 1:
                // Check the option
                if (option <= inventory.getWeapons().size())
                {
                    // Message
                    std::cout << "You equipped the " << inventory.getWeapons()[option - 1].getName() << "." << std::endl;
                    // Equip the weapon
                    equipWeapon(inventory.getWeapons()[option - 1]);
                }
                else if (option <= inventory.getWeapons().size() + inventory.getArmors().size())
                {
                    // Message
                    std::cout << "You equipped the " << inventory.getArmors()[option - inventory.getWeapons().size() - 1].getName() << "." << std::endl;
                    // Equip the armor
                    equipArmor(inventory.getArmors()[option - inventory.getWeapons().size() - 1]);
                }
                else 
                {
                    // Message
                    std::cout << "Unimplemented." << std::endl;
                }
                break;
            case 2:
                if (option <= inventory.getWeapons().size())
                {
                    // Message
                    std::cout << "You dropped the " << inventory.getWeapons()[option - 1].getName() << "." << std::endl;
                    // Drop the weapon
                    inventory.removeWeapon(inventory.getWeapons()[option - 1]);
                }
                else if (option <= inventory.getWeapons().size() + inventory.getArmors().size())
                {
                    // Message
                    std::cout << "You dropped the " << inventory.getArmors()[option - inventory.getWeapons().size() - 1].getName() << "." << std::endl;
                    // Drop the armor
                    inventory.removeArmor(inventory.getArmors()[option - inventory.getWeapons().size() - 1]);
                }
                else if (option <= inventory.getWeapons().size() + inventory.getArmors().size() + inventory.getConsumables().size())
                {
                    // Message
                    std::cout << "You dropped the " << inventory.getConsumables()[option - inventory.getWeapons().size() - inventory.getArmors().size() - 1].getName() << "." << std::endl;
                    // Drop the consumable
                    inventory.removeConsumable(inventory.getConsumables()[option - inventory.getWeapons().size() - inventory.getArmors().size() - 1]);
                }
                else if (option <= inventory.getWeapons().size() + inventory.getArmors().size() + inventory.getConsumables().size() + inventory.getQuestItems().size())
                {
                    // Message
                    std::cout << "You dropped the " << inventory.getQuestItems()[option - inventory.getWeapons().size() - inventory.getArmors().size() - inventory.getConsumables().size() - 1].getName() << "." << std::endl;
                    // Drop the quest item
                    inventory.removeQuestItem(inventory.getQuestItems()[option - inventory.getWeapons().size() - inventory.getArmors().size() - inventory.getConsumables().size() - 1]);
                }
                // Pause
                pause();
                break;
            case 3:
                break;
            default:
                break;
            }
        }

    } while (option != itemNum);
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

/**
 * @brief Method to equip a weapon
 *
 */

void Character::equipWeapon(Weapon weapon)
{
    // Check if the weapon is in the inventory
    if (inventory.hasWeapon(weapon))
    {
        // Check if the weapon is already equipped
        if (equippedWeapon.getName() == weapon.getName())
        {
            std::cout << "The weapon is already equipped." << std::endl;
        }
        else
        {
            // Unequip the current weapon
            unequipWeapon();

            // Equip the new weapon
            equippedWeapon = weapon;
            std::cout << "The weapon has been equipped." << std::endl;
        }
    }
    else
    {
        std::cout << "The weapon is not in the inventory." << std::endl;
    }
}

/**
 * @brief Method to equip an armor
 *
 */

void Character::equipArmor(Armor armor)
{
    // Check if the armor is in the inventory
    if (inventory.hasArmor(armor))
    {
        // Check if the armor is already equipped
        if (equippedArmor.getName() == armor.getName())
        {
            std::cout << "The armor is already equipped." << std::endl;
        }
        else
        {
            // Unequip the current armor
            unequipArmor();

            // Equip the new armor
            equippedArmor = armor;
            std::cout << "The armor has been equipped." << std::endl;
        }
    }
    else
    {
        std::cout << "The armor is not in the inventory." << std::endl;
    }
}

/**
 * @brief Method to unequip a weapon
 *
 */

void Character::unequipWeapon()
{
    // Check if the weapon is equipped
    if (equippedWeapon.getName() == "None")
    {
        std::cout << "The weapon is not equipped." << std::endl;
    }
    else
    {
        // Unequip the weapon
        equippedWeapon = Weapon();
        std::cout << "The weapon has been unequipped." << std::endl;
    }
}

/**
 * @brief Method to unequip an armor
 *
 */

void Character::unequipArmor()
{
    // Check if the armor is equipped
    if (equippedArmor.getName() == "None")
    {
        std::cout << "The armor is not equipped." << std::endl;
    }
    else
    {
        // Unequip the armor
        equippedArmor = Armor();
        std::cout << "The armor has been unequipped." << std::endl;
    }
}

#endif // End of the preprocessor CHARACTER_CC