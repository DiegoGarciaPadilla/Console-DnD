/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class represents the different classes that a character can have.
 */

#ifndef CLASE_H // If the CLASE_H preprocessor is not defined
#define CLASE_H // Define the CLASE_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Arma.h"     // Include the weapon class
#include "Armadura.h" // Include the armor class

class Clase
{
private:
    // Attributes
    std::string nombre;
    std::string descripcion;
    Arma armaInicial;
    Armadura armaduraInicial;

public:
    // Constructors
    Clase();
    Clase(std::string nombre, std::string descripcion, Arma armaInicial,
          Armadura armaduraInicial);

    // Getters
    std::string getNombre();
    std::string getDescripcion();
    Arma getArmaInicial();
    Armadura getArmaduraInicial();

    // Setters
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setArmaInicial(Arma armaInicial);
    void setArmaduraInicial(Armadura armaduraInicial);

    // Methods
    void mostrarClase();
};

// Constructors

/**
 * @brief Construct a default Clase:: Clase object
 *
 * @param
 * @return Clase object
 */

Clase::Clase()
{
    nombre = "Guerrero";
    descripcion = "Todos los guerreros comparten un dominio magistral de las armas y armaduras, y un exhaustivo conocimiento de las habilidades del combate. Además, están muy relacionados con la muerte, tanto repartiéndola como mirándola fijamente, desafiantes.";
    armaInicial = Arma();
    armaduraInicial = Armadura();
}

/**
 * @brief Construct a new Clase:: Clase object
 *
 * @param nombre
 * @param descripcion
 * @param armaInicial
 * @param armaduraInicial
 * @return Clase object
 */

Clase::Clase(std::string nombre, std::string descripcion, Arma armaInicial, Armadura armaduraInicial)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->armaInicial = armaInicial;
    this->armaduraInicial = armaduraInicial;
}

// Getters

/**
 * @brief Getter for the attribute nombre
 *
 * @param
 * @return nombre
 */

std::string Clase::getNombre()
{
    return nombre;
}

/**
 * @brief Getter for the attribute descripcion
 *
 * @param
 * @return descripcion
 */

std::string Clase::getDescripcion()
{
    return descripcion;
}

/**
 * @brief Getter for the attribute armaInicial
 *
 * @param
 * @return armaInicial
 */

Arma Clase::getArmaInicial()
{
    return armaInicial;
}

/**
 * @brief Getter for the attribute armaduraInicial
 *
 * @param
 * @return armaduraInicial
 */

Armadura Clase::getArmaduraInicial()
{
    return armaduraInicial;
}

// Setters

/**
 * @brief Setter for the attribute nombre
 *
 * @param nombre
 * @return
 */

void Clase::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

/**
 * @brief Setter for the attribute descripcion
 *
 * @param descripcion
 * @return
 */

void Clase::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
}

/**
 * @brief Setter for the attribute armaInicial
 *
 * @param armaInicial
 * @return
 */

void Clase::setArmaInicial(Arma armaInicial)
{
    this->armaInicial = armaInicial;
}

/**
 * Setter for the attribute armaduraInicial
 *
 * @param armaduraInicial
 * @return
 */

void Clase::setArmaduraInicial(Armadura armaduraInicial)
{
    this->armaduraInicial = armaduraInicial;
}

// Methods

/**
 * @brief This method prints the class information
 *
 * @param
 * @return
 */

void Clase::mostrarClase()
{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;
    std::cout << "Arma inicial: " << armaInicial.getNombre() << std::endl;
    std::cout << "Armadura inicial: " << armaduraInicial.getNombre() << std::endl;
}

#endif // End of the CLASE_H preprocessor