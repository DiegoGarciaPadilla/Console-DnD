/*+
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class represents the player character.
 *
 */

#ifndef PERSONAJE_H // If the preprocessor PERSONAJE_H is not defined
#define PERSONAJE_H // Define the preprocessor PERSONAJE_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Raza.h"          // Include races class
#include "Clase.h"         // Include classes class
#include "Estadisticas.h"  // Include statistics class
#include "Arma.h"          // Include weapons class
#include "Armadura.h"      // Include armor class
#include "Inicializador.h" // Include initializer class

class Personaje
{
private:
    // Attributes
    std::string nombre;
    std::string genero;
    int edad;
    std::string alineamiento;
    Raza raza;
    Clase clase;
    Estadisticas estadisticas;
    Arma arma;
    Armadura armadura;

public:
    // Constructors
    Personaje();
    Personaje(std::string nombre, std::string genero, int edad, std::string alineamiento,
              Clase clase, Raza raza, Estadisticas estadisticas, Arma arma, Armadura armadura);

    // Getters
    std::string getNombre();
    std::string getGenero();
    int getEdad();
    std::string getAlineamiento();
    Raza getRaza();
    Clase getClase();
    Estadisticas getEstadisticas();
    Arma getArma();
    Armadura getArmadura();

    // Setters
    void setNombre(std::string nombre);
    void setGenero(std::string genero);
    void setEdad(int edad);
    void setAlineamiento(std::string alineamiento);
    void setRaza(Raza raza);
    void setClase(Clase clase);
    void setEstadisticas(Estadisticas estadisticas);
    void setArma(Arma arma);
    void setArmadura(Armadura armadura);

    // Methods
    void mostrarPersonaje();
    void mostrarRaza();
    void definirRaza(Raza *razas, int opcion);
    void mostrarEstadisticas();
    void definirEstadisticas(Raza raza);
    void mostrarClase();
    void definirClase(Clase *clases, int opcion);
};

// Constructors

/**
 * @brief Construct a default Personaje:: Personaje object
 *
 * @param
 * @return Personaje object
 */

Personaje::Personaje()
{
    nombre = " ";
    genero = " ";
    edad = 0;
    alineamiento = "Neutral";
    raza = Raza();
    clase = Clase();
    estadisticas = Estadisticas();
    arma = Arma();
    armadura = Armadura();
}

/**
 * @brief Construct a new Personaje:: Personaje object
 *
 * @param nombre
 * @param genero
 * @param edad
 * @param alineamiento
 * @param clase
 * @param raza
 * @param estadisticas
 * @param arma
 * @param armadura
 * @return Personaje object
 */

Personaje::Personaje(std::string nombre, std::string genero, int edad, std::string alineamiento,
                     Clase clase, Raza raza, Estadisticas estadisticas, Arma arma, Armadura armadura)
{
    this->nombre = nombre;
    this->genero = genero;
    this->edad = edad;
    this->alineamiento = alineamiento;
    this->raza = raza;
    this->clase = clase;
    this->estadisticas = estadisticas;
    this->arma = arma;
    this->armadura = armadura;
}

// Getters

/**
 * @brief Getter for the attribute nombre
 *
 * @param
 * @return nombre
 */

std::string Personaje::getNombre()
{
    return this->nombre;
}

/**
 * @brief Getter for the attribute genero
 *
 * @param
 * @return genero
 */

std::string Personaje::getGenero()
{
    return this->genero;
}

/**
 * @brief Getter for the attribute edad
 *
 * @param
 * @return edad
 */

int Personaje::getEdad()
{
    return this->edad;
}

/**
 * @brief Getter for the attribute alineamiento
 *
 * @param
 * @return alineamiento
 */

std::string Personaje::getAlineamiento()
{
    return this->alineamiento;
}

/**
 * @brief Getter for the attribute raza
 *
 * @param
 * @return raza
 */

Raza Personaje::getRaza()
{
    return this->raza;
}

/**
 * @brief Getter for the attribute estadisticas
 *
 * @param
 * @return estadisticas
 */

Estadisticas Personaje::getEstadisticas()
{
    return this->estadisticas;
}

/**
 * @brief Getter for the attribute arma
 *
 * @param
 * @return arma
 */

Arma Personaje::getArma()
{
    return this->arma;
}

/**
 * @brief Getter for the attribute armadura
 *
 * @param
 * @return armadura
 */

Armadura Personaje::getArmadura()
{
    return this->armadura;
}

// Setters

/**
 * @brief Setter for the attribute nombre
 *
 * @param nombre
 * @return
 */

void Personaje::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

/**
 * @brief Setter for the attribute genero
 *
 * @param genero
 * @return
 */

void Personaje::setGenero(std::string genero)
{
    this->genero = genero;
}

/**
 * @brief Setter for the attribute edad
 *
 * @param edad
 * @return
 */

void Personaje::setEdad(int edad)
{
    this->edad = edad;
}

/**
 * @brief Setter for the attribute alineamiento
 *
 * @param alineamiento
 * @return
 */

void Personaje::setAlineamiento(std::string alineamiento)
{
    this->alineamiento = alineamiento;
}

/**
 * @brief Setter for the attribute raza
 *
 * @param raza
 * @return
 */

void Personaje::setRaza(Raza raza)
{
    this->raza = raza;
}

/**
 * @brief Setter for the attribute estadisticas
 *
 * @param estadisticas
 * @return
 */

void Personaje::setEstadisticas(Estadisticas estadisticas)
{
    this->estadisticas = estadisticas;
}

/**
 * @brief Setter for the attribute arma
 *
 * @param arma
 * @return
 */

void Personaje::setArma(Arma arma)
{
    this->arma = arma;
}

/**
 * @brief Setter for the attribute armadura
 *
 * @param armadura
 * @return
 */

void Personaje::setArmadura(Armadura armadura)
{
    this->armadura = armadura;
}

// Methods

/**
 * @brief Method to show the character's data
 *
 * @param
 * @return
 */

void Personaje::mostrarPersonaje()
{
    std::cout << "DATOS DEL PERSONAJE" << nombre << std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Genero: " << this->genero << std::endl;
    std::cout << "Edad: " << this->edad << std::endl;
    std::cout << "Alineamiento: " << this->alineamiento << std::endl;
    std::cout << "Raza: " << this->raza.getNombre() << std::endl;
    std::cout << "Clase: " << this->clase.getNombre() << std::endl;
    std::cout << std::endl;
    std::cout << "DATOS DE LAS ESTADISTICAS" << std::endl;
    this->mostrarEstadisticas();
    std::cout << std::endl;
    std::cout << "DATOS DEL ARMA" << std::endl;
    arma.mostrarDatos();
    std::cout << std::endl;
    std::cout << "DATOS DE LA ARMADURA" << std::endl;
    armadura.mostrarDatos();
    std::cout << std::endl;
}

/**
 * @brief Method to show the character's race
 *
 * @param
 * @param
 * @return
 */

void Personaje::mostrarRaza()
{
    raza.mostrarRaza();
}

/**
 * @brief Method to define the character's race
 *
 * @param razas
 * @param opcion
 * @return
 */

void Personaje::definirRaza(Raza *razas, int opcion)
{
    raza = razas[opcion];
}

/**
 * @brief Method to show the character's class
 *
 * @param
 * @return
 */

void Personaje::mostrarEstadisticas()
{
    this->estadisticas.mostrarEstadisticas();
}

/**
 * @brief Method to show the character's statistics
 *
 * @param
 * @return
 */

void Personaje::definirEstadisticas(Raza raza)
{
    estadisticas = Estadisticas(raza);
}

/**
 * @brief Method to show the character's class
 *
 * @param
 * @return
 */

void Personaje::mostrarClase()
{
    clase.mostrarClase();
}

/**
 * @brief Method to define the character's class
 *
 * @param clases
 * @param opcion
 * @return
 */

void Personaje::definirClase(Clase *clases, int opcion)
{
    clase = clases[opcion];
    arma = clase.getArmaInicial();
    armadura = clase.getArmaduraInicial();
}

#endif // End of PERSONAJE_H preprocessor