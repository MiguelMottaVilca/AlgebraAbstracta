#ifndef CESAR_H
#define CESAR_H

#include <string>

using namespace std;

class Cesar{
    private:
    int clave ;
    public:
    Cesar();
    string cifrado(string mensaje);
    string descifrado(string mensaje);

};

Cesar::Cesar(){
    clave = 3;
}

string Cesar::cifrado(string mensaje){
    string cifrado ;
    int size = mensaje.size();
    for(int i = 0 ; i < size ; i++){
        int pos = abc.find(mensaje[i]);
        pos += clave;
        if (pos > abc_size)
            pos = modulo(pos ,abc_size);
        cifrado += abc[pos];
    }
    return cifrado;
}

string Cesar::descifrado(string mensaje){
    string descifrado ;
    int size = mensaje.size();
    for(int i = 0 ; i < size ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos -= clave;
        if (pos < 0)
            pos = modulo(pos ,abc_size);
        descifrado += abc[pos];
    }
    return descifrado;
}



#endif //CESAR_H