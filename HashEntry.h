#include <string>

using namespace std;

class nodo {

private:
    long int clave;
    long int  c2;
    string valor;
    int ocurrencias;
    bool flag = true;
    nodo *next;

public:
    nodo(){};

    nodo(long int clave /*, long int c2*/ , string valor , int ocurrencias){
        this->clave = clave;
        this->c2 = c2;
        this->valor = valor;
        this->ocurrencias = ocurrencias;
    }

    long long getClave(){
        return clave;
    }

    void setClave(long long clave){
        this->clave = clave;
    }

    string getValor(){
        return valor;
    }

    bool getFlag(){
        return flag;
    }
    void setFlag(bool f){
        this->flag = f;
    }

    void setValor(string valor){
        this->valor = valor;
    }

    void setOcurrencia(int o){
        this->ocurrencias = o;
    }
    int getOcurrencia(){
        return ocurrencias;
    }

    void setNext(nodo *next){
        this->next = next;
    }
    nodo getNext(){
        return *next;
    }
    long djb2(string pa , int s){
        unsigned long int k;
        char p[s];
        strcpy(p,pa.c_str());
        k = 5381;
        for (int i = 0; i <= s ; ++i) {
            k=((k << 5) + k ) + int(p[i]);
        }
        return k;
    }

};
