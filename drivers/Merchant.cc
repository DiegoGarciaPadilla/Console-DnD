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

// Constructors

/**
 * @brief Construct a new Merchant::Merchant object
 *
 * @param
 * @return
 */

Merchant::Merchant()
{
    this->name = "Merchant";
    this->description = "This is a merchant.";
    this->dialogues = {{"Hello, I am a merchant."}, {"Bye, I am a merchant."}};
    this->options = {{"Hello"}, {"Bye"}};
    this->responses = {{"Hello, I am a merchant."}, {"Bye, I am a merchant."}};
    this->gold = 0;
    this->weapons = {};
    this->armors = {};
    this->consumables = {};
    this->questItems = {};
}

/**
 * @brief Construct a new Merchant::Merchant object
 *
 * @param name
 * @param description
 * @param dialogues
 * @param options
 * @param responses
 * @param gold
 * @param weapons
 * @param armors
 * @param consumables
 * @param questItems
 * @return
 */

Merchant::Merchant(std::string name, std::string description, std::vector<std::string> dialogues, std::vector<std::vector<std::string>> options, std::vector<std::vector<std::string>> responses, int gold, std::vector<Weapon> weapons, std::vector<Armor> armors, std::vector<Consumable> consumables, std::vector<QuestItem> questItems)
{
    this->name = name;
    this->description = description;
    this->dialogues = dialogues;
    this->options = options;
    this->responses = responses;
    this->gold = gold;
    this->weapons = weapons;
    this->armors = armors;
    this->consumables = consumables;
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
 * @brief Get the Consumables attribute
 *
 * @param
 * @return std::vector<Consumable>
 */

std::vector<Consumable> Merchant::getConsumables()
{
    return this->consumables;
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
 * @brief Set the Consumables attribute
 *
 * @param consumables
 * @return void
 */

void Merchant::setConsumables(std::vector<Consumable> consumables)
{
    this->consumables = consumables;
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
 * @brief This method allows the player to buy a weapon from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::buyWeapon(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the weapons
    std::cout << "What weapon do you want to buy?" << std::endl;
    for (int i = 0; i < this->weapons.size(); i++)
    {
        std::cout << i + 1 << ". " << this->weapons[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= this->weapons.size())
    {
        // Check if the character has enough gold
        if (character.getGold() >= this->weapons[option - 1].getPrice())
        {
            // Buy the weapon
            character.setGold(character.getGold() - this->weapons[option - 1].getPrice());
            character.addWeaponToInventory(this->weapons[option - 1]);

            // Print the message
            std::cout << "You bought the " << this->weapons[option - 1].getName() << " for " << this->weapons[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;

            // Add gold to the merchant
            this->gold += this->weapons[option - 1].getPrice();

            // Remove the weapon from the merchant
            this->weapons.erase(this->weapons.begin() + option - 1);
        }
        else
        {
            std::cout << "You don't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy an armor from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::buyArmor(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the armors
    std::cout << "What armor do you want to buy?" << std::endl;
    for (int i = 0; i < this->armors.size(); i++)
    {
        std::cout << i + 1 << ". " << this->armors[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= this->armors.size())
    {
        // Check if the character has enough gold
        if (character.getGold() >= this->armors[option - 1].getPrice())
        {
            // Buy the armor
            character.setGold(character.getGold() - this->armors[option - 1].getPrice());
            character.addArmorToInventory(this->armors[option - 1]);

            // Print the message
            std::cout << "You bought the " << this->armors[option - 1].getName() << " for " << this->armors[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;

            // Add gold to the merchant
            this->gold += this->armors[option - 1].getPrice();

            // Remove the armor from the merchant
            this->armors.erase(this->armors.begin() + option - 1);
        }
        else
        {
            std::cout << "You don't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a consumable from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::buyConsumable(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the consumables
    std::cout << "What consumable do you want to buy?" << std::endl;
    for (int i = 0; i < this->consumables.size(); i++)
    {
        std::cout << i + 1 << ". " << this->consumables[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= this->consumables.size())
    {
        // Check if the character has enough gold
        if (character.getGold() >= this->consumables[option - 1].getPrice())
        {
            // Buy the consumable
            character.setGold(character.getGold() - this->consumables[option - 1].getPrice());
            character.addConsumableToInventory(this->consumables[option - 1]);

            // Print the message
            std::cout << "You bought the " << this->consumables[option - 1].getName() << " for " << this->consumables[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;

            // Add gold to the merchant
            this->gold += this->consumables[option - 1].getPrice();

            // Remove the consumable from the merchant
            this->consumables.erase(this->consumables.begin() + option - 1);
        }
        else
        {
            std::cout << "You don't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to buy a quest item from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::buyQuestItem(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the quest items
    std::cout << "What quest item do you want to buy?" << std::endl;
    for (int i = 0; i < this->questItems.size(); i++)
    {
        std::cout << i + 1 << ". " << this->questItems[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= this->questItems.size())
    {
        // Check if the character has enough gold
        if (character.getGold() >= this->questItems[option - 1].getPrice())
        {
            // Buy the quest item
            character.setGold(character.getGold() - this->questItems[option - 1].getPrice());
            character.addQuestItemToInventory(this->questItems[option - 1]);

            // Print the message
            std::cout << "You bought the " << this->questItems[option - 1].getName() << " for " << this->questItems[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;

            // Add gold to the merchant
            this->gold += this->questItems[option - 1].getPrice();

            // Remove the quest item from the merchant
            this->questItems.erase(this->questItems.begin() + option - 1);
        }
        else
        {
            std::cout << "You don't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a weapon to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::sellWeapon(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the weapons
    std::cout << "What weapon do you want to sell?" << std::endl;
    for (int i = 0; i < character.getWeapons().size(); i++)
    {
        std::cout << i + 1 << ". " << character.getWeapons()[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= character.getWeapons().size())
    {
        // Check if the merchant has enough gold
        if (this->gold >= character.getWeapons()[option - 1].getPrice())
        {
            // Remove gold from the merchant
            this->gold -= character.getWeapons()[option - 1].getPrice();

            // Add gold to the character
            character.setGold(character.getGold() + character.getWeapons()[option - 1].getPrice());

            // Add the weapon to the merchant
            this->weapons.push_back(character.getWeapons()[option - 1]);

            // Remove the weapon from the character
            character.removeWeaponFromInventory(option - 1);

            // Print the message
            std::cout << "You sold the " << character.getWeapons()[option - 1].getName() << " for " << character.getWeapons()[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;
        }
        else
        {
            std::cout << "The merchant doesn't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell an armor to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::sellArmor(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the armors
    std::cout << "What armor do you want to sell?" << std::endl;
    for (int i = 0; i < character.getArmors().size(); i++)
    {
        std::cout << i + 1 << ". " << character.getArmors()[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= character.getArmors().size())
    {
        // Check if the merchant has enough gold
        if (this->gold >= character.getArmors()[option - 1].getPrice())
        {
            // Remove gold from the merchant
            this->gold -= character.getArmors()[option - 1].getPrice();

            // Add gold to the character
            character.setGold(character.getGold() + character.getArmors()[option - 1].getPrice());

            // Add the armor to the merchant
            this->armors.push_back(character.getArmors()[option - 1]);

            // Remove the armor from the character
            character.removeArmorFromInventory(option - 1);

            // Print the message
            std::cout << "You sold the " << character.getArmors()[option - 1].getName() << " for " << character.getArmors()[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;
        }
        else
        {
            std::cout << "The merchant doesn't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a consumable to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::sellConsumable(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the consumables
    std::cout << "What consumable do you want to sell?" << std::endl;
    for (int i = 0; i < character.getConsumables().size(); i++)
    {
        std::cout << i + 1 << ". " << character.getConsumables()[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= character.getConsumables().size())
    {
        // Check if the merchant has enough gold
        if (this->gold >= character.getConsumables()[option - 1].getPrice())
        {
            // Remove gold from the merchant
            this->gold -= character.getConsumables()[option - 1].getPrice();

            // Add gold to the character
            character.setGold(character.getGold() + character.getConsumables()[option - 1].getPrice());

            // Add the consumable to the merchant
            this->consumables.push_back(character.getConsumables()[option - 1]);

            // Remove the consumable from the character
            character.removeConsumableFromInventory(option - 1);

            // Print the message
            std::cout << "You sold the " << character.getConsumables()[option - 1].getName() << " for " << character.getConsumables()[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;
        }
        else
        {
            std::cout << "The merchant doesn't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
    }
}

/**
 * @brief This method allows the player to sell a quest item to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::sellQuestItem(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the quest items
    std::cout << "What quest item do you want to sell?" << std::endl;
    for (int i = 0; i < character.getQuestItems().size(); i++)
    {
        std::cout << i + 1 << ". " << character.getQuestItems()[i].getName() << std::endl;
    }
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check if the option is valid
    if (option > 0 && option <= character.getQuestItems().size())
    {
        // Check if the merchant has enough gold
        if (this->gold >= character.getQuestItems()[option - 1].getPrice())
        {
            // Remove gold from the merchant
            this->gold -= character.getQuestItems()[option - 1].getPrice();

            // Add gold to the character
            character.setGold(character.getGold() + character.getQuestItems()[option - 1].getPrice());

            // Add the quest item to the merchant
            this->questItems.push_back(character.getQuestItems()[option - 1]);

            // Remove the quest item from the character
            character.removeQuestItemFromInventory(option - 1);

            // Print the message
            std::cout << "You sold the " << character.getQuestItems()[option - 1].getName() << " for " << character.getQuestItems()[option - 1].getPrice() << " gold." << std::endl;
            std::cout << "You have " << character.getGold() << " gold." << std::endl;
        }
        else
        {
            std::cout << "The merchant doesn't have enough gold." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid option." << std::endl;
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
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the items
    std::cout << "What type of items do you want to buy?" << std::endl;
    std::cout << "1. Weapons" << std::endl;
    std::cout << "2. Armors" << std::endl;
    std::cout << "3. Consumables" << std::endl;
    std::cout << "4. Quest items" << std::endl;
    std::cout << "5. Nevermind" << std::endl;
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check the option
    switch (option)
    {
    case 1:
        this->buyWeapon(character);
        break;
    case 2:
        this->buyArmor(character);
        break;
    case 3:
        this->buyConsumable(character);
        break;
    case 4:
        this->buyQuestItem(character);
        break;
    case 5:
        std::cout << "If you change your mind, come back." << std::endl;
        break;
    default:
        std::cout << "Invalid option." << std::endl;
        break;
    }

    // Pause the program
    pause();
}

/**
 * @brief This method allows the player to sell items to the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::sellItems(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the items
    std::cout << "What type of items do you want to sell?" << std::endl;
    std::cout << "1. Weapons" << std::endl;
    std::cout << "2. Armors" << std::endl;
    std::cout << "3. Consumables" << std::endl;
    std::cout << "4. Quest items" << std::endl;
    std::cout << "5. Nevermind" << std::endl;
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check the option
    switch (option)
    {
    case 1:
        this->sellWeapon(character);
        break;
    case 2:
        this->sellArmor(character);
        break;
    case 3:
        this->sellConsumable(character);
        break;
    case 4:
        this->sellQuestItem(character);
        break;
    case 5:
        std::cout << "If you change your mind, come back." << std::endl;
        break;
    default:
        std::cout << "Invalid option." << std::endl;
        break;
    }

    // Pause the program
    pause();
}

/**
 * @brief This method allows the player to buy or sell items from the merchant.
 *
 * @param character
 * @return void
 */

void Merchant::openShop(Character &character)
{
    // Clear the screen
    cleanScreen();

    // Variables
    int option = 0;

    // Print the options
    std::cout << "Welcome to my shop." << std::endl;
    std::cout << "1. Buy items" << std::endl;
    std::cout << "2. Sell items" << std::endl;
    std::cout << "3. Nevermind" << std::endl;
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check the option
    switch (option)
    {
    case 1:
        this->buyItems(character);
        break;
    case 2:
        this->sellItems(character);
        break;
    case 3:
        std::cout << "If you change your mind, come back." << std::endl;
        break;
    default:
        std::cout << "Invalid option." << std::endl;
        break;
    }
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

    // Print the options
    std::cout << "Hello, " << character.getName() << "." << std::endl;
    std::cout << "1. Talk" << std::endl;
    std::cout << "2. Open shop" << std::endl;
    std::cout << "3. Nevermind" << std::endl;
    std::cout << std::endl;

    // Get the option
    std::cout << "Enter the option:" << std::endl;
    std::cin >> option;

    // Check the option
    switch (option)
    {
    case 1:
        this->talk();
        break;
    case 2:
        this->openShop(character);
        break;
    case 3:
        std::cout << "If you change your mind, come back." << std::endl;
        break;
    default:
        std::cout << "Invalid option." << std::endl;
        break;
    }

    // Pause the program
    pause();
}


#endif // End of the preprocessor MERCHANT_CC