#ifndef MIZZERRABIN_H
#define MIZZERRABIN_H

using namespace std;
using namespace NTL;


ZZ mulmod(ZZ a, ZZ b, ZZ m) {
   ZZ x {0} ,y = modulo( a , m);
   while (b > 0) {
      if (b % 2 == 1) {
         x = modulo( (x + y) , m) ;
      }
      y =  modulo( (y * 2) , m);
      b /= 2;
   }
   return x % m;
}

bool MillerRabin(ZZ p, int iteration) {
   if (p < 2) 
      return false;
   
   if (p != 2 && p % 2==0) 
      return false;
   
   ZZ s = p - 1;
   while ( modulo( s , ZZ(2))  == 0 ) {
      s /= 2;
   }
   for (int i = 0; i < iteration; i++) {
        ZZ a , temp ,mod ;
        a = modulo( ZZ(rand()) , (p - 1)) + 1, 
        temp = s;
        mod = expModular(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p) ;
            temp *= 2; 
        }
        if (mod != p - 1 && temp % 2 == 0) {
            return false;
      }
   }
   return true;
}


#endif //MIZZERRABIN_H
