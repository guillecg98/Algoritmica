#ifndef ENTERO_HPP
#define ENTERO_HPP

#include <iostream>
using std::istream;
using std::ostream;

class Entero {
    private:
        std::string _num;

    public:
    Entero(std::string num=""){
        this->setNumero(num);
    }

    inline std::string getNumero() { return this->_num; }
    inline void setNumero(std::string num) { this->_num = num; }
    Entero operator*(std::string num);
};

#endif