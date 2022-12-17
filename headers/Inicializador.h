/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This file contains some functions for the initialization of the program.
 *
 */

#ifndef INICIALIZADOR_H // If the preprocessor INICIALIZADOR_H is not defined
#define INICIALIZADOR_H // Define the preprocessor INICIALIZADOR_H

#include <iostream> // Library for input and output
#include <fstream>  // Library for file input and output
#include <string>   // Library for strings
#include <sstream>  // Library for string streams
#include <vector>   // Library for vectors

#include "Arma.h"     // Include the weapon class
#include "Armadura.h" // Include the armor class
#include "Raza.h"     // Include the race class
#include "Clase.h"    // Include the class class

// Functions

// Gender

/**
 * @brief Function to initialize gender array
 *
 * @param
 * @return generos
 */

std::string *inicializarGeneros()
{
    std::string *generos = new std::string[3];
    generos[0] = "Masculino";
    generos[1] = "Femenino";
    generos[2] = "Otro";

    return generos;
}

/**
 * @brief Function to show gender array
 *
 * @param generos
 * @param numGeneros
 */

void mostrarGeneros(std::string *generos, int numGeneros)
{
    for (int i = 0; i < numGeneros; i++)
    {
        std::cout << i + 1 << ". " << generos[i] << std::endl;
    }
}

// Alignment

/**
 * @brief Function to initialize alignment array
 *
 * @param
 * @return alineamientos
 */

std::string *inicializarAlineamientos()
{
    std::string *alineamientos = new std::string[9];
    alineamientos[0] = "Legal Bueno";
    alineamientos[1] = "Neutral Bueno";
    alineamientos[2] = "Caotico Bueno";
    alineamientos[3] = "Legal Neutral";
    alineamientos[4] = "Neutral";
    alineamientos[5] = "Caotico Neutral";
    alineamientos[6] = "Legal Malo";
    alineamientos[7] = "Neutral Malo";
    alineamientos[8] = "Caotico Malo";

    return alineamientos;
}

/**
 * @brief Function to show alignment array
 *
 * @param alineamientos
 * @param numAlineamientos
 */

void mostrarAlineamientos(std::string *alineamientos, int numAlineamientos)
{
    for (int i = 0; i < numAlineamientos; i++)
    {
        std::cout << i + 1 << ". " << alineamientos[i] << std::endl;
    }
}

// Weapons

/**
 * @brief Function to initialize weapons array
 *
 * @param
 * @return armas
 */

Arma *inicializarArmas()
{
    // Open the file
    std::ifstream archivo("./data/weapons.txt");
    // Check if the file was opened correctly
    if (!archivo.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "Error al abrir el archivo" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of weapons
    std::string linea;
    std::getline(archivo, linea);
    int numArmas = std::stoi(linea);

    // Create the array of weapons
    Arma *armas = new Arma[numArmas];

    // Read the file line by line
    int i = 0;
    while (std::getline(archivo, linea))
    {
        // Split the line by the pipe character
        std::stringstream ss(linea);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        // Create the weapon object
        Arma arma(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]),
                  tokens[4], tokens[5], std::stoi(tokens[6]));
        // Add the weapon to the array
        armas[i] = arma;
        i++;
    }

    // Close the file
    archivo.close();

    // Return the array of weapons
    return armas;
}

/**
 * @brief Function to show weapons array
 *
 * @param armas
 * @param numArmas
 */

void mostrarArmas(Arma *armas, int numArmas)
{
    for (int i = 0; i < numArmas; i++)
    {
        std::cout << i + 1 << ". " << armas[i].getNombre() << std::endl;
    }
}

// Armor

/**
 * @brief Function to initialize armor array
 *
 * @param
 * @return armaduras
 */

Armadura *inicializarArmaduras()
{
    // Open the file
    std::ifstream archivo("./data/armors.txt");
    // Check if the file was opened correctly
    if (!archivo.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "Error al abrir el archivo" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of armors
    std::string linea;
    std::getline(archivo, linea);
    int numArmaduras = std::stoi(linea);

    // Create the array of armors
    Armadura *armaduras = new Armadura[numArmaduras];

    // Read the file line by line
    int i = 0;
    while (std::getline(archivo, linea))
    {
        // Split the line by the pipe character
        std::stringstream ss(linea);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        // Create the armor object
        Armadura armadura(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]),
                          tokens[4], tokens[5], std::stoi(tokens[6]));
        // Add the armor to the array
        armaduras[i] = armadura;
        i++;
    }

    // Close the file
    archivo.close();

    // Return the array of armors
    return armaduras;
}

/**
 * @brief Function to show armor array
 *
 * @param armaduras
 * @param numArmaduras
 */

void mostrarArmaduras(Armadura *armaduras, int numArmaduras)
{
    for (int i = 0; i < numArmaduras; i++)
    {
        std::cout << i + 1 << ". " << armaduras[i].getNombre() << std::endl;
    }
}

// Races

/**
 * @brief Function to initialize races array
 * 
 * @param
 * @return razas
 */

Raza *inicializarRazas()
{
    // Open the file
    std::ifstream archivo("./data/races.txt");
    // Check if the file was opened correctly
    if (!archivo.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "Error al abrir el archivo" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of races 
    std::string linea;
    std::getline(archivo, linea);
    int numRazas = std::stoi(linea);

    // Create the array of races
    Raza *razas = new Raza[numRazas];

    // Read the file line by line
    int i = 0;
    while (std::getline(archivo, linea))
    {
        // Split the line by the pipe character
        std::stringstream ss(linea);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        // Create the race object
        Raza raza(tokens[0], tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]),
                  std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]));
        // Add the race to the array
        razas[i] = raza;
        i++;
    }

    // Close the file
    archivo.close();

    // Return the array of races
    return razas;
}

/**
 * @brief Function to show races array
 * 
 * @param razas
 * @param numRazas
 */

void mostrarRazas(Raza *razas, int numRazas)
{
    for (int i = 0; i < numRazas; i++)
    {
        std::cout << i + 1 << ". " << razas[i].getNombre() << std::endl;
    }
}

// Classes

/**
 * @brief Function to initialize classes array
 * 
 * @param
 * @return clases
 */

Clase *inicializarClases()
{
    // Create the array of weapons
    Arma *armas = inicializarArmas();
    // Create the array of armors
    Armadura *armaduras = inicializarArmaduras();

    // Open the file
    std::ifstream archivo("./data/classes.txt");
    // Check if the file was opened correctly
    if (!archivo.is_open())
    {
        // If the file was not opened correctly, show an error message
        std::cout << "Error al abrir el archivo" << std::endl;
        return nullptr;
    }

    // Read the first line to get the number of classes
    std::string linea;
    std::getline(archivo, linea);
    int numClases = std::stoi(linea);

    // Create the array of classes
    Clase *clases = new Clase[numClases];

    // Read the file line by line
    int i = 0;
    while (std::getline(archivo, linea))
    {
        // Split the line by the pipe character
        std::stringstream ss(linea);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        // Create the class object
        Clase clase(tokens[0], tokens[1], armas[i], armaduras[i]);
        // Add the class to the array
        clases[i] = clase;
        i++;
    }

    // Cerrar el archivo
    archivo.close();

    // Devolver el array de clases
    return clases;
}

/**
 * @brief Function to show classes array
 * 
 * @param clases
 * @param numClases
 */

void mostrarClases(Clase *clases, int numClases)
{
    for (int i = 0; i < numClases; i++)
    {
        std::cout << i + 1 << ". " << clases[i].getNombre() << std::endl;
    }
}

#endif // End of the ENTRADAS_H preprocessor