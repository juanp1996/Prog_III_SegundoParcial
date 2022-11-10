//
// Created by juanp on 9/11/2022.
//
#include "HashEntry.h"
#include "iostream"
nodo::nodo() {}

nodo::nodo(long long clave , string valor , int ocurrencias){
    setClave(clave);
    setValor(valor);
    setOcurrencia(ocurrencias);
}

long long nodo::getClave(){
    return clave;
}

void nodo::setClave(long long clave){
    this->clave = clave;
}

string nodo::getValor(){
    return valor;
}

bool nodo::getFlag(){
    return flag;
}
void nodo::setFlag(bool f){
    this->flag = f;
}

void nodo::setValor(string valor){
    this->valor = valor;
}

void nodo::setOcurrencia(int o){
    this->ocurrencias = o;
}
int nodo::getOcurrenciaNodoHash(){
    return ocurrencias;
}

long long nodo::djb2(string pa , int s){
    unsigned long long k;
    int c;
    k = 5381;
    for (auto x:pa) {
        c = x;
        k=((k << 5) + k ) + c;
    }
    return k/3;
}
