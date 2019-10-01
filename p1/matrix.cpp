#include "matrix.hpp"
//#include "sistemaEcuaciones.cpp"

void rellenarMatriz(vector<vector<double>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            double num = 0.95 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(1.05-0.95)));
            v[i][j] = num;
        }
    }
}

void redimensionaMatriz(vector<vector<double>> &v,int tam){
    v.resize(tam);
    for(int i = 0; i < v.size(); i++){
        v[i].resize(tam);
    }
}

void productoMatrices(vector<vector<double>> &v,vector<vector<double>> &matriz_resultado){
    vector<vector<double>> m2 = v;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < m2[i].size(); j++){
            matriz_resultado[i][j] = 0.0;
            for(int k = 0; k < v.size(); k++){
                matriz_resultado[i][j] = matriz_resultado[i][j] + v[i][k] * m2[k][j];
            }
        }
    }
}