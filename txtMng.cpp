//
// Created by juanp on 1/11/2022.
//
#include "txtMng.h"

/*
 *
 * IMPLEMENTAR 2 FUNCIONES DE HASH DISTINTAS PARA REDUCIR LA PROBABILIDAD DE COLICCION.
 *
 * */

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

// abrimos el archivo y lo preparamos para trabajarlo
void txtMng::openFile(string d)
{
    ifstream archivo(direccion);   // archivo de lectura
    if (!archivo)         // si no abre alguno de los 2 archivos, mandamos error
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
            checkPalabra();
            lista.insertarPrimero(getPalabra());
        }
    }
    HashMap.NewTable(Cant_palabras*20); //TAMAÑO DE LA TABLA * 20
    archivo.close();
    int pos= 0;
    while(pos < lista.getTamanio()) {
        HashMap.newNodo(nodo.djb2(lista.getDato(pos), lista.getDato(pos).length()), getPalabra());
        pos++;
    }
}

// checkea/corrige comienzo y fin de palabra recursivamente , si esta mal corrige
void txtMng::checkPalabra()
{
    int l = getLong() - 1;
    char palabra_char[l];
    string palabra_aux;
    strcpy(palabra_char, getPalabra().c_str());
    if (checkPrimerCaracter(palabra_char[0]))
    {
        if (checkUltimoCaracter(palabra_char[l]))
        {
            int c = getPalabra().length();
            Cant_letras = Cant_letras + c; // voy sumando cantidad de letras
        }
        else /*esta mal el final**/
        {
            for (int i = 0; i <= l; ++i)
            {
                palabra_aux.push_back(palabra_char[i]);
            }
            setPalabra(palabra_aux);
            setLong(getLong() - 1);
            checkPalabra();
        }
    }
    else
    {
        for (int i = 1; i <= l; ++i)
        {
            palabra_aux.push_back(palabra_char[i]);
            /* esta mal el inicio**/
        }
        setPalabra(palabra_aux);
        setLong(getLong() - 1);
        checkPalabra();
    }
}

// si devuelve true es una letra
bool txtMng::checkPrimerCaracter(char p) //<---- dividir en primer y segundo caracter
{
    if (int(p) >= 97 && int(p) <= 122) // chequeo si es una letra (ASCII entre 97 y 122)
    {
        return true;
    }
    else if ((int(p) + 32) >= 97 && (int(p) + 32) <= 122)
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
    char palabra_char[longitud];
    string palabra_aux;
    strcpy(palabra_char, getPalabra().c_str());
    palabra_char[i] = tolower(palabra_char[i]);
    for (int j = 0; j <= longitud; ++j)
    {
        palabra_aux.push_back(palabra_char[j]);
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

void txtMng::basic(std::string d)
{
    openFile(d);
}
void txtMng::ocurrencias() {}


void txtMng::excluir() {

}


void txtMng::mostrar(string palabra_arg) {
    if (HashMap.getOcurrencias(nodo.djb2(palabra_arg,palabra_arg.length()))>0){
        /*
         * ordenar
         */
    }else{
        /*
         * La palabra no existe
         */
    }
}
















/*
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
            setLong(p.str().size() - 1);
            checkPalabra();
        }
    }
    archivo.close();
}*/