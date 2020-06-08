#ifndef vigenere_h
#define vigenere_h

#include <string>
using namespace std;

class Vigenere{
    string mensaje, clave;
    public:
    Vigenere();
    Vigenere(string , string );
    string cifrado();
    string descifrado();
    string cifradoAutoClave();
    string descifradoAutoClave();
    string cifradoAscii();
    string descifradoAscii();
};

Vigenere::Vigenere(string mensaje , string clave){
    this -> mensaje = mensaje;
    this -> clave = clave;
}

string Vigenere::cifrado(){
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

string Vigenere::descifrado(){
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

string Vigenere::cifradoAutoClave(){
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

string Vigenere::descifradoAutoClave(){
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

string Vigenere::cifradoAscii(){
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

string Vigenere::descifradoAscii(){
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

#endif /* vigenere_h */
