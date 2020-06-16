#include <NTL/ZZ.h>

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

ZZ expModular(ZZ num , ZZ  n , ZZ mod){
    if (n == 0) return ZZ(1);
    ZZ exp {1} , dos{2};
    ZZ x = modulo(num,mod);

    while(n > 0){
        if(modulo(n,dos) ==  0){
            exp = exp * x ;
            exp = modulo(exp,mod);
        }
        x = x*x;
        x = modulo(x,mod);
        n /= 2; 
    }
    return exp;
}

int main(){



    return 0 ; 
}