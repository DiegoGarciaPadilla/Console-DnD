/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This class represents the race of a character.
 *
 */

#ifndef RAZA_H // If the preprocessor RAZA_H is not defined
#define RAZA_H // Define the preprocessor RAZA_H

#include <iostream> // Library for input and output
#include <string>   // Library for strings

class Raza
{
private:
    // Attributes
    std::string nombre;
    std::string descripcion;
    int modificadorFuerza;
    int modificadorDestreza;
    int modificadorConstitucion;
    int modificadorInteligencia;
    int modificadorSabiduria;
    int modificadorCarisma;

public:
    // Constructors
    Raza();
    Raza(std::string nombre, std::string descripcion, int modificadorFuerza,
         int modificadorDestreza, int modificadorConstitucion, int modificadorInteligencia,
         int modificadorSabiduria, int modificadorCarisma);

    // Getters
    std::string getNombre();
    std::string getDescripcion();
    int getModificadorFuerza();
    int getModificadorDestreza();
    int getModificadorConstitucion();
    int getModificadorInteligencia();
    int getModificadorSabiduria();
    int getModificadorCarisma();

    // Setters
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setModificadorFuerza(int modificadorFuerza);
    void setModificadorDestreza(int modificadorDestreza);
    void setModificadorConstitucion(int modificadorConstitucion);
    void setModificadorInteligencia(int modificadorInteligencia);
    void setModificadorSabiduria(int modificadorSabiduria);
    void setModificadorCarisma(int modificadorCarisma);

    // Methods
    void mostrarRaza();
};

// Constructors

/**
 * @brief Construct a default Raza::Raza object
 *
 * @param
 * @return Raza object
 */

Raza::Raza()
{
    nombre = "Humano";
    descripcion = "En los registros de la mayoría de los mundos, los humanos son la más joven de las  comunes. Han llegado comparativamente tarde al mundo y sus vidas son más cortas que las de enanos, elfos y dragones. Y quizá sea precisamente por estas breves existencias por lo que los humanos aspiran a conseguir tanto como sean capaces en los años que se les han concedido.";
    modificadorFuerza = 1;
    modificadorDestreza = 1;
    modificadorConstitucion = 1;
    modificadorInteligencia = 1;
    modificadorSabiduria = 1;
    modificadorCarisma = 1;
}

/**
 * @brief Construct a new Raza::Raza object
 *
 * @param nombre
 * @param descripcion
 * @param modificadorFuerza
 * @param modificadorDestreza
 * @param modificadorConstitucion
 * @param modificadorInteligencia
 * @param modificadorSabiduria
 * @param modificadorCarisma
 * @return Raza object
 */

Raza::Raza(std::string nombre, std::string descripcion, int modificadorFuerza,
           int modificadorDestreza, int modificadorConstitucion, int modificadorInteligencia,
           int modificadorSabiduria, int modificadorCarisma)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->modificadorFuerza = modificadorFuerza;
    this->modificadorDestreza = modificadorDestreza;
    this->modificadorConstitucion = modificadorConstitucion;
    this->modificadorInteligencia = modificadorInteligencia;
    this->modificadorSabiduria = modificadorSabiduria;
    this->modificadorCarisma = modificadorCarisma;
}

// Getters

/**
 * @brief Getter for the attribute nombre
 *
 * @param
 * @return nombre
 */

std::string Raza::getNombre()
{
    return this->nombre;
}

/**
 * @brief Getter for the attribute descripcion
 *
 * @param
 * @return descripcion
 */

std::string Raza::getDescripcion()
{
    return this->descripcion;
}

/**
 * @brief Getter for the attribute modificadorFuerza
 *
 * @param
 * @return modificadorFuerza
 */

int Raza::getModificadorFuerza()
{
    return this->modificadorFuerza;
}

/**
 * @brief Getter for the attribute modificadorDestreza
 *
 * @param
 * @return modificadorDestreza
 */

int Raza::getModificadorDestreza()
{
    return this->modificadorDestreza;
}

/**
 * @brief Getter for the attribute modificadorConstitucion
 *
 * @param
 * @return modificadorConstitucion
 */

int Raza::getModificadorConstitucion()
{
    return this->modificadorConstitucion;
}

/**
 * @brief Getter for the attribute modificadorInteligencia
 *
 * @param
 * @return modificadorInteligencia
 */

int Raza::getModificadorInteligencia()
{
    return this->modificadorInteligencia;
}

/**
 * @brief Getter for the attribute modificadorSabiduria
 *
 * @param
 * @return modificadorSabiduria
 */

int Raza::getModificadorSabiduria()
{
    return this->modificadorSabiduria;
}

/**
 * @brief Getter for the attribute modificadorCarisma
 *
 * @param
 * @return modificadorCarisma
 */

int Raza::getModificadorCarisma()
{
    return this->modificadorCarisma;
}

// Setters

/**
 * @brief Setter for the attribute nombre
 *
 * @param nombre
 * @return
 */

void Raza::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

/**
 * @brief Setter for the attribute descripcion
 *
 * @param descripcion
 * @return
 */

void Raza::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
}

/**
 * @brief Setter for the attribute modificadorFuerza
 *
 * @param modificadorFuerza
 * @return
 */

void Raza::setModificadorFuerza(int modificadorFuerza)
{
    this->modificadorFuerza = modificadorFuerza;
}

/**
 * @brief Setter for the attribute modificadorDestreza
 *
 * @param modificadorDestreza
 * @return
 */

void Raza::setModificadorDestreza(int modificadorDestreza)
{
    this->modificadorDestreza = modificadorDestreza;
}

/**
 * @brief Setter for the attribute modificadorConstitucion
 *
 * @param modificadorConstitucion
 * @return
 */

void Raza::setModificadorConstitucion(int modificadorConstitucion)
{
    this->modificadorConstitucion = modificadorConstitucion;
}

/**
 * @brief Setter for the attribute modificadorInteligencia
 *
 * @param modificadorInteligencia
 * @return
 */

void Raza::setModificadorInteligencia(int modificadorInteligencia)
{
    this->modificadorInteligencia = modificadorInteligencia;
}

/**
 * @brief Setter for the attribute modificadorSabiduria
 *
 * @param modificadorSabiduria
 * @return
 */

void Raza::setModificadorSabiduria(int modificadorSabiduria)
{
    this->modificadorSabiduria = modificadorSabiduria;
}

/**
 * @brief Setter for the attribute modificadorCarisma
 *
 * @param modificadorCarisma
 * @return
 */

void Raza::setModificadorCarisma(int modificadorCarisma)
{
    this->modificadorCarisma = modificadorCarisma;
}

// Methods

/**
 * @brief Method to show the attributes of the class
 *
 * @param
 * @return
 */

void Raza::mostrarRaza()
{
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Modificador de Fuerza: " << this->modificadorFuerza << std::endl;
    std::cout << "Modificador de Destreza: " << this->modificadorDestreza << std::endl;
    std::cout << "Modificador de Constitucion: " << this->modificadorConstitucion << std::endl;
    std::cout << "Modificador de Inteligencia: " << this->modificadorInteligencia << std::endl;
    std::cout << "Modificador de Sabiduria: " << this->modificadorSabiduria << std::endl;
    std::cout << "Modificador de Carisma: " << this->modificadorCarisma << std::endl;
}

#endif // End of RAZA_H preprocessor
