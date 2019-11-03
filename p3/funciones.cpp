#include "funciones.hpp"

void suma(){
    Entero E1,E2,resultado;

    std::cout<<"Introduce el primer numero:\n";
    std::cin>> E1;
    std::cout<<"Introduce el segundo numero:\n";
    std::cin>> E2;

    resultado = E1 + E2;

    std::cout<<"Resultado de la suma = "<<resultado<<"\n";
}

void producto(){
    Entero E1,E2,resultado;

    std::cout<<"Introduce el primer numero:\n";
    std::cin>> E1;
    std::cout<<"Introduce el segundo numero:\n";
    std::cin>> E2;

    resultado = E1 * E2;
    std::cout<<"Resultado del producto = "<<resultado<<"\n";
}