/**
 * @file NPC.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the NPC class.
 * @version 0.1
 * @date 2023-01-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NPC_CC // If the file is not defined
#define NPC_CC // Define the file

#include "../headers/NPC.h" // Include the NPC header file
#include "Functions.cc"     // Include the functions file

// Constructors

/**
 * @brief Construct a new NPC::NPC object
 * 
 * @param 
 * @return 
 */

NPC::NPC()
{
    this->name = "NPC";
    this->description = "This is a NPC.";
    this->dialogues = {"Hello, I am a NPC."};
    this->options = {{"Hello"}, {"Bye"}};
    this->responses = {{"Hello, I am a NPC."}, {"Bye, I am a NPC."}};
}

/**
 * @brief Construct a new NPC::NPC object
 * 
 * @param name 
 * @param description 
 * @param dialogues 
 * @param options 
 * @param responses 
 * @return 
 */

NPC::NPC(std::string name, std::string description, std::vector<std::string> dialogues, std::vector<std::vector<std::string>> options, std::vector<std::vector<std::string>> responses)
{
    this->name = name;
    this->description = description;
    this->dialogues = dialogues;
    this->options = options;
    this->responses = responses;
}

// Getters

/**
 * @brief Get the Name object
 * 
 * @param 
 * @return std::string 
 */

std::string NPC::getName()
{
    return this->name;
}

/**
 * @brief Get the Description object
 * 
 * @param 
 * @return std::string 
 */

std::string NPC::getDescription()
{
    return this->description;
}

/**
 * @brief Get the Dialogues object
 * 
 * @param 
 * @return std::vector<std::string> 
 */

std::vector<std::string> NPC::getDialogues()
{
    return this->dialogues;
}

/**
 * @brief Get the Options object
 * 
 * @param 
 * @return std::vector<std::string> 
 */

std::vector<std::vector<std::string>> NPC::getOptions()
{
    return this->options;
}

/**
 * @brief Get the Responses object
 * 
 * @param 
 * @return std::vector<std::string> 
 */

std::vector<std::vector<std::string>> NPC::getResponses()
{
    return this->responses;
}

// Setters

/**
 * @brief Set the Name object
 * 
 * @param name 
 * @return void 
 */

void NPC::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description object
 * 
 * @param description 
 * @return void 
 */

void NPC::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Dialogues object
 * 
 * @param dialogues 
 * @return void 
 */

void NPC::setDialogues(std::vector<std::string> dialogues)
{
    this->dialogues = dialogues;
}

/**
 * @brief Set the Options object
 * 
 * @param options 
 * @return void 
 */

void NPC::setOptions(std::vector<std::vector<std::string>> options)
{
    this->options = options;
}

/**
 * @brief Set the Responses object
 * 
 * @param responses 
 * @return void 
 */

void NPC::setResponses(std::vector<std::vector<std::string>> responses)
{
    this->responses = responses;
}

// Methods

/**
 * @brief This method is used to print the NPC information.
 * 
 * @param 
 * @return std::string  
 */

std::string NPC::toString()
{
    std::stringstream ss;

    ss << "Name: " << this->name << std::endl;
    ss << "Description: " << this->description << std::endl;
    ss << "Dialogues: " << std::endl;
    for (int i = 0; i < this->dialogues.size(); i++)
    {
        ss << i + 1 << ". " << this->dialogues[i] << std::endl;
        ss << "Options: " << std::endl;
        for (int j = 0; j < this->options[i].size(); j++)
        {
            ss << j + 1 << ". " << this->options[i][j] << std::endl;
        }
        ss << "Responses: " << std::endl;
        for (int j = 0; j < this->responses[i].size(); j++)
        {
            ss << j + 1 << ". " << this->responses[i][j] << std::endl;
        }
    }
    return ss.str();
}

/**
 * @brief This method is used to talk with the NPC.
 * 
 * @param 
 * @return void 
 */

void NPC::talk()
{
    // Variables
    int randomDialogue = rand() % this->dialogues.size();
    int option;

    // Clear the screen
    cleanScreen();
    
    // Print the NPC name and description
    std::cout << this->name << std::endl;
    std::cout << this->description << std::endl;
    std::cout << std::endl;

    // Print one of the NPC dialogues randomly
    std::cout << this->dialogues[randomDialogue] << std::endl;
    std::cout << std::endl;

    // Print the NPC options
    for (int i = 0; i < this->options[randomDialogue].size(); i++)
    {
        std::cout << i + 1 << ". " << this->options[randomDialogue][i] << std::endl;
    }

    // Ask the user for an option
    std::cout << std::endl;
    std::cout << "Choose an option: ";
    std::cin >> option;

    // Clear the screen
    cleanScreen();

    // Print the NPC response
    std::cout << this->responses[randomDialogue][option - 1] << std::endl;
}

#endif // End of the preprocessor NPC_CC