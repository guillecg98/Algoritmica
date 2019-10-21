#include "entero.hpp"

Entero &operator*(std::string prod){

    std::string mayor;

    if(this->getProd().length() >= prod.length()){
        mayor = this->getProd();
    }else{
        mayor = prod;
    }

    if(mayor.length() <= 4){
        return this->getProd() * prod;
    }
}