#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

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

void rellenarVector(vector <int> &v);
void imprimeVector(vector <int> &v);
bool estaOrdenado(const vector<int> &v);
void quicksort(vector<int> &v, int start, int end);
int divide(vector<int> &v, int start, int end);
void ajusteNlogN(const vector<double> &n,const vector<double> &times,double &a0, double &a1);
double sumatorio(vector<double> vec1, vector<double> vec2, double exp1, double exp2);
void calcularTiemposEstimadosNlogN(const vector<double> &n,const vector<double> &times, const double &a0, const double &a1, vector<double> &estimated_times);
bool escribeFichero(vector<double> &n,vector<double> &times,vector<double> &estimated_times);
double calcularCoeficienteDeterminacion(const vector<double> &times, const vector<double> &estimates_times);
double calcularVarianza(vector <double> vec);
double calculaTiempoEstimado(const double &n,const double &a0, const double &a1);

#endif