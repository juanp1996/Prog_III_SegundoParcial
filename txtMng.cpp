//
// Created by juanp on 1/11/2022.
//
#include "txtMng.h"

txtMng::txtMng() {}

/* MANEJO DE LOS DISTINTOS CASOS DEPENDIENDO DEL ARGUMENTO **/
void txtMng::ArgMng(int c, char *a)
{
    if (c == 0)
    {
        error(1);
    }
    else if (c > 1)
    {
    }
    else
    {
        if (checkFileExt(a))
        {
            normal(a);
        }
        else
        {
            error(2);
        }
    }
}
/*
 * CORROBORA LA TERMINACION .txt DEL ARGUMENTO
 +*/
bool txtMng::checkFileExt(const std::string &s)
{
    size_t l = s.find('.txt');
    if (l != string::npos)
    {
        return true;
    }
    return false;
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
    }
}
/* LIMPIAMOS CARACTERES QUE NO SEAN LETRAS **/
void txtMng::limpiar(string d, string d_temp)
{
    ifstream archivo(d);
    ofstream archivo_temp(d_temp);
    // archivo.open(d , ios::in);
    if (!archivo || !archivo_temp)
    {
        error(3);
    }
    else

    {
        while (!archivo.eof())
        {
            getline(archivo, lineas);
            Cant_lineas++;
            stringstream s(lineas);
            while (getline(s, palabra, ' '))
            {
                stringstream p (palabra);
                Cant_palabras++;
                archivo_temp << checkPalabra(palabra , p.str().size()) << endl;
            }
        }
    archivo.close();
    archivo_temp.close();
    }
}
//checkea comienzo y fin de palabra recursivamente , si esta mal corrige
string txtMng::checkPalabra(string pa, int l)
{
    char palabra_char[l + 1];
    string palabra_aux;
    strcpy(palabra_char, pa.c_str());
    if (checkCaracter(palabra_char[0]))
    {
        if (checkCaracter(palabra_char[l + 1]))
        {
            /* la palabra esta correcta, hay que escribir en el otro archivo **/
            return pa;
        }
        else
        {
            /*esta mal el final**/
            for (int i = 0; i <= l; ++i)
            {
                palabra_aux.push_back(palabra_char[i]);
            }
            checkPalabra(palabra_aux, l - 1);
        }
    }
    else
    {
        for (int i = 1; i <= l; ++i)
        {
            palabra_aux.push_back(palabra_char[i]);
            /* esta mal el inicio**/
        }
        checkPalabra(palabra_aux, l - 1);
    }
}
// si devuelve true es una letra
bool txtMng::checkCaracter(char p)
{
    if (int(p) > 97 && int(p) < 122 || int(p) > 160 && int(p) < 163 || int(p) == 130)
    {
        return true;
    }
    else
        return false;
}

/*

void txtMng::normal(string nombreArchivo) {
    fstream archivo;
    archivo.open(nombreArchivo, ios::in);
    string lineas, palabras, letras;
    char palabra[25];
    int numLineas = 0;
    int numPalabras = 0;
    int numLetras = 0;
    while (getline(archivo,lineas)) { //Primero le mandamos como referencia la primer palabra del archivo y lo almacena en la variable lineas y como aca no pasa ningun delimitador, separa por lineas
        numLineas++; //por eso aca sumamos en el conotador de lineas a medida que hay una nueva.
        stringstream s(lineas); //declaramos la linea como una cadena de caracteres e iteramos
        while (getline(s, palabras, ' ')) { //iteramos y cada vez que encunetra un espacio, suma la can de palabras
            stringstream p(palabras); //volvemos a hacer lo de arriba pero ahora en palabras y despues letras
            numPalabras++;
            int largo = p.str().size();
            palabra[0]=
            for (int i = 1; i < largo ; ++i) {
                palabra[i]=
            }

        }
    }
    cout << "El archivo tiene " << numLetras << " letras." << endl;
    cout << "El archivo tiene " << numPalabras << " palabras." << endl;
    cout << "El archivo tiene " << numLineas << " lineas." << endl;


    /* EJEMPLO
    codigo(){
        if(colicion())
    }
    diferentes = numPalabras - 1 ;
    numPalabras
     **/

void txtMng::contar_palabras()
{
}
void txtMng::ocurrencias()
{
}
void txtMng::excluir()
{
}