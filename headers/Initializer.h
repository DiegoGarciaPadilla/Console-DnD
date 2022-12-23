/**
 * @file Initializer.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that initialize the arrays of the game.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INITIALIZER_H // If the preprocessor INITIALIZER_H is not defined
#define INITIALIZER_H // Define the preprocessor INITIALIZER_H

#include <iostream> // Library for input and output
#include <fstream>  // Library for file input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams
#include <vector>   // Library for vectors

#include "Weapon.h" // Include the weapon class
#include "Armor.h"  // Include the armor class
#include "Race.h"   // Include the race class
#include "Class.h"  // Include the class class

// Genders

/**
 * @brief Function to get the list of genders
 *
 * @param
 * @return list
 */

std::string *listGenders()
{
    // Create the array of strings
    std::string *list;

    // Add genders to the array
    list[0] = "Male";
    list[1] = "Female";
    list[2] = "Other";

    // Return array of genders
    return list;
}

// Alignments

/**
 * @brief Function to get the list of alignments
 *
 * @param
 * @return list
 */

std::string *listAlignments()
{
    // Create the array of strings
    std::string *list;

    // Add alignments to the array
    list[0] = "Lawful Good";
    list[1] = "Neutral Good";
    list[2] = "Chaotic Good";
    list[3] = "Lawful Neutral";
    list[4] = "True Neutral";
    list[5] = "Chaotic Neutral";
    list[6] = "Lawful Evil";
    list[7] = "Neutral Evil";
    list[8] = "Chaotic Evil";

    // Return array of alignments
    return list;
}

// Weapons

/**
 * @brief Function to initialize weapons array
 *
 * @param
 * @return armas
 */

Weapon *initWeapons()
{
    // Open the file
    std::ifstream file("./data/weapons.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of weapons
    std::string line;
    std::getline(file, line);
    int numWeapons = std::stoi(line);

    // Create the array of weapons
    Weapon *weapons = new Weapon[numWeapons];

    // Read the file line by line
    int i = 0;
    while (std::getline(file, line))
    {
        // Split the line by pipe character
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        // Create the weapon
        Weapon weapon(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), tokens[4], tokens[5], std::stoi(tokens[6]));

        // Add the weapon to the array
        weapons[i] = weapon;

        // Increase the counter
        i++;
    }

    // Close the file
    file.close();

    // Return the array of weapons
    return weapons;
}

/**
 * @brief Function to get the list of weapons
 *
 * @param
 * @return list
 */

std::string *listWeapons()
{
    // Create the array of weapons
    Weapon *weapons = initWeapons();

    // Get the number of weapons
    int numWeapons = sizeof(weapons) / sizeof(weapons[0]);

    // Create the array of strings
    std::string *list;

    // Add the weapons to the array
    for (int i = 0; i < numWeapons; i++)
    {
        list[i] = weapons[i].toString();
    }

    // Delete the weapons array
    delete[] weapons;

    // Return the array of strings
    return list;
}

// Armors

/**
 * @brief Function to initialize armors array
 *
 * @param
 * @return armors
 */

Armor *initArmors()
{
    // Open the file
    std::ifstream file("./data/armors.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of armors
    std::string line;
    std::getline(file, line);
    int numArmors = std::stoi(line);

    // Create the array of armors
    Armor *armors = new Armor[numArmors];

    // Read the file line by line
    int i = 0;
    while (std::getline(file, line))
    {
        // Split the line by pipe character
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        // Create the armor
        Armor armor(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), tokens[4], tokens[5], std::stoi(tokens[6]));

        // Add the armor to the array
        armors[i] = armor;

        // Increase the counter
        i++;
    }

    // Close the file
    file.close();

    // Return the array of armors
    return armors;
}

/**
 * @brief Function to get the list of armors
 *
 * @param
 * @return list
 */

std::string *listArmors()
{
    // Create the array of armors
    Armor *armors = initArmors();

    // Get the number of armors
    int numArmors = sizeof(armors) / sizeof(armors[0]);

    // Create the array of strings
    std::string *list;

    // Add the armors to the array
    for (int i = 0; i < numArmors; i++)
    {
        list[i] = armors[i].toString();
    }

    // Delete the armors array
    delete[] armors;

    // Return the array of strings
    return list;
}

// Races

/**
 * @brief Function to initialize races array
 *
 * @param
 * @return races
 */

Race *initRaces()
{
    // Open the file
    std::ifstream file("./data/races.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of races
    std::string line;
    std::getline(file, line);
    int numRaces = std::stoi(line);

    // Create the array of races
    Race *races = new Race[numRaces];

    // Read the file line by line
    int i = 0;
    while (std::getline(file, line))
    {
        // Split the line by pipe character
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        // Create the race
        Race race(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]));

        // Add the race to the array
        races[i] = race;

        // Increase the counter
        i++;
    }

    // Close the file
    file.close();

    // Return the array of races
    return races;
}

/**
 * @brief Function to get the list of races
 *
 * @param
 * @return list
 */

std::string *listRaces()
{
    // Create the array of races
    Race *races = initRaces();

    // Get the number of races
    int numRaces = sizeof(races) / sizeof(races[0]);

    // Create the array of strings
    std::string *list;

    // Add the races to the array
    for (int i = 0; i < numRaces; i++)
    {
        list[i] = races[i].toString();
    }

    // Delete races array
    delete[] races;

    // Return the array of strings
    return list;
}

// Classes

/**
 * @brief Function to initialize classes array
 *
 * @param
 * @return classes
 */

Class *initClasses()
{

    // Initialize the weapons and armors arrays
    Weapon *weapons = initWeapons();
    Armor *armors = initArmors();

    // Open the file
    std::ifstream file("./data/classes.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of classes
    std::string line;
    std::getline(file, line);
    int numClasses = std::stoi(line);

    // Create the array of classes
    Class *classes = new Class[numClasses];

    // Read the file line by line
    int i = 0;
    while (std::getline(file, line))
    {
        // Split the line by pipe character
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        // Create the class
        Class cl(tokens[0], tokens[1], weapons[i], armors[i]);

        // Add the class to the array
        classes[i] = cl;

        // Increase the counter
        i++;
    }

    // Close the file
    file.close();

    // Return the array of classes
    return classes;
}

/**
 * @brief Function to get the list of classes
 *
 * @param
 * @return list
 */

std::string *listClasses()
{
    // Create the array of classes
    Class *classes = initClasses();

    // Get the number of classes
    int numClasses = sizeof(classes) / sizeof(classes[0]);

    // Create the array of strings
    std::string *list;

    // Add the classes to the array
    for (int i = 0; i < numClasses; i++)
    {
        list[i] = classes[i].toString();
    }

    // Delete classes array
    delete[] classes;

    // Return the array of strings
    return list;
}

#endif // End of the INITIALIZER_H preprocessor