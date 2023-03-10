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

#include "../drivers/Race.cc"      // Include races class
#include "../drivers/Class.cc"     // Include classes class
#include "../drivers/Stats.cc"     // Include statistics class
#include "../drivers/Inventory.cc" // Include inventory class
#include "../drivers/Weapon.cc"    // Include weapons class
#include "../drivers/Armor.cc"     // Include armor class
#include "../drivers/Potion.cc"    // Include potions class
#include "../drivers/QuestItem.cc" // Include quest items class

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

    int damage;
    int defense;

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
    int getDamage();
    int getDefense();

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
    void setDamage(int damage);
    void setDefense(int defense);

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

    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();
    std::vector<Potion> getPotions();
    std::vector<QuestItem> getQuestItems();

    void addWeaponToInventory(Weapon weapon);
    void addArmorToInventory(Armor armor);
    void addPotionToInventory(Potion potion);
    void addQuestItemToInventory(QuestItem questItem);

    void removeWeaponFromInventory(int index);
    void removeArmorFromInventory(int index);
    void removePotionFromInventory(int index);
    void removeQuestItemFromInventory(int index);

    void equipWeapon(int index);
    void equipArmor(int index);

    void drinkPotion(int index);

    void unequipWeapon();
    void unequipArmor();
};

#endif // End of PERSONAJE_H preprocessor