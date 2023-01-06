/**
 * @file NPC.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a non-playable character.
 * @version 0.1
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NPC_H // If the NPC_H preprocessor is not defined
#define NPC_H // Define the NPC_H preprocessor

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <cstdlib>  // Include system library
#include <vector>   // Include vector library

class NPC
{
private:
    // Attributes
    std::string name;
    std::string description;
    std::vector<std::string> dialogues;
    std::vector<std::vector<std::string>> options;
    std::vector<std::vector<std::string>> responses;

public:
    // Constructors
    NPC();
    NPC(std::string name, std::string description, std::vector<std::string> dialogues, std::vector<std::vector<std::string>> options, std::vector<std::vector<std::string>> responses);

    // Getters
    std::string getName();
    std::string getDescription();
    std::vector<std::string> getDialogues();
    std::vector<std::vector<std::string>> getOptions();
    std::vector<std::vector<std::string>> getResponses();

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setDialogues(std::vector<std::string> dialogues);
    void setOptions(std::vector<std::vector<std::string>> options);
    void setResponses(std::vector<std::vector<std::string>> responses);

    // Methods
    std::string toString();
    void talk();
};

#endif // End of the NPC_H preprocessor