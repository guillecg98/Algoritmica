#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "reina.hpp"
#include <vector>
#include<cstdlib>

void nReinasBacktracking(int n, std::vector<Reina> reina, std::vector<std::vector<Reina>> &posiciones);
bool lugar(Reina k, std::vector<Reina> &reina);

#endif