/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class represents the statistics of a character.
 */

#ifndef ESTADISTICAS_H // If the ESTADISTICAS_H preprocessor is not defined
#define ESTADISTICAS_H // Define the ESTADISTICAS_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Funciones.h" // Include the functions file
#include "Raza.h"      // Include the race class

class Estadisticas
{
private:
    // Attributes
    int fuerza;
    int destreza;
    int constitucion;
    int inteligencia;
    int sabiduria;
    int carisma;

public:
    // Constructors
    Estadisticas();
    Estadisticas(Raza raza);

    // Getters
    int getFuerza();
    int getDestreza();
    int getConstitucion();
    int getInteligencia();
    int getSabiduria();
    int getCarisma();

    // Setters
    void setFuerza(int fuerza);
    void setDestreza(int destreza);
    void setConstitucion(int constitucion);
    void setInteligencia(int inteligencia);
    void setSabiduria(int sabiduria);
    void setCarisma(int carisma);

    // Methods
    void mostrarEstadisticas();
};

// Constructors

/**
 * @brief Construct a new Estadisticas:: Estadisticas object
 *
 * @param
 * @return Estadisticas object
 */

Estadisticas::Estadisticas()
{
    this->fuerza = tirarDado();
    this->destreza = tirarDado();
    this->constitucion = tirarDado();
    this->inteligencia = tirarDado();
    this->sabiduria = tirarDado();
    this->carisma = tirarDado();
}

/**
 * @brief Construct a new Estadisticas:: Estadisticas object
 *
 * @param raza
 * @return Estadisticas object
 */

Estadisticas::Estadisticas(Raza raza)
{
    this->fuerza = raza.getModificadorFuerza() + tirarDado();
    this->destreza = raza.getModificadorDestreza() + tirarDado();
    this->constitucion = raza.getModificadorConstitucion() + tirarDado();
    this->inteligencia = raza.getModificadorInteligencia() + tirarDado();
    this->sabiduria = raza.getModificadorSabiduria() + tirarDado();
    this->carisma = raza.getModificadorCarisma() + tirarDado();
}

// Getters

/**
 * @brief Getter for the attribute fuerza
 *
 * @param
 * @return fuerza
 */

int Estadisticas::getFuerza()
{
    return this->fuerza;
}

/**
 * @brief Getter for the attribute destreza
 *
 * @param
 * @return destreza
 */

int Estadisticas::getDestreza()
{
    return this->destreza;
}

/**
 * @brief Getter for the attribute constitucion
 *
 * @param
 * @return constitucion
 */

int Estadisticas::getConstitucion()
{
    return this->constitucion;
}

/**
 * @brief Getter for the attribute inteligencia
 *
 * @param
 * @return inteligencia
 */

int Estadisticas::getInteligencia()
{
    return this->inteligencia;
}

/**
 * @brief Getter for the attribute sabiduria
 *
 * @param
 * @return sabiduria
 */

int Estadisticas::getSabiduria()
{
    return this->sabiduria;
}

/**
 * @brief Getter for the attribute carisma
 *
 * @param
 * @return carisma
 */

int Estadisticas::getCarisma()
{
    return this->carisma;
}

// Setters

/**
 * @brief Setter for the attribute fuerza
 *
 * @param fuerza
 * @return
 */

void Estadisticas::setFuerza(int fuerza)
{
    this->fuerza = fuerza;
}

/**
 * @brief Setter for the attribute destreza
 *
 * @param destreza
 * @return
 */

void Estadisticas::setDestreza(int destreza)
{
    this->destreza = destreza;
}

/**
 * @brief Setter for the attribute constitucion
 *
 * @param constitucion
 * @return
 */

void Estadisticas::setConstitucion(int constitucion)
{
    this->constitucion = constitucion;
}

/**
 * @brief Setter for the attribute inteligencia
 *
 * @param inteligencia
 * @return
 */

void Estadisticas::setInteligencia(int inteligencia)
{
    this->inteligencia = inteligencia;
}

/**
 * @brief Setter for the attribute sabiduria
 *
 * @param sabiduria
 * @return
 */

void Estadisticas::setSabiduria(int sabiduria)
{
    this->sabiduria = sabiduria;
}

/**
 * @brief Setter for the attribute carisma
 *
 * @param carisma
 * @return
 */

void Estadisticas::setCarisma(int carisma)
{
    this->carisma = carisma;
}

// Methods

/**
 * @brief Method to show the statistics
 *
 * @param
 * @return
 */

void Estadisticas::mostrarEstadisticas()
{
    std::cout << "Fuerza: " << this->fuerza << std::endl;
    std::cout << "Destreza: " << this->destreza << std::endl;
    std::cout << "Constitucion: " << this->constitucion << std::endl;
    std::cout << "Inteligencia: " << this->inteligencia << std::endl;
    std::cout << "Sabiduria: " << this->sabiduria << std::endl;
    std::cout << "Carisma: " << this->carisma << std::endl;
}

#endif // End of the ESTADISTICAS_H preprocessor