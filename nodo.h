//
// Created by juanp on 7/11/2022.
//

#ifndef PROG_III_SEGUNDOPARCIAL_NODO_H
#define PROG_III_SEGUNDOPARCIAL_NODO_H


template<class T>
class Nodo{
private:
    T dato;
    int ocurrencias;
    Nodo<T> *siguiente;

public:
    T getDato(){
        return dato;
    }

    void setDato(T d){
        dato = d;
    }
    int getOcurrencias(){
        return ocurrencias;
    }
    void setOcurrencias(int c){
        ocurrencias = c;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }
};



#endif //PROG_III_SEGUNDOPARCIAL_NODO_H
