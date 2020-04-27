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

#endif //TOOLS_H
