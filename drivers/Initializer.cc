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

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <fstream>  // Include file stream library
#include <cstdlib>  // Include system library
#include <vector>   // Include vector library

#include "Weapon.cc" // Include the Weapon class
#include "Armor.cc"  // Include the Armor class
#include "Race.cc"   // Include the Race class
#include "Class.cc"  // Include the Class class

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
 * @brief Function to initialize weapons array
 *
 * @param
 * @return vector
 */

std::vector<Weapon> initWeapons()
{
    // Open the file
    std::ifstream file("data/weapons.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return std::vector<Weapon>();
    }

    // Create the vector of weapons
    std::vector<Weapon> weapons;

    // Line of the file
    std::string line;

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

        // Add the weapon to the vector
        weapons.push_back(weapon);

        // Increase the counter
        i++;
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

    // Create the vector of weapons
    std::vector<Weapon> weaponsArray = initWeapons();

    // Get the number of weapons
    int numWeapons = weaponsArray.size();

    // Add weapons to the vector
    for (int i = 0; i < numWeapons; i++)
    {
        weapons.push_back(weaponsArray[i].getName());
    }

    // Return the vector of weapons
    return weapons;
}

// Armors

/**
 * @brief Function to initialize armors array
 *
 * @param
 * @return vector
 */

std::vector<Armor> initArmors()
{
    // Open the file
    std::ifstream file("data/armors.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return std::vector<Armor>();
    }

    // Create the vector of armors
    std::vector<Armor> armors;

    // Line of the file
    std::string line;

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

        // Add the armor to the vector
        armors.push_back(armor);

        // Increase the counter
        i++;
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
 * @return std::vector
 */

std::vector<std::string> listArmors()
{
    // Create the vector of strings
    std::vector<std::string> armors;

    // Create the vector of armors
    std::vector<Armor> armorsArray = initArmors();

    // Get the number of armors
    int numArmors = armorsArray.size();

    // Add armors to the vector
    for (int i = 0; i < numArmors; i++)
    {
        armors.push_back(armorsArray[i].getName());
    }

    // Return the vector of armors
    return armors;
}

// Races

/**
 * @brief Function to initialize races array
 *
 * @param
 * @return vector
 */

std::vector<Race> initRaces()
{
    // Open the file
    std::ifstream file("data/races.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return std::vector<Race>();
    }

    // Create the vector of races
    std::vector<Race> races;

    // Line of the file
    std::string line;

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

        // Add the race to the vector
        races.push_back(race);

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
 * @return vector
 */

std::vector<std::string> listRaces()
{
    // Create the vector of strings
    std::vector<std::string> races;

    // Create the vector of races
    std::vector<Race> racesArray = initRaces();

    // Get the number of races
    int numRaces = racesArray.size();

    // Add races to the vector
    for (int i = 0; i < numRaces; i++)
    {
        races.push_back(racesArray[i].getName());
    }

    // Return the vector of races
    return races;
}

// Classes

/**
 * @brief Function to initialize classes array
 *
 * @param
 * @return vector
 */

std::vector<Class> initClasses()
{

    // Initialize the weapons and armors vectors
    std::vector<Weapon> weapons = initWeapons();
    std::vector<Armor> armors = initArmors();

    // Open the file
    std::ifstream file("data/classes.txt");

    // Check if the file was opened correctly
    if (!file.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "There was an error opening the file" << std::endl;
        return std::vector<Class>();
    }

    // Create the vector of classes
    std::vector<Class> classes;

    // Line of the file
    std::string line;

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

        // Add the class to the vector
        classes.push_back(cl);

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
 * @return vector
 */

std::vector<std::string> listClasses()
{
    // Create the vector of strings
    std::vector<std::string> classes;

    // Create the vector of classes
    std::vector<Class> classesArray = initClasses();

    // Get the number of classes
    int numClasses = classesArray.size();

    // Add classes to the vector
    for (int i = 0; i < numClasses; i++)
    {
        classes.push_back(classesArray[i].getName());
    }

    // Return the vector of classes
    return classes;
}

#endif // End of the preprocessor INITIALIZER_CC