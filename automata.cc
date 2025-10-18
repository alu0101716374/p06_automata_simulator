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

/**
 * @brief the main constructor using an input file
 *
 * @param input_file_name string that matches the input file name
 * @return void, its a constructor
 */
Automata::Automata(const std::string& input_file_name) {

  // open the input file
  std::ifstream input_file;
  input_file.open(input_file_name);

  std::string line;

  // first line is the alphabet
  std::getline(input_file, line);
  std::istringstream string_stream(line);
  Simbolo simbolo;
  // Add each symbol from the line to the alphabet
  while (string_stream >> simbolo) {
    alfabeto_.Insert(simbolo);
  }

  // Second line (amount of states)
  input_file >> numero_estados_; 
  std::getline(input_file, line);

  // Third line (initial state - check that there is only one)
  std::getline(input_file, line);
  string_stream.str(line);
  string_stream.clear();
  string_stream >> estado_inicial_;
  std::string temp{""};
  std::cout << temp;
  // Checks that there is nothing left in the string
  if (string_stream >>  temp) ErrorOne();

  // line 4+ (states and transitions)
  int counter{0}; // To check for error 2 
  while (std::getline(input_file, line)) {
    Estado temp_state{line};
    estados_.insert(temp_state);
    counter++;
  }
  if (counter != numero_estados_) ErrorTwo(numero_estados_, counter);
  ValidStates();
}

/**
 * @brief output stream operator overload, prints the automaton in a readable format ( for testing purposes)
 *
 * @param out_stream  out stream that is used
 * @param automata the automaton that will be printed
 * @return output stream
 */
std::ostream& operator<<(std::ostream& out_stream, const Automata& automata) {
  out_stream << "Alfabeto: " << automata.alfabeto_;
  out_stream << "Nº de estados: " << automata.numero_estados_  << "\n";
  out_stream << "Estado de Arranque: " << automata.estado_inicial_  << "\n";
  for (Estado state : automata.estados_) {
    out_stream << state;
  }
  return out_stream;
}


/**
 * @brief Check that the states dont commit error 3 or 5 (using symbols and states that dont exist in the alphabet/automaton)
 * 
 * @return void, exits program if error is found
 */
void Automata::ValidStates() const{
  for (const Estado& state : estados_) {
    for (auto [symbol, next_state] : state.GetTransitions()) {
      if (!alfabeto_.Contains(symbol) && symbol != '&') {
        ErrorThree(symbol, state.GetIdentifier(), alfabeto_);
      } else if (!StateExists(next_state)) {
        ErrorFive(state.GetIdentifier(), next_state);
      }
    }
  }
 }

 /**
  * @brief checks if a state exists given its identifier
  *
  * @param identifier state id
  * @return true if found, false otherwise
  */
bool Automata::StateExists(const int identifier) const {
  for (const Estado& state : estados_) {
    if (state.GetIdentifier() == identifier) return true;
  }
  return false;
}

/**
 * @brief Iterate though the states and return the state that matches the id
 *
 * @param identifier state id to search for
 * @return A state reference or exit(1) in case of state not existing
 */
const Estado& Automata::GetState(const int identifier) const {
  for (const Estado& state : estados_) {
    if (state.GetIdentifier() == identifier) return state;
  }

  std::cout << "RUNTIME ERROR: Searching for a non existent state\n";
  std::exit(1);
}

/**
 * @brief initial call to the recursive search
 *
 * @param cadena string to check if its accepted or not
 * @return true or false if accepted or not
 */
bool Automata::AcceptString(const Cadena& cadena) const {
  return RecursiveSearch(estado_inicial_, 0, cadena);
}

/**
 * @brief Recursively search all options in the automaton and return if any possible accepted paths have been found
 *
 * @param state_id current state id
 * @param position currnetly position in the input string
 * @param cadena input string to check
 * @return true if accepted, false otherwise
 */
bool Automata::RecursiveSearch(const int state_id, int position, const Cadena& cadena) const {
  // base case (position == length)
  const Estado& current = GetState(state_id);
  if (position == cadena.GetLength()) {
    if (current.IsAccepted()) return true;

    // Check epsilon transitions
    for (auto [symbol, next_state] : current.GetTransitions()) {
      if (symbol == '&') {
        if (RecursiveSearch(next_state, position, cadena)) {
          return true;
        }
      }
    }

    
    return false;
  }
  // Check all transitions for possible paths
  for (auto [symbol, next_state] : current.GetTransitions()) {
    if (symbol == cadena[position]) {
      if (RecursiveSearch(next_state, position + 1, cadena)) {
        return true;
      }
    } else if (symbol == '&') {
      if (RecursiveSearch(next_state, position, cadena)) {
        return true;
      }
    }
  }
  return false;

}

/**
 * @brief Iterate through the input file, and print if each string has been accepted or not
 *
 * @param inp_file_name the input textt file
 * @return void
 */
void Automata::CheckFileStrings(const std::string& inp_file_name) const {
  std::ifstream string_file(inp_file_name);
  Cadena temp;
  while (string_file >> temp) {
    std::cout << temp << "---" << (AcceptString(temp) ? "Accepted" : "Rejected") << std::endl;
  }
  
}

