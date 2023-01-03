/**
 * @file Race.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Race class
 * @version 0.1
 * @date 2023-01-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "headers/Race.h"

// Constructors

/**
 * @brief Construct a new Race:: Race object
 *
 */

Race::Race()
{
    name = "Human";
    description = "Humans are the most adaptable and ambitious people among the common races. They have widely varying tastes, morals, and customs in the many different lands where they have settled. When they settle, though, they stay: they build cities to last for the ages, and great kingdoms that can persist for long centuries. An individual human might have a relatively short life span, but a human nation or culture preserves traditions with origins far beyond the reach of any single human’s memory.";
    strengthModifier = 1;
    dexterityModifier = 1;
    constitutionModifier = 1;
    intelligenceModifier = 1;
    wisdomModifier = 1;
    charismaModifier = 1;
}

/**
 * @brief Construct a new Race:: Race object
 *
 * @param name
 * @param description
 * @param strengthModifier
 * @param dexterityModifier
 * @param constitutionModifier
 * @param intelligenceModifier
 * @param wisdomModifier
 * @param charismaModifier
 */

Race::Race(std::string name, std::string description, int strengthModifier, int dexterityModifier, int constitutionModifier, int intelligenceModifier, int wisdomModifier, int charismaModifier)
{
    this->name = name;
    this->description = description;
    this->strengthModifier = strengthModifier;
    this->dexterityModifier = dexterityModifier;
    this->constitutionModifier = constitutionModifier;
    this->intelligenceModifier = intelligenceModifier;
    this->wisdomModifier = wisdomModifier;
    this->charismaModifier = charismaModifier;
}

// Getters

/**
 * @brief Get the Name attribute
 * 
 * @return std::string 
 */

std::string Race::getName()
{
    return name;
}

/**
 * @brief Get the Description attribute
 * 
 * @return std::string 
 */

std::string Race::getDescription()
{
    return description;
}

/**
 * @brief Get the Strength Modifier attribute
 * 
 * @return int 
 */

int Race::getStrengthModifier()
{
    return strengthModifier;
}

/**
 * @brief Get the Dexterity Modifier attribute
 * 
 * @return int 
 */

int Race::getDexterityModifier()
{
    return dexterityModifier;
}

/**
 * @brief Get the Constitution Modifier attribute
 * 
 * @return int 
 */

int Race::getConstitutionModifier()
{
    return constitutionModifier;
}

/**
 * @brief Get the Intelligence Modifier attribute
 * 
 * @return int 
 */

int Race::getIntelligenceModifier()
{
    return intelligenceModifier;
}

/**
 * @brief Get the Wisdom Modifier attribute
 * 
 * @return int 
 */

int Race::getWisdomModifier()
{
    return wisdomModifier;
}

/**
 * @brief Get the Charisma Modifier attribute
 * 
 * @return int 
 */

int Race::getCharismaModifier()
{
    return charismaModifier;
}

// Methods

std::string Race::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Strength modifier: " << strengthModifier << std::endl;
    ss << "Dexterity modifier: " << dexterityModifier << std::endl;
    ss << "Constitution modifier: " << constitutionModifier << std::endl;
    ss << "Intelligence modifier: " << intelligenceModifier << std::endl;
    ss << "Wisdom modifier: " << wisdomModifier << std::endl;
    ss << "Charisma modifier: " << charismaModifier << std::endl;

    return ss.str();
}