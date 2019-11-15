
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

  std::vector<int> optimalDominantPointsPosition;

  int numberOfIncrement = this->getDominantPointsPosition().size() / (this->getNumberPointsPolygonalApproximation() - 1);
  for(int i = 0; i < this->getDominantPointsPosition().size(); i+numberOfIncrement){
    optimalDominantPointsPosition.push_back(this->getDominantPointsPosition()[i]);
  }
  setDominantPointsPosition(optimalDominantPointsPosition);
  //ya tenemos el vector con los puntos (sin computar) que nos interesan
}

