/**
 * @file Weapon.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a weapon that can be used by the player.
 * @version 0.1
 * @date 2022-12-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef WEAPON_H // If the WEAPON_H preprocessor is not defined
#define WEAPON_H // Define the WEAPON_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams

#include "Object.h" // Include the object class

class Weapon : public Object
{
private:
    // Attributes
    std::string type = "Weapon";
    int damage;

public:
    // Constructors
    Weapon();
    Weapon(std::string name, std::string description, int weight, int value, std::string subtype, std::string material, int damage);

    // Getters
    int getDamage();

    // Setters
    void setDamage(int damage);

    // Methods
    std::string toString();
};

// Constructors

/**
 * @brief Construct a new Weapon:: Weapon object
 *
 */

Weapon::Weapon()
{
    name = "Rusty sword";
    description = "It's a wooden sword, with a rusty steel blade. It doesn't seem very useful.";
    weight = 2;
    value = 0;
    subtype = "Sword";
    material = "Wood and steel";
    damage = 6;
}

/**
 * @brief Construct a new Weapon:: Weapon object
 *
 * @param name
 * @param description
 * @param weight
 * @param value
 * @param subtype
 * @param material
 * @param damage
 */

Weapon::Weapon(std::string name, std::string description, int weight, int value, std::string subtype, std::string material, int damage)
{
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->value = value;
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
    ss << "Value: " << value << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Material: " << material << std::endl;
    ss << "Damage: " << damage << std::endl;

    return ss.str();
}

#endif // End of the WEAPON_H preprocessor