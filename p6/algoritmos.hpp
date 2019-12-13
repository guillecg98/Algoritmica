#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "reina.hpp"
#include <vector>
#include<cstdlib>
#include <iostream>
#include <time.h>

bool lugar(Reina k, std::vector<Reina> &reina);
void nReinasBacktracking(int n, std::vector<Reina> reinas, std::vector<std::vector<Reina>> &posiciones);
bool nReinasLasVegas(int n, std::vector<Reina> &reinas);

#endif