#include "matrix.hpp"
#include "sistemaEcuaciones.cpp"

void rellenarMatriz(vector<vector<double>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            double num = 0.95 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(1.05-0.95)));
            v[i][j] = num;
        }
    }
}