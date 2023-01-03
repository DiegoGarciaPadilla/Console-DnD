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

class Item
{
protected:
    // Attributes
    std::string name;
    std::string description;
    int weight;
    int value;
    std::string type;
    std::string subtype;
    std::string material;

public:
    // Constructors
    Item();
    Item(std::string name, std::string description, int weight, int value, std::string type, std::string subtype, std::string material);

    // Getters
    std::string getName();
    std::string getDescription();
    int getWeight();
    int getValue();
    std::string getType();
    std::string getSubtype();
    std::string getMaterial();

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setWeight(int weight);
    void setValue(int value);
    void setType(std::string type);
    void setSubtype(std::string subtype);
    void setMaterial(std::string material);

    // Methods
    std::string toString();
};

#endif // End of ITEM_H preprossesor
