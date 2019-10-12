#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "posicion.hpp"
#include <vector>

int calcularCaminosFinalInicio(int x, int y, std::vector<Posicion> vector_pos, std::vector<std::vector<Posicion>> &matriz_caminos);
int calcularCaminosInicioFin(int x, int y,std::vector<Posicion> vector_pos, std::vector<std::vector<Posicion>> &matriz_caminos);

#endif