/**
 * @file Quest.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Quest class
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUEST_CC // If the preprocessor QUEST_CC is not defined
#define QUEST_CC // Define the preprocessor QUEST_CC

#include "../headers/Quest.h" // Include the Quest header
#include "Functions.cc"       // Include the Functions file

// Constructors

/**
 * @brief Construct a new Quest:: Quest object
 *
 * @param
 * @return
 */

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->requiredItem = QuestItem();
    this->goldReward = 0;
    this->responsesWhenCompleted = {};
    this->completed = false;
}

/**
 * @brief Construct a new Quest:: Quest object
 *
 * @param name
 * @param description
 * @param requiredItem
 * @param goldReward
 * @param responsesWhenCompleted
 * @return
 */

Quest::Quest(std::string name, std::string description, QuestItem requiredItem, int goldReward, std::vector<std::string> responsesWhenCompleted)
{
    this->name = name;
    this->description = description;
    this->requiredItem = requiredItem;
    this->goldReward = goldReward;
    this->responsesWhenCompleted = responsesWhenCompleted;
    this->completed = false; // Always false when created
}

// Getters

/**
 * @brief Get the Name attribute
 *
 * @param
 * @return std::string
 */

std::string Quest::getName()
{
    return this->name;
}

/**
 * @brief Get the Description attribute
 *
 * @param
 * @return std::string
 */

std::string Quest::getDescription()
{
    return this->description;
}

/**
 * @brief Get the Required Item attribute
 *
 * @param
 * @return QuestItem
 */

QuestItem Quest::getRequiredItem()
{
    return this->requiredItem;
}

/**
 * @brief Get the Gold Reward attribute
 *
 * @param
 * @return int
 */

int Quest::getGoldReward()
{
    return this->goldReward;
}

/**
 * @brief Get the responsesWhenCompleted attribute
 *
 * @param
 * @return std::vector<std::string>
 */

std::vector<std::string> Quest::getResponsesWhenCompleted()
{
    return this->responsesWhenCompleted;
}

/**
 * @brief Get the Completed attribute
 *
 * @param
 * @return bool
 */

bool Quest::getCompleted()
{
    return this->completed;
}

// Setters

/**
 * @brief Set the Name attribute
 *
 * @param name
 * @return void
 */

void Quest::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description attribute
 *
 * @param description
 * @return void
 */

void Quest::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Required Item attribute
 *
 * @param requiredItem
 * @return void
 */

void Quest::setRequiredItem(QuestItem requiredItem)
{
    this->requiredItem = requiredItem;
}

/**
 * @brief Set the Gold Reward attribute
 *
 * @param goldReward
 * @return void
 */

void Quest::setGoldReward(int goldReward)
{
    this->goldReward = goldReward;
}

/**
 * @brief Set the responsesWhenCompleted attribute
 *
 * @param responsesWhenCompleted
 * @return void
 */

void Quest::setResponsesWhenCompleted(std::vector<std::string> responsesWhenCompleted)
{
    this->responsesWhenCompleted = responsesWhenCompleted;
}

/**
 * @brief Set the Completed attribute
 *
 * @param completed
 * @return void
 */

void Quest::setCompleted(bool completed)
{
    this->completed = completed;
}

// Methods

/**
 * @brief Return the Quest as a string
 *
 * @param
 * @return std::string
 */

std::string Quest::toString()
{
    std::stringstream ss;

    ss << "Name: " << name << std::endl;
    ss << "Description: " << description << std::endl;
    ss << "Required Item: " << requiredItem.getName() << std::endl;
    ss << "Gold Reward: " << goldReward << std::endl;
    ss << "Status: " << (completed ? "Completed" : "Not Completed") << std::endl;

    return ss.str();
}

/**
 * @brief Mark the Quest as completed
 *
 * @param character
 * @return void
 */

void Quest::completeQuest(Character &character)
{

    // Print the responses
    for (int i = 0; i < responsesWhenCompleted.size(); i++)
    {
        // Clear the screen
        cleanScreen();

        // Print the response
        std::cout << responsesWhenCompleted[i] << std::endl;

        // Pause the program
        pause();
    }

    // Clear the screen
    cleanScreen();

    // Print
    std::cout << "Congratulations " << character.getName() << "! You have completed the quest: " << name << std::endl;
    std::cout << "Reward: " << goldReward << " gold" << std::endl;
    pause();

    // Add the gold to the character
    character.setGold(character.getGold() + goldReward);

    // Mark the quest as completed
    completed = true;
}

#endif // End of the preprocessor QUEST_CC