/**
 * @file Menu.cc
 * @author Diego Antonio Garcia Padilla (github.com/DiegoGarciaPadilla)
 * @brief This file contains the functions that print the menu.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Function to show the main menu
 *
 * @param
 * @return
 */

void mainMenu()
{
    // Clear the screen
    cleanScreen();

    // Show the main menu
    std::cout << readAscii("ascii/title.txt") << std::endl;
    std::cout << "1. Create character" << std::endl;
    std::cout << "2. Show character" << std::endl;
    std::cout << "3. D&D encyclopedia" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

/**
 * @brief Function to show the race encyclopedia menu
 *
 * @param
 * @return
 */

void racesMenu()
{
    // Variables
    int option;

    // Arrays
    std::vector<Race> races = initRaces();
    std::vector<std::string> racesNames = listRaces();
    int racesNumber = races.size();

    // Show the races menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's races encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show races
        printStringVector(racesNames);
        std::cout << racesNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > racesNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the race
        if (option != racesNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the race
            std::cout << races[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != racesNumber + 1);
}

/**
 * @brief Function to show the class encyclopedia menu
 *
 * @param
 * @return
 */

void classesMenu()
{
    // Variables
    int option;

    // Arrays
    std::vector<Class> classes = initClasses();
    std::vector<std::string> classesNames = listClasses();
    int classesNumber = classes.size();

    // Show the classes menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's classes encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show classes
        printStringVector(classesNames);
        std::cout << classesNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > classesNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the class
        if (option != classesNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the class
            std::cout << classes[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != classesNumber + 1);
}

/**
 * @brief Function to show the weapons encyclopedia menu
 *
 * @param
 * @return
 */

void weaponsMenu()
{
    // Variables
    int option;

    // Arrays
    std::vector<Weapon> weapons = initWeapons();
    std::vector<std::string> weaponsNames = listWeapons();
    int weaponsNumber = weapons.size();

    // Show the weapons menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's weapons encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show weapons
        printStringVector(weaponsNames);
        std::cout << weaponsNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > weaponsNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the weapon
        if (option != weaponsNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the weapon
            std::cout << weapons[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != weaponsNumber + 1);
}

/**
 * @brief Function to show the armor encyclopedia menu
 *
 * @param
 * @return
 */

void armorMenu()
{
    // Variables
    int option;

    // Arrays
    std::vector<Armor> armors = initArmors();
    std::vector<std::string> armorsNames = listArmors();
    int armorsNumber = armors.size();

    // Show the armors menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's armors encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show armors
        printStringVector(armorsNames);
        std::cout << armorsNumber + 1 << ". Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > armorsNumber + 1)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the armor
        if (option != armorsNumber + 1)
        {
            // Clear the screen
            cleanScreen();

            // Show the armor
            std::cout << armors[option - 1].toString() << std::endl;
            pause();
        }

    } while (option != armorsNumber + 1);
}

/**
 * @brief Function to show the encyclopedia menu
 *
 * @param
 * @return
 */

void encyclopediaMenu()
{
    // Variables
    int option;

    // Show the encyclopedia menu
    do
    {
        // Clear the screen
        cleanScreen();

        // Title
        std::cout << "Welcome to the D&D's encyclopedia" << std::endl;
        std::cout << std::endl;

        // Show the options
        std::cout << "1. Races" << std::endl;
        std::cout << "2. Classes" << std::endl;
        std::cout << "3. Weapons" << std::endl;
        std::cout << "4. Armors" << std::endl;
        std::cout << "5. Return" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;

        // Check if the option is valid
        while (option < 1 || option > 5)
        {
            std::cout << "Invalid option" << std::endl;
            std::cin >> option;
        }

        // If the option is valid, show the encyclopedia
        switch (option)
        {
        case 1:
            racesMenu();
            break;
        case 2:
            classesMenu();
            break;
        case 3:
            weaponsMenu();
            break;
        case 4:
            armorMenu();
            break;
        }

    } while (option != 5);
}