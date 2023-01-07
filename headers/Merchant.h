/**
 * @file Merchant.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the declaration of the Merchant class.
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERCHANT_H // If the file is not defined
#define MERCHANT_H // Define the file

#include "../drivers/NPC.cc"        // Include the NPC class
#include "../drivers/Weapon.cc"     // Include the Weapon class
#include "../drivers/Armor.cc"      // Include the Armor class
#include "../drivers/Consumable.cc" // Include the Consumable class
#include "../drivers/QuestItem.cc"  // Include the QuestItem class
#include "../drivers/Character.cc"  // Include the Character class

class Merchant : public NPC
{
private:
    // Attributes
    int gold;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Consumable> consumables;
    std::vector<QuestItem> questItems;

public:
    // Constructors
    Merchant();
    Merchant(std::string name, std::string description, std::vector<std::string> dialogues, std::vector<std::vector<std::string>> options, std::vector<std::vector<std::string>> responses, int gold, std::vector<Weapon> weapons, std::vector<Armor> armors, std::vector<Consumable> consumables, std::vector<QuestItem> questItems);

    // Getters
    int getGold();
    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();
    std::vector<Consumable> getConsumables();
    std::vector<QuestItem> getQuestItems();

    // Setters
    void setGold(int gold);
    void setWeapons(std::vector<Weapon> weapons);
    void setArmors(std::vector<Armor> armors);
    void setConsumables(std::vector<Consumable> consumables);
    void setQuestItems(std::vector<QuestItem> questItems);

    // Methods
    void buyWeapon(Character &character);
    void buyArmor(Character &character);
    void buyConsumable(Character &character);
    void buyQuestItem(Character &character);

    void sellWeapon(Character &character);
    void sellArmor(Character &character);
    void sellConsumable(Character &character);
    void sellQuestItem(Character &character);

    void buyItems(Character &character);
    void sellItems(Character &character);

    void openShop(Character &character);

    void interact(Character &character);
};

#endif // End of the preprocessor MERCHANT_H