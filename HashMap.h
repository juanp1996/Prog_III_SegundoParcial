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

    HashMap(){};

    void NewTable(unsigned int tam);
    void newNodo(long , string);


    void put(int , long int , string);
    void setPos(long);
    int getPos();
    bool copiar(long k);


    void excluir(long);
    int getOcurrenciasHash(long);
    int getOcurrenciasTotales();
    void setOcurrenciasTotales(int o);
};

#endif // U05_HASH_HASHMAP_HASHMAP_H_