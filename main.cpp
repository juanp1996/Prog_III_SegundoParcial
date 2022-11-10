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
            cout << "Entro a palabras" << endl;
            string a = argv[2];
            cout<<a<<endl;
            txtMng.openFile(a);
            cout<<"Se hizo el open file"<<endl;
            txtMng.palabras(0);
        }
    }
    /*if (argc == 3) {
        cout << "Empieza" << endl;
        if (strcmp(argv[1], "-ocurrencias") == 0) {
            cout << "Entro a ocurrencias" << endl;
            string a = argv[2];
            cout<<a<<endl;
            txtMng.openFile(a);
            cout<<"Se hizo el open file"<<endl;
            txtMng.ocurrencias(0);
        }
    }*/

    /*
    switch (argc) {
        case 1:
            cout << "Por favor ingresar argumento. Ej. '-palabras' " << endl;
            break;
        case 2:
            cout<<"1"<<endl;
            txtMng.openFile(argv[2]);
            txtMng.basic();
            break;
        case 3:
            if (argv[2]=="-palabras"){
                cout<<"2"<<endl;
                txtMng.openFile(argv[3]);
                txtMng.palabras(0);
            }else if (argv[2]=="-ocurrencias"){
                txtMng.openFile(argv[3]);
                txtMng.ocurrencias(0);
            }
            break;
        case 4:
            if(argv[2]== "-palabras"){
                if (atoi(argv[3])!=0)
                {
                    txtMng.openFile(argv[4]);
                    txtMng.palabras(atoi(argv[3]));
                }
            }
            if(argv[2]=="-mostrar"){
                txtMng.openFile(argv[4]);
                txtMng.mostrar(argv[3]); //funciona para 1 palabra o para varias entre " "
            }
            break;
        case 5:
            if (argv[2]=="-palabras"){
                if (argv[3]=="-excluir" || argv[3]=="-excluirf"){
                    txtMng.openFile(argv[5]);
                    txtMng.excluir(argv[4] , 1);
                }else
                    cout<<"argumento invalido"<<endl;

            }else if (argv[2]=="-ocurrencias")
                if (argv[3]=="-excluir" || argv[3]=="-excluirf"){
                    txtMng.openFile(argv[5]);
                    txtMng.excluir(argv[4] , 2);
                }
                    cout<<"argumento invalido"<<endl;
            break;
        default:
            cout<<"argumentos invalidos"<<endl;
            break;

    }*/
    return 0;
}
