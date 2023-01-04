/**
 * @file Ascii.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that print the ASCII art.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ASCII_CC // If the file is not defined
#define ASCII_CC // Define the file

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <fstream>  // Include file stream library

/**
 * @brief Function to read the ASCII art from a file and return it as a string
 *
 * @param fileName
 * @return std::string
 */

std::string readAsciiArt(std::string fileName)
{
    // Create the string
    std::string ascii;

    // Create the file stream
    std::ifstream file;

    // Open the file
    file.open(fileName);

    // Check if the file is open
    if (file.is_open())
    {
        // Create the string stream
        std::stringstream stream;

        // Add the file to the stream
        stream << file.rdbuf();

        // Close the file
        file.close();

        // Add the stream to the string
        ascii = stream.str();
    }

    // Return the string
    return ascii;
}

#endif // End of the preprocessor ASCII_CC