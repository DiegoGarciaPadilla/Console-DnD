/**
 * @file Weapon.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Weapon class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WEAPON_CC // If the file is not defined
#define WEAPON_CC // Define the file

#include "../headers/Weapon.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Weapon:: Weapon object
 *
 */

Weapon::Weapon()
{
    name = "None";
    description = "None";
    weight = 0;
    price = 0;
    subtype = "None";
    material = "None";
    damage = 0;
}

/**
 * @brief Construct a new Weapon:: Weapon object
 *
 * @param name
 * @param description
 * @param weight
 * @param price
 * @param subtype
 * @param material
 * @param damage
 */

Weapon::Weapon(std::string name, std::string description, int weight, int price, std::string subtype, std::string material, int damage)
{
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->price = price;
    this->subtype = subtype;
    this->material = material;
    this->damage = damage;
}

// Getters

/**
 * @brief Get the Damage attribute
 *
 * @return int
 */

int Weapon::getDamage()
{
    return damage;
}

// Setters

/**
 * @brief Set the Damage attribute
 *
 * @param damage
 */

void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

// Methods

/**
 * @brief Get the string representation of the object
 *
 * @return std::string
 */

std::string Weapon::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Price: " << price << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Material: " << material << std::endl;
    ss << "Damage: " << damage << std::endl;

    return ss.str();
}

#endif // End of the preprocessor WEAPON_CC