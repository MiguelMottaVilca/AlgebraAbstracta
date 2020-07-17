#ifndef RESTOCHINO_H
#define RESTOCHINO_H

using namespace std;
using namespace NTL;

ZZ restoChino(Vec <ZZ> vec){
    ZZ res, m , p1 , p2 , q1 ,q2 ;
    m = vec[2] * vec[5];
    p1 = m / vec[2];
    p2 = m / vec[5];
    q1 = inversa(p1,p2);
    q2 = inversa(p2,p1);

    ZZ tem1 , tem2;
    tem1 = expModular(vec[0],vec[1],m);
    tem2 = expModular(vec[3],vec[4],m);

    res = tem1 * vec[5] * q1 + tem2 * vec[2] * q2 ;
    res = modulo(res , m);

    return res;
}

#endif //RESTOCHINO_H
