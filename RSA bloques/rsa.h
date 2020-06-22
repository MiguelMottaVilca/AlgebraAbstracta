#ifndef RSA_H
#define RSA_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class RSA{
    private:
    ZZ d;
    long bit;
    public:
    ZZ n ;
    ZZ e;
    RSA(long);
    RSA(ZZ , ZZ);
    void generarClaves(long);
    string cifrado(string);
    string descifrado(string);
};

RSA::RSA(long bits){
    bit = bits;
    generarClaves(bit);
}

RSA::RSA(ZZ n,ZZ e){
    this -> n = n ;
    this -> e = e ;
}

void RSA::generarClaves(long bits){
    ZZ p ;
    ZZ q;
    // vector <int> primos = cribaEratostenes(480000);
    // long al1 = 1+rand()%(primos.size()-1) , al2 = 1+rand()%(primos.size()-1) ;
    // p = primos[al1];
    // q = primos[al2];

    p = 17 ;
    q = 59 ;
    n = p*q;
    ZZ fi_n = (p-1)*(q-1);
    e = 3 ;
    // e = rand() ;
    // while(euclides(fi_n,e) != 1){
        // e = rand() ;
    // }
    d = inversa(e,fi_n);


    cout << "e: " << e << endl;
    cout << "n: " << n << endl;
    cout << "d: " << d << endl;
    cout << "fi_n:" << fi_n << endl;
}

string RSA::cifrado(string mensaje){
    string cifrado , bloques , aux ;
    long size = mensaje.size() ;
    ZZ  tem , pos;

    for(long i = 0 ; i < size ; i++){
        pos = abc.find(mensaje[i]);
        aux = ZZtoString(pos);
        // cout << "AUX: " << aux << endl; 
        while( aux.size() != 2 )
            aux.insert(0,"0");
        bloques += aux;
    }
    cout << "bloque: " << bloques << endl; 
 
    //separar en bloques
    aux.clear();
    size = bloques.size();
    tem = size;
    ZZ valorN {3} , j {1}; // 
    ZZ var = modulo(tem,valorN);
    
    while( var != 0){
        bloques += "0";
        size = bloques.size();
        tem = size;
        var = modulo(tem,valorN);
    }
    cout << bloques << endl;

    for(long i = 0 ; i < size ; i++){  
        // cout << bloques[i] << endl;  
        aux += bloques[i];
        if( j == valorN ){
            cout << " aux : " << aux << endl;
            pos = stringToZZ(aux);
            cout << "pos: " << pos << endl;
            cout << "e: " << e << endl;
            cout << "n: " << n << endl;
            tem = expModular(pos , e , n);
            cout << "exp: " << tem << endl;
            aux = ZZtoString(tem);
            cifrado += aux;
            aux.clear();
            j = 0;
        }
        j++;
    }
    cout << "cifrado: " << cifrado << endl;
    return cifrado;
}

string RSA::descifrado(string mensaje){
    string descifrado , aux , espacio = " ";
    long size = mensaje.size() , x ;
    ZZ tem ;
   
    return descifrado;
}


#endif //RSA_H
