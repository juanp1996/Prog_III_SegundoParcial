#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"
#include "cstddef"
#include "iostream"

class HashMap{
private:

    unsigned int tamanio = 0;
    nodo **tabla;
    int ocurrenciasTotales = 0;
    int posicion ;

public:

    HashMap(){};

    void NewTable(unsigned int tam);
    void newNodo(long , string);


    void put(int , long int , string);
    void setPos(long);
    int getPos();
    bool copiar(long k);
    bool existe(long );


    void excluir(long);
    int getOcurrenciasHash(long);
    int getOcurrenciasTotales();
    void setOcurrenciasTotales(int o);
};

#endif // U05_HASH_HASHMAP_HASHMAP_H_