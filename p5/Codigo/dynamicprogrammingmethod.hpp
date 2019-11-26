#ifndef DYNAMIC_PROGRAMMING_HPP
#define DYNAMIC_PROGRAMMING_HPP

#include "algorithm.hpp"

class DynamicProgrammingMethod:public Algorithm
{
private:
    /* data */
public:
    DynamicProgrammingMethod(char * fileName, int numberPointsPolygonalApproximation);
    ~DynamicProgrammingMethod();
    void apply();
    bool exist(int number, std::vector<int> &interestPointsPosition);
};



#endif