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

class Inventory
{
private:
    // Attributes
    int maxWeight;
    int maxItems;
    int currentWeight;
    int currentItems;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Consumable> consumables;
    std::vector<QuestItem> questItems;

public:
    // Constructors
    Inventory();
    Inventory(int maxWeight, int maxItems);

    // Getters
    int getMaxWeight();
    int getMaxItems();
    int getCurrentWeight();
    int getCurrentItems();
    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();
    std::vector<Consumable> getConsumables();
    std::vector<QuestItem> getQuestItems();

    // Setters
    void setMaxWeight(int maxWeight);
    void setMaxItems(int maxItems);
    void setCurrentWeight(int currentWeight);
    void setCurrentItems(int currentItems);
    void setWeapons(std::vector<Weapon> weapons);
    void setArmors(std::vector<Armor> armors);
    void setConsumables(std::vector<Consumable> consumables);
    void setQuestItems(std::vector<QuestItem> questItems);

    // Methods
    void addItem(Item item);
    void removeItem(Item item);
    void showInventory();
};

#endif // End of the preprocessor INVENTORY_H
