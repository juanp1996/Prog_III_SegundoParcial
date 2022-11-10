//
// Created by juanp on 1/11/2022.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include "txtMng.h"

using namespace std;

// abrimos el archivo y lo preparamos para trabajarlo
void txtMng::openFile(string d)
{
    archivo.open(d, ios::in);
    if (!archivo)    // si no abre alguno de los 2 archivos, mandamos error
    {
        error(3);
    }
    else
    {
        primerPasada();
    }
}

void txtMng::primerPasada() {
    while (!archivo.eof()){
        getline(archivo, lineas);
        Cant_lineas++;
        stringstream s(lineas);
        while (getline(s, palabra, ' '))
        {
            stringstream p(palabra);
            Cant_palabras++;
            setLong(palabra.length());
            setPalabra(palabra);
            checkPalabra();
            lista.insertarPrimero(palabra);
        }
    }
    HashMap.NewTable(Cant_palabras*20); //TAMAÑO DE LA TABLA * 20
    archivo.close();
    int pos = 0;

    while(pos < lista.getTamanio()) {
        HashMap.newNodo(nodo.djb2(lista.getDato(pos), lista.getDato(pos).length()), lista.getDato(pos));
        pos++;
    }
    cout<<"Termino primera pasada"<<endl;
}

// checkea/corrige comienzo y fin de palabra recursivamente , si esta mal corrige
void txtMng::checkPalabra()
{
    cout<<"Entro a check palabras"<<endl;
    int l = getLong() - 1;
    string palabra_aux;
    char palabra_char[l];
    strcpy(palabra_char, getPalabra().c_str());
    if (checkPrimerCaracter(palabra_char[0]))
    {
        if (checkPrimerCaracter(palabra_char[l]))
        {
            Cant_letras = Cant_letras + getPalabra().length(); // voy sumando cantidad de letras
        }
        else /*esta mal el final**/
        {
            for (int i = 0; i < l; ++i)
            {
                palabra_aux.push_back(palabra_char[i]);
            }
            setPalabra(palabra_aux);
            setLong(getLong() - 1);
            checkPalabra();
        }
    }
    else //esta mal la primera
    {
        for (int i = 1; i <= l; ++i)
        {
            palabra_aux.push_back(palabra_char[i]);
        }
        setPalabra(palabra_aux);
        setLong(getLong() - 1);
        checkPalabra();
    }
}

// si devuelve true es una letra
bool txtMng::checkPrimerCaracter(char p)
{
    if (int(p) >= 97 && int(p) <= 122) // chequeo si es una letra (ASCII entre 97 y 122)
    {
        return true;
    }
    else if ((int(p) + 32) >= 97 && (int(p) + 32) <= 122 || int(p)==181 || int(p)==144 || int(p)==214 || int(p)==224 || int(p)==233)
    { // chequeo si es una letra mayuscula (ASCII entre 65 y 90)
        esMayuscula(posicion);
        posicion = 0;
        return true;
    }
    else if (int(p) >= 160 && int(p) <= 163 || int(p) == 130)    //ACENTOS
    {
        return true;
    }
    else
        return false;
}

bool txtMng::checkUltimoCaracter(char p){  //DIFERENCIAMOS PRIMER CARACTER DEL ULTIMO EN LA BUSQUEDA DE MAYUSCULAS. CHECKULTI NO BUSCA MAYUSCULAS
    if (int(p) >= 97 && int(p) <= 122) // chequeo si es una letra (ASCII entre 97 y 122)
    {
        return true;
    }
    else if (int(p) >= 160 && int(p) <= 163 || int(p) == 130)    //ACENTOS
    {
        return true;
    }
    else
        return false;  //EN CASO DE DEVOLVER FALSE SE ELIMINA EL CARACTER
}


void txtMng::esMayuscula(int i)
{
    char palabra_char[getLong() - 1];
    string palabra_aux;
    strcpy(palabra_char, getPalabra().c_str());
    palabra_char[i] = tolower(palabra_char[i]);
    for (int i = 0; i < getLong(); ++i)
    {
        palabra_aux.push_back(palabra_char[i]);
    }
    setPalabra(palabra_aux);
    posicion++;
    checkPrimerCaracter(palabra_char[posicion]);
}

void txtMng::error(int e)
{
    switch (e)
    {
        case 1:
            cout << "Faltan argumentos para operar. Exit code: 1" << endl;
            break;
        case 2:
            cout << "El argumento ingresado es incorrecto. Exit code: 2" << endl;
            break;
        case 3:
            cout << "ERROR al querer abrir el archivo. Exit code: 3" << endl;
            break;
    }
}


/*
 * SET / GET
 */

int txtMng::getCantLineas() { return Cant_lineas; }
int txtMng::getCantPalabras() { return Cant_palabras; }
int txtMng::getCantLetras() { return Cant_letras; }

string txtMng::getPalabra() { return palabra; }
int txtMng::getLong() { return longitud; }

void txtMng::setLong(int i)
{
    longitud = i;
}
void txtMng::setPalabra(string p)
{
    palabra = p;
}



/*
 *  METODOS PARA LOS ARGUMENTOS
 */

void txtMng::basic()
{
    cout<<"Cantidad de lineas: "<< getCantLineas()<<endl;
    cout<<"Cantidad de palabras: "<<getCantPalabras()<<endl;
    cout<<"Cantidad de letras: "<<getCantLetras()<<endl;
    cout<<"Cantidad de palabras diferentes: "<<getCantPalabras()-HashMap.getOcurrenciasTotales()<<endl;
}

void txtMng::palabras(int c){
    int j = 0;
    string array[getCantPalabras() - HashMap.getOcurrenciasTotales()];
    int tamLista = lista.getTamanio();
    for (int i = 0; i < tamLista ; ++i) {
        if (HashMap.copiar(nodo.djb2(lista.getDato(i), lista.getDato(i).length()))){
            array[j] = lista.getDato(i);
            lista_2.insertarPrimero(lista.getDato(i));
            j++;
        }
    }
    int tamL2=lista_2.getTamanio();
    bubbleAlfabetico(array, tamL2);
    if (c>0){
        for (int j = 0; j < c; j++) {
            print(array[j]);
        }
    }else {
        for (int i=0; i<= tamL2; i++){
            print(array[i]);
        }
    }
}

void txtMng::ocurrencias(int c) {
    cout<<"Entro a ocurrencias"<<endl;
    int j = 0;
    string array[getCantPalabras() - HashMap.getOcurrenciasTotales()];
    int tamLista = lista.getTamanio();
    for (int i = 0; i < tamLista; ++i) {
        cout<<"Dato: "<<i<<": "<<lista.getDato(i)<<endl;
        if (HashMap.copiar(nodo.djb2(lista.getDato(i), lista.getDato(i).length()))) {
            cout<<"true"<<endl;
            array[j] = lista.getDato(i);
            lista_2.insertarPrimero(lista.getDato(i));
            cout<<"Copio la palabra"<<endl;
            j++;
        }
    }
    int tamL2=lista_2.getTamanio();
    for (int i=0 ; i<tamL2; i++){
        array[i] = lista_2.getDato(i);
    }
    bubbleSort(array, tamL2);
    if (c>0){
        for (int j = tamL2; j>tamL2 - c - 1; j--) {
            print(array[j]);
           }
    }else {
        for (int i=0; i<=tamL2; i++){
            print(array[i]);
        }
    }
}


void txtMng::excluir(string Ex, int con) {
        exc.open(Ex, ios::in);// archivo de lectura
        if (!exc)         // si no abre alguno de los 2 archivos, mandamos error
        {
            cout<<"No es un archivo"<<endl;
            stringstream excluir(Ex);
            cout<<Ex<<endl;
            while (getline(excluir,palabra,','))
            {
                cout<<palabra<<endl;
                checkPalabra();
                cout<<palabra<<endl;
                stringstream p(palabra);
                liEx.insertarPrimero(getPalabra());
            }
            cout<<endl;
            liEx.print();
        }
        else
        {
            while (!exc.eof()) {
                getline(exc, lineas);
                stringstream s(lineas);
                while (getline(s, palabra, ' ')) {
                    stringstream p(palabra);
                    checkPalabra();
                    liEx.insertarPrimero(getPalabra());
                }
            }
        }
        for (int i = 0; i < liEx.getTamanio(); ++i) {
            HashMap.copiar(nodo.djb2(liEx.getDato(i),liEx.getDato(i).length()));
        }
        if(con==1){
            palabras(0);
        }else{
            ocurrencias(0);
        }
}


void txtMng::mostrar(string str_argv) {
    int j = 0;
    string array[getCantPalabras() - HashMap.getOcurrenciasTotales()];
    stringstream s( str_argv);
    while (getline(s,palabra,','))
    {
        cout<<palabra<<endl;
        checkPalabra();
        stringstream p(palabra);
        lista_2.insertarPrimero(palabra);
        cout<<lista_2.getDato(0)<<endl;
    }
    lista_2.print();
    for (int i = 0; i < lista_2.getTamanio(); ++i) {
        if (HashMap.existe(nodo.djb2(lista_2.getDato(i), lista_2.getDato(i).length()))) {
            cout<<"true"<<endl;
            array[j] = lista_2.getDato(i);
            cout<<"Copio la palabra: "<<lista_2.getDato(i)<<endl;
            j++;
            cout<<"j: "<<j<<endl;
        } else{
            cout<<"La palabra "<<lista_2.getDato(i)<<" no esta en el texto"<<endl;
        }
    }
    bubbleSort(array, j);
    for (int i = j; i>=0; i--) {
        print(array[i]);
    }
}

void txtMng::print(string p){
    cout<<p<<endl;
}

void txtMng::bubbleSort(string *array, int tam) {
        string aux;
        bool seguir = true;
        for (int i = 0; i < tam - 1 && seguir; i++)
        {
            seguir = false;
            for (int j = 0; j < tam - i - 1; j++)
            {
                if (HashMap.getOcurrenciasHash(nodo.djb2(array[j], array[j].length())) > HashMap.getOcurrenciasHash(nodo.djb2(array[j+1], array[j+1].length())))
                {
                    seguir = true;
                    aux = array[j + 1];
                    cout<<aux<<endl;
                    array[j + 1] = array[j];
                    cout<<array[j+1]<<endl;
                    array[j] = aux;
                    cout<<array[j]<<endl;
                }
            }
        }
}


void txtMng::bubbleAlfabetico(string *array, int tam) {
    string aux;
    bool seguir = true;
    for (int i = 0; i < tam; i++) {
        seguir = false;
        for (int j = i + 1; j < tam; j++) {
            if (array[i] > array[j]) {
                seguir = true;
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}



