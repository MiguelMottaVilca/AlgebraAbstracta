#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

using namespace std;

int modulo(int num , int d ){
   int c , r;
   c = num / d ;
   r = num - ( c * d );
   if (r < 0)
       r = r + d ;
   return r ;
}
 
int euclides(int a ,int b){
   int r = modulo(a,b);
   while(r > 0){
       if (r > (b/2) )
           r = b - r;
       a = b;
       b = r;
       r = modulo(a,b);
   }
   return b ;
}
 
vector <int> euclidesExtendido(int a , int b){
   vector <int> res;
   int r1 = a , r2 = b , s1 = 1 , s2 = 0 , t1 = 0 ,t2 = 1 ;
   int q , r , s , t;
 
   while(r2 > 0 ){
       q = r1/r2;
 
       r = r1 - q*r2 ;
       r1 = r2 ; r2 = r ;
 
       s = s1 - q*s2;
       s1 = s2 ; s2 = s ;
 
       t = t1 - q*t2 ;
       t1 = t2 ; t2 = t;
   }
   res.push_back(r1); // gcd( a, b)
   res.push_back(s1);
   res.push_back(t1);
 
   return res;
}
 
int inversa(int x , int y ){
    int num = euclides(x,y);
    if( num == 1){
        vector <int> aux = euclidesExtendido(x,y);
        num = aux[1];
        if (num  < 0 )
            num = modulo(num , y );
        return  num;
    }
    else{
        cout << "NO TIENE INVERSA" << endl;
        return 0;
    }
}

long pow(long num ,long n){
    if (n == 0)
        return 1;

    long aux = num;
    for(int i = 1 ; i < n ;i++)
        aux *=num; 
    return num;
}

int expModular(int num ,int n ,int mod){
    if (n == 0)
        return 1;

    long aux = num;
    for(int i = 1 ; i < n ;i++){
        aux *= num;
        if(aux > mod){
            aux = modulo(aux,mod);
        }
        if(aux == 1)
            return 1; 
    }
    return num;
}


#endif //TOOLS_H