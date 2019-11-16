
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
  std::vector<int> optimalDominantPointsPosition;
  int numberOfIncrement = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() - 1);

  for(int i = 0; i < getDominantPointsPosition().size(); i+numberOfIncrement){
    optimalDominantPointsPosition.push_back(getDominantPointsPosition()[i]);
  }

  setDominantPointsPosition(optimalDominantPointsPosition);
  //ya tenemos el vector con los puntos (sin computar) que nos interesan


  //Algoritmo voraz que busca la posicion más optima de cada punto
  for(int i = 0; i < getDominantPointsPosition().size(); i++){
    sumaErroresTotales.clear();
    if( (i != 0) && (i != getDominantPointsPosition().size()-1) ){
      //hacer todos los puntos desde el [i]
      calculoSumasErroresTotales(sumaErroresTotales,i);
      posicionOptima = encontrarPosicionMenorError(sumaErroresTotales);
    }
  }
}

double GreedyMethod::error(int a, int b){
  return std::abs(getDominantPointsPosition()[a] - getDominantPointsPosition()[b]);
}

void GreedyMethod::calculoSumasErroresTotales(std::vector<double> &sumaErroresTotales,int i){
  for(int j = 0; j < getDominantPointsPosition().size(); j++){
    if(i != j){
      sumaErroresTotales.push_back(
        error(getDominantPointsPosition()[i-1],getDominantPointsPosition()[i]) +
        error(getDominantPointsPosition()[i],getDominantPointsPosition()[i+j])
      );
    }
  }

}

int GreedyMethod::encontrarPosicionMenorError(std::vector<double> &sumaErroresTotales){
   double menorError = sumaErroresTotales[0];
   int pos = 0;
   for(int i = 1; i < sumaErroresTotales.size(); i++){
     if(menorError < sumaErroresTotales[i]){
       menorError = sumaErroresTotales[i];
       pos = i;
     }
   }

   return pos;
}

