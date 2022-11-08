//
// Created by juanp on 1/11/2022.
//

#ifndef PROG_III_SEGUNDOPARCIAL_TXTMNG_H
#define PROG_III_SEGUNDOPARCIAL_TXTMNG_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include "HashMap.h"
#include "lista.h"

using namespace std;

class txtMng{
private:
    fstream archivo;
    fstream temp;
    string direccion, direccion_temp , lineas, palabra, resultado_cp;
    int Cant_lineas, Cant_palabras, Cant_letras, Cant_diferentes;
    int longitud;
    int posicion;


protected:

public:
    txtMng();
    void ArgMng(int c , char *a);
    void primerPasada();
    void limpiar();
    bool checkPrimerCaracter(char p);
    bool checkUltimoCaracter(char p);
    void esMayuscula(int i);
    void checkPalabra();
    void error(int);
    bool checkFileExt(const string& s);
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
    Lista <string> aux;



    void basic(string d);
    void palabras(int , string);
    void ocurrencias(int , string);
    void excluir();
    void mostrar(string);
    void print(string);






    void quickSort(Lista<string>, int, int);
    bool StrCmp(string,string);
    int MinLen(string , string);



};





#endif //PROG_III_SEGUNDOPARCIAL_TXTMNG_H