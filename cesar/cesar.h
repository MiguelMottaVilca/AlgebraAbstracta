#ifndef CESAR_H
#define CESAR_H

#include <string>
using namespace std;

class Cesar{
    private:
    int clave = 3;
    public:
    Cesar();
    string cifrado(string mensaje);
    string descifrado(string mensaje);

};

Cesar::Cesar(){}

string Cesar::cifrado(string mensaje){
    string cifrado ;
    for(int i = 0 ; i < mensaje.size() ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos += clave;
        pos %= size_abc;
        cifrado += abc[pos];
    }
    return cifrado;
}

string Cesar::descifrado(string mensaje){
    string descifrado ;
    for(int i = 0 ; i < mensaje.size() ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos -= clave;
        pos %= size_abc;
        descifrado += abc[pos];
    }
    return descifrado;
}



#endif //CESAR_H