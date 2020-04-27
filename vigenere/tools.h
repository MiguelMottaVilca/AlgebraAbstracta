#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

using namespace std;

int modulo(int num , int d ){
    int c , r;
    c = num / d ;
    r = num - ( c * d );
    if (r < 0){
        c -= 1 ; 
        r = r + d ;
    }
    return r ;
}

int euclides(int num , int d){
    int r = modulo(num,d);
    while(r > 0){
        cout << "vuelta nuevo" << endl;
        num = d;
        d = r;
        r = modulo(num,d);
    }
    return d;
}

// int euclidesExtend(int num , int d){  
// }


#endif //TOOLS_H
