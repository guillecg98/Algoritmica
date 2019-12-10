#include "algoritmos.hpp"

bool lugar(Reina k, std::vector<Reina> &reina){
  for(int i = 0; i < reina.size(); i++){
      if( (reina[i].getColumna() == k.getColumna()) || std::abs(reina[i].getColumna() - k.getColumna()) == std::abs(reina[i].getFila() - k.getFila()) ){
          return false;
      }
  }
  return true;
}

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

void nReinasLasVegas(int n, std::vector<Reina> reinas, std::vector<std::vector<Reina>> &posiciones, bool &exito){
  Reina k(0,0);
  srand(time(NULL));
  int contador,random;
  for(int i = 0; i < n; i++){
    contador = 0;
    for(int j = 0; j < n; j++){
      k.setColumna(j);
      if(lugar(k,reinas)){
        contador++;
        reinas.push_back(k);
      }
    }
    random = rand()%contador+1;
    k.setColumna(random);
  }
  if(contador == 0){
      exito = false;
  }else{
    exito = true;
  }
}