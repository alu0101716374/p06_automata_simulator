// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 15/10/2025-
// Archivo automata.h
// declara la clase Automata(un objeto que almacena una automata)
//
// Historial de revisiones
// 15/10/2025 - Creación (primera versión) del código

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "estado.h"

#include "alfabeto.h"
#include <set>



class Automata {
  public:
    // Constructor usando un fichero de entrada
    Automata(const std::string& input_file_name);

    const Estado& GetState(const int identifier) const;

    void CheckFileStrings(const std::string& inp_file_name) const;
    bool AcceptString(const Cadena& cadena) const;
    friend std::ostream& operator<<(std::ostream& out_stream, const Automata& automata);
  private:
    Alfabeto alfabeto_;
    std::set<Estado> estados_;
    int estado_inicial_;
    int numero_estados_;
    std::set<int> identificadores_estados_;

    void ValidStates() const;
    bool StateExists(const int identifier) const;
    bool RecursiveSearch(const int state_id, int position, const Cadena& cadena) const;
};

#endif