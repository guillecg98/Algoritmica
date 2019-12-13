#include "algoritmos.hpp"

bool lugar(Reina k, std::vector<Reina> &reinas){
  for(int i = 0; i < reinas.size(); i++){
      if( (reinas[i].getColumna() == k.getColumna()) || std::abs(reinas[i].getColumna() - k.getColumna()) == std::abs(reinas[i].getFila() - k.getFila()) ){
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

bool nReinasLasVegas(int n, std::vector<Reina> &reinas){
  int contador,random;
  Reina k(0,0);
  std::vector<int> ok;
  ok.resize(n);

  for(int i = 0; i < n; i++){
    contador = 0;
    k.setFila(i);
    for(int j = 0; j < n; j++){
      k.setColumna(j);
      if(lugar(k,reinas)){
        ok[contador] = k.getColumna();
        contador++;
      }
    }
    if(contador == 0){
      return false;
    }
    random = rand()%contador;
    k.setColumna(ok[random]);
    reinas.push_back(k);
  }
  if(contador == 0){
    return false;
  }
  return true;
}