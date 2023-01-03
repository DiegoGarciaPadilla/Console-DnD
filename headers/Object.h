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

#endif // End of OBJECT_H preprossesor
