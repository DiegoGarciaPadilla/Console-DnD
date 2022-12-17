/**
 * DnD Character Creator
 * Diego Antonio Garcia Padilla
 * A01710777
 * 02/12/2022
 */

/**
 * @brief This program was created for the course of Object Oriented Computational Thinking, and consists of a character creator for the board game Dungeons and Dragons.
 *
 * The program is divided into 4 main parts:
 * 1. The main menu, where the user can create a character, see the character's information, see the encyclopedia or exit the program.
 * 2. The character creation menu, where the user can choose
 * 3. The encyclopedia, where the user can see the information
 * 4. The character information menu, where the user can see the information of the character created.
 * 
 */

#include <iostream> // Library for input and output
#include <string>   // Library for strings

#include "headers/Menu.h"          // Library for menus
#include "headers/Inicializador.h" // Library for initializers
#include "headers/Funciones.h"     // Library for functions
#include "headers/Personaje.h"     // Library for the character class

int main()
{
    // Variables
    int opcion, opcionEnciclopedia;
    Personaje personaje;

    // Main menu loop
    do
    {
        menuPrincipal();
        std::cin >> opcion;
        limpiarPantalla();
        switch (opcion)
        {
        case 1:
            crearPersonaje(personaje);
            pausa();
            break;
        case 2:
            if (personaje.getNombre() == " ")
            {
                std::cout << "No hay ningun personaje creado" << std::endl;
            }
            else
            {
                personaje.mostrarPersonaje();
            }
            pausa();
            break;
        case 3:
            menuEnciclopedia();
            break;
        case 4:
            std::cout << "Gracias por usar el creador de personajes de D&D" << std::endl;
            pausa();
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            pausa();
            break;
        }
        limpiarPantalla();
    } while (opcion != 4);
}
