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
 * @brief Get the Potions object
 *
 * @return vector
 */

std::vector<Potion> Inventory::getPotions()
{
    return potions;
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
 * @brief Set the Potions object
 *
 * @param potions
 */

void Inventory::setPotions(std::vector<Potion> potions)
{
    this->potions = potions;
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
 * @brief Add a potion to the inventory
 *
 * @param potion
 */

void Inventory::addPotion(Potion potion)
{
    potions.push_back(potion);
    currentWeight += potion.getWeight();
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
 * @param index
 */

void Inventory::removeWeapon(int index)
{
    currentWeight -= weapons[index].getWeight();
    weapons.erase(weapons.begin() + index);
}

/**
 * @brief Remove an armor from the inventory
 *
 * @param index
 */

void Inventory::removeArmor(int index)
{
    currentWeight -= armors[index].getWeight();
    armors.erase(armors.begin() + index);
}

/**
 * @brief Remove a potion from the inventory
 *
 * @param index
 */

void Inventory::removePotion(int index)
{
    currentWeight -= potions[index].getWeight();
    potions.erase(potions.begin() + index);
}

/**
 * @brief Remove a quest item from the inventory
 *
 * @param index
 */

void Inventory::removeQuestItem(int index)
{
    currentWeight -= questItems[index].getWeight();
    questItems.erase(questItems.begin() + index);
}

#endif // End of the preprocessor INVENTORY_CC