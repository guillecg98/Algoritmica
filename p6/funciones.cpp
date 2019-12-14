#include "funciones.hpp"

void backtracking(){
    int n;
    std::vector<Reina> reinas;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas:";
    std::cin>>n;

    nReinasBacktracking(n,reinas,posiciones);
    std::cout << "Hay " << posiciones.size() << " posibles combinaciones para su colocación: \n";
    std::cout<<"\n";
    for(int i = 0; i < posiciones.size(); i++){
        for(int j = 0; j < posiciones[i].size(); j++){
        std::cout<<"("<<posiciones[i][j].getFila()+1<<","<<posiciones[i][j].getColumna()+1<<") ";
        }
        std::cout<<"\n";
    }
}

void lasVegas(){
    int n;
    bool exito = false;
    int numIntentos = 1;
    std::vector<Reina> reinas;
    std::cout<<"Introduce el numero de reinas:";
    std::cin>>n;

    while(!exito){
        reinas.clear();
        exito = nReinasLasVegas(n,reinas);
        numIntentos++;
    }
    std::cout<<"Se han necesitado "<<numIntentos<<" intentos para resolver la solucion:\n";
    for(int i = 0; i < reinas.size(); i++){
        std::cout<<"("<<reinas[i].getFila()+1<<","<<reinas[i].getColumna()+1<<")";
    }
    std::cout<<"\n";
}

void tiemposBacktracking(){
    Clock time;
    double tiempo, media;
    int n,ejecuciones;
    std::vector<Reina> reinas;
    std::vector<double> tiempos;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas:";
    std::cin>>n;
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
    }
    media /= (n-4);
    std::cout<<"El programa ha tardado "<<media<<" microsegundos de media\n";
    for(int i = 0; i < tiempos.size(); i++){
        std::cout<<"tiempo "<<i+1<<" = "<<tiempos[i]<<"\n";
    }
}