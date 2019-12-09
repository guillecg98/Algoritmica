#include "algoritmos.hpp"

void nReinasBacktracking(int n, std::vector<Reina> reinas, std::vector<std::vector<Reina>> &posiciones){
  Reina k(0,0);
  while(k.getFila() >= 0){
    if(k.getFila() == n){
      posiciones.push_back(reinas);
      k.setFila(k.getFila()-1);
      k.setColumna(reinas[k.getFila()].getColumna() + 1);
      reinas.erase(reinas.begin() + k.getFila());
    }
    while( (k.getColumna() < n) && (!lugar(k, reinas)) ){
        k.setColumna(k.getColumna()+1);
    }
    if(k.getColumna() < n){
      reinas.push_back(k);
      k.setFila(k.getFila()+1);
      k.setColumna(0);
    }else{
      k.setFila(k.getFila()-1);
      if(k.getFila() >= 0){
        k.setColumna(reinas[k.getFila()].getColumna() + 1);
        reinas.erase(reinas.begin() + k.getFila());
      }
    }
  }
}

bool lugar(Reina k, std::vector<Reina> &reina){
for(int i = 0; i < reina.size(); i++){
    if( (reina[i].getColumna() == k.getColumna()) || std::abs(reina[i].getColumna() - k.getColumna()) == std::abs(reina[i].getFila() - k.getFila()) ){
        return false;
    }
}
return true;
}