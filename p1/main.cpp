#include "quicksort.hpp"
//#include "sistemaEcuaciones.hpp"

int main() {

    int max,min,inc,rep;
    double a0,a1;
    Clock time;

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
    escribeFichero(n,times);
    ajusteNlogN(n,times,a0,a1);
    calcularTiemposEstimadosNlogN(n,times,a0,a1,estimated_times);

    for(int i = 0; i<estimated_times.size(); i++){
        cout<<"estimados["<<i<<"] = "<<estimated_times[i]<<"\n";
    }

    cout<<"Coeficiente de Determinacion = "<<calcularCoeficienteDeterminacion(times,estimated_times)<<"\n";

    return 0;
}