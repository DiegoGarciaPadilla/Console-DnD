/**
 * @file Spell.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the spell class.
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifdef SPELL_CC // If the preprocessor SPELL_H is defined
#undef SPELL_CC // Undefine the preprocessor SPELL_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams
#include <fstream>  // Library for file streams
#include <cstdlib>  // Library for system functions
#include <vector>   // Library for vectors

#include "../headers/Spell.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Spell:: Spell object
 * 
 * @param 
 * @return 
 */

Spell::Spell()
{
    name = "None";
    description = "None";
    type = "None";
    level = 0;
    damage = 0;
    manaCost = 0;
}

/**
 * @brief Construct a new Spell:: Spell object
 * 
 * @param name 
 * @param description 
 * @param type 
 * @param level 
 * @param damage 
 * @param manaCost 
 * @return 
 */

Spell::Spell(std::string name, std::string description, std::string type, int level, int damage, int manaCost)
{
    this->name = name;
    this->description = description;
    this->type = type;
    this->level = level;
    this->damage = damage;
    this->manaCost = manaCost;
}

// Getters

/**
 * @brief Get the Name attribute
 * 
 * @param 
 * @return std::string 
 */

std::string Spell::getName()
{
    return name;
}

/**
 * @brief Get the Description attribute
 * 
 * @param 
 * @return std::string 
 */

std::string Spell::getDescription()
{
    return description;
}

/**
 * @brief Get the Type attribute
 * 
 * @param 
 * @return std::string 
 */

std::string Spell::getType()
{
    return type;
}

/**
 * @brief Get the Level attribute
 * 
 * @param 
 * @return int 
 */

int Spell::getLevel()
{
    return level;
}

/**
 * @brief Get the Damage attribute
 * 
 * @param 
 * @return int 
 */

int Spell::getDamage()
{
    return damage;
}

/**
 * @brief Get the Mana Cost attribute
 * 
 * @param 
 * @return int 
 */

int Spell::getManaCost()
{
    return manaCost;
}

// Setters

/**
 * @brief Set the Name attribute
 * 
 * @param name 
 * @return void 
 */

void Spell::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description attribute
 * 
 * @param description 
 * @return void 
 */

void Spell::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Type attribute
 * 
 * @param type 
 * @return void 
 */

void Spell::setType(std::string type)
{
    this->type = type;
}

/**
 * @brief Set the Level attribute
 * 
 * @param level 
 * @return void 
 */

void Spell::setLevel(int level)
{
    this->level = level;
}

/**
 * @brief Set the Damage attribute
 * 
 * @param damage 
 * @return void 
 */

void Spell::setDamage(int damage)
{
    this->damage = damage;
}

/**
 * @brief Set the Mana Cost attribute
 * 
 * @param manaCost 
 * @return void 
 */

void Spell::setManaCost(int manaCost)
{
    this->manaCost = manaCost;
}

// Methods

/**
 * @brief Get the Spell object as a string
 * 
 * @param 
 * @return std::string 
 */

std::string Spell::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Level: " << level << std::endl;
    ss << "Damage: " << damage << std::endl;
    ss << "Mana Cost: " << manaCost << std::endl;

    return ss.str();
}

/**
 * @brief Level up the spell
 * 
 * @param 
 * @return
 */

void Spell::levelUp()
{
    level++;
    damage += 10;
    manaCost += 10;
}

#endif // End of the preprocessor SPELL_H