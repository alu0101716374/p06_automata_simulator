# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 6: automata simulator
# Autor: Kye Brandon Rogers
# Correo: alu0101716374@ull.edu.es
# Fecha: 15/10/2025
# Archivo Makefile
#
# Historial de revisiones
# 15/10/2025 - Creación (primera versión) del código

ejecutable := p06_automata_simulator

all:
	@echo "Programa compilado"
	g++ -Wall main.cc alfabeto.cc cadena.cc automata.cc tools.cc estado.cc -o $(ejecutable)

clean: $(ejecutable)
	@echo "Ejecutable borrado del directorio"
	rm -f $(ejecutable)
	rm -rf *.txt