/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This file contains the class that represents the different objects that a character can have.
 *
 */

#ifndef OBJETO_H // If the preprocessor OBJETO_H is not defined
#define OBJETO_H // Define the preprocessor OBJETO_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings

class Objeto
{
protected:
    // Attributes
    std::string nombre;
    std::string descripcion;
    int peso;
    int valor;
    std::string tipo;
    std::string subtipo;
    std::string material;

public:
    // Constructors
    Objeto();
    Objeto(std::string nombre, std::string descripcion, int peso, int valor,
           std::string tipo, std::string subtipo, std::string material);

    // Getters
    std::string getNombre();
    std::string getDescripcion();
    int getPeso();
    int getValor();
    std::string getTipo();
    std::string getSubtipo();
    std::string getMaterial();

    // Setters
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setPeso(int peso);
    void setValor(int valor);
    void setTipo(std::string tipo);
    void setSubtipo(std::string subtipo);
    void setMaterial(std::string material);

    // Methods
    void mostrarDatos();
};

// Constructors

/**
 * @brief Construct a default Objeto:: Objeto object
 *
 * @param
 * @return Objeto
 */

Objeto::Objeto()
{
    nombre = "Objeto";
    descripcion = "Es un objeto.";
    peso = 1;
    valor = 0;
    tipo = "Objeto";
    subtipo = "Objeto";
    material = "Objeto";
}

/**
 * @brief Construct a new Objeto:: Objeto object
 *
 * @param nombre
 * @param descripcion
 * @param peso
 * @param valor
 * @param tipo
 * @param subtipo
 * @param material
 * @return Objeto
 */

Objeto::Objeto(std::string nombre, std::string descripcion, int peso, int valor,
               std::string tipo, std::string subtipo, std::string material)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->peso = peso;
    this->valor = valor;
    this->tipo = tipo;
    this->subtipo = subtipo;
    this->material = material;
}

// Getters

/**
 * @brief Getter for the attribute nombre
 *
 * @param
 * @return nombre
 */

std::string Objeto::getNombre()
{
    return nombre;
}

/**
 * @brief Getter for the attribute descripcion
 *
 * @param
 * @return descripcion
 */

std::string Objeto::getDescripcion()
{
    return descripcion;
}

/**
 * @brief Getter for the attribute peso
 *
 * @param
 * @return peso
 */

int Objeto::getPeso()
{
    return peso;
}

/**
 * @brief Getter for the attribute valor
 *
 * @param
 * @return valor
 */

int Objeto::getValor()
{
    return valor;
}

/**
 * @brief Getter for the attribute tipo
 *
 * @param
 * @return tipo
 */

std::string Objeto::getTipo()
{
    return tipo;
}

/**
 * @brief Getter for the attribute subtipo
 *
 * @param
 * @return subtipo
 */

std::string Objeto::getSubtipo()
{
    return subtipo;
}

/**
 * @brief Getter for the attribute material
 *
 * @param
 * @return material
 */

std::string Objeto::getMaterial()
{
    return material;
}

// Setters

/**
 * @brief Setter for the attribute nombre
 *
 * @param nombre
 * @return
 */

void Objeto::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

/**
 * @brief Setter for the attribute descripcion
 *
 * @param descripcion
 * @return
 */

void Objeto::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
}

/**
 * @brief Setter for the attribute peso
 *
 * @param peso
 * @return
 */

void Objeto::setPeso(int peso)
{
    this->peso = peso;
}

/**
 * @brief Setter for the attribute valor
 *
 * @param valor
 * @return
 */

void Objeto::setValor(int valor)
{
    this->valor = valor;
}

/**
 * @brief Setter for the attribute tipo
 *
 * @param tipo
 * @return
 */

void Objeto::setTipo(std::string tipo)
{
    this->tipo = tipo;
}

/**
 * @brief Setter for the attribute subtipo
 *
 * @param subtipo
 * @return
 */

void Objeto::setSubtipo(std::string subtipo)
{
    this->subtipo = subtipo;
}

/**
 * @brief Setter for the attribute material
 *
 * @param material
 * @return
 */

void Objeto::setMaterial(std::string material)
{
    this->material = material;
}

// Methods

/**
 * @brief Method to show the object's data
 *
 * @param
 * @return
 */

void Objeto::mostrarDatos()
{
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Peso: " << this->peso << std::endl;
    std::cout << "Valor: " << this->valor << std::endl;
    std::cout << "Tipo: " << this->tipo << std::endl;
    std::cout << "Subtipo: " << this->subtipo << std::endl;
    std::cout << "Material: " << this->material << std::endl;
}

#endif // End of OBJETO_H preprossesor
