/**
 * @file Armor.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Armor class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ARMOR_CC
#define ARMOR_CC

#include "../headers/Armor.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Armor:: Armor object
 *
 */

Armor::Armor() : Item()
{
    defense = 0;
}

/**
 * @brief Construct a new Armor:: Armor object
 *
 * @param name
 * @param description
 * @param rarity
 * @param weight
 * @param price
 * @param type
 * @param subtype
 * @param defense
 */

Armor::Armor(std::string name, std::string description, std::string rarity, float weight, int price, std::string subtype, int defense) : Item(name, description, rarity, weight, price, "Armor", subtype)
{
    this->defense = defense;
}

// Getters

/**
 * @brief Get the Defense attribute
 *
 * @return int
 */

int Armor::getDefense()
{
    return defense;
}

// Setters

/**
 * @brief Set the Defense attribute
 *
 * @param defense
 */

void Armor::setDefense(int defense)
{
    this->defense = defense;
}

// Methods

/**
 * @brief Get the Armor object as a string
 *
 * @return std::string
 */

std::string Armor::toString()
{
    // Create a string stream
    std::stringstream ss;

    // Inherit the Item::toString() method
    std::string item = Item::toString();

    // Add the Item attributes to the string stream
    ss << item;

    // Add the Armor attributes to the string stream
    ss << "Defense: " << defense << std::endl;
    
    // Return the string stream as a string
    return ss.str();
}

#endif // End of the preprocessor ARMOR_CC