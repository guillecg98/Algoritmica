#include "funciones.hpp"

void backtracking(){
    int n;
    std::vector<Reina> reinas;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas: ";
    std::cin>>n;

    nReinasBacktracking(n,reinas,posiciones);
    std::cout << "\nHay " << posiciones.size() << " posibles soluciones, ¿desea mostrar las posiciones? [s/n]: ";
    char c;
    std::cin >> c;
    std::cout<<"\n";
    if(c == 's' or c == 'S'){
        for(int i = 0; i < posiciones.size(); i++){
            for(int j = 0; j < posiciones[i].size(); j++){
                std::cout<<"("<<posiciones[i][j].getFila()+1<<","<<posiciones[i][j].getColumna()+1<<") ";
            }
            std::cout<<"\n";
        }
    }
}

void lasVegas(){
    int n;
    bool exito = false;
    int numIntentos = 1;
    std::vector<Reina> reinas;
    std::cout<<"Introduce el numero de reinas: ";
    std::cin>>n;

    while(!exito){
        reinas.clear();
        exito = nReinasLasVegas(n,reinas);
        numIntentos++;
    }
    std::cout<<"\nSe han necesitado "<<numIntentos<<" intentos para obtener la solucion:\n";
    std::cout<<"\n";
    for(int i = 0; i < reinas.size(); i++){
        std::cout<<"("<<reinas[i].getFila()+1<<","<<reinas[i].getColumna()+1<<")";
    }
    std::cout<<"\n";
}

void tiemposBacktracking(){
    int n;
    Clock time;
    double tiempo, media,a0,a1;
    std::vector<int> x;
    string file_name = "DatosN-Reinas.txt";
    std::vector<Reina> reinas;
    std::vector<double> tiempos;
    std::vector<double> tiempos_estimados;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas: ";
    std::cin>>n;
    std::cout<<"Calculando tiempos...";
    for(int i = 4; i <= n ; i++){
        time.start();
        posiciones.clear();
        nReinasBacktracking(i,reinas,posiciones);
        if(time.isStarted()){
	        time.stop();
            tiempo = time.elapsed();
            media +=time.elapsed();
	    }
        tiempos.push_back(tiempo);
        x.push_back(i);
    }
    std::cout<<"Hecho!\n";
    ajusteFactorial(x,tiempos,a0,a1);
    calcularTiemposEstimadosFactorialN(x,tiempos,a0,a1,tiempos_estimados);

    if(escribeFichero(x,tiempos,tiempos_estimados,file_name)){
        cout<<"\nSe ha creado el fichero "<<file_name<<" con la muestra, los tiempos reales y los tiempos estimados\n";
    }else{
        cerr<<"Error al escribir en fichero\n";
    }

    std::cout<<"\nEcuación del ajuste: t(n) = "<<a0<<" + "<<a1<<" * (!n)\n";

    std::cout<<"Coeficiente de Determinacion (R2) = "<<calcularCoeficienteDeterminacion(tiempos,tiempos_estimados)<<"\n";
    media /= (n-4);
    std::cout<<"El programa ha tardado "<<media<<" microsegundos de media\n";

    std::cout<<"¿Desea estimar el tiempo para un numero N de reinas mayor? [s/n]: ";
    char c;
    std::cin >> c;
    std::cout<<"\n";
    if(c == 's' or c == 'S'){
        std::cout<<"Introduce el numero de reinas:";
        std::cin>>n;
        std::cout<<"El tiempo estimado para "<<n<<" reinas es: "<<calculaTiempoEstimado(n,a0,a1)<<" dias\n";
    }

}