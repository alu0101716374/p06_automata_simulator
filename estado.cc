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

bool Estado::operator<(const Estado& other) const {
  return identifier_ < other.identifier_;
}

std::multimap<Simbolo, int> Estado::GetTransitions() const {
  return transitions_;
}

int Estado::GetIdentifier() const {
  return identifier_;
}

