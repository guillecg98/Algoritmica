
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
    calculateSummations();
    collinearPointsElimination();

    if(getOriginalCurve().isClosed()){
        setNumberPointsPolygonalApproximation(getNumberPointsPolygonalApproximation()-1);
    }
    int paso = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() -1);

    std::vector<int> nuevosDominantes;
    for(int i = 0; i < getDominantPointsPosition().size(); i+=paso){
        nuevosDominantes.push_back(getDominantPointsPosition()[i]);
    }

    if(nuevosDominantes.back() != getDominantPointsPosition().back()){
        nuevosDominantes.push_back(getDominantPointsPosition().back());
    }

    int nuevo = 0;
    float minError, error;
    for(int i = 1; i < getNumberPointsPolygonalApproximation(); i++){
        minError = 9999;
        for(int j = nuevosDominantes[i-1]+1; j <= nuevosDominantes[i+1]; j++){
            error = calculateISEValue(nuevosDominantes[i-1],j) + calculateISEValue(j,nuevosDominantes[i+1]);
            if(error < minError){
                minError = error;
                nuevo = j;
            }
        }
        nuevosDominantes[i] = nuevo;
    }
    setDominantPointsPosition(nuevosDominantes);
    calculatePolygonalApproximation();
}

