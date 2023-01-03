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

#include <string>  // Include string library
#include <sstream> // Include string stream library
#include <vector>  // Include vector library

#include "../drivers/Race.cc"        // Include races class
#include "../drivers/Class.cc"       // Include classes class
#include "../drivers/Stats.cc"       // Include statistics class
#include "../drivers/Inventory.cc"   // Include inventory class
#include "../drivers/Weapon.cc"      // Include weapons class
#include "../drivers/Armor.cc"       // Include armor class
#include "../drivers/Initializer.cc" // Include initializer class

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
    Inventory inventory;
    Weapon equippedWeapon;
    Armor equippedArmor;

public:
    // Constructors
    Character();

    // Getters

    // There are no getters for this class because the attributes are going to be set in the constructor and change only when the player picks up or drops an item.

    // Setters
    void setName(std::string name);
    void setGender(std::string gender);
    void setAge(int age);
    void setAlignment(std::string alignment);

    // Methods
    std::string toString();

    void defineRace(int option);
    void defineStats();
    void defineClass(int option);

    void showInventory();

    void addWeapon(Weapon weapon);
    void addArmor(Armor armor);
    void addConsumable(Consumable consumable);
    void addQuestItem(QuestItem questItem);

    void removeWeapon(Weapon weapon);
    void removeArmor(Armor armor);
    void removeConsumable(Consumable consumable);
    void removeQuestItem(QuestItem questItem);

};

#endif // End of PERSONAJE_H preprocessor