/**
 * @file main.cpp
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This program is a character creator for the D&D game.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MAIN_H // If the preprocessor MAIN_H is not defined
#define MAIN_H // Define the preprocessor MAIN_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams
#include <fstream>  // Library for file streams
#include <cstdlib>  // Library for system functions
#include <vector>   // Library for vectors

#include "drivers/Menu.cc"        // Library for menus
#include "drivers/Initializer.cc" // Library for initializers
#include "drivers/Functions.cc"   // Library for functions
#include "drivers/Character.cc"   // Library for the character class

// Main function
int main()
{
    // Variables
    int mainOption;
    Character character;

    // Main menu loop
    do
    {
        // Show the main menu
        mainMenu();
        std::cin >> mainOption;
        cleanScreen();

        // Switch for the main menu
        switch (mainOption)
        {
        case 1:
            character.createCharacter();
            pause();
            break;
        case 2:
            if (character.getName() == "None")
            {
                std::cout << "There is no character to show" << std::endl;
            }
            else
            {
                std::cout << character.toString() << std::endl;
            }
            pause();
            break;
        case 3:
            if (character.getName() == "None")
            {
                std::cout << "There is no character to show" << std::endl;
            }
            else
            {
                character.showInventory();
            }
            break;
        case 4:
            encyclopediaMenu();
            break;
        case 5:
            std::cout << "Goodbye adventurer. See you soon..." << std::endl;
            pause();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            pause();
            break;
        }
        cleanScreen();
    } while (mainOption != 4);
}

#endif // End of the preprocessor MAIN_H