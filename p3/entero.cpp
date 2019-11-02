#include "entero.hpp"

void Entero::agregarCerosDelante(int nCeros){
    for(int i = 0; i < nCeros; i++){
        this->setNumero('0' + this->getNumero());
    }
}

void Entero::agregarCerosFinal(int nCeros){
    for(int i = 0; i < nCeros; i++){
        this->setNumero(this->getNumero()+ '0');
    }
}

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

    for(int i = this->getNumero().length()-1; i >= 0; i--){
        x = this->getNumero()[i] - '0';
        y = num.getNumero()[i] - '0';

        if(!acarreo){
            res = 0;
        }else{
            res = 1;
        }

        if( (res + x + y) < 10 ){
            res += (x + y);
            acarreo = false;
        }else{
            if( i == 0){
                res += x + y;
            }else{
                if( (res + x + y) % 10 == 0 ){//cuando la suma del acarreo más la suma en cuestion da 10, el resultado es 0 y me llevo 1 - ejemplo 125 + 578
                    res = 0;
                    acarreo = true;
                }else{
                    res += ((x + y) % 10);
                    acarreo = true;
                }
            }
        }
        resultado = std::to_string(res) + resultado;
    }
    this->setNumero(resultado);
    return *this;
}

Entero & Entero::operator*(Entero &num){
    int mayor,res;

    if( this->getNumero().length() >= num.getNumero().length() ){
        mayor = this->getNumero().length();
    }else{
        mayor = num.getNumero().length();
    }

    if(mayor <= 4){
        res = stoi(this->getNumero()) * stoi(num.getNumero());
        this->setNumero(std::to_string(res));
        return *this;
    }else{
        //hacer la multiplicacion de enteros grandes
        Entero w(),x(),y(),x();
    }
}

istream &operator>>(istream &stream, Entero &num){
    std::string numero_grande;
    stream >> numero_grande;
    num.setNumero(numero_grande);
    // Se devuelve el flujo de salida
    return stream;
}

ostream &operator<<(ostream &stream, Entero &num){
    stream << num.getNumero();
    return stream;
}