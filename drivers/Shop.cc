/**
 * @file Shop.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Shop class.
 * @version 0.1
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHOP_CC // If the file is not defined
#define SHOP_CC // Define the file

#include "../headers/Shop.h" // Include the Shop header file

// Constructors

/**
 * @brief Construct a new Shop::Shop object
 *
 * @param
 * @return
 */

Shop::Shop()
{
    this->name = "Shop";
    this->description = "This is a shop.";
    this->weapons = {};
    this->armors = {};
    this->consumables = {};
    this->questItems = {};
    this->shopkeeper = NPC("Shopkeeper", "This is a shopkeeper.", {"Hello, I am a shopkeeper."}, {{"Hello"}, {"Bye"}}, {{"Hello, I am a shopkeeper."}, {"Bye, I am a shopkeeper."}});
}

/**
 * @brief Construct a new Shop::Shop object
 *
 * @param name
 * @param description
 * @param weapons
 * @param armors
 * @param consumables
 * @param questItems
 * @param shopkeeper
 * @return
 */

Shop::Shop(std::string name, std::string description, std::vector<Weapon> weapons, std::vector<Armor> armors, std::vector<Consumable> consumables, std::vector<QuestItem> questItems, NPC shopkeeper)
{
    this->name = name;
    this->description = description;
    this->weapons = weapons;
    this->armors = armors;
    this->consumables = consumables;
    this->questItems = questItems;
    this->shopkeeper = shopkeeper;
}

// Getters

/**
 * @brief Get the Name object
 *
 * @param
 * @return std::string
 */

std::string Shop::getName()
{
    return this->name;
}

/**
 * @brief Get the Description object
 *
 * @param
 * @return std::string
 */

std::string Shop::getDescription()
{
    return this->description;
}

/**
 * @brief Get the Weapons object
 *
 * @param
 * @return std::vector<Weapon>
 */

std::vector<Weapon> Shop::getWeapons()
{
    return this->weapons;
}

/**
 * @brief Get the Armors object
 *
 * @param
 * @return std::vector<Armor>
 */

std::vector<Armor> Shop::getArmors()
{
    return this->armors;
}

/**
 * @brief Get the Consumables object
 *
 * @param
 * @return std::vector<Consumable>
 */

std::vector<Consumable> Shop::getConsumables()
{
    return this->consumables;
}

/**
 * @brief Get the Quest Items object
 *
 * @param
 * @return std::vector<QuestItem>
 */

std::vector<QuestItem> Shop::getQuestItems()
{
    return this->questItems;
}

/**
 * @brief Get the Shopkeeper object
 *
 * @param
 * @return NPC
 */

NPC Shop::getShopkeeper()
{
    return this->shopkeeper;
}

// Setters

/**
 * @brief Set the Name object
 *
 * @param name
 * @return void
 */

void Shop::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Description object
 *
 * @param description
 * @return void
 */

void Shop::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the Weapons object
 *
 * @param weapons
 * @return void
 */

void Shop::setWeapons(std::vector<Weapon> weapons)
{
    this->weapons = weapons;
}

/**
 * @brief Set the Armors object
 *
 * @param armors
 * @return void
 */

void Shop::setArmors(std::vector<Armor> armors)
{
    this->armors = armors;
}

/**
 * @brief Set the Consumables object
 *
 * @param consumables
 * @return void
 */

void Shop::setConsumables(std::vector<Consumable> consumables)
{
    this->consumables = consumables;
}

/**
 * @brief Set the Quest Items object
 *
 * @param questItems
 * @return void
 */

void Shop::setQuestItems(std::vector<QuestItem> questItems)
{
    this->questItems = questItems;
}

/**
 * @brief Set the Shopkeeper object
 *
 * @param shopkeeper
 * @return void
 */

void Shop::setShopkeeper(NPC shopkeeper)
{
    this->shopkeeper = shopkeeper;
}

// Methods

/**
 * @brief This method returns the shop's information.
 *
 * @param
 * @return std::string
 */

std::string Shop::toString()
{
    std::stringstream ss;

    ss << "Name: " << this->name << std::endl;
    ss << "Description: " << this->description << std::endl;
    ss << "Weapons: " << std::endl;
    for (int i = 0; i < this->weapons.size(); i++)
    {
        ss << this->weapons[i].toString() << std::endl;
    }
    ss << "Armors: " << std::endl;
    for (int i = 0; i < this->armors.size(); i++)
    {
        ss << this->armors[i].toString() << std::endl;
    }
    ss << "Consumables: " << std::endl;
    for (int i = 0; i < this->consumables.size(); i++)
    {
        ss << this->consumables[i].toString() << std::endl;
    }
    ss << "Quest Items: " << std::endl;
    for (int i = 0; i < this->questItems.size(); i++)
    {
        ss << this->questItems[i].toString() << std::endl;
    }
    ss << "Shopkeeper: " << std::endl;
    ss << this->shopkeeper.toString() << std::endl;

    return ss.str();
}

/**
 * @brief This method allows the player to buy a weapon.
 * 
 * @param character
 * @param index
 * @return void
 */

void Shop::buyWeapon(Character &character, int index)
{
    if (character.getGold() >= this->weapons[index].getValue())
    {
        character.setGold(character.getGold() - this->weapons[index].getValue());
        character.addWeaponToInventory(this->weapons[index]);
        this->weapons.erase(this->weapons.begin() + index);
    }
    else
    {
        std::cout << "You don't have enough gold to buy this weapon." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy an armor.
 * 
 * @param character
 * @param index
 * @return void
 */

void Shop::buyArmor(Character &character, int index)
{
    if (character.getGold() >= this->armors[index].getValue())
    {
        character.setGold(character.getGold() - this->armors[index].getValue());
        character.addArmorToInventory(this->armors[index]);
        this->armors.erase(this->armors.begin() + index);
    }
    else
    {
        std::cout << "You don't have enough gold to buy this armor." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a consumable.
 * 
 * @param character
 * @param index
 * @return void
 */

void Shop::buyConsumable(Character &character, int index)
{
    if (character.getGold() >= this->consumables[index].getValue())
    {
        character.setGold(character.getGold() - this->consumables[index].getValue());
        character.addConsumableToInventory(this->consumables[index]);
        this->consumables.erase(this->consumables.begin() + index);
    }
    else
    {
        std::cout << "You don't have enough gold to buy this consumable." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a quest item.
 * 
 * @param character
 * @param index
 * @return void
 */

void Shop::buyQuestItem(Character &character, int index)
{
    if (character.getGold() >= this->questItems[index].getValue())
    {
        character.setGold(character.getGold() - this->questItems[index].getValue());
        character.addQuestItemToInventory(this->questItems[index]);
        this->questItems.erase(this->questItems.begin() + index);
    }
    else
    {
        std::cout << "You don't have enough gold to buy this quest item." << std::endl;
    }
}

#endif // End of preprocessor SHOP_CC


