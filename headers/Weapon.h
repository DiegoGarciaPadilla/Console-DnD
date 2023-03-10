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

#include "../drivers/Item.cc" // Include the object class

class Weapon : public Item
{
private:
    // Attributes
    std::string type = "Weapon";
    int damage;

public:
    // Constructors
    Weapon();
    Weapon(std::string name, std::string description, std::string rarity, float weight, int price, std::string subtype, int damage);

    // Getters
    int getDamage();

    // Setters
    void setDamage(int damage);

    // Methods
    std::string toString();
};

#endif // End of the WEAPON_H preprocessor