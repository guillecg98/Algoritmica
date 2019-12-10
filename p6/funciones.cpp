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
    // for(int i = 0; i < posiciones.size(); i++){
    //     for(int j = 0; j < posiciones[i].size(); j++){
    //         std::cout<<"("<<posiciones[i][j].getFila()+1<<","<<posiciones[i][j].getColumna()+1<<") ";
    //     }
    //     std::cout<<"\n";
    //}
}

void lasVegas(){
    int n;
    bool exito = true;
    std::vector<Reina> reinas;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas:";
    std::cin>>n;

    nReinasLasVegas(n,reinas,posiciones,exito);
    if(exito){
    std::cout << "Hay " << posiciones.size() << " posibles combinaciones para su colocación: \n";
    }else{
    std::cout << "No hay posibles combinaciones para su colocación: \n";
    }
    std::cout<<"\n";
    // for(int i = 0; i < posiciones.size(); i++){
    //     for(int j = 0; j < posiciones[i].size(); j++){
    //         std::cout<<"("<<posiciones[i][j].getFila()+1<<","<<posiciones[i][j].getColumna()+1<<") ";
    //     }
    //     std::cout<<"\n";
    // }
}