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
    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();
    std::vector<Consumable> getConsumables();
    std::vector<QuestItem> getQuestItems();

    // Setters
    void setGold(int gold);
    void setMaxWeight(int maxWeight);
    void setCurrentWeight(int currentWeight);
    void setWeapons(std::vector<Weapon> weapons);
    void setArmors(std::vector<Armor> armors);
    void setConsumables(std::vector<Consumable> consumables);
    void setQuestItems(std::vector<QuestItem> questItems);

    // Methods
    void addWeapon(Weapon weapon);
    void addArmor(Armor armor);
    void addConsumable(Consumable consumable);
    void addQuestItem(QuestItem questItem);

    void removeWeapon(int index);
    void removeArmor(int index);
    void removeConsumable(int index);
    void removeQuestItem(int index);
};

#endif // End of the preprocessor INVENTORY_H