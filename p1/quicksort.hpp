#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>

using namespace std;

void rellenarVector(vector <int> &v);
void imprimeVector(vector <int> &v);
bool estaOrdenado(const vector<int> &v);
void quicksort(vector<int> &v, int start, int end);
int divide(vector<int> &v, int start, int end);

#endif