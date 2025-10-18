// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 15/10/2025-
// Archivo main.cc
// Especifica el funcionamiento del programa y gestiona la linea de comandos
//
// Historial de revisiones
// 15/10/2025 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include "tools.h"
#include "automata.h"

/**
 * @brief Checks command line arguments, creates the automaton, ad¡nd checks strings
 *
 * @return 0 = no errors
 */
int main(int argc, char* argv []) {
  if (argc == 1) {
    Usage();
  } else if (std::string(argv[1]) == "--help" || argc != 3) {
    PrintHelp();
  } else {
    const std::string automata_file_name{argv[1]}, test_file_name{argv[2]};
    Automata automata(automata_file_name);
    automata.CheckFileStrings(test_file_name);
    return 0;
  }
}