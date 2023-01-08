/**
 * @file Consumable.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the declaration of the Consumable class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CONSUMABLE_H // If the preprocessor CONSUMABLE_H is not defined
#define CONSUMABLE_H // Define the preprocessor CONSUMABLE_H

#include "../drivers/Item.cc" // Include the Item class

class Consumable : public Item
{
protected:
    // Attributes
    std::string type = "Consumable";
    int health;
    int mana;
    int stamina;

public:
    // Constructors
    Consumable();
    Consumable(std::string name, std::string description, std::string rarity, int weight, int price, std::string subtype, int health, int mana, int stamina);

    // Getters
    int getHealth();
    int getMana();
    int getStamina();

    // Setters

    // There are no setters because the attributes are constant

    // Methods
    std::string toString();
};

#endif // End of the preprocessor CONSUMABLE_H