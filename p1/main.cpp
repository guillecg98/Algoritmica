#include "quicksort.hpp"
//#include "sistemaEcuaciones.hpp"

int main() {

    int max,min,inc,rep;

    std::vector<int> v;

    cout<<"Introduce el tamaño del vector:\n";
    cin>>max;
    v.resize(max);
    cerr<<"Tamaño del vector: "<<v.size()<<"\n";
    cout<<"Rellenando vector...\n";
    rellenarVector(v);
    cout<<"Imprimiendo vector ...\n";
    imprimeVector(v);
    cout<<"Ordenando vector...\n";
    quicksort(v);//MIRATE ESTO
    if(estaOrdenado(v)){
        cout<<"Está ordenado\n";
    }else{
        cout<<"Está desordenado\n";
    }

    return 0;
}