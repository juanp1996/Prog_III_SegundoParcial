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
using namespace std;

class txtMng{
private:
    fstream archivo;
    fstream temp;
    string direccion, direccion_temp , lineas, palabra, *caracter , resultado_cp;
    int Cant_lineas, Cant_palabras, Cant_letras;

protected:




public:
    txtMng();
    void ArgMng(int c , char *a);
    void limpiar();
    bool checkCaracter(char p);
    void checkPalabra(string pa , int l);
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


    void basic(string d);
    void ocurrencias();
    void excluir();


};





#endif //PROG_III_SEGUNDOPARCIAL_TXTMNG_H
