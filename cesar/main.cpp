#include <iostream>
#include <string>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";
int size_abc = abc.size();

#include "cesar.h"


int main(){

    Cesar emisor;
    Cesar receptor;

    string mensaje = "holaprimo";
    // cin>> mensaje;

    cout << mensaje << endl;
    mensaje = emisor.cifrado(mensaje);
    cout << mensaje << endl;
    mensaje  = receptor.descifrado(mensaje);
    cout << mensaje << endl;

    return 0;
}