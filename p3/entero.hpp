#ifndef ENTERO_HPP
#define ENTERO_HPP

#include <iostream>
#include <string>
using std::istream;
using std::ostream;

class Entero{
    private:
        std::string _num;

    public:
        inline Entero(std::string num=""){
            this->setNumero(num);
        }
        inline std::string getNumero() { return _num; }
        inline void setNumero(std::string num) { _num = num; }
        Entero & operator+(Entero &num);
        Entero & operator*(Entero &num);
        void agregarCerosDelante(int nCeros);
};

#endif