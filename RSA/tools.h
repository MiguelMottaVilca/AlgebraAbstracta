#ifndef TOOLS_H
#define TOOLS_H

// #include <iostream>
using namespace std;
using namespace NTL;

ZZ modulo(ZZ num , ZZ d ){
   ZZ c , r;
   c = num / d ;
   r = num - ( c * d );
   if (r < 0)
       r = r + d ;
   return r ;
}

ZZ euclides(ZZ a ,ZZ b){
   ZZ r ;
   r = modulo(a,b);
   while(r > 0){
       if (r > (b/2) )
           r = b - r;
       a = b;
       b = r;
       r = modulo(a,b);
   }
   return b ;
}

ZZ euclidesExtendido(ZZ a ,ZZ b){
   ZZ res;
   ZZ r1{a} , r2 {b} , s1{1} , s2{0} , t1{0} ,t2{1} ;
   ZZ q , r , s , t;
 
   while(r2 > 0 ){
       q = r1/r2;
 
       r = r1 - q*r2 ;
       r1 = r2 ; r2 = r ;
 
       s = s1 - q*s2;
       s1 = s2 ; s2 = s ;
 
       t = t1 - q*t2 ;
       t1 = t2 ; t2 = t;
   }
   res = s1 ;
   return res;
}

ZZ inversa(ZZ x , ZZ y ){
    ZZ num ;
    num = euclides(x,y);
    if( num == 1){
        ZZ aux;
        aux = euclidesExtendido(x,y);
        if (aux  < 0 )
            aux = modulo(aux , y );
        return  aux;
    }
    else{
        num = 0; 
        cout << "NO TIENE INVERSA" << endl;
        return num;
    }
}

ZZ pow(ZZ num ,ZZ n){
    if (n == 0){
        ZZ aux{0};
        return  aux;
    }
    ZZ aux{num};
    for(long i = 1 ; i < n ;i++)
        aux *=num; 
    return num;
}

ZZ expModular(ZZ num , ZZ  n , ZZ mod){
    if (n == 0) 
        return ZZ(1);
    ZZ exp {1} ;
    ZZ x = modulo(num,mod);

    while(n > 0){
        if(modulo(n,ZZ(2)) ==  0){
            exp = exp * x ;
            exp = modulo(exp,mod);
        }
        x = x*x;
        x = modulo(x,mod);
        n /= 2; 
    }
    return exp;
}

string ZZtoString(const ZZ &z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ stringToNumber(string cadena){
    ZZ num ;
	istringstream(cadena) >> num;
	return num;
}

 

#endif //TOOLS_H