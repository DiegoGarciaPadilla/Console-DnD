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
#include "Functions.cc"           // Include the Functions file

// Constructors

/**
 * @brief Construct a new Character:: Character object
 *
 */

Character::Character()
{
    name = "None";
    gender = "None";
    age = 0;
    alignment = "True Neutral";

    health = 100;
    mana = 100;
    stamina = 100;

    maxHealth = 100;
    maxMana = 100;
    maxStamina = 100;

    damage = 0;
    defense = 0;

    race = Race();
    clss = Class();
    stats = Stats(race);

    equippedWeapon = clss.getInitialWeapon();
    equippedArmor = clss.getInitialArmor();
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
 * @brief Get the Health attribute
 *
 * @return int
 */

int Character::getHealth()
{
    return health;
}

/**
 * @brief Get the Mana attribute
 *
 * @return int
 */

int Character::getMana()
{
    return mana;
}

/**
 * @brief Get the Stamina attribute
 *
 * @return int
 */

int Character::getStamina()
{
    return stamina;
}

/**
 * @brief Get the Max Health attribute
 *
 * @return int
 */

int Character::getMaxHealth()
{
    return maxHealth;
}

/**
 * @brief Get the Max Mana attribute
 *
 * @return int
 */

int Character::getMaxMana()
{
    return maxMana;
}

/**
 * @brief Get the Max Stamina attribute
 *
 * @return int
 */

int Character::getMaxStamina()
{
    return maxStamina;
}

/**
 * @brief Get the Damage attribute
 *
 * @return int
 */

int Character::getDamage()
{
    return damage;
}

/**
 * @brief Get the Defense attribute
 *
 * @return int
 */

int Character::getDefense()
{
    return defense;
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
 * @brief Set the Health attribute
 *
 * @param health
 */

void Character::setHealth(int health)
{
    this->health = health;
}

/**
 * @brief Set the Mana attribute
 *
 * @param mana
 */

void Character::setMana(int mana)
{
    this->mana = mana;
}

/**
 * @brief Set the Stamina attribute
 *
 * @param stamina
 */

void Character::setStamina(int stamina)
{
    this->stamina = stamina;
}

/**
 * @brief Set the Max Health attribute
 *
 * @param maxHealth
 */

void Character::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

/**
 * @brief Set the Max Mana attribute
 *
 * @param maxMana
 */

void Character::setMaxMana(int maxMana)
{
    this->maxMana = maxMana;
}

/**
 * @brief Set the Max Stamina attribute
 *
 * @param maxStamina
 */

void Character::setMaxStamina(int maxStamina)
{
    this->maxStamina = maxStamina;
}

/**
 * @brief Set the Damage attribute
 *
 * @param attack
 */

void Character::setDamage(int damage)
{
    this->damage = damage;
}

/**
 * @brief Set the Defense attribute
 *
 * @param defense
 */

void Character::setDefense(int defense)
{
    this->defense = defense;
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

    ss << readAsciiArt("asciiArt/myCharacter.txt") << std::endl;

    ss << "CHARACTER" << std::endl;
    ss << "Name: " << name << std::endl;
    ss << "Gender: " << gender << std::endl;
    ss << "Age: " << age << std::endl;
    ss << "Alignment: " << alignment << std::endl;
    ss << "Race: " << race.getName() << std::endl;
    ss << "Class: " << clss.getName() << std::endl;
    ss << std::endl;

    ss << "DAMAGE AND DEFENSE" << std::endl;
    ss << "Damage: " << damage << std::endl;
    ss << "Defense: " << defense << std::endl;
    ss << std::endl;

    ss << "STATS" << std::endl;
    ss << stats.toString() << std::endl;
    ss << std::endl;

    ss << "EQUIPPED WEAPON" << std::endl;
    if (equippedWeapon.getName() == "None")
    {
        ss << "There is no weapon equipped." << std::endl;
    }
    else
    {
        ss << equippedWeapon.toString() << std::endl;
    }
    ss << std::endl;

    ss << "EQUIPPED ARMOR" << std::endl;
    if (equippedArmor.getName() == "None")
    {
        ss << "There is no armor equipped." << std::endl;
    }
    else
    {
        ss << equippedArmor.toString() << std::endl;
    }
    ss << std::endl;

    return ss.str();
}

/**
 * @brief Get the gold of the character from the inventory
 *
 * @return int
 */

int Character::getGold()
{
    return inventory.getGold();
}

/**
 * @brief Set the gold of the character
 *
 * @param gold
 * @return
 */

void Character::setGold(int gold)
{
    inventory.setGold(gold);
}

/**
 * @brief Add gold to the character
 *
 * @param gold
 * @return
 */

void Character::addGold(int gold)
{
    inventory.setGold(inventory.getGold() + gold);
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
    damage += clss.getInitialWeapon().getDamage();

    // Set initial armor
    equippedArmor = clss.getInitialArmor();
    defense += clss.getInitialArmor().getDefense();
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
    int numWeapons;
    int numArmors;
    int numPotions;
    int numQuestItems;

    do
    {
        // Reset the item number
        itemNum = 1;

        // Get the number of items
        numWeapons = inventory.getWeapons().size();
        numArmors = inventory.getArmors().size();
        numPotions = inventory.getPotions().size();
        numQuestItems = inventory.getQuestItems().size();

        // Clear the screen
        cleanScreen();

        // Title
        std::cout << readAsciiArt("asciiArt/inventory.txt") << std::endl;

        // Gold
        std::cout << "Gold: " << inventory.getGold() << std::endl;
        std::cout << std::endl;

        // Current and max weight
        std::cout << "Current Weight: " << inventory.getCurrentWeight() << std::endl;
        std::cout << "Max Weight: " << inventory.getMaxWeight() << std::endl;
        std::cout << std::endl;

        // Weapons
        if (numWeapons > 0)
        {
            std::cout << "Weapons: " << std::endl;
            for (int i = 0; i < numWeapons; i++)
            {
                std::cout << itemNum << ". " << inventory.getWeapons()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Armors
        if (numArmors > 0)
        {
            std::cout << "Armors: " << std::endl;
            for (int i = 0; i < numArmors; i++)
            {
                std::cout << itemNum << ". " << inventory.getArmors()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Potions
        if (numPotions > 0)
        {
            std::cout << "Potions: " << std::endl;
            for (int i = 0; i < numPotions; i++)
            {
                std::cout << itemNum << ". " << inventory.getPotions()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Quest Items
        if (numQuestItems > 0)
        {
            std::cout << "Quest Items: " << std::endl;
            for (int i = 0; i < numQuestItems; i++)
            {
                std::cout << itemNum << ". " << inventory.getQuestItems()[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Exit
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter an option: ";
        std::cin >> option;
        std::cout << std::endl;

        // Check the option
        if (option != 0)
        {
            // Clear the screen
            cleanScreen();

            // Variables
            int itemOption = 0;

            // Check the option
            if (option <= numWeapons)
            {
                // Show the weapon
                std::cout << inventory.getWeapons()[option - 1].toString() << std::endl;
            }
            else if (option <= numWeapons + numArmors)
            {
                // Show the armor
                std::cout << inventory.getArmors()[option - numWeapons - 1].toString() << std::endl;
            }
            else if (option <= numWeapons + numArmors + numPotions)
            {
                // Show the potion
                std::cout << inventory.getPotions()[option - numWeapons - numArmors - 1].toString() << std::endl;
            }
            else if (option <= numWeapons + numArmors + numPotions + numQuestItems)
            {
                // Show the quest item
                std::cout << inventory.getQuestItems()[option - numWeapons - numArmors - numPotions - 1].toString() << std::endl;
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
                if (option <= numWeapons)
                {
                    // Equip the weapon
                    equipWeapon(option - 1);
                }
                else if (option <= numWeapons + numArmors)
                {
                    // Equip the armor
                    equipArmor(option - numWeapons - 1);
                }
                else if (option <= numWeapons + numArmors + numPotions)
                {
                    // Use the potion
                    drinkPotion(option - numWeapons - numArmors - 1);
                }
                else if (option <= numWeapons + numArmors + numPotions + numQuestItems)
                {
                    // Message
                    std::cout << "Quest items cannot be used." << std::endl;
                }
                // Pause
                pause();
                break;
            case 2:
                if (option <= inventory.getWeapons().size())
                {
                    // Drop the weapon
                    inventory.removeWeapon(option - 1);
                }
                else if (option <= inventory.getWeapons().size() + numArmors)
                {
                    // Drop the armor
                    inventory.removeArmor(option - inventory.getWeapons().size() - 1);
                }
                else if (option <= inventory.getWeapons().size() + numArmors + numPotions)
                {
                    // Drop the potion
                    inventory.removePotion(option - inventory.getWeapons().size() - numArmors - 1);
                }
                else if (option <= inventory.getWeapons().size() + numArmors + numPotions + numQuestItems)
                {
                    // Drop the quest item
                    inventory.removeQuestItem(option - inventory.getWeapons().size() - numArmors - numPotions - 1);
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

    } while (option != 0);
}

/**
 * @brief Method to show the equipped items
 *
 */

void Character::showEquippedItems()
{
    // Variables
    int option;
    int itemOption;
    int itemNum = 1;
    bool weaponEquipped = false;
    bool armorEquipped = false;

    do
    {
        // Clear the screen
        cleanScreen();

        // Reset the variables
        itemNum = 1;
        weaponEquipped = false;
        armorEquipped = false;

        // Check if the weapon is equipped
        if (equippedWeapon.getName() != "None")
        {
            weaponEquipped = true;
        }

        // Check if the armor is equipped
        if (equippedArmor.getName() != "None")
        {
            armorEquipped = true;
        }

        // Title
        std::cout << readAsciiArt("asciiArt/equipment.txt") << std::endl;

        // Show the equipped weapon
        std::cout << "Weapon: " << std::endl;
        if (weaponEquipped)
        {
            std::cout << itemNum << ". " << equippedWeapon.getName() << std::endl;
            itemNum++;
        }
        else
        {
            std::cout << "There is no weapon equipped." << std::endl;
        }
        std::cout << std::endl;

        // Show the equipped armor
        std::cout << "Armor: " << std::endl;
        if (armorEquipped)
        {
            std::cout << itemNum << ". " << equippedArmor.getName() << std::endl;
            itemNum++;
        }
        else
        {
            std::cout << "There is no armor equipped." << std::endl;
        }
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter an option: " << std::endl;
        std::cin >> option;

        // Check the option
        if (option == 0)
        {
            // Return
            return;
        }
        else
        {
            // Clear the screen
            cleanScreen();

            // Show the selected item
            if (option == 1 && weaponEquipped)
            {
                // Show the equipped weapon
                std::cout << "EQUIPPED WEAPON" << std::endl;
                std::cout << equippedWeapon.toString() << std::endl;
                std::cout << std::endl;

                // Show options
                std::cout << "1. Unequip" << std::endl;
                std::cout << "2. Return" << std::endl;

                // Get the option
                std::cout << "Enter an option: " << std::endl;
                std::cin >> itemOption;

                // Check the option
                if (itemOption == 1)
                {
                    // Clear the screen
                    cleanScreen();

                    // Unequip the weapon
                    unequipWeapon();

                    // Pause
                    pause();
                }
                else if (itemOption == 2)
                {
                    // Return
                    return;
                }
            }
            else if ((option == 2 && weaponEquipped && armorEquipped) || (option == 1 && !weaponEquipped && armorEquipped))
            {
                // Show the equipped armor
                std::cout << "EQUIPPED ARMOR" << std::endl;
                std::cout << equippedArmor.toString() << std::endl;
                std::cout << std::endl;

                // Show options
                std::cout << "1. Unequip" << std::endl;
                std::cout << "2. Return" << std::endl;

                // Get the option
                std::cout << "Enter an option: " << std::endl;
                std::cin >> itemOption;

                // Check the option
                if (itemOption == 1)
                {
                    // Clear the screen
                    cleanScreen();

                    // Unequip the armor
                    unequipArmor();

                    // Pause
                    pause();
                }
                else if (itemOption == 2)
                {
                    // Return
                    return;
                }
            }
        }

    } while (option != 0);
}

/**
 * @brief Get the character's weapons in the inventory
 *
 * @return std::vector<Weapon>
 */

std::vector<Weapon> Character::getWeapons()
{
    return inventory.getWeapons();
}

/**
 * @brief Get the character's armors in the inventory
 *
 * @return std::vector<Armor>
 */

std::vector<Armor> Character::getArmors()
{
    return inventory.getArmors();
}

/**
 * @brief Get the character's potions in the inventory
 *
 * @return std::vector<Potion>
 */

std::vector<Potion> Character::getPotions()
{
    return inventory.getPotions();
}

/**
 * @brief Get the character's quest items in the inventory
 *
 * @return std::vector<QuestItem>
 */

std::vector<QuestItem> Character::getQuestItems()
{
    return inventory.getQuestItems();
}

/**
 * @brief Method to add a weapon to the inventory
 *
 * @param weapon
 */

void Character::addWeaponToInventory(Weapon weapon)
{
    inventory.addWeapon(weapon);
}

/**
 * @brief Method to add an armor to the inventory
 *
 * @param armor
 */

void Character::addArmorToInventory(Armor armor)
{
    inventory.addArmor(armor);
}

/**
 * @brief Method to add a potion to the inventory
 *
 * @param potion
 */

void Character::addPotionToInventory(Potion potion)
{
    inventory.addPotion(potion);
}

/**
 * @brief Method to add a quest item to the inventory
 *
 * @param questItem
 */

void Character::addQuestItemToInventory(QuestItem questItem)
{
    inventory.addQuestItem(questItem);
}

/**
 * @brief Method to remove a weapon from the inventory
 *
 * @param index
 */

void Character::removeWeaponFromInventory(int index)
{
    inventory.removeWeapon(index);
}

/**
 * @brief Method to remove an armor from the inventory
 *
 * @param index
 */

void Character::removeArmorFromInventory(int index)
{
    inventory.removeArmor(index);
}

/**
 * @brief Method to remove a potion from the inventory
 *
 * @param index
 */

void Character::removePotionFromInventory(int index)
{
    inventory.removePotion(index);
}

/**
 * @brief Method to remove a quest item from the inventory
 *
 * @param index
 */

void Character::removeQuestItemFromInventory(int index)
{
    inventory.removeQuestItem(index);
}

/**
 * @brief Method to equip a weapon
 *
 * @param index
 */

void Character::equipWeapon(int index)
{
    // Check if the weapon is equipped
    if (equippedWeapon.getName() != "None")
    {
        std::cout << "There is already a weapon equipped." << std::endl;
    }
    else
    {
        // Equip the weapon
        equippedWeapon = inventory.getWeapons()[index];

        // Add the weapon's damage to the character's attack
        damage += equippedWeapon.getDamage();

        // Remove the weapon from the inventory
        inventory.removeWeapon(index);

        // Show a message
        std::cout << "The weapon has been equipped." << std::endl;
    }
}

/**
 * @brief Method to equip an armor
 *
 * @param index
 */

void Character::equipArmor(int index)
{
    // Check if the armor is equipped
    if (equippedArmor.getName() != "None")
    {
        std::cout << "There is already an armor equipped." << std::endl;
    }
    else
    {
        // Equip the armor
        equippedArmor = inventory.getArmors()[index];

        // Add the armor's defense to the character's defense
        defense += equippedArmor.getDefense();

        // Remove the armor from the inventory
        inventory.removeArmor(index);

        // Show a message
        std::cout << "The armor has been equipped." << std::endl;
    }
}

/**
 * @brief Method to drink a potion
 *
 * @param index
 */

void Character::drinkPotion(int index)
{
    // Check if the potion adds health
    if (inventory.getPotions()[index].getHealth() > 0)
    {
        // Check if the character is at full health
        if (health == maxHealth)
        {
            std::cout << "You are already at full health." << std::endl;
        }
        else
        {
            // Check if the character's health will be over the max health
            if (health + inventory.getPotions()[index].getHealth() > maxHealth)
            {
                // Set the character's health to the max health
                health = maxHealth;
            }
            else
            {
                // Add the health to the character's health
                health += inventory.getPotions()[index].getHealth();
            }

            // Message
            std::cout << "You have drank a " << inventory.getPotions()[index].getName() << "." << std::endl;
            std::cout << "Your health is now " << health << "." << std::endl;

            // Remove the potion from the inventory
            inventory.removePotion(index);
        }
        // Check if the potion adds mana
        if (inventory.getPotions()[index].getMana() > 0)
        {
            // Check if the character is at full mana
            if (mana == maxMana)
            {
                std::cout << "You are already at full mana." << std::endl;
            }
            else
            {
                // Check if the character's mana will be over the max mana
                if (mana + inventory.getPotions()[index].getMana() > maxMana)
                {
                    // Set the character's mana to the max mana
                    mana = maxMana;
                }
                else
                {
                    // Add the mana to the character's mana
                    mana += inventory.getPotions()[index].getMana();
                }

                // Message
                std::cout << "You have drank a " << inventory.getPotions()[index].getName() << "." << std::endl;
                std::cout << "Your mana is now " << mana << "." << std::endl;

                // Remove the potion from the inventory
                inventory.removePotion(index);
            }
        }
        // Check if the potion adds stamina
        if (inventory.getPotions()[index].getStamina() > 0)
        {
            // Check if the character is at full stamina
            if (stamina == maxStamina)
            {
                std::cout << "You are already at full stamina." << std::endl;
            }
            else
            {
                // Check if the character's stamina will be over the max stamina
                if (stamina + inventory.getPotions()[index].getStamina() > maxStamina)
                {
                    // Set the character's stamina to the max stamina
                    stamina = maxStamina;
                }
                else
                {
                    // Add the stamina to the character's stamina
                    stamina += inventory.getPotions()[index].getStamina();
                }

                // Message
                std::cout << "You have drank a " << inventory.getPotions()[index].getName() << "." << std::endl;
                std::cout << "Your stamina is now " << stamina << "." << std::endl;

                // Remove the potion from the inventory
                inventory.removePotion(index);
            }
        }
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
        std::cout << "There is no weapon equipped." << std::endl;
    }
    else
    {
        // Reduce the damage
        damage -= equippedWeapon.getDamage();

        // Unequip the weapon
        inventory.addWeapon(equippedWeapon);

        // Set the weapon to none
        equippedWeapon = Weapon();

        // Show a message
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
        std::cout << "There is no armor equipped." << std::endl;
    }
    else
    {
        // Reduce the defense
        defense -= equippedArmor.getDefense();

        // Unequip the armor
        inventory.addArmor(equippedArmor);

        // Set the armor to none
        equippedArmor = Armor();

        // Show a message
        std::cout << "The armor has been unequipped." << std::endl;
    }
}

#endif // End of the preprocessor CHARACTER_CC