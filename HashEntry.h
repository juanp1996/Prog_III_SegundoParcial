#include <string>
#include <cstring>
using namespace std;

class nodo {

private:
    long int clave;
    long int  c2;
    string valor;
    int ocurrencias;
    bool flag = true;

public:
    nodo();
    nodo(long int , string , int);
    long long getClave();
    void setClave(long long clave);
    string getValor();
    bool getFlag();
    void setFlag(bool);
    void setValor(string);
    void setOcurrencia(int);
    int getOcurrenciaNodoHash();
    long djb2(string, int);

};
