
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
    //si la curva es cerrada, quitamos un punto de la aproximacion poligonal
    if(getOriginalCurve().isClosed()){
        setNumberPointsPolygonalApproximation(getNumberPointsPolygonalApproximation() -1);
    }
    //calculamos el tamaño del paso. tamaño del vector de dominantes entre (numero de puntos de la aproximacion - 1)
    int paso = (getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() -1));
    //Rellenamos el nuevo vector de dominantes cumpliendo con los pasos
    std::vector<int> nuevosDominantes;
    for(int i = 0; i < getDominantPointsPosition().size(); i+=paso){
        nuevosDominantes.push_back(getDominantPointsPosition()[i]);
    }
    //si el ultimo de dominantes y el ultimo de nuevos dominantes no son el mismo, forzamos a que lo sea
    if(nuevosDominantes.back() != getDominantPointsPosition().back()){
        nuevosDominantes.push_back(getDominantPointsPosition().back());
    }
    //Algoritmo:
    int nuevoPunto = 0;
    float minError,error;
    for(int i = 1; i < getNumberPointsPolygonalApproximation(); i++){
        minError = 9999;
        for(int j = nuevosDominantes[i-1] + 1; j <= nuevosDominantes[i+1]; j++){
            error = calculateISEValue(nuevosDominantes[i-1],j) + calculateISEValue(j,nuevosDominantes[i+1]);
            if(error < minError){
                minError = error;
                nuevoPunto = j;
            }
        }
        nuevosDominantes[i] = nuevoPunto;
    }

    //insertamos el nuevo vector de dominantes en  el vector de dominantPoints
    setDominantPointsPosition(nuevosDominantes);
    calculatePolygonalApproximation();
}

