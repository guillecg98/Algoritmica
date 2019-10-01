#include "quicksort.hpp"
#include "matrix.hpp"
#include "ClaseTiempo.cpp"

int main() {
/*
---------------------------------------------------------------COMIENZA LA PARTE DEL QUICKSORT
    int max,min,inc,rep;
    double a0,a1;
    Clock time;
    //Para la parte del quicksort
    std::vector<int> v;
    std::vector<double> n;
    std::vector<double> times;
    std::vector<double> estimated_times;

    cout<<"Introduce el tamaño minimo del vector:\n";
    cin>>min;
    v.resize(min);
    cout<<"Introduce el tamaño maximo del vector:\n";
    cin>>max;
    cout<<"Introduce el incremento del vector:\n";
    cin>>inc;
    cout<<"Introduce el numero de repeticiones:\n";
    cin>>rep;

    while(v.size() <= max){
        n.push_back(min);
        double media = 0;
        cout<<"Para "<<v.size()<<" elementos:\n";
        for(int i = 0; i < rep; i++){
            rellenarVector(v);
            time.start();
            quicksort(v,0,v.size()-1);
            if(time.isStarted()){
	        time.stop();
            media +=time.elapsed();
	        }
        }
        media /= rep;
        std::cout << "Han pasado " << media << " microsegundos de media\n";
        times.push_back(media);
        v.clear();
        min += inc;
        v.resize(min);
    }

    ajusteNlogN(n,times,a0,a1);
    calcularTiemposEstimadosNlogN(n,times,a0,a1,estimated_times);

    escribeFichero(n,times,estimated_times);

    for(int i = 0; i<times.size(); i++){
        cout<<"reales["<<i<<"] = "<<times[i]<<"\n";
    }
    for(int i = 0; i<estimated_times.size(); i++){
        cout<<"estimados["<<i<<"] = "<<estimated_times[i]<<"\n";
    }

    cout<<"El tiempo en dias para 100000 millones de elementos es = "<<calculaTiempoEstimado(100000000000,a0,a1)<<"\n";

    cout<<"Varianza tiempos reales = "<<calcularVarianza(times)<<"\n";
    cout<<"Varianza tiempos estimados = "<<calcularVarianza(estimated_times)<<"\n";
    cout<<"Coeficiente de Determinacion = "<<calcularCoeficienteDeterminacion(times,estimated_times)<<"\n";
    ------------------------------------------------------------------------------ TERMINA LA PARTE DEL QUICKSORT
*/

/*
---------------------------------------------------------COMIENZA LA PARTE DEL PRODUCTO DE MATRICES*/
    std::vector<vector<double>> v;
    int filas,columnas;
    cout<<"Introduce tamaño de la matriz\n";
    cin>> filas;
    cout<<"-\n";
    cin>>columnas;
    //damos tamaño a la matriz
    v.resize(filas);
    for(int i = 0; i < v.size(); i++){
        v[i].resize(columnas);
    }
    rellenarMatriz(v);

    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout<<"v["<<i<<"]["<<j<<"] = "<<v[i][j]<<"\t";
        }
        cout<<"\n";
    }
    /*----------------------------------------------------TERMINA LA PARTE DEL PRODUCTO DE MATRICES
    */
    return 0;
}