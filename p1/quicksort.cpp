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
    bool is_ordered = true;
    for(int i = 0; i < v.size()-1; i++){
        #ifndef NDEBUG
            assert( v[i] <= v[i+1] );
        #endif
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
    pivot = v[start];
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (v[right] > pivot) {
            right--;
        }
        while ((left < right) && (v[left] <= pivot)) {
            left++;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = v[right];
    v[right] = v[start];
    v[start] = temp;
    // La nueva posición del pivot
    return right;
}

bool escribeFichero(vector<double> &n,vector<double> &times){
    bool escrito = false;
    #ifndef NDEBUG
        assert( !n.empty() );
        assert( !times.empty() );
        assert( n.size() == times.size());
    #endif

    ofstream file("tiempos.txt");

    for(int i = 0; i < n.size(); i++){
        file << n[i] << " " << times[i] << "\n";
    }

    file.close();

    escrito = true;

    #ifndef NDEBUG
        assert( escrito == true );
    #endif
    return escrito;
}

void ajusteNlogN(const vector<double> &n,const vector<double> &times,double &a0, double &a1){
    std::vector<double> z;
    z.resize(n.size());

    for(int i = 0; i < z.size(); i++){
        z[i] = n[i] * log10(n[i]);
    }
}

void calcularTiemposEstimadosNlogN(const vector<double> &n,const vector<double> &times, const double &a0, const double &a1, vector<double> estimated_times){
    estimated_times.resize(times.size());
    for(int i = 0; i < estimated_times.size(); i++){
        estimated_times.push_back(a0 + a1 * n[i]*log10(n[i]));
    }
}   