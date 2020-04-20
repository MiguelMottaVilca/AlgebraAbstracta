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

int euclides(int num ,int d ){
    int c , r ;

    while (r > 0){
        r  = modulo( num , d);
        num = d ;
        d = r;
    }
    return num ;
}

// int euclidesExtend(int num , int d){  
// }


#endif //TOOLS_H
