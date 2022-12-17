/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class is the base class for all the armors in the game.
 */

#ifndef ARMADURA_H // If the ARMADURA_H preprocessor is not defined
#define ARMADURA_H // Define the ARMADURA_H preprocessor

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "Objeto.h" // Include the object class

class Armadura : public Objeto
{
private:
    // Attributes
    std::string tipo = "Armadura";
    int defensa;

public:
    // Constructors
    Armadura();
    Armadura(std::string nombre, std::string descripcion, int peso, int valor,
             std::string subtipo, std::string material, int defensa);

    // Getters
    std::string getTipo();
    int getDefensa();

    // Setters
    void setTipo(std::string tipo);
    void setDefensa(int defensa);

    // Methods
    void mostrarDatos();
};

// Constructors

/**
 * @brief Construct a default Armadura:: Armadura object
 *
 * @param
 * @return Objeto Armadura
 */

Armadura::Armadura()
{
    nombre = "Armadura desgastada";
    descripcion = "Es una armadura de madera, con placas de acero oxidado. No parece muy útil.";
    peso = 2;
    valor = 0;
    subtipo = "Armadura";
    material = "Madera y acero";
    defensa = 10;
}

/**
 * @brief Construct a new Armadura:: Armadura object
 *
 * @param nombre
 * @param descripcion
 * @param peso
 * @param valor
 * @param subtipo
 * @param material
 * @param defensa
 * @return Objeto Armadura
 */

Armadura::Armadura(std::string nombre, std::string descripcion, int peso, int valor,
                   std::string subtipo, std::string material, int defensa)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->peso = peso;
    this->valor = valor;
    this->subtipo = subtipo;
    this->material = material;
    this->defensa = defensa;
}

// Getters

/**
 * @brief Getter for the attribute defensa
 *
 * @param
 * @return defensa
 */

int Armadura::getDefensa()
{
    return defensa;
}

// Setters

/**
 * @brief Setter for the attribute defensa
 *
 * @param defensa
 * @return
 */

void Armadura::setDefensa(int defensa)
{
    this->defensa = defensa;
}

// Methods

/**
 * @brief Method to show the object's data
 *
 * @param
 * @return
 */

void Armadura::mostrarDatos()
{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;
    std::cout << "Peso: " << peso << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Subtipo: " << subtipo << std::endl;
    std::cout << "Material: " << material << std::endl;
    std::cout << "Defensa: " << defensa << std::endl;
}

#endif // End of the ARMADURA_H preprocessor