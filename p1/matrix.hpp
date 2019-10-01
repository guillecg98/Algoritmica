#ifndef MARTIX_HPP
#define MARTIX_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t
#include <fstream>

using namespace std;

void rellenarMatriz(vector<vector<double>> &v);
void redimensionaMatriz(vector<vector<double>> &v,int tam);
void productoMatrices(vector<vector<double>> &v,vector<vector<double>> &matriz_resultado);

#endif