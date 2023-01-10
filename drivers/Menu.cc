/**
 * @file Menu.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that print the menu.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MENU_CC // If the file is not defined
#define MENU_CC // Define the file

#include "Ascii.cc"       // Include the Ascii file
#include "Initializer.cc" // Include the Initializer file
#include "Functions.cc"   // Include the Functions file

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
    std::cout << readAsciiArt("asciiArt/title.txt") << std::endl;

    // Show the options
    std::cout << "1. Create character" << std::endl;
    std::cout << "2. Show character" << std::endl;
    std::cout << "3. Show equipped items" << std::endl;
    std::cout << "4. Show inventory" << std::endl;
    std::cout << "5. Merchant" << std::endl;
    std::cout << "6. D&D encyclopedia" << std::endl;
    std::cout << std::endl;

    // Exit option
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
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
    std::vector<Race> races = initRaces();
    std::vector<std::string> racesNames = listRaces();
    int racesNumber = races.size();

    // Show the races menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's races encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show races
        printStringVector(racesNames);
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check the option
        if (option > 0 && option <= racesNumber)
        {
            // Clear the screen
            cleanScreen();

            //  Show the race
            std::cout << races[option - 1].toString() << std::endl;
            pause();
        }
        else if (option == 0)
        {
            // Return
        }
        else
        {
            // Invalid option
            std::cout << "Invalid option" << std::endl;
            pause();
        }

    } while (option != 0);
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
    std::vector<Class> classes = initClasses();
    std::vector<std::string> classesNames = listClasses();
    int classesNumber = classes.size();

    // Show the classes menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's classes encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show classes
        printStringVector(classesNames);
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check the option
        if (option > 0 && option <= classesNumber)
        {
            // Clear the screen
            cleanScreen();

            //  Show the class
            std::cout << classes[option - 1].toString() << std::endl;
            pause();
        }
        else if (option == 0)
        {
            // Return
        }
        else
        {
            // Invalid option
            std::cout << "Invalid option" << std::endl;
            pause();
        }

    } while (option != 0);
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
    std::vector<Weapon> weapons = initWeapons();
    std::vector<std::string> weaponsNames = listWeapons();
    int weaponsNumber = weapons.size();

    // Show the weapons menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's weapons encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show weapons
        printStringVector(weaponsNames);
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check the option
        if (option > 0 && option <= weaponsNumber)
        {
            // Clear the screen
            cleanScreen();

            // Show the weapon
            std::cout << weapons[option - 1].toString() << std::endl;
            pause();
        }
        else if (option == 0)
        {
            // Return
        }
        else
        {
            // Invalid option
            std::cout << "Invalid option" << std::endl;
            pause();
        }

    } while (option != 0);
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
    std::vector<Armor> armors = initArmors();
    std::vector<std::string> armorsNames = listArmors();
    int armorsNumber = armors.size();

    // Show the armors menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's armors encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show armors
        printStringVector(armorsNames);
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check the option
        if (option > 0 && option <= armorsNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the armor
            std::cout << armors[option - 1].toString() << std::endl;
            pause();
        }
        else if (option == 0)
        {
            // Do nothing
        }
        else
        {
            // Print a message
            std::cout << "Invalid option" << std::endl;
            pause();
        }

    } while (option != 0);
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
        std::cout << readAsciiArt("asciiArt/encyclopedia.txt") << std::endl;

        // Show the options
        std::cout << "1. Races" << std::endl;
        std::cout << "2. Classes" << std::endl;
        std::cout << "3. Weapons" << std::endl;
        std::cout << "4. Armors" << std::endl;
        std::cout << std::endl;

        // Return option
        std::cout << "0. Return" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check the option
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
        case 0:
            std::cout << "You can come here if you want to learn more about D&D" << std::endl;
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            break;
        }

    } while (option != 0);
}

#endif // End of the preprocessor MENU_CC