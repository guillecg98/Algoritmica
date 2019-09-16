#include "quicksort.hpp"

int getTamVector(vector <int> &v){
    return v.size();
}

void rellenarVector(vector <int> &v){

    srand(time(0));

    for(int i = 0; i < getTamVector(v); i++){
        int num = rand() % 999;
        v.push_back(num);
    }
}

void imprimeVector(vector <int> &v){

    for(int i = 0; i < getTamVector(v); i++){
        cout<<"v["<<v[i]<<"]\n";
    }
}