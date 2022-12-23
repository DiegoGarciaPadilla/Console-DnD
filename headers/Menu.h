/**
 * @file Menu.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that show the menus of the game.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MENU_H // If the preprocessor MENU_H is not defined
#define MENU_H // Define the preprocessor MENU_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Functions.h"   // Include the functions file
#include "Initializer.h" // Include the Initializer file
#include "Race.h"        // Include the race class
#include "Class.h"       // Include the class class
#include "Weapon.h"      // Include the weapon class
#include "Armor.h"       // Include the armor class

// Functions

/**
 * @brief Function to show the main menu
 *
 * @param
 * @return
 */

void mainMenu()
{
    // Clear the screen
    cleanScreen();

    // Show the main menu
    std::cout << "Welcome to the D&D character creator" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Create character" << std::endl;
    std::cout << "2. Show character" << std::endl;
    std::cout << "3. D&D encyclopedia" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

/**
 * @brief Function to show the race encyclopedia menu
 *
 * @param
 * @return
 */

void racesMenu()
{
    // Variables
    int option;

    // Arrays
    Race *races = initRaces();
    std::string *racesNames = listRaces();
    int racesNumber = sizeof(races) / sizeof(races[0]);

    // Show the races menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's races encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show races
        printArray(racesNames);
        std::cout << racesNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > racesNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the race
        if (option != racesNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the race
            std::cout << races[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != racesNumber + 1);

    // Delete the arrays
    delete[] races;
    delete[] racesNames;
}

/**
 * @brief Function to show the class encyclopedia menu
 *
 * @param
 * @return
 */

void classesMenu()
{
    // Variables
    int option;

    // Arrays
    Class *classes = initClasses();
    std::string *classesNames = listClasses();
    int classesNumber = sizeof(classes) / sizeof(classes[0]);

    // Show the classes menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's classes encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show classes
        printArray(classesNames);
        std::cout << classesNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > classesNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the class
        if (option != classesNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the class
            std::cout << classes[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != 10);

    // Delete the arrays
    delete[] classes;
    delete[] classesNames;
}

/**
 * @brief Function to show the weapons encyclopedia menu
 *
 * @param
 * @return
 */

void weaponsMenu()
{
    // Variables
    int option;

    // Arrays
    Weapon *weapons = initWeapons();
    std::string *weaponsNames = listWeapons();
    int weaponsNumber = sizeof(weapons) / sizeof(weapons[0]);

    // Show the weapons menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's weapons encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show weapons
        printArray(weaponsNames);
        std::cout << weaponsNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > weaponsNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the weapon
        if (option != weaponsNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the weapon
            std::cout << weapons[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != weaponsNumber + 1);

    // Delete the arrays
    delete[] weapons;
    delete[] weaponsNames;
}

/**
 * @brief Function to show the armor encyclopedia menu
 *
 * @param
 * @return
 */

void armorMenu()
{
    // Variables
    int option;

    // Arrays
    Armor *armors = initArmors();
    std::string *armorsNames = listArmors();
    int armorsNumber = sizeof(armors) / sizeof(armors[0]);

    // Show the armors menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's armors encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show armors
        printArray(armorsNames);
        std::cout << armorsNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > armorsNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the armor
        if (option != armorsNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the armor
            std::cout << armors[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != 10);

    // Delete the arrays
    delete[] armors;
    delete[] armorsNames;
}

/**
 * @brief Function to show the encyclopedia menu
 *
 * @param
 * @return
 */

void encyclopediaMenu()
{
    // Variables
    int option;

    // Show the encyclopedia menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Bienvenido a la enciclopedia de D&D" << std::endl;
        std::cout << std::endl;

        // Show the options
        std::cout << "1. Races" << std::endl;
        std::cout << "2. Classes" << std::endl;
        std::cout << "3. Weapons" << std::endl;
        std::cout << "4. Armors" << std::endl;
        std::cout << "5. Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > 5)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the encyclopedia
        switch (option)
        {
        case 1:
            racesMenu();
            break;
        case 2:
            classesMenu();
            break;
        case 3:
            weaponsMenu();
            break;
        case 4:
            armorMenu();
            break;
        }

    } while (option != 5);
}

#endif // End of the MENU_H preprocessor