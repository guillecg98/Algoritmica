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
        inline std::string getNumero() const { return _num; }
        inline void setNumero(std::string num) { _num = num; }
        void agregarCerosDelante (int nCeros);
        void agregarCerosFinal(int nCeros);
        void quitarCerosNoSignificativos();
        void partirCadena(Entero &a, Entero &b);
        Entero multiplicarPotencia10(int potencia);
        Entero operator+(Entero num);
        Entero operator*(Entero num);
};

istream &operator>>(istream &stream, Entero &num);
ostream &operator<<(ostream &stream, Entero &num);

#endif