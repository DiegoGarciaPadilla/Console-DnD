/**
 * @file Merchant.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the implementation of the Merchant class.
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERCHANT_CC // If the file is not defined
#define MERCHANT_CC // Define the file

#include "../headers/Merchant.h" // Include the Merchant header file
#include "Functions.cc"          // Include the Functions header file
#include "Initializer.cc"        // Include the Initializer header file

// Constructors

/**
 * @brief Construct a new Merchant::Merchant object
 *
 * @param
 * @return
 */

Merchant::Merchant() : NPC()
{
    this->gold = 0;
    this->weapons = {};
    this->armors = {};
    this->potions = {};
    this->questItems = {};
}

/**
 * @brief Construct a new Merchant::Merchant object
 *
 * @param name
 * @param description
 * @param gold
 * @param weapons
 * @param armors
 * @param potions
 * @param questItems
 * @return
 */

Merchant::Merchant(std::string name, std::string description, int gold, std::vector<Weapon> weapons, std::vector<Armor> armors, std::vector<Potion> potions, std::vector<QuestItem> questItems) : NPC(name, description)
{
    this->gold = gold;
    this->weapons = weapons;
    this->armors = armors;
    this->potions = potions;
    this->questItems = questItems;
}

// Getters

/**
 * @brief Get the Gold attribute
 *
 * @param
 * @return int
 */

int Merchant::getGold()
{
    return this->gold;
}

/**
 * @brief Get the Weapons attribute
 *
 * @param
 * @return std::vector<Weapon>
 */

std::vector<Weapon> Merchant::getWeapons()
{
    return this->weapons;
}

/**
 * @brief Get the Armors attribute
 *
 * @param
 * @return std::vector<Armor>
 */

std::vector<Armor> Merchant::getArmors()
{
    return this->armors;
}

/**
 * @brief Get the Potions attribute
 *
 * @param
 * @return std::vector<Potion>
 */

std::vector<Potion> Merchant::getPotions()
{
    return this->potions;
}

/**
 * @brief Get the Quest Items attribute
 *
 * @param
 * @return std::vector<QuestItem>
 */

std::vector<QuestItem> Merchant::getQuestItems()
{
    return this->questItems;
}

// Setters

/**
 * @brief Set the Gold attribute
 *
 * @param gold
 * @return void
 */

void Merchant::setGold(int gold)
{
    this->gold = gold;
}

/**
 * @brief Set the Weapons attribute
 *
 * @param weapons
 * @return void
 */

void Merchant::setWeapons(std::vector<Weapon> weapons)
{
    this->weapons = weapons;
}

/**
 * @brief Set the Armors attribute
 *
 * @param armors
 * @return void
 */

void Merchant::setArmors(std::vector<Armor> armors)
{
    this->armors = armors;
}

/**
 * @brief Set the Potions attribute
 *
 * @param potions
 * @return void
 */

void Merchant::setPotions(std::vector<Potion> potions)
{
    this->potions = potions;
}

/**
 * @brief Set the Quest Items attribute
 *
 * @param questItems
 * @return void
 */

void Merchant::setQuestItems(std::vector<QuestItem> questItems)
{
    this->questItems = questItems;
}

// Methods

/**
 * @brief This method initializes the merchant with example data.
 *
 * @return void
 */

void Merchant::initialize()
{
    // Initialize arrays
    std::vector<Weapon> weapons = initWeapons();
    std::vector<Armor> armors = initArmors();
    std::vector<Potion> potions = initPotions();
    std::vector<QuestItem> questItems = {};

    // Initialize the merchant
    this->name = "Bob";
    this->description = "I'm Bob, the merchant. I sell weapons, armors and potions.";
    this->gold = 100;

    //  Add random items to the merchant
    for (int i = 0; i < 3; i++)
    {
        this->weapons.push_back(weapons[rand() % weapons.size()]);
        this->armors.push_back(armors[rand() % armors.size()]);
        this->potions.push_back(potions[rand() % potions.size()]);
    }
}

/**
 * @brief This method allows the player to buy a weapon from the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::buyWeapon(Character &character, int index)
{
    // Variables
    Weapon weapon = this->weapons[index];
    int gold = character.getGold();
    int weaponPrice = weapon.getPrice();

    // Check if the player has enough gold
    if (gold >= weaponPrice)
    {
        // Add the weapon to the player
        character.addWeaponToInventory(weapon);

        // Remove the weapon from the merchant
        this->weapons.erase(this->weapons.begin() + index);

        // Remove the gold from the player
        character.setGold(gold - weaponPrice);

        // Add the gold to the merchant
        this->gold += weaponPrice;

        // Print the message
        std::cout << "You bought " << weapon.getName() << " for " << weaponPrice << " gold." << std::endl;
        std::cout << "You have " << character.getGold() << " gold left." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "You don't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy an armor from the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::buyArmor(Character &character, int index)
{
    // Variables
    Armor armor = this->armors[index];
    int gold = character.getGold();
    int armorPrice = armor.getPrice();

    // Check if the player has enough gold
    if (gold >= armorPrice)
    {
        // Add the armor to the player
        character.addArmorToInventory(armor);

        // Remove the armor from the merchant
        this->armors.erase(this->armors.begin() + index);

        // Remove the gold from the player
        character.setGold(gold - armorPrice);

        // Add the gold to the merchant
        this->gold += armorPrice;

        // Print the message
        std::cout << "You bought " << armor.getName() << " for " << armorPrice << " gold." << std::endl;
        std::cout << "You have " << character.getGold() << " gold left." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "You don't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a potion from the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::buyPotion(Character &character, int index)
{
    // Variables
    Potion potion = this->potions[index];
    int gold = character.getGold();
    int potionPrice = potion.getPrice();

    // Check if the player has enough gold
    if (gold >= potionPrice)
    {
        // Add the potion to the player
        character.addPotionToInventory(potion);

        // Remove the potion from the merchant
        this->potions.erase(this->potions.begin() + index);

        // Remove the gold from the player
        character.setGold(gold - potionPrice);

        // Add the gold to the merchant
        this->gold += potionPrice;

        // Print the message
        std::cout << "You bought " << potion.getName() << " for " << potionPrice << " gold." << std::endl;
        std::cout << "You have " << character.getGold() << " gold left." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "You don't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a quest item from the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::buyQuestItem(Character &character, int index)
{
    // Variables
    QuestItem questItem = this->questItems[index];
    int gold = character.getGold();
    int questItemPrice = questItem.getPrice();

    // Check if the player has enough gold
    if (gold >= questItemPrice)
    {
        // Add the quest item to the player
        character.addQuestItemToInventory(questItem);

        // Remove the quest item from the merchant
        this->questItems.erase(this->questItems.begin() + index);

        // Remove the gold from the player
        character.setGold(gold - questItemPrice);

        // Add the gold to the merchant
        this->gold += questItemPrice;

        // Print the message
        std::cout << "You bought " << questItem.getName() << " for " << questItemPrice << " gold." << std::endl;
        std::cout << "You have " << character.getGold() << " gold left." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "You don't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a weapon to the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::sellWeapon(Character &character, int index)
{
    // Variables
    Weapon weapon = character.getWeapons()[index];
    int weaponPrice = weapon.getPrice();

    // Check if the merchant has enough gold
    if (this->gold >= weaponPrice)
    {
        // Add the weapon to the merchant
        this->weapons.push_back(weapon);

        // Remove the weapon from the player
        character.removeWeaponFromInventory(index);

        // Remove the gold from the merchant
        this->gold -= weaponPrice;

        // Add the gold to the player
        character.addGold(weaponPrice);

        // Print the message
        std::cout << "You sold " << weapon.getName() << " for " << weaponPrice << " gold." << std::endl;
        std::cout << "You now have " << character.getGold() << " gold." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "The merchant doesn't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell an armor to the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::sellArmor(Character &character, int index)
{
    // Variables
    Armor armor = character.getArmors()[index];
    int armorPrice = armor.getPrice();

    // Check if the merchant has enough gold
    if (this->gold >= armorPrice)
    {
        // Add the armor to the merchant
        this->armors.push_back(armor);

        // Remove the armor from the player
        character.removeArmorFromInventory(index);

        // Remove the gold from the merchant
        this->gold -= armorPrice;

        // Add the gold to the player
        character.addGold(armorPrice);

        // Print the message
        std::cout << "You sold " << armor.getName() << " for " << armorPrice << " gold." << std::endl;
        std::cout << "You now have " << character.getGold() << " gold." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "The merchant doesn't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a potion to the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::sellPotion(Character &character, int index)
{
    // Variables
    Potion potion = character.getPotions()[index];
    int potionPrice = potion.getPrice();

    // Check if the merchant has enough gold
    if (this->gold >= potionPrice)
    {
        // Add the potion to the merchant
        this->potions.push_back(potion);

        // Remove the potion from the player
        character.removeArmorFromInventory(index);

        // Remove the gold from the merchant
        this->gold -= potionPrice;

        // Add the gold to the player
        character.addGold(potionPrice);

        // Print the message
        std::cout << "You sold " << potion.getName() << " for " << potionPrice << " gold." << std::endl;
        std::cout << "You now have " << character.getGold() << " gold." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "The merchant doesn't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a quest item to the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::sellQuestItem(Character &character, int index)
{
    // Variables
    QuestItem questItem = character.getQuestItems()[index];
    int questItemPrice = questItem.getPrice();

    // Check if the merchant has enough gold
    if (this->gold >= questItemPrice)
    {
        // Add the quest item to the merchant
        this->questItems.push_back(questItem);

        // Remove the quest item from the player
        character.removeQuestItemFromInventory(index);

        // Remove the gold from the merchant
        this->gold -= questItemPrice;

        // Add the gold to the player
        character.addGold(questItemPrice);

        // Print the message
        std::cout << "You sold " << questItem.getName() << " for " << questItemPrice << " gold." << std::endl;
        std::cout << "You now have " << character.getGold() << " gold." << std::endl;
    }
    else
    {
        // Print the message
        std::cout << "The merchant doesn't have enough gold." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy items from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::buyItems(Character &character)
{
    // Variables
    int option = 0;
    int itemNum = 1;
    int numWeapons;
    int numArmors;
    int numPotions;
    int numQuestItems;

    do
    {
        // Clear the screen
        cleanScreen();

        // Reset the item number
        itemNum = 1;

        // Get the number of items
        numWeapons = this->weapons.size();
        numArmors = this->armors.size();
        numPotions = this->potions.size();
        numQuestItems = this->questItems.size();

        // Print the options
        std::cout << "Hello, " << character.getName() << "." << std::endl;
        std::cout << "What would you like to buy?" << std::endl;
        std::cout << std::endl;

        // Print the weapons
        if (numWeapons > 0)
        {
            std::cout << "Weapons:" << std::endl;
            for (int i = 0; i < numWeapons; i++)
            {
                std::cout << itemNum << ". " << this->weapons[i].getName() << " - " << this->weapons[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the armors
        if (numArmors > 0)
        {
            std::cout << "Armors:" << std::endl;
            for (int i = 0; i < numArmors; i++)
            {
                std::cout << itemNum << ". " << this->armors[i].getName() << " - " << this->armors[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the potions
        if (numPotions > 0)
        {
            std::cout << "Potions:" << std::endl;
            for (int i = 0; i < numPotions; i++)
            {
                std::cout << itemNum << ". " << this->potions[i].getName() << " - " << this->potions[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the quest items
        if (numQuestItems > 0)
        {
            std::cout << "Quest Items:" << std::endl;
            for (int i = 0; i < numQuestItems; i++)
            {
                std::cout << itemNum << ". " << this->questItems[i].getName() << " - " << this->questItems[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the return option
        std::cout << "0. Nevermind" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter the option:" << std::endl;
        std::cin >> option;

        // Clear the screen
        cleanScreen();

        // Check the option
        if (option > 0 && option <= numWeapons)
        {
            // Buy the weapon
            this->buyWeapon(character, option - 1);
        }
        else if (option > numWeapons && option <= numWeapons + numArmors)
        {
            // Buy the armor
            this->buyArmor(character, option - numWeapons - 1);
        }
        else if (option > numWeapons + numArmors && option <= numWeapons + numArmors + numPotions)
        {
            // Buy the potion
            this->buyPotion(character, option - numWeapons - numArmors - 1);
        }
        else if (option > numWeapons + numArmors + numPotions && option <= numWeapons + numArmors + numPotions + numQuestItems)
        {
            // Buy the quest item
            this->buyQuestItem(character, option - numWeapons - numArmors - numPotions - 1);
        }
        else if (option == 0)
        {
            // Print the message
            std::cout << "If you ever need anything, just come back." << std::endl;
        }
        else
        {
            // Print the message
            std::cout << "Invalid option." << std::endl;
        }

        // Pause the program
        pause();

        // Clear the screen
        cleanScreen();

        // Ask the user if they want to buy another item
        if (option != 0)
        {
            std::cout << "Would you like to buy another item?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "0. No" << std::endl;

            // Get the option
            std::cout << "Enter the option:" << std::endl;
            std::cin >> option;
        }

    } while (option != 0);
}

/**
 * @brief This method allows the player to sell items to the merchant.
 *
 * @param character
 * @param index
 * @return void
 */

void Merchant::sellItems(Character &character)
{
    // Variables
    int option = 0;
    int itemNum = 1;
    int numWeapons;
    int numArmors;
    int numPotions;
    int numQuestItems;

    do
    {
        // Clear the screen
        cleanScreen();

        // Reset the item number
        itemNum = 1;

        // Get the number of items
        numWeapons = character.getWeapons().size();
        numArmors = character.getArmors().size();
        numPotions = character.getPotions().size();
        numQuestItems = character.getQuestItems().size();

        // Print the options
        std::cout << "Hello, " << character.getName() << "." << std::endl;
        std::cout << "What would you like to sell?" << std::endl;
        std::cout << std::endl;

        // Print the weapons
        if (numWeapons > 0)
        {
            std::cout << "Weapons:" << std::endl;
            for (int i = 0; i < numWeapons; i++)
            {
                std::cout << itemNum << ". " << character.getWeapons()[i].getName() << " - " << character.getWeapons()[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the armors
        if (numArmors > 0)
        {
            std::cout << "Armors:" << std::endl;
            for (int i = 0; i < numArmors; i++)
            {
                std::cout << itemNum << ". " << character.getArmors()[i].getName() << " - " << character.getArmors()[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the potions
        if (numPotions > 0)
        {
            std::cout << "Potions:" << std::endl;
            for (int i = 0; i < numPotions; i++)
            {
                std::cout << itemNum << ". " << character.getPotions()[i].getName() << " - " << character.getPotions()[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the quest items
        if (numQuestItems > 0)
        {
            std::cout << "Quest Items:" << std::endl;
            for (int i = 0; i < numQuestItems; i++)
            {
                std::cout << itemNum << ". " << character.getQuestItems()[i].getName() << " - " << character.getQuestItems()[i].getPrice() << " gold" << std::endl;
                itemNum++;
            }
            std::cout << std::endl;
        }

        // Print the return option
        std::cout << "0. Nevermind" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter the option:" << std::endl;
        std::cin >> option;

        // Clear the screen
        cleanScreen();

        // Check the option
        if (option > 0 && option <= numWeapons)
        {
            // Sell the weapon
            this->sellWeapon(character, option - 1);
        }
        else if (option > numWeapons && option <= numWeapons + numArmors)
        {
            // Sell the armor
            this->sellArmor(character, option - numWeapons - 1);
        }
        else if (option > numWeapons + numArmors && option <= numWeapons + numArmors + numPotions)
        {
            // Sell the potion
            this->sellPotion(character, option - numWeapons - numArmors - 1);
        }
        else if (option > numWeapons + numArmors + numPotions && option <= numWeapons + numArmors + numPotions + numQuestItems)
        {
            // Sell the quest item
            this->sellQuestItem(character, option - numWeapons - numArmors - numPotions - 1);
        }
        else if (option == 0)
        {
            // Print the message
            std::cout << "If you ever need anything, just come back." << std::endl;
        }
        else
        {
            // Print the message
            std::cout << "Invalid option." << std::endl;
        }

        // Pause the program
        pause();

        // Clear the screen
        cleanScreen();

        // Ask the user if they want to sell another item
        if (option != 0)
        {
            std::cout << "Would you like to sell another item?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "0. No" << std::endl;

            // Get the option
            std::cout << "Enter the option:" << std::endl;
            std::cin >> option;
        }

    } while (option != 0);
}

/**
 * @brief This method allows the player to buy or sell items to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::openShop(Character &character)
{
    // Variables
    int option = 0;

    do
    {
        // Clear the screen
        cleanScreen();

        // Print the options
        std::cout << "Hello, " << character.getName() << "." << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << std::endl;

        // Print the options
        std::cout << "1. Buy items" << std::endl;
        std::cout << "2. Sell items" << std::endl;
        std::cout << std::endl;

        // Return option
        std::cout << "0. Goodbye" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter the option:" << std::endl;
        std::cin >> option;

        // Check the option
        switch (option)
        {
        case 0:
            // Print the message
            std::cout << "If you ever need anything, just come back." << std::endl;
            break;
        case 1:
            // Buy items
            this->buyItems(character);
            break;
        case 2:
            // Sell items
            this->sellItems(character);
            break;
        default:
            // Print the message
            std::cout << "Invalid option." << std::endl;
            break;
        }

    } while (option != 0);
}

/**
 * @brief This method allows the player to interact with the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::interact(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    do
    {
        // Clear the screen
        cleanScreen();

        // Print the options
        std::cout << "Hello, " << character.getName() << "." << std::endl;
        std::cout << "1. Open shop" << std::endl;

        // Return option
        std::cout << "0. Goodbye" << std::endl;
        std::cout << std::endl;

        // Get the option
        std::cout << "Enter the option:" << std::endl;
        std::cin >> option;

        // Check the option
        switch (option)
        {
        case 1:
            // Open the shop
            this->openShop(character);
            break;
        case 0:
            // Print the message
            std::cout << "Goodbye, " << character.getName() << "." << std::endl;
            break;
        default:
            // Print the message
            std::cout << "Invalid option." << std::endl;
            break;
        }
    } while (option != 0);
}

#endif // End of the preprocessor MERCHANT_CC