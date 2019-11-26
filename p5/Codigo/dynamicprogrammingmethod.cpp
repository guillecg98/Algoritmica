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
    int posAnterior;
    std::vector<int> interestPointsPosition;
    int puntosCurva = getOriginalCurve().getNumberPointsDigitalCurve();
    int puntosAproximacion = getNumberPointsPolygonalApproximation();

    Matrix E(puntosCurva+1,puntosAproximacion+1);
    Matrix Father(puntosCurva+1,puntosAproximacion+1);

    //Rellenamos la primera columna de la matriz de errores con los casos particulares
    for(int m = 1; m < 2; m++){
        E.setElement(1,m,0);
        for(int n = 2; n < puntosCurva; n++){
            E.setElement(n,m,9999);
        }
    }

    /*              ALGORITMO                          */
    for(int m = 2; m <= puntosAproximacion; m++){
        for(int n = 2; n <= puntosCurva; n++){
            min = E.getElement(n,m-1);
            for(int j = m-1; j <= n-1; j++){
                if( (E.getElement(j,m-1) + calculateISEValue(j-1,n-1)) < min){
                min = E.getElement(j,m-1) + calculateISEValue(j-1,n-1);
                posAnterior = j;
                }
            }
            E.setElement(n,m,min);//error minimo
            Father.setElement(n,m,posAnterior);//El valor de j que minimiza la expresion
        }
    }

    int i = Father.getRows()-1;
    int j = Father.getColumns()-1;
    while(Father.getElement(i,j) != 1){
        if( Father.getElement(i,j) == Father.getElement(i-1,j) ){
            i--;
        }else{
            interestPointsPosition.push_back(Father.getElement(i-1,j)-1);
            j --;
        }
    }

    std::cout<<"Tamaño dominantes = "<<interestPointsPosition.size()<<"\n";

    setDominantPointsPosition(interestPointsPosition);//finalmente seteamos el vector resultado al algoritmo
    //se llama a la funcion encargada de calcular la aproximacion poligonal
    calculatePolygonalApproximation();
}