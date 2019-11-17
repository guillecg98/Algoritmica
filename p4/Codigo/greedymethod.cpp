
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
  for(int i = 0; i < getDominantPointsPosition().size(); i+increments){
    interestDominantPointsPosition.push_back(getDominantPointsPosition()[i]);
  }


  //Algoritmo voraz que busca la posicion más optima de cada punto
  for(int i = 0; i < interestDominantPointsPosition.size(); i++){
    sumaErroresTotales.clear();
    if( (i != 0) && (i != interestDominantPointsPosition.size()-1) ){
      //hacer todos los puntos desde el [i]
      for(int j = getPositionOfAPoint(interestDominantPointsPosition[i-1])+1; j < getPositionOfAPoint(interestDominantPointsPosition[i+1]); j++){
        sumaErroresTotales.push_back(
          error(interestDominantPointsPosition[i-1],getDominantPointsPosition()[j]) +
          error(getDominantPointsPosition()[j],interestDominantPointsPosition[i+1])
        );
      }
      posicionOptima = encontrarPosicionMenorError(sumaErroresTotales);
      interestDominantPointsPosition[i] = getDominantPointsPosition()[posicionOptima];//sustituimos en
    }
  }
  setDominantPointsPosition(interestDominantPointsPosition);//finalmente seteamos el vector resultado al algoritmo
}

double GreedyMethod::error(int a, int b){
  return std::abs(a - b);
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
   return pos+1; //ya que para mover los puntos empezamos desde el elemento[1] y no desde el [0]
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

