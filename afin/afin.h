#ifndef AFIN_H
#define AFIN_H

#include <string>

using namespace std;

class Afin{
    int a , b;
    public:
    Afin();
    Afin(int , int);
    void generarClaves();
    string cifrado(string);
    string descifrado(string);
};

Afin::Afin(){
     generarClaves();
}

Afin::Afin(int a, int b){
    this -> a = inversa(a,abc_size);
    this -> b = b;
}

void Afin::generarClaves(){
    a = 1+rand()%(abc_size-1) ;
    int tem = euclides( a , abc_size);
    while( tem != 1){
        a = 1+rand()%(abc_size-1);
        tem = euclides( a , abc_size);   
    }
    b = 1+rand()%(abc_size-1) ;
    cout <<"CLAVE GENERADA    a: " << a <<"   b: "<< b << endl;
}

string Afin::cifrado(string mensaje){
    string cifrado ;
    int size =  mensaje.size() , pos;
    for(int i = 0  ; i < size ; i++ ){
        pos  = abc.find(mensaje[i]);
        pos = pos*a + b;
        if (pos > abc_size)
            pos = modulo(pos,abc_size);
        cifrado += abc[pos]; 
    }
    return cifrado;
}

string Afin::descifrado(string mensaje){
    cout <<"    a: " << a <<"   b: "<< b << endl;
    string descifrado ;
    int size = mensaje.size() , pos;
    for(int i = 0 ; i < size ; i++){
        pos = abc.find(mensaje[i]);
        pos -= b;
        pos *= a; 
        // if( pos < 0)
            pos = modulo(pos,abc_size);
        descifrado += abc[pos];
    }
    return descifrado;
}


#endif //Afin_H