/**
 * @file Initializer.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that initialize the arrays of the game.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INITIALIZER_CC // If the file is not defined
#define INITIALIZER_CC // Define the file

#include <iostream>          // Include input and output library
#include <string>            // Include string library
#include <sstream>           // Include string stream library
#include <fstream>           // Include file stream library
#include <cstdlib>           // Include system library
#include <vector>            // Include vector library
#include <nlohmann/json.hpp> // Include JSON library

#include "Weapon.cc" // Include the Weapon class
#include "Armor.cc"  // Include the Armor class
#include "Race.cc"   // Include the Race class
#include "Class.cc"  // Include the Class class
#include "Potion.cc" // Include the Potion class

// Genders

/**
 * @brief Function to get the list of genders
 *
 * @param
 * @return vector
 */

std::vector<std::string> listGenders()
{
    // Create the vector of strings
    std::vector<std::string> genders;

    // Add genders to the vector
    genders.push_back("Male");
    genders.push_back("Woman");
    genders.push_back("Other");

    // Return the vector of genders
    return genders;
}

// Alignments

/**
 * @brief Function to get the list of alignments
 *
 * @param
 * @return vector
 */

std::vector<std::string> listAlignments()
{
    // Create the vector of strings
    std::vector<std::string> alignments;

    // Add alignments to the vector
    alignments.push_back("Lawful Good");
    alignments.push_back("Neutral Good");
    alignments.push_back("Chaotic Good");
    alignments.push_back("Lawful Neutral");
    alignments.push_back("Neutral");
    alignments.push_back("Chaotic Neutral");
    alignments.push_back("Lawful Evil");
    alignments.push_back("Neutral Evil");
    alignments.push_back("Chaotic Evil");

    // Return the vector of alignments
    return alignments;
}

// Weapons

/**
 * @brief Function to initialize weapons array from a JSON file
 *
 * @param
 * @return vector
 */

std::vector<Weapon> initWeapons()
{
    // Variables
    std::string name;
    std::string description;
    std::string rarity;
    float weight;
    int price;
    std::string subtype;
    int damage;

    // Create the vector of weapons
    std::vector<Weapon> weapons;

    // Create the JSON reader
    using json = nlohmann::json;

    // Open the JSON file
    std::ifstream file("data/weapons.json");

    // Check if the file is open
    if (!file.is_open())
    {
        // If the file is not open, print an error message
        std::cout << "Error: The file could not be opened." << std::endl;

        // Return the vector of weapons
        return weapons;
    }

    // Create the JSON object
    json weaponsJSON = json::parse(file);

    // Create the weapon objects
    for (int i = 0; i < weaponsJSON.size(); i++)
    {
        // Get the Weapon attributes
        name = weaponsJSON[i]["name"];
        description = weaponsJSON[i]["description"];
        rarity = weaponsJSON[i]["rarity"];
        weight = weaponsJSON[i]["weight"];
        price = weaponsJSON[i]["price"];
        subtype = weaponsJSON[i]["subtype"];
        damage = weaponsJSON[i]["damage"];

        // Create the weapon object
        Weapon weapon(name, description, rarity, weight, price, subtype, damage);

        // Add the weapon to the vector
        weapons.push_back(weapon);
    }

    // Close the file
    file.close();

    // Return the vector of weapons
    return weapons;
}

/**
 * @brief Function to get the list of weapons
 *
 * @param
 * @return vector
 */

std::vector<std::string> listWeapons()
{
    // Create the vector of strings
    std::vector<std::string> weapons;

    // Create the weapon vector
    std::vector<Weapon> weaponsVector = initWeapons();

    // Add the weapons to the vector
    for (int i = 0; i < weaponsVector.size(); i++)
    {
        weapons.push_back(weaponsVector[i].getName());
    }

    // Return the vector of weapons
    return weapons;
}

// Armors

/**
 * @brief Function to initialize armors array from a JSON file
 *
 * @param
 * @return vector
 */

std::vector<Armor> initArmors()
{
    // Variables
    std::string name;
    std::string description;
    std::string rarity;
    float weight;
    int price;
    std::string subtype;
    int defense;

    // Create the vector of armors
    std::vector<Armor> armors;

    // Create the JSON reader
    using json = nlohmann::json;

    // Open the JSON file
    std::ifstream file("data/armors.json");

    // Check if the file is open
    if (!file.is_open())
    {
        // If the file is not open, print an error message
        std::cout << "Error: The file could not be opened." << std::endl;

        // Return the vector of armors
        return armors;
    }

    // Create the JSON object
    json armorsJSON = json::parse(file);

    // Create the armor objects
    for (int i = 0; i < armorsJSON.size(); i++)
    {
        // Get the Armor attributes
        name = armorsJSON[i]["name"].get<std::string>();
        description = armorsJSON[i]["description"].get<std::string>();
        rarity = armorsJSON[i]["rarity"].get<std::string>();
        weight = armorsJSON[i]["weight"].get<float>();
        price = armorsJSON[i]["price"].get<int>();
        subtype = armorsJSON[i]["subtype"].get<std::string>();
        defense = armorsJSON[i]["defense"].get<int>();

        // Create the armor object
        Armor armor(name, description, rarity, weight, price, subtype, defense);

        // Add the armor to the vector
        armors.push_back(armor);
    }

    // Close the file
    file.close();

    // Return the vector of armors
    return armors;
}

/**
 * @brief Function to get the list of armors
 *
 * @param
 * @return vector
 */

std::vector<std::string> listArmors()
{
    // Create the vector of strings
    std::vector<std::string> armors;

    // Create the armor vector
    std::vector<Armor> armorsVector = initArmors();

    // Add the armors to the vector
    for (int i = 0; i < armorsVector.size(); i++)
    {
        armors.push_back(armorsVector[i].getName());
    }

    // Return the vector of armors
    return armors;
}

// Races

/**
 * @brief Function to initialize the races array from a JSON file
 *
 * @param
 * @return vector
 */

std::vector<Race> initRaces()
{
    // Variables
    std::string name;
    std::string description;
    int strengthModifier;
    int dexterityModifier;
    int constitutionModifier;
    int intelligenceModifier;
    int wisdomModifier;
    int charismaModifier;

    // Create the vector of races
    std::vector<Race> races;

    // Create the JSON reader
    using json = nlohmann::json;

    // Open the JSON file
    std::ifstream file("data/races.json");

    // Check if the file is open
    if (!file.is_open())
    {
        // If the file is not open, print an error message
        std::cout << "Error: The file could not be opened." << std::endl;

        // Return the vector of races
        return races;
    }

    // Create the JSON object
    json racesJSON = json::parse(file);

    // Create the armor objects
    for (int i = 0; i < racesJSON.size(); i++)
    {
        // Get the Race attributes
        name = racesJSON[i]["name"].get<std::string>();
        description = racesJSON[i]["description"].get<std::string>();
        strengthModifier = racesJSON[i]["strengthModifier"].get<int>();
        dexterityModifier = racesJSON[i]["dexterityModifier"].get<int>();
        constitutionModifier = racesJSON[i]["constitutionModifier"].get<int>();
        intelligenceModifier = racesJSON[i]["intelligenceModifier"].get<int>();
        wisdomModifier = racesJSON[i]["wisdomModifier"].get<int>();
        charismaModifier = racesJSON[i]["charismaModifier"].get<int>();

        // Create the race object
        Race race(name, description, strengthModifier, dexterityModifier, constitutionModifier, intelligenceModifier, wisdomModifier, charismaModifier);

        // Add the race to the vector
        races.push_back(race);
    }

    // Close the file
    file.close();

    // Return the vector of races
    return races;
}

/**
 * @brief Function to get the list of races
 *
 * @param
 * @return vector
 */

std::vector<std::string> listRaces()
{
    // Create the vector of strings
    std::vector<std::string> races;

    // Create the races vector
    std::vector<Race> racesVector = initRaces();

    // Add the races to the vector
    for (int i = 0; i < racesVector.size(); i++)
    {
        races.push_back(racesVector[i].getName());
    }

    // Return the vector of races
    return races;
}

// Classes

/**
 * @brief Function to initialize the classes array from a JSON file
 *
 * @param
 * @return vector
 */

std::vector<Class> initClasses()
{
    // Variables for the class
    std::string name;
    std::string description;

    // Variables for the initial weapon
    std::string initialWeaponName;
    std::string initialWeaponDescription;
    std::string initialWeaponRarity;
    float initialWeaponWeight;
    int initialWeaponPrice;
    std::string initialWeaponSubtype;
    int initialWeaponDamage;

    // Variables for the initial armor
    std::string initialArmorName;
    std::string initialArmorDescription;
    std::string initialArmorRarity;
    float initialArmorWeight;
    int initialArmorPrice;
    std::string initialArmorSubtype;
    int initialArmorDefense;

    // Create the vector of classes
    std::vector<Class> classes;

    // Create the JSON reader
    using json = nlohmann::json;

    // Open the JSON file
    std::ifstream file("data/classes.json");

    // Check if the file is open
    if (!file.is_open())
    {
        // If the file is not open, print an error message
        std::cout << "Error: The file could not be opened." << std::endl;

        // Return the vector of classes
        return classes;
    }

    // Create the JSON object
    json classesJSON = json::parse(file);

    // Create the class objects
    for (int i = 0; i < classesJSON.size(); i++)
    {
        // Get the Class attributes
        name = classesJSON[i]["name"].get<std::string>();
        description = classesJSON[i]["description"].get<std::string>();

        // Get the initial weapon attributes
        initialWeaponName = classesJSON[i]["initialWeapon"]["name"].get<std::string>();
        initialWeaponDescription = classesJSON[i]["initialWeapon"]["description"].get<std::string>();
        initialWeaponRarity = classesJSON[i]["initialWeapon"]["rarity"].get<std::string>();
        initialWeaponWeight = classesJSON[i]["initialWeapon"]["weight"].get<float>();
        initialWeaponPrice = classesJSON[i]["initialWeapon"]["price"].get<int>();
        initialWeaponSubtype = classesJSON[i]["initialWeapon"]["subtype"].get<std::string>();
        initialWeaponDamage = classesJSON[i]["initialWeapon"]["damage"].get<int>();

        // Get the initial armor attributes
        initialArmorName = classesJSON[i]["initialArmor"]["name"].get<std::string>();
        initialArmorDescription = classesJSON[i]["initialArmor"]["description"].get<std::string>();
        initialArmorRarity = classesJSON[i]["initialArmor"]["rarity"].get<std::string>();
        initialArmorWeight = classesJSON[i]["initialArmor"]["weight"].get<float>();
        initialArmorPrice = classesJSON[i]["initialArmor"]["price"].get<int>();
        initialArmorSubtype = classesJSON[i]["initialArmor"]["subtype"].get<std::string>();
        initialArmorDefense = classesJSON[i]["initialArmor"]["defense"].get<int>();

        // Create the initial weapon object
        Weapon initialWeapon(initialWeaponName, initialWeaponDescription, initialWeaponRarity, initialWeaponWeight, initialWeaponPrice, initialWeaponSubtype, initialWeaponDamage);

        // Create the initial armor object
        Armor initialArmor(initialArmorName, initialArmorDescription, initialArmorRarity, initialArmorWeight, initialArmorPrice, initialArmorSubtype, initialArmorDefense);

        // Create the class object
        Class classObject(name, description, initialWeapon, initialArmor);

        // Add the class to the vector
        classes.push_back(classObject);
    }
}

/**
 * @brief Function to get the list of classes
 *
 * @param
 * @return vector
 */

std::vector<std::string> listClasses()
{
    // Create the vector of strings
    std::vector<std::string> classes;

    // Create the classes vector
    std::vector<Class> classesVector = initClasses();

    // Add the classes to the vector
    for (int i = 0; i < classesVector.size(); i++)
    {
        classes.push_back(classesVector[i].getName());
    }

    // Return the vector of classes
    return classes;
}

// Potions

/**
 * @brief Function to initialize the potions array from a JSON file
 *
 * @param
 * @return vector
 */

std::vector<Potion> initPotions()
{
    // Variables for the potion
    std::string name;
    std::string description;
    std::string rarity;
    float weight;
    int price;
    int health;
    int mana;
    int stamina;

    // Create the vector of potions
    std::vector<Potion> potions;

    // Create the JSON reader
    using json = nlohmann::json;

    // Open the JSON file
    std::ifstream file("data/potions.json");

    // Check if the file is open
    if (!file.is_open())
    {
        // If the file is not open, print an error message
        std::cout << "Error: The file could not be opened." << std::endl;

        // Return the vector of potions
        return potions;
    }

    // Create the JSON object
    json potionsJSON = json::parse(file);

    // Create the potion objects
    for (int i = 0; i < potionsJSON.size(); i++)
    {
        // Get the potion attributes
        name = potionsJSON[i]["name"].get<std::string>();
        description = potionsJSON[i]["description"].get<std::string>();
        rarity = potionsJSON[i]["rarity"].get<std::string>();
        weight = potionsJSON[i]["weight"].get<float>();
        price = potionsJSON[i]["price"].get<int>();
        health = potionsJSON[i]["health"].get<int>();
        mana = potionsJSON[i]["mana"].get<int>();
        stamina = potionsJSON[i]["stamina"].get<int>();

        // Create the potion object
        Potion potion(name, description, rarity, weight, price, health, mana, stamina);

        // Add the potion to the vector
        potions.push_back(potion);
    }

    // Close the file
    file.close();

    // Return the vector of potions
    return potions;
}

/**
 * @brief Function to get the list of potions
 *
 * @param
 * @return vector
 */

std::vector<std::string> listPotions()
{
    // Create the vector of strings
    std::vector<std::string> potions;

    // Create the potions vector
    std::vector<Potion> potionsVector = initPotions();

    // Add the potions to the vector
    for (int i = 0; i < potionsVector.size(); i++)
    {
        potions.push_back(potionsVector[i].getName());
    }

    // Return the vector of potions
    return potions;
}

#endif // End of the preprocessor INITIALIZER_CC
