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

/**
 * @brief Constructor from string
 *
 * @param input the input string
 * @return void
 */
Cadena::Cadena(std::string input) : cadena_{input} {}

/**
 * @brief default constructor, creates empty string
 *
 * @return void
 */
Cadena::Cadena() : cadena_{""} {}

/**
 * @brief returns the string
 *
 * @return string
 */
std::string Cadena::GetCadena() const {
  return cadena_;
}

/**
 * @brief Returns the string length
 *
 * @return string length<int>
 */
int Cadena::GetLength() const {
  return cadena_.size();
}

/**
 * @brief Return the inverse of a string
 *
 * @return cadena
 */
Cadena Cadena::Inverse() const {
  Cadena output;
  for (int i{1}; i <= GetLength(); i++) {
    output.cadena_ += cadena_[GetLength() - i];
  }
  return output;
}

/**
 * @brief overload outstream operator to print string
 *
 * @param os out stream
 * @param cadena string to print
 * 
 * @return out stream
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.cadena_;
  return os;
}

/**
 * @brief overload input operator
 *
 * @param is input stream
 * @param cadena cadea to create
 * @return input stream
 */
std::istream& operator>>(std::istream& is, Cadena& cadena) {
  std::string temp{""};
  if (is >> temp) {
    cadena = Cadena(temp);
  }
  return is;
}

/**
 * @brief overload the =
 *
 * @param other  the string you want to duplicate
 * @return void
 */
void Cadena::operator=(const Cadena& other) {
  cadena_ = other.cadena_;
}

/**
 * @brief order by size first then lexicographically
 *
 * @param other the string youre comparing against
 * @return true or false
 */
bool Cadena::operator<(const Cadena& other) const {
  if (GetLength() != other.GetLength()) 
    return GetLength() < other.GetLength();
  return cadena_ < other.cadena_;
}

/**
 * @brief checks if the symbols in the string are part of the alphabet
 *
 * @param alfabeto alphabet that the string shoukd belong to
 * @return true if valid, else false
 */
bool Cadena::IsValid(const Alfabeto& alfabeto) {
  for (Simbolo simbolo : cadena_) {
    if (!alfabeto.Contains(simbolo)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief overload == operato
 *
 * @param other string to compare agiants
 * @return true if equeal, else false
 */
bool Cadena::operator==(const Cadena& other) const {
  return cadena_ == other.cadena_;
}

/**
 * @brief overload [] operator 
 *
 * @param position the idex of the symbol you would like to find
 * @return symbol found at cadena[position]
 */
Simbolo Cadena::operator[](const int position) const {
  return Simbolo{cadena_[position]};
}
