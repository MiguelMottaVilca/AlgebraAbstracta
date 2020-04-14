#include <iostream>
#include <string>
#include "tools.h"

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
static int abc_size = abc.size();

#include "cesar.h"


int main(){

    Cesar emisor;
    Cesar receptor;

    string mensaje = "hola...primo";
    //cin>> mensaje;

    cout << mensaje << endl;
    mensaje = emisor.cifrado(mensaje);
    cout << mensaje << endl;
    mensaje  = receptor.descifrado(mensaje);
    cout << mensaje << endl;

    return 0;
}