#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include "txtMng.h"
using namespace std;


int main(int argc , char *argv[])  //argc: Cant de arg  -- argv: C/U de los argumentos
{
    txtMng txtMng;
    txtMng.ArgMng(argc , *argv);
    system("pause");
    return 0;
}

