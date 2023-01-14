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

    void increaseStats(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
    void decreaseStats(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);

    void increaseByOne(int stat);
    void decreaseByOne(int stat);

};

#endif // End of the STATS_H preprocessor