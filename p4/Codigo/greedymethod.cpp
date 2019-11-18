
#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "greedymethod.hpp"
#include "digitalcurve.hpp"
//#include "heapvectorMasood.hpp"
//#include "nodoMasood.hpp"



using namespace std;

/* Functions for Collinear suppression method */

//Constructor.

GreedyMethod::GreedyMethod(char *fileName, int numberPointsPolygonalApproximation)
{
  //A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);

  //Digital curve as saved as original curve
  setOriginalCurve(dc);

  //Set the number of points of the polygonal approximation
  setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
GreedyMethod::~GreedyMethod()
{
}

void GreedyMethod::apply()
{
  //Completar
  calculateSummations();
  collinearPointsElimination();

  int posicionOptima;
  std::vector<double> sumaErroresTotales;
  std::vector<int> interestDominantPointsPosition;//vector en el que en primer lugar guardamos las posiciones de los puntos que nos interesan

  int increments = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() - 1);
  int value = 0;

  for(int i = 0; i < getNumberPointsPolygonalApproximation(); i++){

    interestDominantPointsPosition.push_back(getDominantPointsPosition()[value]);
    value += increments;
  }

  setDominantPointsPosition(interestDominantPointsPosition);

  std::cerr<<"Vector de Dominantes = \n";
  imprimeVector(getDominantPointsPosition());

  //Algoritmo voraz que busca la posicion más optima de cada punto
  for(int i = 1; i < getDominantPointsPosition().size(); i++){
    double suma = 0;
    double menor = calculateISEValue(getDominantPointsPosition()[i-1],getDominantPointsPosition()[i]) +
                   calculateISEValue(getDominantPointsPosition()[i],getDominantPointsPosition()[i+1]);
    int pos = getDominantPointsPosition()[i];
      //hacer todos los puntos desde el [i]
      for(int j = getDominantPointsPosition()[i-1]; j < getDominantPointsPosition()[i+1]; j++){
        suma = calculateISEValue(getDominantPointsPosition()[i-1],j) + calculateISEValue(j,getDominantPointsPosition()[i+1]);
        if(suma < menor){
          menor = suma;
          pos = j;
        }
      }
      interestDominantPointsPosition[i] = pos;//actualizamos el vector de puntos interesados con la posicion más optima
  }

  std::cerr<<"Vector de Interesados = \n";
  imprimeVector(interestDominantPointsPosition);

  setDominantPointsPosition(interestDominantPointsPosition);//finalmente seteamos el vector resultado al algoritmo
  //se llama a la funcion encargada de calcular la aproximacion poligonal
  calculatePolygonalApproximation();
}

//este metodo se ha codificado para comprobar los vectores
void GreedyMethod::imprimeVector(std::vector<int> vec){
  for(int i = 0; i < vec.size(); i++){
    std::cerr<<"v["<<i+1<<"] = "<<vec[i]<<"\n";
  }
}

int GreedyMethod::getPositionOfAPoint(int value){
  int position = 0;
  for(int i = 0; i < getDominantPointsPosition().size(); i++){
    if(value == getDominantPointsPosition()[i]){
      position = i;
    }
  }
  return position;
}

