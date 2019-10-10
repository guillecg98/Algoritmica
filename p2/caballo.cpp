#include "caballo.hpp"

int calcularCaminos(int x, int y,std::vector<Posicion> &vector_pos,std::vector<std::vector<Posicion>> &matriz_caminos){
    Posicion p;

    if( (x > 8) || (y > 8)){//casos absurdos
        return 0;
    }
    if( (x < 1) || (y < 1) ){//casos absurdos
        return 0;
    }

    p.setX(x);
    p.setY(y);
    if(!inside(matriz_caminos,p)){
        vector_pos.push_back(p);
    }

    if( x < 2){
        matriz_caminos.push_back(vector_pos);
        //vector_pos.clear();
        return 1;
    }else{
        return calcularCaminos(x-1,y-2,vector_pos, matriz_caminos) + calcularCaminos(x-2,y-1,vector_pos, matriz_caminos) + calcularCaminos(x-2,y+1,vector_pos, matriz_caminos) + calcularCaminos(x-1,y+2,vector_pos, matriz_caminos);
    }
}

bool inside(std::vector<std::vector<Posicion>> &matriz_caminos, Posicion p){
    for(int i = 0; i < matriz_caminos.size(); i++){
        for(int j = 0; j < matriz_caminos[i].size(); j++){
            if( (p.getX() == matriz_caminos[i][j].getX()) && (p.getY() == matriz_caminos[i][j].getY()) ){
                return true;
            }
        }
    }
    return false;
}
