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


void palabras () {}


void ocurrencias(){}

bool colicion(){
    return true;
}

void normal(string nombreArchivo){
    fstream archivo;
    archivo.open(nombreArchivo, ios::in);
    vector<string> linea;
    string lineas, palabras, letras;
    int numLineas = 0;
    int numPalabras = 0;
    int numLetras = 0;

    while (getline(archivo, lineas)){ //Primero le mandamos como referencia la primer palabra del archivo y lo almacena en la variable lineas y como aca no pasa ningun delimitador, separa por lineas
        numLineas++; //por eso aca sumamos en el conotador de lineas a medida que hay una nueva.
        linea.clear();//Despues de iterar con la primer linea, el objeto linea va a estar lleno entonces lo vaciamos
        stringstream s(lineas); //declaramos la linea como una cadena de caracteres e iteramos
        while (getline(s, palabras, ' ')){ //iteramos y cada vez que encunetra un espacio, suma la can de palabras
            stringstream p(palabras); //volvemos a hacer lo de arriba pero ahora en palabras y despues letras
            numPalabras++;
            int largo = p.str().size();
            for (int i=0; i<largo; i++){
                numLetras++;
            }
        }
    }
    cout<<"El archivo tiene "<<numLetras<<" letras."<<endl;
    cout<<"El archivo tiene "<<numPalabras<<" palabras."<<endl;
    cout<<"El archivo tiene "<<numLineas<<" lineas."<<endl;


    /* EJEMPLO
    codigo(){
        if(colicion())
    }
    diferentes = numPalabras - 1 ;
    numPalabras
     **/
}



void error(int e){
    switch (e) {
        case 1:
            cout << "Faltan argumentos para operar. Exit code: 1" << endl;
            break;
        case 2:
            cout << "El argumento ingresado es incorrecto. Exit code: 2" << endl;
            break;
    }
}

/* CORROBORA LA TERMINACION .txt DEL ARGUMENTO +*/
bool checkFileExt(const string& s){
    size_t l = s.find('.txt');
    if (l!=string::npos){
        return true;
    }
    return false;
}





#endif //PROG_III_SEGUNDOPARCIAL_TXTMNG_H
