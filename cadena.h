// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Kye Brandon Rogers
// Correo: alu0101716374@ull.edu.es
// Fecha: 20/09/2025-
// Archivo header.h
// declaracion del objeto cadena para facilitar el trabajo y la lectura
//
// REFERENCIAS
// Para arreglar el problema de "dependencias circulares entre clases", leí este artículo: https://pvigier.github.io/2018/02/09/dependency-graph.html
// 
// Historial de revisiones
// 20/09/2025 - Creación (primera versión) del código
#ifndef CADENA_H
#define CADENA_H

#include <string>
#include <ostream>
#include <set>

// declaraciones para resolver problema de dependencia circular entre las clases
class Lenguaje;
class Alfabeto;

class Cadena {
public:
    // constructores
    Cadena(std::string input);
    Cadena();

    // otras necesarias
    std::string GetCadena() const;
  

    // opciones pedidas en el guión
    int GetLength() const;
    Cadena Inverse() const;


    bool IsValid(const Alfabeto& alfabeto);

    // sobrecargas
    friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena); 
    friend std::istream& operator>>(std::istream& is, Cadena& cadena);
    void operator=(const Cadena& other);
    bool operator<(const Cadena& other) const; 

private:
    std::string cadena_{""};
};

#endif
