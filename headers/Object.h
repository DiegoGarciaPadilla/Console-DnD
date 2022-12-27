/**
 * @file Object.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief
 * @version 0.1
 * @date 2022-12-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef OBJECT_H // If the preprocessor OBJECT_H is not defined
#define OBJECT_H // Define the preprocessor OBJECT_H

class Object
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
    Object();
    Object(std::string name, std::string description, int weight, int value, std::string type, std::string subtype, std::string material);

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

// Constructors

/**
 * @brief Construct a new Object:: Object object
 * 
 */

Object::Object()
{
    name = "Object";
    description = "This is an object";
    weight = 0;
    value = 0;
    type = "Object";
    subtype = "Object";
    material = "Object";
}

/**
 * @brief Construct a new Object:: Object object
 * 
 * @param name 
 * @param description 
 * @param weight 
 * @param value 
 * @param type 
 * @param subtype 
 * @param material 
 */

Object::Object(std::string name, std::string description, int weight, int value, std::string type, std::string subtype, std::string material)
{
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->value = value;
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

std::string Object::getName()
{
    return name;
}

/**
 * @brief Get the Description attribute
 * 
 * @return std::string 
 */

std::string Object::getDescription()
{
    return description;
}

/**
 * @brief Get the Weight attribute
 * 
 * @return int
 */

int Object::getWeight()
{
    return weight;
}

/**
 * @brief Get the Value attribute
 * 
 * @return int
 */

int Object::getValue()
{
    return value;
}

/**
 * @brief Get the Type attribute
 * 
 * @return std::string 
 */

std::string Object::getType()
{
    return type;
}

/**
 * @brief Get the Subtype attribute
 * 
 * @return std::string 
 */

std::string Object::getSubtype()
{
    return subtype;
}

/**
 * @brief Get the Material attribute
 * 
 * @return std::string 
 */

std::string Object::getMaterial()
{
    return material;
}

// Setters

/**
 * @brief Set the Name attribute
 * 
 * @param name 
 */

void Object::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description attribute
 * 
 * @param description 
 */

void Object::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Weight attribute
 * 
 * @param weight 
 */

void Object::setWeight(int weight)
{
    this->weight = weight;
}

/**
 * @brief Set the Value attribute
 * 
 * @param value 
 */

void Object::setValue(int value)
{
    this->value = value;
}

/**
 * @brief Set the Type attribute
 * 
 * @param type 
 */

void Object::setType(std::string type)
{
    this->type = type;
}

/**
 * @brief Set the Subtype attribute
 * 
 * @param subtype 
 */

void Object::setSubtype(std::string subtype)
{
    this->subtype = subtype;
}

/**
 * @brief Set the Material attribute
 * 
 * @param material 
 */

void Object::setMaterial(std::string material)
{
    this->material = material;
}

// Methods

std::string Object::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Weight: " << weight << std::endl;
    ss << "Value: " << value << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Subtype: " << subtype << std::endl;
    ss << "Material: " << material << std::endl;

    return ss.str();
}

#endif // End of OBJECT_H preprossesor
