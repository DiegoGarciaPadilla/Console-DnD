/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class is the base class for all the weapons in the game.
 */

#ifndef ARMA_H // If the ARMA_H preprocessor is not defined
#define ARMA_H // Define the ARMA_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Objeto.h" // Include the object class

class Arma : public Objeto
{
private:
    // Attributes
    std::string tipo = "Arma";
    int daño;

public:
    // Constructors
    Arma();
    Arma(std::string nombre, std::string descripcion, int peso, int valor, std::string subtipo,
         std::string material, int daño);

    // Getters
    std::string getTipo();
    int getDaño();

    // Setters
    void setTipo(std::string tipo);
    void setDaño(int daño);

    // Methods
    void mostrarDatos();
};

// Constructors

/**
 * @brief Construct a default Arma:: Arma object
 *
 * @param
 * @return Arma object
 */

Arma::Arma()
{
    nombre = "Espada oxidada";
    descripcion = "Es una espada oxidada, con el filo muy desgastado. No parece muy útil.";
    peso = 2;
    valor = 0;
    subtipo = "Espada";
    material = "Madera y acero";
    daño = 10;
}

/**
 * @brief Construct a new Arma:: Arma object
 *
 * @param nombre
 * @param descripcion
 * @param peso
 * @param valor
 * @param subtipo
 * @param material
 * @param daño
 * @return Arma object
 */

Arma::Arma(std::string nombre, std::string descripcion, int peso, int valor, std::string subtipo,
           std::string material, int daño)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->peso = peso;
    this->valor = valor;
    this->subtipo = subtipo;
    this->material = material;
    this->daño = daño;
}

// Getters

/**
 * @brief Getter for the attribute daño
 *
 * @param
 * @return daño
 */

int Arma::getDaño()
{
    return daño;
}

// Setters

/**
 * @brief Setter for the attribute daño
 *
 * @param daño
 * @return
 */

void Arma::setDaño(int daño)
{
    this->daño = daño;
}

// Methods

/**
 * @brief Method to show the object's data
 *
 * @param
 * @return
 */

void Arma::mostrarDatos()
{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;
    std::cout << "Peso: " << peso << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Subtipo: " << subtipo << std::endl;
    std::cout << "Material: " << material << std::endl;
    std::cout << "Daño: " << daño << std::endl;
}

#endif // End of the ARMA_H preprocessor