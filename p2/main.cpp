#include "posicion.hpp"
#include <vector>

int calcularCaminos(int x, int y);

int main(){

    int x = 5;
    int y;
    int cont = 0;
    std::vector<Posicion> vector_pos;

    std::cout<<"Introduzca la coordenada 'y' de la octava fila\n";
    std::cin>>y;
    if((y < 1) || (y > 8)){
        std::cerr<<"Error: numeros entre 1 y 8\n";
        return 0;
    }

    Posicion p(x,y);

    std::cout<<"Existen "<<calcularCaminos(p.getX(),p.getY())<<" formas de alcanzar la posicion ("<<p.getX()<<","<<p.getY()<<")\n";


    return 0;
}

int calcularCaminos(int x, int y){

    if( (x > 8) || (y > 8)){
        return 0;
    }else{
        if( (x < 1) || (y < 1) ){
            return 0;
        }else{
            if( x < 2){
                return 1;
            }else{
                return calcularCaminos(x-1,y-2) + calcularCaminos(x-2,y-1) + calcularCaminos(x-2,y+1) + calcularCaminos(x-1,y+2);
            }
        }
    }

    //casos base
    /*if(p.getX() == 0){
        return 0;
    }
    if(p.getX() < 2){
        if( (p.getY() == 0) || (p.getY() == 1) || (p.getY() == 6) || (p.getY() == 7) ){
            return numero_caminos + 1;
        }else{
            return numero_caminos + 2;
        }
    }

    //ejecucion
    if( (p.getY() == 8) || (p.getY() == 0) ){
        return calcularCaminos(p.setX(p.getX() - 1) p.setY(),numero_caminos + 2) + calcularCaminos(p.setX())
    }
    if( (p.getY() == 1) || (p.getY() == 7) ){
        numero_caminos += 3;
    }
    if( (p.getY() > 1) && (p.getY() < 7) ){
        numero_caminos += 4;
    }

    p.setX(p.getX() - 1);
    p.setY(p.getY())
    return calcularCaminos(p,numero_caminos);*/
}