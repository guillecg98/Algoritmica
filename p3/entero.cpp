#include "entero.hpp"

Entero & Entero::operator+(Entero &num){

    int x,y,res;
    bool acarreo = false;
    std::string resultado = "";

    if( this->getNumero().length() > num.getNumero().length() ){
        num.agregarCerosDelante(this->getNumero().length() - num.getNumero().length());
    }
    if( this->getNumero().length() < num.getNumero().length() ){
        this->agregarCerosDelante(num.getNumero().length() - this->getNumero().length());
    }

    //Hacer la suma
    for(int i = this->getNumero().length() - 1; i >= 0; i--){

        x = this->getNumero()[i] - '0';
        y = num.getNumero()[i] - '0';
        std::cerr<<"x = "<<x<<", y = "<<y<<"\n";

        if(!acarreo){
            res = 0;
        }else{
            res = 1;
        }

        if((x + y) < 9){
            res += (x + y);
            acarreo = false;
        }else{
            res += ((x+y) % 10);
            acarreo = true;
        }
        resultado = std::to_string(res) + resultado;
    }

    this->setNumero(resultado);

    return *this;
}

Entero & Entero::operator*(Entero &num){

}

void Entero::agregarCerosDelante(int nCeros){
    for(int i = 0; i < nCeros; i++){
        this->setNumero("0" + this->getNumero());
    }
}