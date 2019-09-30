#include "quicksort.hpp"
#include "sistemaEcuaciones.cpp"

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
    std::vector<vector<double>> A(2, vector<double>(2, 0));
    std::vector<vector<double>> B(2, vector<double>(1, 0));
    std::vector<vector<double>> X(2, vector<double>(1, 0));

    std::vector<double> z;
    z.resize(n.size());
    //calculo del cambio de variable
    for(int i = 0; i < z.size(); i++){
        z[i] = n[i] * log10(n[i]);
    }

    //planteamos el sistema para el caso t(n) = a0 + a1 * nlog(n)
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if( (i == 0) && (j == 0) ){
                A[0][0] = times.size();
            }else{
                A[i][j] = sumatorio(z,times,i+j,0);
            }
        }
        B[i][0] = sumatorio(z,times,i,1);
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout<<"A["<<i<<"]["<<j<<"] = "<<A[i][j]<<"\n";
            cout<<"B["<<i<<"]["<<j<<"] = "<<B[i][j]<<"\n";
        }
    }
    //resolvemos el sistema de ecuaciones
    resolverSistemaEcuaciones(A,B,2,X);
    a0 = X[0][0];
    a1 = X[1][0];
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

void calcularTiemposEstimadosNlogN(const vector<double> &n,const vector<double> &times, const double &a0, const double &a1, vector<double> &estimated_times){

    for(int i = 0; i < times.size(); i++){
        estimated_times.push_back(a0 + a1 * n[i]*log10(n[i]));
    }
}

double calcularCoeficienteDeterminacion(const vector<double> &times, const vector<double> &estimates_times){
    return calcularVarianza(times) / calcularVarianza(estimates_times);
}

double calcularVarianza(vector <double> vec){
    double media = 0;
    double varianza = 0;

    for(int i = 0; i < vec.size(); i++){
        media += vec[i];
    }
    media = media / vec.size();

    for(int i = 0; i < vec.size(); i++){
        varianza += pow(vec[i]-media,2);
    }
    varianza = varianza / vec.size();

    return varianza;
}