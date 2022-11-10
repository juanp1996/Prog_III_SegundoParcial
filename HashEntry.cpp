//
// Created by juanp on 9/11/2022.
//
#include "HashEntry.h"

nodo::nodo() {}

nodo::nodo(long int clave , string valor , int ocurrencias){
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

long nodo::djb2(string pa , int s){
    unsigned long int k;
    char p[s];
    strcpy(p,pa.c_str());
    k = 5381;
    for (int i = 0; i <= s ; ++i) {
        k=((k << 5) + k ) + int(p[i]);
    }
    if (k < 0){
        k = k * (-1);
    }
    return k;
}
