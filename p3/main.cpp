#include "entero.hpp"

int main(){

    Entero E1("125631024");
    Entero E2("578847294");

    std::cout<<"Primer sumando = "<<E1.getNumero()<<" Longitud: "<<E1.getNumero().length()<<"\n";
    std::cout<<"Segundo sumando = "<<E2.getNumero()<<" Longitud: "<<E2.getNumero().length()<<"\n";

    E1 + E2;

    std::cout<<"Resultado = "<<E1.getNumero()<<"\n";


    return 0;
}