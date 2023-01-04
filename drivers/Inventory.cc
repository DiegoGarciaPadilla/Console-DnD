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

/**
 * @brief Get the Weapons object
 *
 * @return vector
 */

std::vector<Weapon> Inventory::getWeapons()
{
    return weapons;
}

/**
 * @brief Get the Armors object
 *
 * @return vector
 */

std::vector<Armor> Inventory::getArmors()
{
    return armors;
}

/**
 * @brief Get the Consumables object
 *
 * @return vector
 */

std::vector<Consumable> Inventory::getConsumables()
{
    return consumables;
}

/**
 * @brief Get the Quest Items object
 *
 * @return vector
 */

std::vector<QuestItem> Inventory::getQuestItems()
{
    return questItems;
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

/**
 * @brief Set the Max Weight object
 *
 * @param maxWeight
 */

void Inventory::setMaxWeight(int maxWeight)
{
    this->maxWeight = maxWeight;
}

/**
 * @brief Set the Current Weight object
 *
 * @param currentWeight
 */

void Inventory::setCurrentWeight(int currentWeight)
{
    this->currentWeight = currentWeight;
}

/**
 * @brief Set the Weapons object
 *
 * @param weapons
 */

void Inventory::setWeapons(std::vector<Weapon> weapons)
{
    this->weapons = weapons;
}

/**
 * @brief Set the Armors object
 *
 * @param armors
 */

void Inventory::setArmors(std::vector<Armor> armors)
{
    this->armors = armors;
}

/**
 * @brief Set the Consumables object
 *
 * @param consumables
 */

void Inventory::setConsumables(std::vector<Consumable> consumables)
{
    this->consumables = consumables;
}

/**
 * @brief Set the Quest Items object
 *
 * @param questItems
 */

void Inventory::setQuestItems(std::vector<QuestItem> questItems)
{
    this->questItems = questItems;
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

#endif // End of the preprocessor INVENTORY_CC