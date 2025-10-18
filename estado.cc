// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 18/10/2025-
// Archivo estado.cc
// crea los metodos declarados en el fichero estado.h
//
// Historial de revisiones
// 18/10/2025 - Creación (primera versión) del código

#include "estado.h"

#include <sstream>
#include <iostream>

/**
 * @brief creates a state from an input line
 *
 * @param line line in format <id> <accepted 1, else 0> <nº transitions> <transition_symbol transition_state> .. 
 * @return void
 */
Estado::Estado(const std::string& line) {
  int next_state;
  Simbolo symbol;
  std::istringstream string_stream(line);
  string_stream >> identifier_ >> accepted_ >> transition_count_;
  for (int i{0}; i < transition_count_; i++) {
    string_stream >> symbol >> next_state;
    transitions_.insert({symbol, next_state});
  }
}

/**
 * @brief default constructor, creates empty state
 *
 * @return void
 */
Estado::Estado() {};

/**
 * @brief overload out stream operator in a readable format
 *
 * @param os out stream
 * @param state state to print
 * @return out stream
 */
std::ostream& operator<<(std::ostream& os, const Estado& state) {
  os << "# State: " << state.identifier_ << "\t";
  os << "Accepted: " << (state.accepted_ ? "True " : "False") << "   ";
  os << "Transitions: ";
  for (auto [symbol, next_state] : state.transitions_) {
    os << "{" << symbol << ", " << next_state << "} ";
  }
  os << std::endl;

  return os;
}

/**
 * @brief comparison operator for ordering in set, sorts by id
 *
 * @param other state to compare against
 * @return true or false 
 */
bool Estado::operator<(const Estado& other) const {
  return identifier_ < other.identifier_;
}

/**
 * @brief getter for trasiotions
 *
 * @return Multimap in format <symbol, state> 
 */
std::multimap<Simbolo, int> Estado::GetTransitions() const {
  return transitions_;
}

/**
 * @brief returns state id
 *
 * @return int
 */
int Estado::GetIdentifier() const {
  return identifier_;
}

/**
 * @brief checks if its an accepting state in the automaton
 *
 * @return true if accepted, else false
 */
bool Estado::IsAccepted() const {
  return accepted_;
}

/**
 * @brief overload asignment operator 
 *
 * @param other state to copy
 * @return void
 */
void Estado::operator=(const Estado& other) {
  identifier_ = other.identifier_;
  accepted_ = other.accepted_;
  transition_count_ = other.transition_count_;
  transitions_ = other.transitions_;
}



