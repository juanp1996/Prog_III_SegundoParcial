//
// Created by juanp on 9/11/2022.
//
#include "HashMap.h"

void HashMap::NewTable(unsigned int tam) {
    tamanio = tam;
    tabla = new nodo * [tamanio];
    for (int i = 0; i < tamanio; i++){
        tabla[i] = NULL;
    }
}

void HashMap::newNodo(long K, string valor) {
    setPos(K);
    int p = getPos();
    put(p,K,valor);
}

void HashMap::setPos(long K) {
    unsigned int pos =  K % tamanio;
    posicion = pos;
}

int HashMap::getPos(){
    return posicion;
}

void HashMap::put(int pos, long clave, string valor) {
    if (tabla[pos]!=NULL)
    {
        //colicion
        if (clave == tabla[pos]->getClave()){
            tabla[pos]->setOcurrencia(tabla[pos]->getOcurrenciaNodoHash() + 1);
            cout<<"Nueva ocurrencia de: "<<tabla[pos]->getValor()<<" ocurrencias:"<<tabla[pos]->getOcurrenciaNodoHash()<<endl;
            setOcurrenciasTotales(getOcurrenciasTotales()+1);
        }else{
            put(pos+1 , clave , valor);
        }
    }else if (tabla[pos] == NULL){
        tabla[pos] = new nodo(clave , valor, 0);
        tabla[pos]->setOcurrencia(1);
    }
}


void HashMap::excluir(long k){
    setPos(k);
    int i = getPos();
    while (tabla[i] != NULL){
        if (k == tabla[i]->getClave())
        {
            tabla[i]->setOcurrencia(0);
        }
        i++;
    }
}

int HashMap::getOcurrenciasHash(long k) {
    setPos(k);
    int i = getPos();
    while (tabla[i] != NULL){
        if (k == tabla[getPos()]->getClave()) {
            return tabla[getPos()]->getOcurrenciaNodoHash();
        }
        i++;
    }
    return 0;
}


bool HashMap::copiar(long k){
    setPos(k);
    int i = getPos();
    while (tabla[i] != NULL){
        if (k == tabla[getPos()]->getClave()) {
            if (tabla[getPos()]->getFlag()){
                tabla[getPos()]->setFlag(false);
                return true;
            }else
                return tabla[getPos()]->getFlag();
        }else i++;
    }
    return false;
}
void HashMap::setOcurrenciasTotales(int o) {this->ocurrenciasTotales = o;}
int HashMap::getOcurrenciasTotales() { return ocurrenciasTotales;}