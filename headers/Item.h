/**
 * @file Item.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the declaration of the Item class
 * @version 0.1
 * @date 2022-12-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ITEM_H // If the preprocessor ITEM_H is not defined
#define ITEM_H // Define the preprocessor ITEM_H

#include <iostream> // Include the input/output library
#include <string>   // Include the string library
#include <sstream>  // Include the string stream library

class Item
{
protected:
    // Attributes
    std::string name;
    std::string description;
    std::string rarity;

    int weight;
    int price;

    std::string type;
    std::string subtype;

public:
    // Constructors
    Item();
    Item(std::string name, std::string description, std::string rarity, int weight, int price, std::string type, std::string subtype);

    // Getters
    std::string getName();
    std::string getDescription();
    std::string getRarity();
    int getWeight();
    int getPrice();
    std::string getType();
    std::string getSubtype();

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setRarity(std::string rarity);
    void setWeight(int weight);
    void setPrice(int value);
    void setType(std::string type);
    void setSubtype(std::string subtype);

    // Methods
    std::string toString();
};

#endif // End of ITEM_H preprossesor
