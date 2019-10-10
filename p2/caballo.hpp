#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "posicion.hpp"
#include <vector>

int calcularCaminos(int x, int y, std::vector<Posicion> &vector_pos, std::vector<std::vector<Posicion>> &matriz_caminos);
bool notexist(std::vector<std::vector<Posicion>> &matriz_caminos, Posicion p);

#endif