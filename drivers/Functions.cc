/**
 * @file Functions.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that are used in the game.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FUNCTIONS_CC // If the file is not defined
#define FUNCTIONS_CC // Define the file

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <cstdlib>  // Include system library
#include <vector>   // Include vector library

#include "Initializer.cc" // Include the Initializer file
#include "Race.cc"        // Include the Race class
#include "Class.cc"       // Include the Class class
#include "Stats.cc"       // Include the Stats class
#include "Character.cc"   // Include the Character class

// General functions

/**
 * @brief Function to clear the screen on Windows
 *
 * @param
 * @return
 */

void cleanScreen()
{
    system("cls");
}

/**
 * @brief Function to pause the program on Windows
 *
 * @param
 * @return
 */

void pause()
{
    system("pause");
}

/**
 * @brief Function to print a vector
 *
 * @param vector
 * @return
 */

void printStringVector(std::vector<std::string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << i + 1 << ". " << v[i] << std::endl;
    }
}

/**
 * @brief Function to create a character with the data entered by the user
 *
 * @param character
 * @return
 */

void createCharacter(Character &character)
{
    // Variables
    std::string name;
    std::string gender;
    int age;
    std::string alignment;
    Race race;
    int option;

    // Vectors
    std::vector<std::string> genders = listGenders();
    std::vector<std::string> alignments = listAlignments();
    std::vector<std::string> races = listRaces();
    std::vector<std::string> classes = listClasses();

    // Clear the screen
    cleanScreen();

    // Introduction
    std::cout << "Hello adventurer! Welcome to the world of D&D!" << std::endl;
    std::cout << "I'm going to ask you some questions to create your character." << std::endl;
    std::cout << "Are you ready? " << std::endl;
    pause();

    // Clear the screen
    cleanScreen();

    // Set the name
    std::cout << "What is your name? ";
    getline(std::cin >> std::ws, name);
    std::cout << std::endl;
    character.setName(name);

    // Set the gender
    std::cout << "What gender do you identify with? " << std::endl;
    printStringVector(genders);
    std::cin >> option;
    while (option < 1 || option > 3)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    // If the user chooses the option 3, it will ask for the specific gender
    if (option == 3)
    {
        std::string specificGender;
        std::cout << "Can you specify it? " << std::endl;
        getline(std::cin >> std::ws, specificGender);
        character.setGender(specificGender);
    }
    else
    {
        character.setGender(genders[option - 1]);
    }
    std::cout << std::endl;

    // Set the age
    std::cout << "Age: ";
    std::cin >> age;
    while (age < 0)
    {
        std::cout << "Invalid age" << std::endl;
        std::cin >> age;
    }
    std::cout << std::endl;
    character.setAge(age);

    // Set the alignment
    std::cout << "Alignment: " << std::endl;
    printStringVector(alignments);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.setAlignment(alignments[option - 1]);

    // Set the race
    std::cout << "Race: " << std::endl;
    printStringVector(races);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.defineRace(option - 1);

    // Set the class
    std::cout << "Class: " << std::endl;
    printStringVector(classes);
    std::cin >> option;
    while (option < 1 || option > 9)
    {
        std::cout << "Invalid option" << std::endl;
        std::cin >> option;
    }
    std::cout << std::endl;
    character.defineClass(option - 1);

    // Set the stats
    std::cout << "Stats:" << std::endl;
    std::cout << "The stats are generated randomly." << std::endl;
    character.defineStats();
    std::cout << std::endl;
}

#endif // End of the preprocessor FUNCTIONS_CC