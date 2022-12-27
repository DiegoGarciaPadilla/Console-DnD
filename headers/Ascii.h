/**
 * @file Ascii.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the ASCII art of the game.
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ASCII_H // If the preprocessor ASCII_H is not defined
#define ASCII_H // Define the preprocessor ASCII_H

/**
 * @brief Function to read the ASCII art from a file and return it as a string
 *
 * @param fileName
 * @return std::string
 */

std::string readAscii(std::string fileName)
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

#endif // End of the preprocessor ASCII_H