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
            if (character.getName() != "None")
            {
                // Variables
                int characterOption;

                // Ask the user if they want to overwrite the character
                std::cout << "There is already a character created" << std::endl;
                std::cout << "Do you want to overwrite it?" << std::endl;
                std::cout << "1. Yes" << std::endl;
                std::cout << "2. No" << std::endl;
                std::cin >> characterOption;

                // Switch for the character menu
                switch (characterOption)
                {
                case 1:
                    character.createCharacter();
                    break;
                case 2:
                    std::cout << "The character was not overwritten" << std::endl;
                    break;
                default:
                    std::cout << "Invalid option" << std::endl;
                    break;
                }
            }
            else
            {
                character.createCharacter();
            }
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
                character.showEquippedItems();
            }
            pause();
            break;
        case 4:
            if (character.getName() == "None")
            {
                std::cout << "There is no character to show" << std::endl;
            }
            else
            {
                character.showInventory();
            }
            pause();
            break;
        case 5:
            encyclopediaMenu();
            break;
        case 6:
            std::cout << "Goodbye adventurer. See you soon..." << std::endl;
            pause();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            pause();
            break;
        }
        cleanScreen();
    } while (mainOption != 6);
}

#endif // End of the preprocessor MAIN_H