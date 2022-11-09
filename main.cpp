#include <string>
#include <iostream>
#include "txtMng.h"
#include <ctime>
using namespace std;


int main(int argc , char *argv[])  //argc: Cant de arg  -- argv: C/U de los argumentos
{
    clock_t ini, final;
    txtMng txtMng;
    switch (argc) {
        case 1:
                cout << "Por favor ingresar argumento. Ej. '-palabras' " << endl;
            break;
        case 2:
            txtMng.openFile(argv[2]);
            txtMng.basic();
            break;
        case 3:
            if (argv[2]=="-palabras"){
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

    }
    return 0;
}

