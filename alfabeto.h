// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2
// Practica 2: Cadenas y lenguajes
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 19/09/2025-
// Archivo alfabeto.h
// definicion de la clase alfabeto
//
// Historial de revisiones
// 19/09/2025 - Creacion (primera version) del codigo

#ifndef ALFABETO_H
#define ALFABETO_H


#include "simbolo.h"
#include "cadena.h"

#include <set>

class Alfabeto {
  public:
    // constructor desde una cadena
    Alfabeto(const Cadena& cadena);

    // Constructor por defecto (vacío)
    Alfabeto();

    void Insert(const Simbolo& simbolo);

    bool Contains(const Simbolo& simbolo) const;

    // sobrecargas utiles
    friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto); 
    friend std::istream& operator>>(std::istream& is, Alfabeto& alfabeto);

  private:
    std::set<Simbolo> alfabeto_;

};



#endif