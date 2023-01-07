/**
 * @file Item.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Item class
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ITEM_CC // If the file is not defined
#define ITEM_CC // Define the file

#include "../headers/Item.h" // Include the header file

// Constructors

/**
 * @brief Construct a new Item:: Item object
 *
 */

Item::Item()
{
    name = "Item";
    description = "This is an object";
    weight = 0;
    price = 0;
    type = "Item";
    subtype = "Item";
    material = "Item";
}

/**
 * @brief Construct a new Item:: Item object
 *
 * @param name
 * @param description
 * @param weight
 * @param price
 * @param type
 * @param subtype
 * @param material
 */

Item::Item(std::string name, std::string description, int weight, int price, std::string type, std::string subtype, std::string material)
{
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->price = price;
    this->type = type;
    this->subtype = subtype;
    this->material = material;
}

// Getters

/**
 * @brief Get the Name attribute
 *
 * @return std::string
 */

std::string Item::getName()
{
    return name;
}

/**
 * @brief Get the Description attribute
 *
 * @return std::string
 */

std::string Item::getDescription()
{
    return description;
}

/**
 * @brief Get the Weight attribute
 *
 * @return int
 */

int Item::getWeight()
{
    return weight;
}

/**
 * @brief Get the Price attribute
 *
 * @return int
 */

int Item::getPrice()
{
    return price;
}

/**
 * @brief Get the Type attribute
 *
 * @return std::string
 */

std::string Item::getType()
{
    return type;
}

/**
 * @brief Get the Subtype attribute
 *
 * @return std::string
 */

std::string Item::getSubtype()
{
    return subtype;
}

/**
 * @brief Get the Material attribute
 *
 * @return std::string
 */

std::string Item::getMaterial()
{
    return material;
}

// Setters

/**
 * @brief Set the Name attribute
 *
 * @param name
 */

void Item::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description attribute
 *
 * @param description
 */

void Item::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Weight attribute
 *
 * @param weight
 */

void Item::setWeight(int weight)
{
    this->weight = weight;
}

/**
 * @brief Set the Price attribute
 *
 * @param value
 */

void Item::setPrice(int price)
{
    this->price = price;
}

/**
 * @brief Set the Type attribute
 *
 * @param type
 */

void Item::setType(std::string type)
{
    this->type = type;
}

/**
 * @brief Set the Subtype attribute
 *
 * @param subtype
 */

void Item::setSubtype(std::string subtype)
{
    this->subtype = subtype;
}

/**
 * @brief Set the Material attribute
 *
 * @param material
 */

void Item::setMaterial(std::string material)
{
    this->material = material;
}

// Methods

std::string Item::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Price: " << price << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Material: " << material << std::endl;

    return ss.str();
}

#endif // End of the preprocessor ITEM_CC