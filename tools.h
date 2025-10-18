// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: automata simulator
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 15/10/2025-
// Archivo tools.h
// Crea las funciones utilizadas en el main para describir modo de empleo etc
//
// Historial de revisiones
// 15/10/2025 - Creación (primera versión) del código

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include "alfabeto.h"

void Usage();

void PrintHelp();

void ErrorOne();

void ErrorTwo(const int expected, const int recieved);
void ErrorThree(const Simbolo symbol, const int state, const Alfabeto& alphabet);
void ErrorFour();
void ErrorFive(const int state, const int next_state);

#endif