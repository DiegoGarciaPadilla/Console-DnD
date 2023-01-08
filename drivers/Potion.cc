/**
 * @file Potion.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Potion class
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef POTION_CC // If the file is not defined
#define POTION_CC // Define the file

#include <iostream> // Include iostream library
#include <string>   // Include string library
#include <sstream>  // Include sstream library

#include "../headers/Potion.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Potion:: Potion object
 *
 */

Potion::Potion() : Consumable()
{
    subtype = "Potion";
}

/**
 * @brief Construct a new Potion:: Potion object
 *
 * @param name
 * @param description
 * @param rarity
 * @param weight
 * @param price
 * @param health
 * @param mana
 * @param stamina
 */

Potion::Potion(std::string name, std::string description, std::string rarity, int weight, int price, int health, int mana, int stamina) : Consumable(name, description, rarity, weight, price, "Potion", health, mana, stamina) {}

// Methods

/**
 * @brief This method returns the object as a string
 *
 * @return std::string
 */

std::string Potion::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Rarity: " << rarity << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Price: " << price << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Health: " << health << std::endl;
    ss << "Mana: " << mana << std::endl;
    ss << "Stamina: " << stamina << std::endl;

    return ss.str();
}

#endif // End of the file