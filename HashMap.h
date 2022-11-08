#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"
#include "cstddef"
#include "iostream"

class HashMap{
private:

    unsigned int tamanio;
    nodo **tabla;
//    unsigned int (*hashFuncP)(nodo clave);
    int ocurrenciasTotales;
    int posicion;


public:

    HashMap();

    void NewTable(unsigned int tam);

    void put(int , long int , string);

    bool existe();

    void get(long int);

    bool esVacio();

    void removeOcurrencia(int , long);

    void colicion(long , string );

    void newNodo(long , string);
    void setPos(long);
    int getPos();

    void excluir(long);
    int getOcurrencias(long);
};


void HashMap::NewTable(unsigned int tam) {
        tamanio = tam;
        tabla = new nodo * [tamanio];
        for (int i = 0; i < tamanio; i++)
        {
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
            ocurrenciasTotales++;
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






































/*
template <class K, class K2 ,  class T , class O>
class HashMap {
private:
    HashEntry<K,  K2 ,T ,  O> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMap(unsigned int tam);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    HashMap Cmp( K c1 , K2 c2); //generar 2 claves

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

    void print();


};


template <class K, class T, class O>
HashMap<K, T , O>::HashMap(unsigned int tam)
{
    tamanio = tam;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

template <class K, class T, class O>
HashMap<K, T , O>::HashMap(unsigned int tam, unsigned int (*fp)(K))
{
    tamanio = tam;
    tabla = new HashEntry<K, T > *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

template <class K, class T, class O>
HashMap<K, T, O>::~HashMap()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {
            delete tabla[i];
        }
    }
}

template <class K, class T, class O>
T HashMap<K, T, O>::get(K clave)
{
    unsigned int pos = hashFuncP(clave) % tamanio; //para asegurar que entre en el tamanio de la tabla
    if (tabla[pos] == NULL)
    {
        throw 404;
    }
    if(tabla[pos]->getClave() == clave){
        return tabla[pos]->getValor();
    }else{
        throw 409; //409 porque es una colision
    }
}

template <class K, class T, class O>
void HashMap<K, T, O>::put(K clave, T valor)
{
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] != NULL)
    {
        //Manejar la Colision!!!!!!!
        throw 409;
    }

    tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
}

template <class K, class T, class O>
void HashMap<K, T, O>::remove(K clave) {}

template <class K, class T>
bool HashMap<K, T, O>::esVacio()
{
    for (int i = 0; i < tamanio; i++)
    {
        if (tabla[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

template <class K, class T, class O>
unsigned int HashMap<K, T, O>::hashFunc(K clave)
{
    return (unsigned int)clave;
}

template <class K, class T, class O>
void HashMap<K, T, O>::print()
{

    std::cout << "i"
              << " "
              << "Clave"
              << "\t\t"
              << "Valor" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (int i = 0; i < tamanio; i++)
    {
        std::cout << i << " ";
        if (tabla[i] != NULL)
        {
            std::cout << tabla[i]->getClave() << "\t\t";
            std::cout << tabla[i]->getValor();
        }
        std::cout << std::endl;
    }
}
*/
#endif // U05_HASH_HASHMAP_HASHMAP_H_