// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 20/09/2025-
// Archivo alfabeto.cc
// crea las funciones/metodos declaradas en el fichero alfabeto.h
//
// Historial de revisiones
// 20/09/2025 - Creación (primera versión) del código

#include "alfabeto.h"

#include "cadena.h"
#include "simbolo.h"
#include "tools.h"
#include <iostream>

// constructor desde cadena
Alfabeto::Alfabeto(const Cadena& cadena) {
  for (char character : cadena.GetCadena()) {
    Simbolo simbolo{character};
    alfabeto_.insert(simbolo);
  }
}

void Alfabeto::Insert(const Simbolo& simbolo) {
  if (simbolo == '&') ErrorFour();
  alfabeto_.insert(simbolo);
}


bool Alfabeto::Contains(const Simbolo& simbolo) const {
  return (alfabeto_.find(simbolo) != alfabeto_.end());
}

// constructor por defecto
Alfabeto::Alfabeto() {};

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  bool first{true};
  for (Simbolo simbolo : alfabeto.alfabeto_) {
    if (first) {
      os << "{" << simbolo;
      first = false;
    } else {
      os << ", " << simbolo;
    }
  }
  os << "}\n";
  return os;
}

std::istream& operator>>(std::istream& is, Alfabeto& alfabeto) {
  Cadena temp_cadena;
  if (is >> temp_cadena) {
    alfabeto = Alfabeto(temp_cadena);
  }
  return is;
}