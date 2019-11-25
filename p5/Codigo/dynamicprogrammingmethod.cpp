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

    double min;
    std::vector<int> interestPointsPosition;
    int puntosCurva = getOriginalCurve().getNumberPointsDigitalCurve();
    int puntosAproximacion = getNumberPointsPolygonalApproximation();

    Matrix E(puntosCurva,puntosAproximacion);
    Matrix Father(puntosCurva,puntosAproximacion);

    //Rellenamos la primera columna de la matriz de errores con los casos particulares
    for(int m = 1; m < 2; m++){
        E.setElement(1,m,0);
        for(int n = 2; n < puntosCurva; n++){
            E.setElement(n,m,9999);
        }
    }
    E.printMatrix();
    /*              ALGORITMO                          */
    /*for(int m = 2; m < puntosAproximacion; m++){
        for(int n = 2; n < puntosCurva; n++){
            min = E.getElement(2,1);
            for(int j = m-1; j <= n-1; j++){
                if(){
                min = E[m-1][m-1] + calculateISEValue(j-1,n-1);
                }
            }
            E[n][m] = min;//error minimo
            Father[n][m] = 1;//
        }
    }*/



    setDominantPointsPosition(interestPointsPosition);//finalmente seteamos el vector resultado al algoritmo
    //se llama a la funcion encargada de calcular la aproximacion poligonal
    calculatePolygonalApproximation();
}