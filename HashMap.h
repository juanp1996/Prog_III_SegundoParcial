#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"
#include "cstddef"
#include "iostream"

class HashMap{
private:

    unsigned int tamanio;
    nodo **tabla;
    int ocurrenciasTotales;
    int posicion;

public:

    HashMap();

    void NewTable(unsigned int tam);
    void newNodo(long , string);


    void put(int , long int , string);
    void setPos(long);
    int getPos();
    bool copiar(long k);


    void excluir(long);
    int getOcurrencias(long);
    int getOcurrenciasTotales();
    void setOcurrenciasTotales(int o);
};



void HashMap::NewTable(unsigned int tam) {
        tamanio = tam;
        tabla = new nodo * [tamanio];
        for (int i = 0; i < tamanio; i++){
            tabla[i] = NULL;
        }
}

void HashMap::newNodo(long K, string valor) {
    setPos(K);
    put(getPos(),K,valor);
}

void HashMap::setPos(long K) {
    unsigned int pos =  K % tamanio;
    this->posicion = pos;
}

int HashMap::getPos(){
    return posicion;
}

void HashMap::put(int pos, long clave, string valor) {
    if (tabla[pos]!=NULL)
    {
        //colicion
        if (clave == tabla[pos]->getClave()){
            tabla[pos]->setOcurrencia(tabla[pos]->getOcurrencia()+1);
            setOcurrenciasTotales(getOcurrenciasTotales()+1);
        }else{
            put(pos+1 , clave , valor);
        }
    }
    tabla[pos] = new nodo(clave , valor , 0);
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

int HashMap::getOcurrencias(long k) {
    setPos(k);
    int i = getPos();
    while (tabla[i] != NULL){
        if (k == tabla[getPos()]->getClave()) {
            return tabla[getPos()]->getOcurrencia();
        }
        i++;
    }
    return 0;
}


bool HashMap::copiar(long k){
    bool r;
    setPos(k);
    int i = getPos();
    while (tabla[i] != NULL){
        if (k == tabla[getPos()]->getClave()) {
            if (tabla[getPos()]->getFlag()){
                r = tabla[getPos()]->getFlag();
                tabla[getPos()]->setFlag(false);
                return r;
            }else
                return tabla[getPos()]->getFlag();
        }else i++;
    }
}


void HashMap::setOcurrenciasTotales(int o) {this->ocurrenciasTotales = o;}
int HashMap::getOcurrenciasTotales() { return ocurrenciasTotales;}
#endif // U05_HASH_HASHMAP_HASHMAP_H_