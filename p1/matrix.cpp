#include "matrix.hpp"
#include "sistemaEcuaciones.hpp"

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

void ajustePolinomico(const vector<double> &n, const vector<double> &times, vector <double> &a){
    vector<vector<double>> A(4, vector<double>(4, 0));
    vector<vector<double>> B(4, vector<double>(1, 0));
    vector<vector<double>> X(4, vector<double>(1, 0));

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if( (i == 0) && (j == 0) ){
                A[0][0] = times.size();
            }else{
                A[i][j] = sumatorio(n,times,i+j,0);
            }
        }
        B[i][0] = sumatorio(n,times,i,1);
    }

    resolverSistemaEcuaciones(A,B,4,X);

    for(int i = 0; i < 4; i++){
        a.push_back(X[i][0]);
    }
}

double sumatorio(vector<double> vec1, vector<double> vec2, double exp1, double exp2){
    #ifndef NDEBUG
        assert( vec1.size() == vec2.size());
    #endif
    double sum = 0;
    for(int i = 0; i < vec1.size(); i++){
        sum += pow(vec1[i],exp1) * pow(vec2[i],exp2);
    }
    return sum;
}

void calcularTiemposEstimadosPolinomio(const vector<double> &n, const vector<double> &times, const vector<double> &a, vector<double> &estimated_times){

    for(int i = 0; i < n.size(); i ++){
        double res = 0.0;
        for(int j = 0; j < a.size(); j++){
            res += a[j] * pow(n[i],j);
        }
        estimated_times.push_back(res);
    }
}

double calcularTiempoEstimadoPolinomico(const double &n,const vector<double> &a){
    double res = 0.0;
    for(int i = 0; i < a.size(); i++){
        res += a[i] * pow(n,i);
    }
    return res;
}