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
