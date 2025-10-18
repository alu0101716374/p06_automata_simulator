// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 18/10/2025-
// Archivo estado.h
// declara la clase y los metodos que utilizara la clase Estado
//
// Historial de revisiones
// 18/10/2025 - Creación (primera versión) del código

#ifndef ESTADO_H
#define ESTADO_H

#include <map>
#include <set>
#include <string>

#include "simbolo.h"

class Estado {
 public:
  Estado(const std::string& line);
  Estado();
  std::multimap<Simbolo, int> GetTransitions() const;
  int GetIdentifier() const;
  bool operator<(const Estado& other) const ;
  bool IsAccepted() const;

  friend std::ostream& operator<<(std::ostream& os, const Estado& state);
  void operator=(const Estado& other);
 private:
  int identifier_;
  bool accepted_;
  int transition_count_;
  std::multimap<Simbolo, int> transitions_;
};

#endif