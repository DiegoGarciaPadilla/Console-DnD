/**
 * @file Quest.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This class represents the quest of the game
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUEST_H // If the preprocessor QUEST_H is not defined
#define QUEST_H // Define the preprocessor QUEST_H

#include <string> // Include string library
#include <vector> // Include vector library

#include "../drivers/QuestItem.cc" // Include the QuestItem class
#include "../drivers/Character.cc" // Include the Character class

class Quest
{
private:
    // Attributes
    std::string name;
    std::string description;
    QuestItem requiredItem;
    int goldReward;
    std::vector<std::string> responsesWhenCompleted;
    bool completed;

public:
    // Constructors
    Quest();
    Quest(std::string name, std::string description, QuestItem requiredItem, int goldReward, std::vector<std::string> responsesWhenCompleted);

    // Getters
    std::string getName();
    std::string getDescription();
    QuestItem getRequiredItem();
    int getGoldReward();
    std::vector<std::string> getResponsesWhenCompleted();
    bool getCompleted();

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setRequiredItem(QuestItem requiredItem);
    void setGoldReward(int goldReward);
    void setResponsesWhenCompleted(std::vector<std::string> responsesWhenCompleted);
    void setCompleted(bool completed);

    // Methods
    std::string toString();

    void completeQuest(Character &character);

};

#endif // End of the preprocessor QUEST_H