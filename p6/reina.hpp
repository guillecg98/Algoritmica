#ifndef REINA_HPP
#define REINA_HPP

class Reina{

    private:
        int fila_;
        int columna_;
    public:
        Reina(int fila, int columna){
            this->setFila(fila);
            this->setColumna(columna);
        }
        int getFila() { return this->fila_; }
        int getColumna() { return this->columna_; }
        void setFila(int fila) { this->fila_ = fila; }
        void setColumna(int columna) { this->columna_ = columna; }
};

#endif