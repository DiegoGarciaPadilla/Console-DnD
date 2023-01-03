/**
 * @file Character.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a character.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CHARACTER_H // If the preprocessor CHARACTER_H is not defined
#define CHARACTER_H // Define the preprocessor CHARACTER_H

#include "Race.h"        // Include races class
#include "Class.h"       // Include classes class
#include "Stats.h"       // Include statistics class
#include "Weapon.h"      // Include weapons class
#include "Armor.h"       // Include armor class
#include "Initializer.h" // Include initializer class

class Character
{
private:
    // Attributes
    std::string name;
    std::string gender;
    int age;
    std::string alignment;
    Race race;
    Class clss;
    Stats stats;
    Weapon weapon;
    Armor armor;

public:
    // Constructors
    Character();

    // Getters
    std::string getName();
    std::string getGender();
    int getAge();
    std::string getAlignment();
    Race getRace();
    Class getClass();
    Stats getStats();
    Weapon getWeapon();
    Armor getArmor();

    // Setters
    void setName(std::string name);
    void setGender(std::string gender);
    void setAge(int age);
    void setAlignment(std::string alignment);
    void setWeapon(Weapon weapon);
    void setArmor(Armor armor);

    // Methods
    std::string toString();
    void defineRace(int option);
    void defineStats();
    void defineClass(int option);
};

#endif // End of PERSONAJE_H preprocessor