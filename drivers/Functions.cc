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

#endif // End of the preprocessor FUNCTIONS_CC