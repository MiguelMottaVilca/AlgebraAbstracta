#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
using namespace std;

class Vigenere{
    public:
    Vigenere();
    string cifrado(string mensaje , string clave);
    string descifrado(string mensaje , string clave);
    string cifradoAutoClave(string mensaje , string clave);
    string descifradoAutoClave(string mensaje , string clave);
};

Vigenere::Vigenere(){}

//mensaje :hñola
//clave :xa 

string Vigenere::cifrado(string mensaje , string clave){
    string cifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        aux = pos_mensaje + pos_clave;
        aux = modulo(aux,abc_size);
        cifrado += abc[aux];
    }
    return cifrado;
}

string Vigenere::descifrado(string mensaje , string clave){
    string descifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        aux = pos_mensaje - pos_clave;
        aux = modulo(aux,abc_size);   
        descifrado += abc[aux];
    }
    return descifrado;
}

string Vigenere::cifradoAutoClave(string mensaje ,string clave){
    string cifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        if (i < clave_size)
            pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        else
            pos_clave = abc.find(mensaje[i - clave_size]);
        aux = pos_mensaje + pos_clave;
        aux = modulo(aux,abc_size);
        cifrado += abc[aux];
    }
    return cifrado;
}

string Vigenere::descifradoAutoClave(string mensaje ,string clave){
    string cifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        if (i < clave_size)
            pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        else
            pos_clave = abc.find(mensaje[i - clave_size]);
        aux = pos_mensaje - pos_clave;
        aux = modulo(aux,abc_size);
        cifrado += abc[aux];
    }
    return cifrado;
}

string Vigenere::cifradoAscii(string mensaje , string clave){
    string cifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        pos_mensaje += 32; // codigo ascii
        pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        pos_clave += 32; // codigo ascii
        aux = pos_mensaje + pos_clave;
        aux = modulo(aux,abc_size + 32);
        if (aux < 32)
            aux += abc_size + 1 ;
        aux -=32;
        cifrado += abc[aux];
    }
    return cifrado;
}

string Vigenere::descifradoAscii(string mensaje , string clave){
    string cifrado ;
    int mensaje_size = mensaje.size(), clave_size = clave.size() , pos_mensaje , pos_clave , aux;
    for(int i = 0 ; i < mensaje_size ; i++ ){
        pos_mensaje = abc.find(mensaje[i]);
        pos_mensaje += 32; // codigo ascii
        pos_clave = abc.find(clave[ modulo(i,clave_size) ]);
        pos_clave += 32; // codigo ascii
        aux = pos_mensaje - pos_clave;
        aux = modulo(aux,abc_size + 32);
        if (aux < 32)
            aux += abc_size + 1 ;
        aux -=32;
        cifrado += abc[aux];
    }
    return cifrado;
}

#endif //VIGENERE_H
