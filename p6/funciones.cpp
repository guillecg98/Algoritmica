#include "funciones.hpp"

void backtracking(){
    int n;
    std::vector<Reina> reinas;
    std::vector<std::vector<Reina>> posiciones;
    std::cout<<"Introduce el numero de reinas:";
    std::cin>>n;

    nReinasBacktracking(n,reinas,posiciones);
    std::cout << "Hay " << posiciones.size() << " posibles combinaciones para su colocación \n";
}