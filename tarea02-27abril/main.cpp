#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

#include "tools.h"

ZZ algoritmo1(ZZ a , ZZ b){
    ZZ r = modulo(a,b);
    while(r > 0){
        a = b;
        b = r;
        r = modulo(a,b);
    }
    return b ;
}

ZZ algoritmo2(ZZ a ,ZZ b){
    ZZ r = modulo(a,b);
    while(r > 0){
        if (r > (b/2) )
            r = b - r;
        a = b;
        b = r;
        r = modulo(a,b);
    }
    return b ;
}

/*---------  ejercicio3 --------*/
ZZ euclidesmcd(ZZ a,ZZ b){
    if (b == 0)
        return a;
    return euclidesmcd(b, modulo(a,b));
}

ZZ algoritmo4(ZZ a, ZZ b){
  if(valorAbsoluto(b) > valorAbsoluto(a))
    return algoritmo4(b,a);
  if(b==0)
    return a;
  if( (modulo(a,2)==0) and (modulo(b,2)==0) )
    return 2*algoritmo4(a/2, b/2);
  if( (modulo(a,2)==0) and (modulo(b,2)!=0) )
    return algoritmo4(a/2, b);
  if( (modulo(a,2)!=0) and (modulo(b,2)==0) )
    return algoritmo4(a, b/2);
  return algoritmo4( (valorAbsoluto(a)- valorAbsoluto(b) )/2,b );
}

ZZ algoritmo5(ZZ a , ZZ b){
    ZZ g(1);
    while(!(modulo(a,2)) && !(modulo(b,2))){
        a/=2;
        b/=2;
        g*=2;
    }
    while(a!=0){
        while(!(modulo(a,2)))
            a/=2; 
        while(!(modulo(b,2)))
            b/=2;    
        ZZ t = valorAbsoluto(a-b)/2;
        if(a>=b)
            a = t;
        else
            b = t;
    }
    return g*b;
}

ZZ algoritmo6(ZZ a , ZZ b){

    while(a != b){
        if (a >b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main(){

    ZZ a , b ;

    cout << "a : "; cin >> a;
    cout << "b : "; cin >> b;

    cout <<"algoritmo 1: " << algoritmo1(a,b) << endl;
    //cout <<"algoritmo 2: " << algoritmo2(a,b) << endl;
    //cout <<"algoritmo 3: " << euclidesmcd(a,b) << endl;
    //cout <<"algoritmo 4: " << algoritmo4(a,b) <<endl;
    // cout <<"algoritmo 5: " << algoritmo5(a,b) << endl;
    //cout <<"algoritmo 6: " << algoritmo6(a,b) << endl;


    return 0;
}
