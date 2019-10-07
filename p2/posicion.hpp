#ifndef POSICION_HPP
#define POSICION_HPP

#include <iostream>

class Posicion{
    private:
        int x_;
        int y_;

    public:
        Posicion(int x,int y){
            setX(x);
            setY(y);
        }
        inline int getX() {return x_;}
        inline int getY() {return y_;}
        inline void setX(int x) {x_ = x;}
        inline void setY(int y) {y_ = y;}
};

#endif