#include "quicksort.hpp"

void rellenarVector(vector <int> &v){
    for(int i = 0; i < v.size(); i++){
        int num = rand() % 1000;
        v[i] = num;
    }
}

void imprimeVector(vector <int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<"v["<<v[i]<<"]\n";
    }
}

bool estaOrdenado(const vector<int> &v){
    int flag = 1, i = 0;
    bool is_ordered = true;
    while( (i<v.size()) && (flag == 1) ){
        if(v[i] > v[i+1]){
            flag = 0;
            is_ordered = false;
        }
        i++;
    }
    return is_ordered;
}

void quicksort(vector<int> &v, int start, int end){
    int pivot;
    if (start < end) {
        pivot = divide(v, start, end);
        // Ordeno la lista de los menores
        quicksort(v, start, pivot - 1);
        // Ordeno la lista de los mayores
        quicksort(v, pivot + 1, end);
    }
}

int divide(vector<int> &v, int start, int end){
    int left,right,pivot,temp;
    pivot = array[start];
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
    // La nueva posición del pivot
    return right;
}