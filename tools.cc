// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 18/10/2025-
// Archivo tools.cc
// creates the functions declared in tools.h
//
// Historial de revisiones
// 18/10/2025 - Creación (primera versión) del código

#include <iostream>

#include "tools.h"

/**
 * @brief prints the way to use the progam
 *
 * @return void
 */
void Usage() {
  std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt\nPruebe 'p06_automata_simulator --help' para mas informacion.\n";
}

/**
 * @brief prints the --help option including file format instructions 
 *
 * @return void
 */
void PrintHelp() {
    std::cout << "######################\n";
  std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt\nPruebe 'p06_automata_simulator --help' para mas informacion.\n\n";
  std::cout << "######################\n";
  std::cout << "FORMATO DEL FICHERO .fa:\n"
  << "\t- Linea 1: Simbolos del alfabeto separado por espacios\n"
  << "\t- Linea 2: Nº totalde estados del automata\n"
  << "\t- Linea 3: Estado de arranque del automata\n"
  << "\t- A continuacion figurara una linea para cada uno de los estados. Cada\n"
  << "\t linea contendra los siguientes numeros, separados entre si por espacios en blanco:\n"
  << "\t\t* Numero identificador del estado (usando numeros naturales)\n"
  << "\t\t* Un 1 si se trata de un estado de aceptacion y un 0 en caso contrario\n"
  << "\t\t* Nº de transiciones\n"
  << "\t\t* A continuacion, para cada una de las transiciones, y utilizando\n \t\tespacios en blanco como separadores, se detallara la informacion siguiente:\n"
  << "\t\t\t ◦ Simbolo de entrada necesario para que se produzca la transicion (& = cadena vacia)\n"
  << "\t\t\t ◦ Estado destino de la transicion.\n";
  std::cout << "######################\n";
  std::cout << "FORMATO DEL FICHERO .txt:\n"
  << "El fichero deberia de tener una unica cadena por linea.\n\n"; 
}

/**
 * @brief more that 1 initial state error, force stop program 
 *
 * @return exit(1)
 */
void ErrorOne() {
  std::cerr << "ERROR 1: More than one initial state\nPROGRAM TERMINATED\n";
  std::exit(1);
}

/**
 * @brief one line per transition definition error, force stop program
 *
 * @return exit(1)
 */
void ErrorTwo(const int expected, const int recieved) {
  std::cerr << "ERROR 2: Expected " << expected << " lines to define states.\nRecieved: " << recieved << " lines to define states.\nPROGRAM TERMINATED\n";
  std::exit(1);
}

/**
 * @brief transitions only use symbols found in the alphabet, force close program
 *
 * @return exit(1)
 */
void ErrorThree(const Simbolo symbol, const int state, const Alfabeto& alphabet) {
  std::cerr << "ERROR 3: The transition symbol '" << symbol << "' in state " << state << " is not found in the defined alphabet " << alphabet << "\nPROGRAM TERMINATED\n";
  std::exit(1);
}

/**
 * @brief & cannot be part of alphabet error, force close program
 *
 * @return exit(1)
 */
void ErrorFour() {
  std::cerr << "Error 4: The symbol '&' cannot be in the alphabet as it is saved to represent the empty string\nPROGRAM TERMINATED\n";
  std::exit(1);
}

/**
 * @brief transition to non existing state error, force close program
 *
 * @return exit(1)
 */
void ErrorFive(const int state, const int next_state) {
  std::cerr << "ERROR 5: state (" << state << ") contains transition to non existing state (" << next_state << ")\nPROGRAM TERMINATED\n";
  std::exit(1);
}
