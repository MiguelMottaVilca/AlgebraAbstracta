#ifndef TOOLS_H
#define TOOLS_H

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

ZZ modulo(ZZ num , int d ){
    ZZ c , r;
    c = num / d ;
    r = num - ( c * d );
    if (r < 0)
        r = r + d ;
    return r ;
}

ZZ valorAbsoluto(ZZ a){
    if ( a < 0)
        a *=-1;
    return a;
}



#endif //TOOLS_H
