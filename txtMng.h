//
// Created by juanp on 1/11/2022.
//

#ifndef PROG_III_SEGUNDOPARCIAL_TXTMNG_H
#define PROG_III_SEGUNDOPARCIAL_TXTMNG_H
#include <fstream>
#include "HashMap.h"
#include "lista.h"

using namespace std;

class txtMng{
private:
    ifstream archivo;
    ifstream exc;
    string direccion, direccion_temp , lineas, palabra, resultado_cp;
    int Cant_lineas = 0, Cant_palabras = 0, Cant_letras = 0, Cant_diferentes;
    int longitud;
    int posicion;


protected:

public:
    void primerPasada();
    bool checkCaracter(char p);
    bool checkUltimoCaracter(char p);
    void esMayuscula(int i);
    void checkPalabra();
    void error(int);
    void openFile(string d);
    void setCantLineas();
    int getCantLineas();
    void setCantPalabras();
    int getCantPalabras();
    void setCantLetras();
    int getCantLetras();
    void setCaracter(string *p);
    string getCaracter();

    string getPalabra();
    void setLong(int l);
    int getLong();
    void setPalabra(string p);

    nodo nodo;
    HashMap HashMap;
    Lista <string> lista;
    Lista <string> lista_2;
    Lista <string> liEx;
    char *aux;
    string auxiliar;



    void basic();
    void palabras(int);
    void ocurrencias(int);
    void excluir(string,int );
    void mostrar(string);
    void print(string);



    void bubbleSort(string *, int );
    void bubbleAlfabetico(string *, int);
};

#endif //PROG_III_SEGUNDOPARCIAL_TXTMNG_H