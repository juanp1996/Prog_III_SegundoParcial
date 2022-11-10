#include <string>
#include <cstring>
using namespace std;

class nodo {

private:
    long long clave;
    string valor;
    int ocurrencias;
    bool flag = true;

public:
    nodo();
    nodo(long long , string , int);
    long long getClave();
    void setClave(long long clave);
    string getValor();
    bool getFlag();
    void setFlag(bool);
    void setValor(string);
    void setOcurrencia(int);
    int getOcurrenciaNodoHash();
    long long djb2(string, int);

};
