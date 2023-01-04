/**
 * @file Inventory.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This class represents the inventory of the player
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INVENTORY_H // If the preprocessor INVENTORY_H is not defined
#define INVENTORY_H // Define the preprocessor INVENTORY_H

#include "../drivers/Weapon.cc"     // Include the Weapon class
#include "../drivers/Armor.cc"      // Include the Armor class
#include "../drivers/Consumable.cc" // Include the Consumable class
#include "../drivers/QuestItem.cc"  // Include the QuestItem class

class Inventory
{
private:
    // Attributes
    int gold;
    int maxWeight;
    int currentWeight;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Consumable> consumables;
    std::vector<QuestItem> questItems;

public:
    // Constructors
    Inventory();
    Inventory(int capacity);

    // Getters
    int getGold();
    int getMaxWeight();
    int getCurrentWeight();

    // Setters

    // There is only one setter for the gold attribute.

    void setGold(int gold);

    // Methods
    void addWeapon(Weapon weapon);
    void addArmor(Armor armor);
    void addConsumable(Consumable consumable);
    void addQuestItem(QuestItem questItem);

    void removeWeapon(Weapon weapon);
    void removeArmor(Armor armor);
    void removeConsumable(Consumable consumable);
    void removeQuestItem(QuestItem questItem);
    
    void showInventory();
};

#endif // End of the preprocessor INVENTORY_H