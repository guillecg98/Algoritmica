#include "entero.hpp"

void Entero::agregarCerosDelante(int nCeros){
    for(int i = 0; i < nCeros; i++){
        this->setNumero('0' + this->getNumero());
    }
}

void Entero::agregarCerosFinal(int nCeros){
    for(int i = 0; i < nCeros; i++){
        this->setNumero(this->getNumero()+ '0');
    }
}

void Entero::quitarCerosNoSignificativos(){
    int numero_ceros = 0;
    for(int i = 0; i<this->getNumero().length()-1; i++){
        if(this->getNumero()[i] == '0'){
            numero_ceros++;
        }else{
            break;
        }
    }
   this->setNumero(this->getNumero().substr(numero_ceros));
}

void Entero::partirCadena(Entero &a, Entero &b){
    int mitad;
    if(this->getNumero().length() % 2 == 0){//si es par las mitades serán iguales
        mitad = this->getNumero().length()/2;
        a.setNumero(this->getNumero().substr(0,mitad));
        b.setNumero(this->getNumero().substr(mitad));
    }else{//si la longitud no es par, la primera mitad es la mas significativa
        mitad = (this->getNumero().length() + 1) / 2;
        a.setNumero(this->getNumero().substr(0,mitad));
        b.setNumero(this->getNumero().substr(mitad));
    }
}

Entero Entero::multiplicarPotencia10(int potencia){
	this->agregarCerosFinal(potencia);
	return *this;
}

Entero Entero::operator+(Entero num){
    int x,y,res;
    bool acarreo = false;
    std::string resultado = "";

    if( this->getNumero().length() > num.getNumero().length() ){
        num.agregarCerosDelante(this->getNumero().length() - num.getNumero().length());
    }
    if( this->getNumero().length() < num.getNumero().length() ){
        this->agregarCerosDelante(num.getNumero().length() - this->getNumero().length());
    }

    for(int i = this->getNumero().length()-1; i >= 0; i--){
        x = this->getNumero()[i] - '0';
        y = num.getNumero()[i] - '0';

        if(!acarreo){
            res = 0;
        }else{
            res = 1;
        }

        if( (res + x + y) < 10 ){
            res += (x + y);
            acarreo = false;
        }else{
            if( i == 0){
                res += x + y;
            }else{
                if( (res + x + y) % 10 == 0 ){//cuando la suma del acarreo más la suma en cuestion da 10, el resultado es 0 y me llevo 1 - ejemplo 125 + 578
                    res = 0;
                    acarreo = true;
                }else{
                    res += ((x + y) % 10);
                    acarreo = true;
                }
            }
        }
        resultado = std::to_string(res) + resultado;
    }
    this->setNumero(resultado);
    return *this;
}

Entero Entero::operator*(Entero num){
    int tamanio_mayor;

    if( this->getNumero().length() >= num.getNumero().length() ){
        tamanio_mayor = this->getNumero().length();
    }else{
        tamanio_mayor = num.getNumero().length();
    }
    if(tamanio_mayor <= 4){//caso base, multiplicacion normal de enteros de 4 digitos o menos
        int resultado = stoi(this->getNumero()) * stoi(num.getNumero());
        return Entero(std::to_string(resultado));
    }else{
        Entero w,x,y,z;
        int s = tamanio_mayor / 2;
        //Igualamos los enteros grandes añadiendo ceros no significativos
        if( this->getNumero().length() > num.getNumero().length() ){
            num.agregarCerosDelante(this->getNumero().length() - num.getNumero().length());
        }
        if( this->getNumero().length() < num.getNumero().length() ){
            this->agregarCerosDelante(num.getNumero().length() - this->getNumero().length());
        }

        this->partirCadena(w,x);
        w.quitarCerosNoSignificativos();
        x.quitarCerosNoSignificativos();

        num.partirCadena(y,z);
        y.quitarCerosNoSignificativos();
        z.quitarCerosNoSignificativos();

        return (w*y).multiplicarPotencia10(2*s) + ((w*z) + (x*y)).multiplicarPotencia10(s) + (x*z);
    }
}

istream &operator>>(istream &stream, Entero &num){
    std::string numero_grande;
    stream >> numero_grande;
    num.setNumero(numero_grande);
    // Se devuelve el flujo de salida
    return stream;
}

ostream &operator<<(ostream &stream, Entero &num){
    stream << num.getNumero();
    return stream;
}