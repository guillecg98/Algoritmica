#include "funcionesAuxiliares.hpp"

/*---------------------------------------------------------------COMIENZA LA PARTE DEL QUICKSORT*/
void quicksort(){
    Clock time;
    string file_name = "DatosQuicksort.txt";
    int max,min,inc,rep,opcion;
    std::vector<int> v;
    double a0,a1,muestra = 1;
    std::vector<double> n,times,estimated_times;

    cout<<"\nIntroduce el tamaño minimo del vector:\n";
    cin>>min;
    v.resize(min);
    cout<<"Introduce el tamaño maximo del vector:\n";
    cin>>max;
    cout<<"Introduce el incremento:\n";
    cin>>inc;
    cout<<"Introduce el numero de repeticiones:\n";
    cin>>rep;
    cout<<"\n";

    while(v.size() <= max){
        n.push_back(min);
        double media = 0;
        cout<<"Para una n = "<<v.size()<<":\n";
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
        cout<<"\n";
        times.push_back(media);
        v.clear();
        min += inc;
        v.resize(min);
    }

    ajusteNlogN(n,times,a0,a1);
    calcularTiemposEstimadosNlogN(n,times,a0,a1,estimated_times);

    if(escribeFichero(n,times,estimated_times,file_name)){
        cout<<"\nSe ha creado el fichero "<<file_name<<" con la muestra, los tiempos reales y los tiempos estimados\n";
    }else{
        cerr<<"Error al escribir en fichero\n";
    }

    cout<<"\nCoeficiente de Determinacion (R2) = "<<calcularCoeficienteDeterminacion(times,estimated_times)<<"\n";

    do{
        cout<<"\nSi desea estimar el tiempo para una muestra mayor pulse 1, sino pulse 0.\n";
        cin>>opcion;
        switch (opcion){
            case 1:
                while(muestra !=0){
                    cout<<"\nIntroduzca el tamaño de la muestra o 0 para salir\n";
                    cin>>muestra;
                    if(muestra != 0){
                        cout<<"El tiempo estimado para "<<muestra<<" elementos es de "<<calculaTiempoEstimado(muestra,a0,a1)<<" dias.\n";
                    }
                }
                break;
            default:
                cout<<"Opcion "<<opcion<<"incorrecta\n";
                break;
        }
    }while(opcion != 0);
}
/*------------------------------------------------------------------------------ TERMINA LA PARTE DEL QUICKSORT*/


/*---------------------------------------------------------COMIENZA LA PARTE DEL PRODUCTO DE MATRICES*/
void productoMatrices(){
    Clock time;
    int max,min,inc,opcion;
    double muestra = 1;
    string file_name = "DatosMatriz.txt";
    std::vector<double> n,a,times,estimated_times;
    std::vector<vector<double>> v,matriz_resultado;

    cout<<"\nIntroduce el tamaño minimo de la matriz:\n";
    cin>>min;
    cout<<"Introduce el tamaño maximo de la matriz:\n";
    cin>>max;
    cout<<"Introduce el incremento:\n";
    cin>>inc;

    //damos tamaño a la matriz
    redimensionaMatriz(v,min);
    redimensionaMatriz(matriz_resultado,min);

    while(v.size() <= max){
        n.push_back(min);
        rellenarMatriz(v);
        cout<<"Para una n = "<<min<<":\n";
        time.start();
        productoMatrices(v,matriz_resultado);
        if(time.isStarted()){
	        time.stop();
        }
        std::cout << "Han pasado " << time.elapsed() << " microsegundos\n";
        times.push_back(time.elapsed());
        min += inc;
        redimensionaMatriz(v,min);
        redimensionaMatriz(matriz_resultado,min);
    }

    ajustePolinomico(n,times,a);
    calcularTiemposEstimadosPolinomio(n,times,a,estimated_times);

    if(escribeFichero(n,times,estimated_times,file_name)){
        cout<<"\nSe ha creado el fichero "<<file_name<<" con la muestra, los tiempos reales y los tiempos estimados\n";
    }else{
        cerr<<"Error al escribir en fichero\n";
    }

    cout<<"\nCoeficiente de Determinacion (R2) = "<<calcularCoeficienteDeterminacion(times,estimated_times)<<"\n";

    do{
        cout<<"\nSi desea estimar el tiempo para una muestra mayor pulse 1, sino pulse 0.\n";
        cin>>opcion;
        switch (opcion){
            case 1:
                while(muestra !=0){
                    cout<<"\nIntroduzca el tamaño de la muestra o 0 para salir\n";
                    cin>>muestra;
                    if(muestra != 0){
                        cout<<"El tiempo estimado para "<<muestra<<" elementos es de "<<calcularTiempoEstimadoPolinomico(muestra,a)<<" dias.\n";
                    }
                }
                break;
            default:
                cout<<"Opcion "<<opcion<<"incorrecta\n";
                break;
        }
    }while(opcion != 0);
}
/*----------------------------------------------------TERMINA LA PARTE DEL PRODUCTO DE MATRICES*/