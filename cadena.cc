// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 20/09/2025-
// Archivo cadena.cc
// creacion de las funciones declaradas en el .h
//
// Historial de revisiones
// 20/09/2025 - Creación (primera versión) del código

#include "simbolo.h"
#include "alfabeto.h"

#include "cadena.h"
#include <iostream>

// Constructor
Cadena::Cadena(std::string input) : cadena_{input} {}

// Default constructor
Cadena::Cadena() : cadena_{""} {}

std::string Cadena::GetCadena() const {
  return cadena_;
}

// Returns the length
int Cadena::GetLength() const {
  return cadena_.size();
}

// Returns the inverse of the string
Cadena Cadena::Inverse() const {
  Cadena output;
  for (int i{1}; i <= GetLength(); i++) {
    output.cadena_ += cadena_[GetLength() - i];
  }
  return output;
}

// Overload of <<
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.cadena_;
  return os;
}

// overload >>
std::istream& operator>>(std::istream& is, Cadena& cadena) {
  std::string temp{""};
  if (is >> temp) {
    cadena = Cadena(temp);
  }
  return is;
}

// Overload = 
void Cadena::operator=(const Cadena& other) {
  cadena_ = other.cadena_;
}

// Overload of <, needed for set.insert
// Orders first by length, then lexicographically
bool Cadena::operator<(const Cadena& other) const {
  if (GetLength() != other.GetLength()) 
    return GetLength() < other.GetLength();
  return cadena_ < other.cadena_;
}

bool Cadena::IsValid(const Alfabeto& alfabeto) {
  for (Simbolo simbolo : cadena_) {
    if (!alfabeto.Contains(simbolo)) {
      return false;
    }
  }
  return true;
}