#ifndef RSA_H
#define RSA_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class RSA{
    private:
    ZZ d;
    public:
    ZZ n ;
    ZZ e;
    RSA();
    RSA(ZZ , ZZ);
    void generarClaves();
    string cifrado(string);
    string descifrado(string);
};

RSA::RSA(){
    generarClaves();
}

RSA::RSA(ZZ n,ZZ e){
    this -> n = n ;
    this -> e = e ;
}

void RSA::generarClaves(){
    ZZ p ;
    ZZ q;
    // vector <int> primos = cribaEratostenes(480000);
    // long al1 = 1+rand()%(primos.size()-1) , al2 = 1+rand()%(primos.size()-1) ;
    // p = primos[al1];
    // q = primos[al2];

    p = 397 ;
    q = 401 ;
    n = p*q;
    ZZ fi_n = (p-1)*(q-1);
    e = 343 ;
    // e = rand() ;
    // while(euclides(fi_n,e) != 1){
    //     e = rand() ;
    // }
    d = inversa(e,fi_n);


    cout << "e: " << e << endl;
    cout << "n: " << n << endl;
    cout << "d: " << d << endl;
    cout << "fi_n:" << fi_n << endl;
}

string RSA::cifrado(string mensaje){
    string cifrado , aux ;
    long size = mensaje.size() ;
    ZZ  tem , pos;

    for(long i = 0 ; i < size ; i++){
        pos = abc.find(mensaje[i]);
        tem = expModular(pos, e , n);
        aux = ZZtoString(tem);
        cifrado += aux; 
        cifrado += " "; 
    }
    return cifrado;
}

string RSA::descifrado(string mensaje){
    string descifrado , aux , espacio = " ";
    long size = mensaje.size();
    ZZ tem ;
    for(long i = 0 ; i < size ;i++){
        if( mensaje[i] != espacio[0] )
            aux += mensaje[i];
        if( mensaje[i] == espacio[0] ){
            tem = stringToNumber(aux);
            cout << "tem: "<< tem << endl;// ZZ 
            aux.clear();
            tem = expModular(tem , d , n);
            // aux = ZZtoString(tem);
            // descifrado += abc[tem];
            aux.clear();
        }
    }
    return descifrado;
}


#endif //RSA_H
