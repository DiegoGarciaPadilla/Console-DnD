/**
 * @file Potion.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a potion.
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef POTION_H // If the preprocessor POTION_H is not defined
#define POTION_H // Define the preprocessor POTION_H

#include <string> // Include string library

#include "../drivers/Consumable.cc" // Include consumable class

class Potion : public Consumable
{
private:
    // Attributes
    std::string subtype = "Potion";
    std::string material = "Glass";

public:
    // Constructors
    Potion();
    Potion(std::string name, std::string description, int weight, int price, std::string effect, int health, int mana, int stamina);

    // Getters

    // Setters

    // Methods
    std::string toString();
};

#endif // End of the preprocessor POTION_H