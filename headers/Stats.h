/**
 * @file Stats.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents the stats of a character.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef STATS_H // If the STATS_H preprocessor is not defined
#define STATS_H // Define the STATS_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams

#include "Race.h" // Include the race class

class Stats
{
private:
    // Attributes
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

public:
    // Constructors
    Stats();
    Stats(Race race);

    // Getters
    int getStrength();
    int getDexterity();
    int getConstitution();
    int getIntelligence();
    int getWisdom();
    int getCharisma();

    // Setters
    void setStrength(int strength);
    void setDexterity(int dexterity);
    void setConstitution(int constitution);
    void setIntelligence(int intelligence);
    void setWisdom(int wisdom);
    void setCharisma(int charisma);

    // Methods
    std::string toString();
};

// Constructors

/**
 * @brief Construct a new Stats:: Stats object
 *
 */

Stats::Stats()
{
    strength = rand() % 20 + 1;
    dexterity = rand() % 20 + 1;
    constitution = rand() % 20 + 1;
    intelligence = rand() % 20 + 1;
    wisdom = rand() % 20 + 1;
    charisma = rand() % 20 + 1;
}

/**
 * @brief Construct a new Stats:: Stats object
 * 
 * @param race 
 */

Stats::Stats(Race race)
{
    strength = race.getStrengthModifier() + rand() % 20 + 1;
    dexterity = race.getDexterityModifier() + rand() % 20 + 1;
    constitution = race.getConstitutionModifier() + rand() % 20 + 1;
    intelligence = race.getIntelligenceModifier() + rand() % 20 + 1;
    wisdom = race.getWisdomModifier() + rand() % 20 + 1;
    charisma = race.getCharismaModifier() + rand() % 20 + 1;
}

// Getters

/**
 * @brief Get the Strength attribute
 * 
 * @return int 
 */

int Stats::getStrength()
{
    return strength;
}

/**
 * @brief Get the Dexterity attribute
 * 
 * @return int 
 */

int Stats::getDexterity()
{
    return dexterity;
}

/**
 * @brief Get the Constitution attribute
 * 
 * @return int 
 */

int Stats::getConstitution()
{
    return constitution;
}

/**
 * @brief Get the Intelligence attribute
 * 
 * @return int 
 */

int Stats::getIntelligence()
{
    return intelligence;
}

/**
 * @brief Get the Wisdom attribute
 * 
 * @return int 
 */

int Stats::getWisdom()
{
    return wisdom;
}

/**
 * @brief Get the Charisma attribute
 * 
 * @return int 
 */

int Stats::getCharisma()
{
    return charisma;
}

// Setters

/**
 * @brief Set the Strength attribute
 * 
 * @param strength 
 */

void Stats::setStrength(int strength)
{
    this->strength = strength;
}

/**
 * @brief Set the Dexterity attribute
 * 
 * @param dexterity 
 */

void Stats::setDexterity(int dexterity)
{
    this->dexterity = dexterity;
}

/**
 * @brief Set the Constitution attribute
 * 
 * @param constitution 
 */

void Stats::setConstitution(int constitution)
{
    this->constitution = constitution;
}

/**
 * @brief Set the Intelligence attribute
 * 
 * @param intelligence 
 */

void Stats::setIntelligence(int intelligence)
{
    this->intelligence = intelligence;
}

/**
 * @brief Set the Wisdom attribute
 * 
 * @param wisdom 
 */

void Stats::setWisdom(int wisdom)
{
    this->wisdom = wisdom;
}

/**
 * @brief Set the Charisma attribute
 * 
 * @param charisma 
 */

void Stats::setCharisma(int charisma)
{
    this->charisma = charisma;
}

// Methods

/**
 * @brief Get the Stats object as a string
 * 
 * @return std::string 
 */

std::string Stats::toString()
{
    std::stringstream ss;

    ss << "Strength: " << strength << std::endl;
    ss << "Dexterity: " << dexterity << std::endl;
    ss << "Constitution: " << constitution << std::endl;
    ss << "Intelligence: " << intelligence << std::endl;
    ss << "Wisdom: " << wisdom << std::endl;
    ss << "Charisma: " << charisma << std::endl;

    return ss.str();
}

#endif // End of the STATS_H preprocessor