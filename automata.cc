// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 15/10/2025-
// Archivo automata.cc
// crea las funciones/metodos declaradas en automata.h
//
// Historial de revisiones
// 15/10/2025 - Creación (primera versión) del código

#include "automata.h"
#include "tools.h"

#include <fstream>
#include <string>
#include <sstream>


Automata::Automata(const std::string& input_file_name) {

  std::ifstream input_file;
  input_file.open(input_file_name);

  std::string line;

  // Primera linea (alfabeto)
  std::getline(input_file, line);
  std::istringstream string_stream(line);
  Simbolo simbolo;
  while (string_stream >> simbolo) {
    alfabeto_.Insert(simbolo);
  }

  // Segunda línea (numero de estados)
  input_file >> numero_estados_; 
  std::getline(input_file, line);

  // Tercera linea (estado inicia - comprobar que es único)
  std::getline(input_file, line);
  string_stream.str(line);
  string_stream.clear();
  string_stream >> estado_inicial_;
  std::string temp{""};
  std::cout << temp;
  if (string_stream >>  temp) ErrorOne();

  // linea 4+ (estados)
  int counter{0};
  while (std::getline(input_file, line)) {
    Estado temp_state{line};
    estados_.insert(temp_state);
    counter++;
  }
  if (counter != numero_estados_) ErrorTwo(numero_estados_, counter);
  // Comprobar que los estados son validos
  ValidStates();
}

std::ostream& operator<<(std::ostream& out_stream, const Automata& automata) {
  out_stream << "Alfabeto: " << automata.alfabeto_;
  out_stream << "Nº de estados: " << automata.numero_estados_  << "\n";
  out_stream << "Estado de Arranque: " << automata.estado_inicial_  << "\n";
  for (Estado state : automata.estados_) {
    out_stream << state;
  }
  return out_stream;
}


void Automata::ValidStates() const{
  for (Estado state : estados_) {
    for (auto [symbol, next_state] : state.GetTransitions()) {
      if (!alfabeto_.Contains(symbol) && symbol != '&') {
        ErrorThree(symbol, state.GetIdentifier(), alfabeto_);
      } else if (!StateExists(next_state)) {
        ErrorFive(state.GetIdentifier(), next_state);
      }
    }
  }
 }

bool Automata::StateExists(const int identifier) const {
  for (Estado state : estados_) {
    if (state.GetIdentifier() == identifier) return true;
  }
  return false;
}
