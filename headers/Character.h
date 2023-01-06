/**
 * @file Character.h
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the class that represents a character.
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CHARACTER_H // If the preprocessor CHARACTER_H is not defined
#define CHARACTER_H // Define the preprocessor CHARACTER_H

#include <string>  // Include string library
#include <sstream> // Include string stream library
#include <vector>  // Include vector library

#include "../drivers/Race.cc"        // Include races class
#include "../drivers/Class.cc"       // Include classes class
#include "../drivers/Stats.cc"       // Include statistics class
#include "../drivers/Inventory.cc"   // Include inventory class
#include "../drivers/Weapon.cc"      // Include weapons class
#include "../drivers/Armor.cc"       // Include armor class

class Character
{
private:
    // Attributes
    std::string name;
    std::string gender;
    int age;
    std::string alignment;

    int health;
    int mana;
    int stamina;

    int maxHealth;
    int maxMana;
    int maxStamina;

    Race race;
    Class clss;
    Stats stats;

    Inventory inventory;
    
    Weapon equippedWeapon;
    Armor equippedArmor;

public:
    // Constructors
    Character();

    // Getters
    std::string getName();
    std::string getGender();
    int getAge();
    std::string getAlignment();
    int getHealth();
    int getMana();
    int getStamina();
    int getMaxHealth();
    int getMaxMana();
    int getMaxStamina();

    // Setters
    void setName(std::string name);
    void setGender(std::string gender);
    void setAge(int age);
    void setAlignment(std::string alignment);
    void setHealth(int health);
    void setMana(int mana);
    void setStamina(int stamina);
    void setMaxHealth(int maxHealth);
    void setMaxMana(int maxMana);
    void setMaxStamina(int maxStamina);

    // Methods
    void createCharacter();

    std::string toString();

    int getGold();
    void setGold(int gold);
    void addGold(int gold);

    void defineRace(int option);
    void defineStats();
    void defineClass(int option);

    void showInventory();
    void showEquippedItems();

    void addWeaponToInventory(Weapon weapon);
    void addArmorToInventory(Armor armor);
    void addConsumableToInventory(Consumable consumable);
    void addQuestItemToInventory(QuestItem questItem);

    void removeWeaponFromInventory(Weapon weapon);
    void removeArmorFromInventory(Armor armor);
    void removeConsumableFromInventory(Consumable consumable);
    void removeQuestItemFromInventory(QuestItem questItem);

    void equipWeapon(Weapon weapon);
    void equipArmor(Armor armor);

    void useConsumable(Consumable consumable);

    void unequipWeapon();
    void unequipArmor();
};

#endif // End of PERSONAJE_H preprocessor