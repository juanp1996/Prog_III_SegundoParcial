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
    if (!archivo)    // si no abre el archivo, mandamos error
    {
        error(3);
    }
    else
    {
        primerPasada(); //SI ABRE, SE REALIZA PRIMER PASAD
    }
}

void txtMng::primerPasada() {
    while (!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DEL ARCHIVO
        getline(archivo, lineas); //DIVIDIMOS EN LINEAS
        Cant_lineas++;
        stringstream s(lineas);
        //cout<<"Linea: "<<lineas<<endl;
        while (getline(s, palabra, ' ')) //DIVIDIMOS EN PALABRAS
        {
            stringstream p(palabra);
            Cant_palabras++;
            setLong(palabra.length());
            setPalabra(palabra);
            checkPalabra(); //LLAMAMOS PARA LIMPIAR LA PALABRA
            lista.insertarPrimero(palabra);
        }
    }
    archivo.close();
    HashMap.NewTable(Cant_palabras*20); //CREAMOS LA TABLA HASH CON TAMANIO * 20 PARA DISMINUIR COLISIONES

    for (int i=0; i<lista.getTamanio(); i++){
        HashMap.newNodo(nodo.djb2(lista.getDato(i), lista.getDato(i).length()), lista.getDato(i)); //GENERAMOS LOS NODOS
    }

}

// checkea/corrige comienzo y fin de palabra recursivamente , si esta mal corrige
void txtMng::checkPalabra()
{
    int l = getLong() - 1;
    string palabra_aux;
    char palabra_char[l];
    strcpy(palabra_char, getPalabra().c_str());
    if (checkCaracter(palabra_char[0]))
    {
        if (checkCaracter(palabra_char[l])) //ENTRA SI YA ESTA BIEN
        {
            Cant_letras = Cant_letras + getPalabra().length(); //LLEGAMOS CON RECURSIVIDAD A LA PALABRA LIMPIA
        }
        else //SI ESTA MAL EL FINAL
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
    else //ESTA MAL LA PRIMERA
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


bool txtMng::checkCaracter(char p) //SI DEVUELVE TRUE ES UNA LETRA
{
    if (int(p) >= 97 && int(p) <= 122) // CHEQUEAMOS MINUSCULAS
    {
        return true;
    }
    else if ((int(p) + 32) >= 97 && (int(p) + 32) <= 122 || int(p)==181 || int(p)==144 || int(p)==214 || int(p)==224 || int(p)==233)
    { // CHEQUEAMOS MAYUSCULAS Y MAYUSCULAS CON TILDE
        esMayuscula(posicion); //LLAMADA RECURSIVA QUE VERIFICA SI TODA LA PALABRA ESTA EN MAYUSCULA
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


void txtMng::esMayuscula(int i)
{
    char palabra_char[getLong() - 1];
    string palabra_aux;
    strcpy(palabra_char, getPalabra().c_str());
    palabra_char[i] = tolower(palabra_char[i]); //CAMBIAMOS LA MAYUSCULA EN LA POSICION POR LA MINUSCULA
    for (int i = 0; i < getLong(); ++i)
    {
        palabra_aux.push_back(palabra_char[i]);
    }
    setPalabra(palabra_aux);
    posicion++;
    checkCaracter(palabra_char[posicion]); //LLAMAMOS DE NUEVO CON LA SIGUIENTE POSICION
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
    string array[Cant_palabras - HashMap.getOcurrenciasTotales()]; //DECLARAMOS UN ARRAY PARA PODER HACER EL ORDENAMIENTO
    int tamLista = lista.getTamanio();
    for (int i = 0; i < tamLista ; ++i) {
        if (HashMap.getFlagTB(nodo.djb2(lista.getDato(i), lista.getDato(i).length()))){ //SE COPIAN LAS PALABRAS UNA SOLA VEZ
            HashMap.setFlagTB(nodo.djb2(lista.getDato(i), lista.getDato(i).length()),false);
            array[j] = lista.getDato(i);
            lista_2.insertarPrimero(lista.getDato(i));
            j++;
        }
    }

    int tamL2=lista_2.getTamanio();
    bubbleAlfabetico(array, tamL2); //MANDAMOS A ORDENAR
    if (c>0){ //SI MANDA COMO ARGUMENTO QUE PRINTEE CIERTA CANTIDAD DE PALABRAS
        for (int j = 0; j < c; j++) {
            print(array[j]);
        }
    }else { //SI NO MANDA NADA COMO ARGUMENTO DE CANTIDAD
        for (int i=0; i<= tamL2; i++){
            print(array[i]);
        }
    }
    cout<<"Cantidad de palabras diferentes: "<<tamL2<<endl;
}

void txtMng::ocurrencias(int c) {
    int j = 0;
    int largo = Cant_palabras - HashMap.getOcurrenciasTotales();
    //cout<<"Largo: "<<largo<<endl;
    string array[largo]; //DECLARAMOS UN ARRAY PARA PODER HACER EL ORDENAMIENTO
    for (int i = 0; i < lista.getTamanio(); ++i) {
        //cout<<"Dato: "<<i<<": "<<lista.getDato(i)<<endl;
        if (HashMap.getFlagTB(nodo.djb2(lista.getDato(i), lista.getDato(i).length()))) { //UN FLAG PARA INGRESAR O NO LA PALABRA
            //cout<<"true"<<endl;
            HashMap.setFlagTB(nodo.djb2(lista.getDato(i), lista.getDato(i).length()),false ); //SETEAMOS FALSE PARA EVITAR COPIAS
            array[j] = lista.getDato(i);
            //cout<<"Copio la palabra"<<endl;
            j++;
        }
    }
    cout<<"Salio del bucle"<<endl;
    bubbleSort(array, j);
    cout<<"YA ORDENO"<<endl;

    if (c>0){
        for (int i = j; i>j - c - 1; i--) {
            print(array[j]);
           }
        cout<<"TERMINO OCURRENCIAS"<<endl;
        cout<<"Tamanio lista: "<<lista.getTamanio();
    }else {
        for (int i=j; i>=0; i--){
            print(array[i]);
        }
    }
    cout<<endl;
    cout<<"Printeamos la de mas ocurrencias arriba y la de menos debajo"<<endl;
    cout<<endl;
    cout<<"Tamaño array: "<< j<<endl;
}


void txtMng::excluir(string Ex, int con) {
        exc.open(Ex, ios::in);// ARCHIVO EXTERNO DE LECTURA
        if (!exc)         // SI NO ABRE MANDAMOS ERROR
        {
            cout<<"No es un archivo"<<endl; //RECONOCE QUE SE INGRESO UNA LINEA DE CARACTERES Y NO UN .TXT
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
            HashMap.setFlagTB(nodo.djb2(liEx.getDato(i),liEx.getDato(i).length()),false);  //SETEAMOS FALSE PARA EVITAR COPIAS
        }
        if(con==1){
            palabras(0);
        }else{
            ocurrencias(0);
        }
        exc.close();
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
        if (HashMap.existe(nodo.djb2(lista_2.getDato(i), lista_2.getDato(i).length()))) { //VERIFICA SI EXISTE LA PALABRA EN EL HASH
            //cout<<"true"<<endl;
            array[j] = lista_2.getDato(i);
            //cout<<"Copio la palabra: "<<lista_2.getDato(i)<<endl;
            j++;
            //cout<<"j: "<<j<<endl;
        } else{
            cout<<"La palabra "<<lista_2.getDato(i)<<" no esta en el texto"<<endl;
        }
    }
    bubbleSort(array, j);
    for (int i = j; i>=0; i--) {
        print(array[i]);
        cout<<" -- "<<HashMap.getOcurrenciasHash(nodo.djb2(array[i], array[i].length()))<<endl;
    }
}

void txtMng::print(string p){
    cout<<p<<endl;
}

void txtMng::bubbleSort(string *array, int tam) {
    //cout<<"entro al sort"<<endl;
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
                    //cout<<"Auxiliar: "<<aux<<endl;
                    array[j + 1] = array[j];
                    //cout<<"Siguiente: "<<array[j+1]<<endl;
                    array[j] = aux;
                    //cout<<"Nuevo: "<<array[j]<<endl;
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



