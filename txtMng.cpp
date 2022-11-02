//
// Created by juanp on 1/11/2022.
//
#include "txtMng.h"

txtMng::txtMng() {}

/* MANEJO DE LOS DISTINTOS CASOS DEPENDIENDO DEL ARGUMENTO **/
void txtMng::ArgMng(int c, char *a)
{
    if (c == 1)
    {
        error(1);
    }
    else if (c > 2)
    {

    }
    else
    {

        if (checkFileExt(a))
        {
            basic(a);
        }
        else
        {
            error(2);
        }
    }
}

//abrimos el archivo y lo preparamos para trabajarlo
void txtMng::openFile(string d)
{
    ifstream archivo(direccion);           //archivo de lectura
    ofstream temp(direccion_temp);        //archivo de escritura
    if (!archivo || !temp)                  //si no abre alguno de los 2 archivos, mandamos error
    {
        error(3);
    }
    else
    {
        limpiar();
    }
}

// limpiamos lo que no sea letra
void txtMng::limpiar()
{
    while (!archivo.eof())
    {
        getline(archivo, lineas);
        Cant_lineas++;
        stringstream s(lineas);
        while (getline(s, palabra, ' '))
        {
            stringstream p(palabra);
            Cant_palabras++;
            temp << checkPalabra(palabra, p.str().size()) << endl; // <----- SACAR TEMP Y AGREGAR FUNCION DE HASH
        }
    }
    archivo.close();
    temp.close();

}

// checkea/corrige comienzo y fin de palabra recursivamente , si esta mal corrige
string txtMng::checkPalabra(string pa, int l)
{
    char palabra_char[l + 1];
    string palabra_aux;
    strcpy(palabra_char, pa.c_str());
    if (checkCaracter(palabra_char[0]))
    {
        if (checkCaracter(palabra_char[l + 1]))
        {
            Cant_letras = Cant_letras + pa.length();  // voy sumando cantidad de letras
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
bool txtMng::checkCaracter(char p)   //<---- dividir en primer y segundo caracter
{

    if (int(p) >= 97 && int(p) <= 122) //chequeo si es una letra (ASCII entre 97 y 122)
    {
        return true;
    }
    else if ((int(p)+32) >= 97 && (int(p)+32) <= 122 ){ //chequeo si es una letra mayuscula (ASCII entre 65 y 90)
        return true;
    }else if(int(p) >= 160 && int(p) <= 163 || int(p) == 130){
        return true;
    }else
        return false;
}


//corrobora terminacion .txt del archivo citado
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
        case 3:
            cout << "ERROR al querer abrir el archivo. Exit code: 3" << endl;
            break;
    }
}

/*
 * SET / GET
 */

void txtMng::setCantLineas() {}
void txtMng::setCantPalabras() {}
void txtMng::setCantLetras() {}

int txtMng::getCantLineas() { return Cant_lineas; }
int txtMng::getCantPalabras() { return Cant_palabras; }
int txtMng::getCantLetras() { return Cant_letras; }

void txtMng::setCaracter(string *c) {caracter = c;}
string txtMng::getCaracter() {return *caracter;}

/*
 *  METODOS PARA LOS ARGUMENTOS
 */


void txtMng::basic(std::string d) {
    openFile(d);


}
void txtMng::ocurrencias() {}
void txtMng::excluir() {}