/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This file contains some functions used in the program.
 *
 */

#ifndef FUNCIONES_H // If the preprocessor FUNCIONES_H is not defined
#define FUNCIONES_H // Define the preprocessor FUNCIONES_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings
#include <cstdlib>  // Library for system functions

#include "Inicializador.h" // Include the Initializer file
#include "Raza.h"          // Include the race class
#include "Clase.h"         // Include the class class
#include "Estadisticas.h"  // Include the statistics class
#include "Personaje.h"     // Include the character class

// Functions

// General functions

/**
 * @brief Function to clear the screen on Windows
 *
 * @param
 * @return
 */

void limpiarPantalla()
{
    system("cls");
}

/**
 * @brief Function to pause the program on Windows
 *
 * @param
 * @return
 */

void pausa()
{
    system("pause");
}

/**
 * @brief Function to generate a random number
 *
 * @param
 * @return int
 */

int tirarDado()
{
    return rand() % 20 + 1;
}

/**
 * @brief Function to create a character with the data entered by the user
 *
 * @param personaje
 * @return
 */

void crearPersonaje(Personaje &personaje)
{
    // Variables
    std::string nombre, genero, alineamiento;
    int edad, opcion;
    Raza raza;

    limpiarPantalla();

    // Title
    std::cout << "Creacion de personaje" << std::endl;
    std::cout << std::endl;

    // Ask for the name
    std::cout << "Nombre (Solo una palabra): ";
    std::cin >> nombre;
    std::cout << std::endl;
    personaje.setNombre(nombre);

    // Ask for the gender
    std::cout << "Genero: " << std::endl;
    mostrarGeneros(inicializarGeneros(), 3);
    std::cin >> opcion;
    while (opcion < 1 || opcion > 3)
    {
        std::cout << "Opcion no valida" << std::endl;
        std::cin >> opcion;
    }
    std::cout << std::endl;
    personaje.setGenero(inicializarGeneros()[opcion - 1]);

    // Ask for the age
    std::cout << "Edad: ";
    std::cin >> edad;
    while (edad < 0)
    {
        std::cout << "Edad no valida" << std::endl;
        std::cout << "Edad: ";
        std::cin >> edad;
    }
    std::cout << std::endl;
    personaje.setEdad(edad);

    // Ask for the alignment
    std::cout << "Alineamiento: " << std::endl;
    mostrarAlineamientos(inicializarAlineamientos(), 9);
    std::cin >> opcion;
    while (opcion < 1 || opcion > 9)
    {
        std::cout << "Opcion no valida" << std::endl;
        std::cout << "Alineamiento: ";
        std::cin >> opcion;
    }
    std::cout << std::endl;
    personaje.setAlineamiento(inicializarAlineamientos()[opcion - 1]);

    // Raza
    std::cout << "Raza: " << std::endl;
    mostrarRazas(inicializarRazas(), 9);
    std::cin >> opcion;
    while (opcion < 1 || opcion > 9)
    {
        std::cout << "Opcion no valida" << std::endl;
        std::cout << "Raza: ";
        std::cin >> opcion;
    }
    std::cout << std::endl;
    personaje.definirRaza(inicializarRazas(), opcion - 1);

    // Ask for the class
    std::cout << "Clase: " << std::endl;
    mostrarClases(inicializarClases(), 9);
    std::cin >> opcion;
    while (opcion < 1 || opcion > 9)
    {
        std::cout << "Opcion no valida" << std::endl;
        std::cout << "Clase: ";
        std::cin >> opcion;
    }
    std::cout << std::endl;
    personaje.definirClase(inicializarClases(), opcion - 1);

    // Generate the statistics
    std::cout << "Estadisticas: " << std::endl;
    std::cout << "Las estadisticas se generan aleatoriamente" << std::endl;
    personaje.definirEstadisticas(personaje.getRaza());
    std::cout << std::endl;

    return;
}

#endif // End of the preprocessor FUNCIONES_H