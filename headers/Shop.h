/**
 * @file Shop.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Shop class.
 * @version 0.1
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHOP_H // If the file is not defined
#define SHOP_H // Define the file

#include <iostream> // Include input and output library
#include <string>   // Include string library
#include <sstream>  // Include string stream library
#include <cstdlib>  // Include system library
#include <vector>   // Include vector library

#include "../drivers/Character.cc"  // Include the Character class
#include "../drivers/Weapon.cc"     // Include the Weapon class
#include "../drivers/Armor.cc"      // Include the Armor class
#include "../drivers/Consumable.cc" // Include the Consumable class
#include "../drivers/QuestItem.cc"  // Include the QuestItem class
#include "../drivers/Npc.cc"        // Include the NPC class
#include "../drivers/Functions.cc"  // Include the functions file

class Shop
{
private:
    // Attributes
    std::string name;
    std::string description;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Consumable> consumables;
    std::vector<QuestItem> questItems;
    NPC shopkeeper;

public:
    // Constructors
    Shop();
    Shop(std::string name, std::string description, std::vector<Weapon> weapons, std::vector<Armor> armors, std::vector<Consumable> consumables, std::vector<QuestItem> questItems, NPC shopkeeper);

    // Getters
    std::string getName();
    std::string getDescription();
    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();
    std::vector<Consumable> getConsumables();
    std::vector<QuestItem> getQuestItems();
    NPC getShopkeeper();

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setWeapons(std::vector<Weapon> weapons);
    void setArmors(std::vector<Armor> armors);
    void setConsumables(std::vector<Consumable> consumables);
    void setQuestItems(std::vector<QuestItem> questItems);
    void setShopkeeper(NPC shopkeeper);

    // Methods
    std::string toString();

    void buyWeapon(Character &character, int index);
    void buyArmor(Character &character, int index);
    void buyConsumable(Character &character, int index);
    void buyQuestItem(Character &character, int index);

    void sellWeapon(Character &character, int index);
    void sellArmor(Character &character, int index);
    void sellConsumable(Character &character, int index);
    void sellQuestItem(Character &character, int index);

    void showShop();
};

#endif // End of the file