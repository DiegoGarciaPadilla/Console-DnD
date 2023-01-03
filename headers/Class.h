/**
 * @file Class.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a class that can be used by the player.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CLASS_H // If the CLASS_H preprocessor is not defined
#define CLASS_H // Define the CLASS_H preprocessor

#include "Weapon.h" // Include the weapon class
#include "Armor.h"  // Include the armor class

class Class
{
private:
    // Attributes
    std::string name;
    std::string description;
    Weapon initialWeapon;
    Armor initialArmor;

public:
    // Constructors
    Class();
    Class(std::string name, std::string description, Weapon initialWeapon, Armor initialArmor);

    // Getters
    std::string getName();
    std::string getDescription();
    Weapon getInitialWeapon();
    Armor getInitialArmor();

    // Methods
    std::string toString();
};

#endif // End of the CLASS_H preprocessor