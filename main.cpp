#include <string>
#include <iostream>
#include "txtMng.h"
#include <ctime>
using namespace std;


int main(int argc , char **argv)  //argc: Cant de arg  -- argv: C/U de los argumentos
{
    for (int i= 0; i<argc; i++){
        cout<<"Argumento numero: "<<i<<endl;
        cout<<"Argumento: "<<argv[i]<<endl;
    }
    clock_t ini, final;
    txtMng txtMng;
    if (argc == 2){
        cout<<"Empieza"<<endl;
        string a = argv[1];
        cout<<a<<endl;
        txtMng.openFile(a);
        cout<<"Hizo el open file"<<endl;
        txtMng.basic();
        cout<<"Termino"<<endl;
    }

    if (argc == 3) {
        cout << "Empieza" << endl;
        if (strcmp(argv[1], "-palabras") == 0) {
            string a = argv[2];
            txtMng.openFile(a);
            txtMng.palabras(0);
        }else if (strcmp(argv[1], "-ocurrencias") == 0) {
            string a = argv[2];
            txtMng.openFile(a);
            txtMng.ocurrencias(0);
    }
    }
    if (argc == 4) {
        if (strcmp(argv[1], "-palabras") == 0) {
            string a = argv[3];
            txtMng.openFile(a);
            cout<<"Paso open"<<endl;
            txtMng.palabras(atoi(argv[2]));
            cout<<"finalizo"<<endl;
        } else if (strcmp(argv[1], "-ocurrencias") == 0) {
            string a = argv[3];
            txtMng.openFile(a);
            txtMng.ocurrencias(atoi(argv[2]));
        } else if (strcmp(argv[1], "-mostrar")==0){
            string a = argv[3];
            txtMng.openFile(a);
            txtMng.mostrar(argv[2]);
        }
    }
    if (argc == 5){
        if (strcmp(argv[1], "-palabras") == 0){
            if ((strcmp(argv[2], "-excluir") == 0) || (strcmp(argv[2], "-excluirf") == 0)){
                txtMng.openFile(argv[4]);
                txtMng.excluir(argv[3] , 1);
            }else
                cout<<"argumento invalido"<<endl;
        }else if (strcmp(argv[1], "-ocurrencias") == 0){
            if ((strcmp(argv[2], "-excluir") == 0) || (strcmp(argv[2], "-excluirf") == 0)){
                txtMng.openFile(argv[4]);
                txtMng.excluir(argv[3] , 2);
            }
        }
    }

    return 0;
}
