/**
 * @file Inventory.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Inventory class
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INVENTORY_CC // If the file is not defined
#define INVENTORY_CC // Define the file

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <vector>   // Include vector library

#include "../headers/Inventory.h" // Include the header file
#include "Functions.cc"           // Include the functions file
#include "Ascii.cc"               // Include the ASCII art file

// Constructors

/**
 * @brief Construct a new Inventory:: Inventory object
 *
 */

Inventory::Inventory()
{
    gold = 0;
    maxWeight = 20;
    currentWeight = 0;
}

/**
 * @brief Construct a new Inventory:: Inventory object
 *
 * @param capacity
 */

Inventory::Inventory(int capacity)
{
    gold = 0;
    maxWeight = capacity;
    currentWeight = 0;
}

// Getters

/**
 * @brief Get the Gold object
 *
 * @return int
 */

int Inventory::getGold()
{
    return gold;
}

/**
 * @brief Get the Max Weight object
 *
 * @return int
 */

int Inventory::getMaxWeight()
{
    return maxWeight;
}

/**
 * @brief Get the Current Weight object
 *
 * @return int
 */

int Inventory::getCurrentWeight()
{
    return currentWeight;
}

// Setters

/**
 * @brief Set the Gold object
 *
 * @param gold
 */

void Inventory::setGold(int gold)
{
    this->gold = gold;
}

// Methods

/**
 * @brief Add a weapon to the inventory
 *
 * @param weapon
 */

void Inventory::addWeapon(Weapon weapon)
{
    weapons.push_back(weapon);
    currentWeight += weapon.getWeight();
}

/**
 * @brief Add an armor to the inventory
 *
 * @param armor
 */

void Inventory::addArmor(Armor armor)
{
    armors.push_back(armor);
    currentWeight += armor.getWeight();
}

/**
 * @brief Add a consumable to the inventory
 *
 * @param consumable
 */

void Inventory::addConsumable(Consumable consumable)
{
    consumables.push_back(consumable);
    currentWeight += consumable.getWeight();
}

/**
 * @brief Add a quest item to the inventory
 *
 * @param questItem
 */

void Inventory::addQuestItem(QuestItem questItem)
{
    questItems.push_back(questItem);
    currentWeight += questItem.getWeight();
}

/**
 * @brief Remove a weapon from the inventory
 *
 * @param weapon
 */

void Inventory::removeWeapon(Weapon weapon)
{
    for (int i = 0; i < weapons.size(); i++)
    {
        if (weapons[i].getName() == weapon.getName())
        {
            weapons.erase(weapons.begin() + i);
            currentWeight -= weapon.getWeight();
        }
    }
}

/**
 * @brief Remove an armor from the inventory
 *
 * @param armor
 */

void Inventory::removeArmor(Armor armor)
{
    for (int i = 0; i < armors.size(); i++)
    {
        if (armors[i].getName() == armor.getName())
        {
            armors.erase(armors.begin() + i);
            currentWeight -= armor.getWeight();
        }
    }
}

/**
 * @brief Remove a consumable from the inventory
 *
 * @param consumable
 */

void Inventory::removeConsumable(Consumable consumable)
{
    for (int i = 0; i < consumables.size(); i++)
    {
        if (consumables[i].getName() == consumable.getName())
        {
            consumables.erase(consumables.begin() + i);
            currentWeight -= consumable.getWeight();
        }
    }
}

/**
 * @brief Remove a quest item from the inventory
 *
 * @param questItem
 */

void Inventory::removeQuestItem(QuestItem questItem)
{
    for (int i = 0; i < questItems.size(); i++)
    {
        if (questItems[i].getName() == questItem.getName())
        {
            questItems.erase(questItems.begin() + i);
            currentWeight -= questItem.getWeight();
        }
    }
}

/**
 * @brief Check if the weapon is in the inventory
 *
 */

bool Inventory::hasWeapon(Weapon weapon)
{
    for (int i = 0; i < weapons.size(); i++)
    {
        if (weapons[i].getName() == weapon.getName())
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the armor is in the inventory
 *
 */

bool Inventory::hasArmor(Armor armor)
{
    for (int i = 0; i < armors.size(); i++)
    {
        if (armors[i].getName() == armor.getName())
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the consumable is in the inventory
 *
 */

bool Inventory::hasConsumable(Consumable consumable)
{
    for (int i = 0; i < consumables.size(); i++)
    {
        if (consumables[i].getName() == consumable.getName())
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the quest item is in the inventory
 *
 */

bool Inventory::hasQuestItem(QuestItem questItem)
{
    for (int i = 0; i < questItems.size(); i++)
    {
        if (questItems[i].getName() == questItem.getName())
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Show the inventory
 *
 */

void Inventory::showInventory()
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
        std::cout << "Gold: " << gold << std::endl;
        std::cout << std::endl;

        // Current and max weight
        std::cout << "Current Weight: " << currentWeight << std::endl;
        std::cout << "Max Weight: " << maxWeight << std::endl;
        std::cout << std::endl;

        // Weapons
        if (weapons.size() > 0)
        {
            std::cout << "Weapons: " << std::endl;
            for (int i = 0; i < weapons.size(); i++)
            {
                std::cout << itemNum << ". " << weapons[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Armors
        if (armors.size() > 0)
        {
            std::cout << "Armors: " << std::endl;
            for (int i = 0; i < armors.size(); i++)
            {
                std::cout << itemNum << ". " << armors[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Consumables
        if (consumables.size() > 0)
        {
            std::cout << "Consumables: " << std::endl;
            for (int i = 0; i < consumables.size(); i++)
            {
                std::cout << itemNum << ". " << consumables[i].getName() << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Quest Items
        if (questItems.size() > 0)
        {
            std::cout << "Quest Items: " << std::endl;
            for (int i = 0; i < questItems.size(); i++)
            {
                std::cout << itemNum << ". " << questItems[i].getName() << std::endl;
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
            if (option <= weapons.size())
            {
                // Show the weapon
                std::cout << weapons[option - 1].toString() << std::endl;
            }
            else if (option <= weapons.size() + armors.size())
            {
                // Show the armor
                std::cout << armors[option - weapons.size() - 1].toString() << std::endl;
            }
            else if (option <= weapons.size() + armors.size() + consumables.size())
            {
                // Show the consumable
                std::cout << consumables[option - weapons.size() - armors.size() - 1].toString() << std::endl;
            }
            else if (option <= weapons.size() + armors.size() + consumables.size() + questItems.size())
            {
                // Show the quest item
                std::cout << questItems[option - weapons.size() - armors.size() - consumables.size() - 1].toString() << std::endl;
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
                std::cout << "Use / Equip" << std::endl;
                std::cout << "Not implemented yet" << std::endl;
                std::cout << std::endl;
                pause();
                break;
            case 2:
                if (option <= weapons.size())
                {
                    // Title
                    std::cout << "Drop " << weapons[option - 1].getName() << std::endl;

                    // Drop the weapon
                    removeWeapon(weapons[option - 1]);
                }
                else if (option <= weapons.size() + armors.size())
                {
                    // Title
                    std::cout << "Drop " << armors[option - weapons.size() - 1].getName() << std::endl;

                    // Drop the armor
                    removeArmor(armors[option - weapons.size() - 1]);
                }
                else if (option <= weapons.size() + armors.size() + consumables.size())
                {
                    // Title
                    std::cout << "Drop " << consumables[option - weapons.size() - armors.size() - 1].getName() << std::endl;

                    // Drop the consumable
                    removeConsumable(consumables[option - weapons.size() - armors.size() - 1]);
                }
                else if (option <= weapons.size() + armors.size() + consumables.size() + questItems.size())
                {
                    // Title
                    std::cout << "Drop " << questItems[option - weapons.size() - armors.size() - consumables.size() - 1].getName() << std::endl;

                    // Drop the quest item
                    removeQuestItem(questItems[option - weapons.size() - armors.size() - consumables.size() - 1]);
                }

                // Wait for the user to press enter
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

#endif // End of the preprocessor INVENTORY_CC