/**
 * @file Armor.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents an armor that can be used by the player.
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ARMOR_H // If the ARMOR_H preprocessor is not defined
#define ARMOR_H // Define the ARMOR_H preprocessor

#include "Object.h" // Include the object class

class Armor : public Object
{
private:
    // Attributes
    std::string type = "Armor";
    int defense;

public:
    // Constructors
    Armor();
    Armor(std::string name, std::string description, int weight, int value, std::string subtype, std::string material, int defense);

    // Getters
    int getDefense();

    // Setters
    void setDefense(int defense);

    // Methods
    std::string toString();
};

// Constructors

/**
 * @brief Construct a new Armor:: Armor object
 * 
 */

Armor::Armor()
{
    name = "Wooden armor";
    description = "It's a wooden armor, with some rusty steel plates. It doesn't seem very useful.";
    weight = 2;
    value = 0;
    subtype = "Armor";
    material = "Wood and steel";
    defense = 6;
}

/**
 * @brief Construct a new Armor:: Armor object
 * 
 * @param name 
 * @param description 
 * @param weight 
 * @param value 
 * @param subtype 
 * @param material 
 * @param defense 
 */

Armor::Armor(std::string name, std::string description, int weight, int value, std::string subtype, std::string material, int defense)
{
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->value = value;
    this->subtype = subtype;
    this->material = material;
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
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Value: " << value << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Material: " << material << std::endl;
    ss << "Defense: " << defense << std::endl;

    return ss.str();
}

#endif // End of the ARMOR_H preprocessor