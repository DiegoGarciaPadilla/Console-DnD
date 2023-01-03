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

// Constructors

/**
 * @brief Construct a new Inventory:: Inventory object
 *
 */

Inventory::Inventory()
{
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
    maxWeight = capacity;
    currentWeight = 0;
}

// Getters

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
 * @brief Show the inventory
 *
 */

void Inventory::showInventory()
{
    int itemNum = 1;

    std::cout << "INVENTORY" << std::endl;
    std::cout << std::endl;

    std::cout << "Current Weight: " << currentWeight << std::endl;
    std::cout << "Max Weight: " << maxWeight << std::endl;
    std::cout << std::endl;

    std::cout << "Weapons: " << std::endl;
    for (int i = 0; i < weapons.size(); i++)
    {
        std::cout << itemNum << ". " << weapons[i].getName() << std::endl;
        itemNum++;
    }

    std::cout << "Armors: " << std::endl;
    for (int i = 0; i < armors.size(); i++)
    {
        std::cout << itemNum << ". " << armors[i].getName() << std::endl;
        itemNum++;
    }

    std::cout << "Consumables: " << std::endl;
    for (int i = 0; i < consumables.size(); i++)
    {
        std::cout << itemNum << ". " << consumables[i].getName() << std::endl;
        itemNum++;
    }

    std::cout << "Quest Items: " << std::endl;
    for (int i = 0; i < questItems.size(); i++)
    {
        std::cout << itemNum << ". " << questItems[i].getName() << std::endl;
        itemNum++;
    }
}

#endif // End of the preprocessor INVENTORY_CC