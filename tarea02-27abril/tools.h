#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>

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

int valorAbsoluto(int a){
    if ( a < 0)
        a *=-1;
    return a;
}



#endif //TOOLS_H