#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include "txtMng.h"
#include <ctime>
using namespace std;


int main(int argc , char *argv[])  //argc: Cant de arg  -- argv: C/U de los argumentos
{
    clock_t ini, final;
    char *argumentos;
    txtMng txtMng;

    if(argc == 1)
    {
        cout << "Por favor ingresar argumento. Ej. '-palabras' " << endl;
        return 0;
    }
    if(argc == 2){
        txtMng.basic(argv[2]);
        return 0;
    }
    if(argc == 3){
        if (argv[2]=="-palabras"){
            txtMng.palabras( 0 , argv[3]);
            return 0;
        }else if (argv[2]=="-ocurrencias"){
            txtMng.ocurrencias(0 , argv[3]);
            return 0;
        }
    }
    if (argc == 4){

    }





    system("pause");
    return 0;
}

