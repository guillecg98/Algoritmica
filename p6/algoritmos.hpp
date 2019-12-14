#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "reina.hpp"
#include "sistemaEcuaciones.hpp"

#include <vector>
#include<cstdlib>
#include <iostream>
#include <time.h>
#include <cmath>
#include <cassert>

bool lugar(Reina k, std::vector<Reina> &reina);
void nReinasBacktracking(int n, std::vector<Reina> reinas, std::vector<std::vector<Reina>> &posiciones);
bool nReinasLasVegas(int n, std::vector<Reina> &reinas);
double factorial(double x);
void ajusteFactorial(const std::vector<double> &tiempos, double &a0, double &a1);
double sumatorio(std::vector<double> vec1, std::vector<double> vec2, double exp1, double exp2);

#endif