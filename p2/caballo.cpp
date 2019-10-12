#include "caballo.hpp"

int calcularCaminosFinalInicio(int x, int y, std::vector<Posicion> vector_pos, std::vector<std::vector<Posicion>> &matriz_caminos){

    if( (x > 8) || (y > 8)){//casos absurdos
        return 0;
    }
    if( (x < 1) || (y < 1) ){//casos absurdos
        return 0;
    }

    Posicion p;
    p.setX(x);
    p.setY(y);
    vector_pos.push_back(p);

    if( x < 2){
        matriz_caminos.push_back(vector_pos);
        return 1;
    }else{
        return calcularCaminosFinalInicio(x-1,y-2,vector_pos,matriz_caminos) + calcularCaminosFinalInicio(x-2,y-1,vector_pos,matriz_caminos) + calcularCaminosFinalInicio(x-2,y+1,vector_pos,matriz_caminos) + calcularCaminosFinalInicio(x-1,y+2,vector_pos,matriz_caminos);
    }
}

int calcularCaminosInicioFin(int x, int y,std::vector<Posicion> vector_pos, std::vector<std::vector<Posicion>> &matriz_caminos){

    if( (x > 8) || (y > 8)){//casos absurdos
        return 0;
    }
    if( (x < 1) || (y < 1) ){//casos absurdos
        return 0;
    }

    Posicion p;
    p.setX(x);
    p.setY(y);
    vector_pos.push_back(p);

    if( x > 7){
        matriz_caminos.push_back(vector_pos);
        return 1;
    }else{
        return calcularCaminosInicioFin(x+1,y-2,vector_pos,matriz_caminos) + calcularCaminosInicioFin(x+2,y-1,vector_pos,matriz_caminos) + calcularCaminosInicioFin(x+2,y+1,vector_pos,matriz_caminos) + calcularCaminosInicioFin(x+1,y+2,vector_pos,matriz_caminos);
    }
}