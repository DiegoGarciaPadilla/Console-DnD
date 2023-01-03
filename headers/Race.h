/**
 * @file Race.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a race that can be chosen by the player.
 * @version 0.1
 * @date 2022-12-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef RACE_H // If the preprocessor RACE_H is not defined
#define RACE_H // Define the preprocessor RACE_H

class Race
{
private:
    // Attributes
    std::string name;
    std::string description;
    int strengthModifier;
    int dexterityModifier;
    int constitutionModifier;
    int intelligenceModifier;
    int wisdomModifier;
    int charismaModifier;

public:
    // Constructors
    Race();
    Race(std::string name, std::string description, int strengthModifier, int dexterityModifier, int constitutionModifier, int intelligenceModifier, int wisdomModifier, int charismaModifier);

    // Getters
    std::string getName();
    std::string getDescription();
    int getStrengthModifier();
    int getDexterityModifier();
    int getConstitutionModifier();
    int getIntelligenceModifier();
    int getWisdomModifier();
    int getCharismaModifier();

    // There are no setters because there is no need to change the values of the attributes

    // Methods
    std::string toString();
};

#endif // End of the preprocessor RACE_H
