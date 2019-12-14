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

double factorial(double x){
  if(x < 0){
    return 0;
  }else{
    if(x > 1){
      return x*factorial(x-1);
    }else{
      return 1;
    }
  }
}

void ajusteFactorial(const std::vector<double> &tiempos, double &a0, double &a1){
  std::vector<std::vector<double>> A(2, std::vector<double>(2, 0));
  std::vector<std::vector<double>> B(2, std::vector<double>(1, 0));
  std::vector<std::vector<double>> X(2, std::vector<double>(1, 0));
  std::vector<double> z;

  z.resize(tiempos.size());
  for(int i = 0; i < z.size(); i++){
    z[i] = factorial(tiempos[i]);
  }
  //planteamos el sistema para el caso t(n) = a0 + a1 * factorial(n)
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      if( (i == 0) && (j == 0) ){
        A[0][0] = tiempos.size();
      }else{
        A[i][j] = sumatorio(z,tiempos,i+j,0);
      }
    }
    B[i][0] = sumatorio(z,tiempos,i,1);
  }
  //resolvemos el sistema de ecuaciones
  resolverSistemaEcuaciones(A,B,2,X);
  a0 = X[0][0];
  a1 = X[1][0];
}

double sumatorio(std::vector<double> vec1, std::vector<double> vec2, double exp1, double exp2){
    #ifndef NDEBUG
        assert( vec1.size() == vec2.size());
    #endif
    double sum = 0;
    for(int i = 0; i < vec1.size(); i++){
        sum += pow(vec1[i],exp1) * pow(vec2[i],exp2);
    }
    return sum;
}