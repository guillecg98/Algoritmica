#include "funcionesAuxiliares.hpp"

void cualquierCasillaInicial(){
    int x = 3;
    int y;
    std::vector<Posicion> vector_pos;
    std::vector<std::vector<Posicion>> matriz_caminos;

    std::cout<<"Introduzca la coordenada 'y' de la octava fila\n";
    std::cin>>y;
    if((y < 1) || (y > 8)){
        std::cerr<<"Error: numeros entre 1 y 8\n";
        exit (-1);
    }

    Posicion p(x,y);

    std::cout<<"Existen "<<calcularCaminos(p.getX(),p.getY(),vector_pos,matriz_caminos)<<" formas de alcanzar la posicion ("<<p.getX()<<","<<p.getY()<<")\n";
    std::cout<<"Los posibles caminos son: \n";

    for(int i = 0; i < matriz_caminos.size(); i++){
        for(int j = 0; j < matriz_caminos[i].size(); j++){
            std::cout<<"("<<matriz_caminos[i][j].getX()<<","<<matriz_caminos[i][j].getY()<<")\t";
        }
        std::cout<<"\n";
    }
}