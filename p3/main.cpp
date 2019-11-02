#include "entero.hpp"

int main(){

    Entero E1("");
    Entero E2("");

    std::cout<<"Introduce el primer numero:\n";
    std::cin>> E1;
    std::cout<<"Introduce el segundo numero:\n";
    std::cin>> E2;

    std::cout<<"Primer sumando = "<<E1<<"\n";
    std::cout<<"Segundo sumando = "<<E2<<"\n";

    E1 + E2;

    std::cout<<"Resultado de la suma = "<<E1<<"\n";


    return 0;
}