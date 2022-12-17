/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This file contains the menu functions.
 *
 */

#ifndef MENU_H // If the preprocessor MENU_H is not defined
#define MENU_H // Define the preprocessor MENU_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Funciones.h"     // Include the functions file
#include "Inicializador.h" // Include the Initializer file
#include "Raza.h"          // Include the race class
#include "Clase.h"         // Include the class class
#include "Estadisticas.h"  // Include the statistics class
#include "Personaje.h"     // Include the character class

// Functions

/**
 * @brief Function to show the main menu
 * 
 * @param
 * @return
 */

void menuPrincipal()
{
    limpiarPantalla();
    std::cout << "Bienvenido al creador de personajes de D&D" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Crear personaje" << std::endl;
    std::cout << "2. Mostrar personaje" << std::endl;
    std::cout << "3. Enciclopedia de DnD" << std::endl;
    std::cout << "4. Salir" << std::endl;
}

/**
 * @brief Function to show the race encyclopedia menu
 * 
 * @param
 * @return
 */

void menuRazas()
{
    int opcion;
    Raza *razas = inicializarRazas();

    do
    {
        limpiarPantalla();
        std::cout << "Bienvenido a la enciclopedia de razas de D&D" << std::endl;
        std::cout << std::endl;
        mostrarRazas(razas, 9);
        std::cout << "10. Volver" << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        while (opcion < 1 || opcion > 10)
        {
            std::cout << "Opcion no valida" << std::endl;
            std::cin >> opcion;
        }

        if (opcion != 10)
        {
            limpiarPantalla();
            razas[opcion - 1].mostrarRaza();
            pausa();
        }

    } while (opcion != 10);

    delete[] razas;
}

/**
 * @brief Function to show the class encyclopedia menu
 * 
 * @param
 * @return
 */

void menuClases()
{
    int opcion;
    Clase *clases = inicializarClases();

    do
    {
        limpiarPantalla();
        std::cout << "Bienvenido a la enciclopedia de clases de D&D" << std::endl;
        std::cout << std::endl;
        mostrarClases(clases, 9);
        std::cout << "10. Volver" << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        while (opcion < 1 || opcion > 10)
        {
            std::cout << "Opcion no valida" << std::endl;
            std::cin >> opcion;
        }

        if (opcion != 10)
        {
            limpiarPantalla();
            clases[opcion - 1].mostrarClase();
            pausa();
        }

    } while (opcion != 10);

    delete[] clases;
}

/**
 * @brief Function to show the statistics encyclopedia menu
 * 
 * @param
 * @return
 */

void menuArmas()
{
    int opcion;
    Arma *armas = inicializarArmas();

    do
    {
        limpiarPantalla();
        std::cout << "Bienvenido a la enciclopedia de armas de D&D" << std::endl;
        std::cout << std::endl;
        mostrarArmas(armas, 9);
        std::cout << "10. Volver" << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        while (opcion < 1 || opcion > 10)
        {
            std::cout << "Opcion no valida" << std::endl;
            std::cin >> opcion;
        }

        if (opcion != 10)
        {
            limpiarPantalla();
            armas[opcion - 1].mostrarDatos();
            pausa();
        }

    } while (opcion != 10);

    delete[] armas;
}

/**
 * @brief Function to show the armor encyclopedia menu
 * 
 * @param
 * @return
 */

void menuArmaduras()
{
    int opcion;
    Armadura *armaduras = inicializarArmaduras();

    do
    {
        limpiarPantalla();
        std::cout << "Bienvenido a la enciclopedia de armaduras de D&D" << std::endl;
        std::cout << std::endl;
        mostrarArmaduras(armaduras, 9);
        std::cout << "10. Volver" << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        while (opcion < 1 || opcion > 10)
        {
            std::cout << "Opcion no valida" << std::endl;
            std::cin >> opcion;
        }

        if (opcion != 10)
        {
            limpiarPantalla();
            armaduras[opcion - 1].mostrarDatos();
            pausa();
        }

    } while (opcion != 10);

    delete[] armaduras;
}

/**
 * @brief Function to show the encyclopedia menu
 * 
 * @param
 * @return
 */

void menuEnciclopedia()
{
    int opcion;

    do
    {
        limpiarPantalla();
        std::cout << "Bienvenido a la enciclopedia de D&D" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Razas" << std::endl;
        std::cout << "2. Clases" << std::endl;
        std::cout << "3. Armas" << std::endl;
        std::cout << "4. Armaduras" << std::endl;
        std::cout << "5. Volver" << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        while (opcion < 1 || opcion > 5)
        {
            std::cout << "Opcion no valida" << std::endl;
            std::cin >> opcion;
        }

        switch (opcion)
        {
        case 1:
            menuRazas();
            break;
        case 2:
            menuClases();
            break;
        case 3:
            menuArmas();
            break;
        case 4:
            menuArmaduras();
            break;
        }

    } while (opcion != 5);
}

#endif // End of the MENU_H preprocessor