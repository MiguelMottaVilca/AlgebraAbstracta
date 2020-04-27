#include <iostream>
#include "tools.h"

using namespace std;


int algoritmo1(int a , int b){
    while(true){
        int r = modulo(a,b);
        if(r == 0)
         return b ;

        a = b;
        b = r;
        cout << "a % b = " << r <<endl;
        cout << "a = " << a << endl;
        cout <<"b = " << b << endl;
    }
}

int algoritmo2(int a ,int b){
    while(true){
        int r = modulo(a,b);
        cout << "a % b = " << r <<endl;
        if(r == 0)
            return b ;
        
        if (r > (b/2) )
            r = b - r;
        a = b;
        b = r;
        cout << "a = " << a << endl;
        cout <<"b = " << b << endl;
    }

}

/*---------  ejercicio3 --------*/
int euclidesmcd(int a,int b){
    if (b == 0)
        return a;
    return euclidesmcd(b, modulo(a,b));
}

int algoritmo4(int a, int b){
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

int algoritmo5(int a , int b){
    int g = 1 ;
    while((  (!modulo(a,2))    and   (!modulo(b,2))   )){
        a /= 2;
        b /= 2;
        g*=2;
    }
    while(a != 0){
        a /= 2; 
        // cout << "a = " <<a <<endl;
        }
          
    while( b != 0){
        b /= 2;
        // cout << "b = " <<b <<endl;
        }

    int t = (a - b)/2; 
    if (a >= b)
        a = t;
    else
        b = t;
    
    return g*b;   
}

int algoritmo6(int a , int b){

    while(a != b){
        if (a >b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}




int main(){

    int a = 412 , b = 260;
    //cout <<"algoritmo 1: " << algoritmo1(a,b) << endl;
    //cout <<"algoritmo 2: " << algoritmo2(a,b) << endl;
    //cout <<"algoritmo 3: " << euclidesmcd(a,b) << endl;
    //cout <<"algoritmo 4: " << algoritmo4(a,b) <<endl;
    //cout <<"algoritmo 5: " << algoritmo5(a,b) << endl;
     cout <<"algoritmo 6: " << algoritmo6(a,b) << endl;


    return 0;
}