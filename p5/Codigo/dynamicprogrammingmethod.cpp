#include "dynamicprogrammingmethod.hpp"
#include "digitalcurve.hpp"

DynamicProgrammingMethod::DynamicProgrammingMethod(char * fileName, int numberPointsPolygonalApproximation)
{
    DigitalCurve dc(fileName);
    setOriginalCurve(dc);
    setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

DynamicProgrammingMethod::~DynamicProgrammingMethod()
{
}

void DynamicProgrammingMethod::apply(){
    calculateSummations();

    std::vector<int> interestDominantPointsPosition;//vector en el que en primer lugar guardamos las posiciones de los puntos que nos interesan

    int increments = getDominantPointsPosition().size() / (getNumberPointsPolygonalApproximation() - 1);
    int value = 0;

    for(int i = 0; i < getNumberPointsPolygonalApproximation(); i++){
        interestDominantPointsPosition.push_back(getDominantPointsPosition()[value]);
        value += increments;
    }

    setDominantPointsPosition(interestDominantPointsPosition);

    /*              ALGORITMO                          */




    setDominantPointsPosition(interestDominantPointsPosition);//finalmente seteamos el vector resultado al algoritmo
    //se llama a la funcion encargada de calcular la aproximacion poligonal
    calculatePolygonalApproximation();
}