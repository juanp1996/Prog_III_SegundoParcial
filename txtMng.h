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



protected:



public:
    txtMng();
    void ArgMng(int c , char *a);
    void error(int);
    bool checkFileExt(const string& s);
    void normal(string NombreArchivo);
    void palabras();
    void ocurrencias();
    void excluir();
};





#endif //PROG_III_SEGUNDOPARCIAL_TXTMNG_H
