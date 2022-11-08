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

void txtMng::basic(string d)
{
    openFile(d);
    cout<<"Cantidad de lineas: "<< getCantLineas()<<endl;
    cout<<"Cantidad de palabras: "<<getCantPalabras()<<endl;
    cout<<"Cantidad de letras: "<<getCantLetras()<<endl;
    cout<<"Cantidad de palabras diferentes: "<<getCantPalabras()-HashMap.getOcurrenciasTotales()<<endl;
}

void txtMng::palabras(int c , string d){
    openFile(d);
    for (int i = 0; i < lista.getTamanio() ; ++i) {
        if (HashMap.copiar(nodo.djb2(lista.getDato(i),lista.getDato(i).length())))
        lista_2.insertarPrimero(lista.getDato(i));
    }

}

void txtMng::ocurrencias(int c , string d) {
    openFile(d);
    for (int i = 0; i < lista.getTamanio(); ++i) {
        if (HashMap.copiar(nodo.djb2(lista.getDato(i), lista.getDato(i).length()))) {
            int ocurrencia = HashMap.getOcurrencias(nodo.djb2(lista.getDato(i), lista.getDato(i).length()));
            lista_2.insertarPrimeroConOcurrencias(lista.getDato(i), ocurrencia);
        }
        int tamL2=lista_2.getTamanio();
        quickSort(lista_2, 0, tamL2);
        if (c!=0){
            for (int j = 0; j <= c; ++j) {
                print(lista_2.getDato(tamL2));
                tamL2--;
            }
        }
        while (tamL2!=0){
            print(lista_2.getDato(tamL2));
            tamL2--;
        }
    }
}


void txtMng::excluir() {;}

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



void txtMng::print(string p){
    cout<<p<<endl;
}

//plantilla quicksort murgui
void txtMng::quickSort(Lista<string> li, int inicio, int fin)
{
    int i, j;
    int pivot;
    pivot = (inicio+fin) / 2; //!!!!!!!!!!!!!!!!!!REVISAR ACA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    i = inicio;
    j = fin;
    do
    {
        while (li.getOcurrencia(i) < li.getOcurrencia(pivot))
            i++;
        while (li.getOcurrencia(j) > li.getOcurrencia(pivot))
            j--;
        if (i <= j)
        {
            aux.insertarConOcurrencia(i , li.getDato(i) , li.getOcurrencia(i));
            //aux = arr[i];
            li.insertarConOcurrencia(i,li.getDato(j),li.getOcurrencia(j));
            //arr[i] = arr[j];
            li.insertarConOcurrencia(j,aux.getDato(i),aux.getOcurrencia(i));
            //arr[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > inicio)
        quickSort(li, inicio, j);
    if (i < fin)
        quickSort(li, i, fin);

}

//adaptacion del otro quicksort
void txtMng::quickSortAlphabetical(Lista<string> li, int inicio, int fin) {
    int i, j;
    int pivot;
    pivot = (inicio+fin) / 2;
    i = inicio;
    j = fin;
    do
    {
        while (strcmp(li.getDato(i).c_str(),li.getDato(pivot).c_str())<0)
        i++;
        while (strcmp(li.getDato(j).c_str(),li.getDato(pivot).c_str())>0)
        j--;
        if (i<=j) {
            //aux = arr[i];
            aux.insertar(i, li.getDato(i));
            //arr[i] = arr[j];
            li.insertar(i, li.getDato(j));
            //arr[j] = aux;
            li.insertar(j, aux.getDato(i));
            i++;
            j--;
        }
    } while (i <= j);
        if (j > inicio){
            quickSortAlphabetical(li, inicio, j);
        }
        if (i < fin){
            quickSortAlphabetical(li, i, fin);
        }
}

