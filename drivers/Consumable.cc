/**
 * @file Consumable.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Consumable class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CONSUMABLE_CC // If the file is not defined
#define CONSUMABLE_CC // Define the file

#include "../headers/Consumable.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Consumable:: Consumable object
 *
 */

Consumable::Consumable() : Item()
{
    health = 0;
    mana = 0;
    stamina = 0;
}

/**
 * @brief Construct a new Consumable:: Consumable object
 *
 * @param name
 * @param description
 * @param rarity
 * @param weight
 * @param price
 * @param subtype
 * @param health
 * @param mana
 * @param stamina
 */

Consumable::Consumable(std::string name, std::string description, std::string rarity, int weight, int price, std::string subtype, int health, int mana, int stamina) : Item(name, description, rarity, weight, price, "Consumable", subtype)
{
    this->health = health;
    this->mana = mana;
    this->stamina = stamina;
}

// Getters

/**
 * @brief Get the Health attribute
 *
 * @return int
 */

int Consumable::getHealth()
{
    return health;
}

/**
 * @brief Get the Mana attribute
 *
 * @return int
 */

int Consumable::getMana()
{
    return mana;
}

/**
 * @brief Get the Stamina attribute
 *
 * @return int
 */

int Consumable::getStamina()
{
    return stamina;
}

// Methods

/**
 * @brief Get the string representation of the object
 *
 * @return std::string
 */

std::string Consumable::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Rarity: " << rarity << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Price: " << price << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Health: " << health << std::endl;
    ss << "Mana: " << mana << std::endl;
    ss << "Stamina: " << stamina << std::endl;

    return ss.str();
}

#endif // End of the preprocessor CONSUMABLE_CC
