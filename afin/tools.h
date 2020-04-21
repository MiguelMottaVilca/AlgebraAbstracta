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

int euclides(int num ,int d ){
    int r = 1;

    while (r > 0){
        r  = modulo( num , d);
        num = d ;
        d = r;
    }
    return num ;
}

vector <int> euclideanExtended(int a, int b) {
    int d , x , y;
    vector <int> dataRes ; 
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        dataRes.push_back(d);
        dataRes.push_back(x);
        dataRes.push_back(y);
        return dataRes;
    }

    int x2 = 1 , x1 = 0 , y2 = 0 , y1 = 1 , q ,r;

    while (b > 0) {
        q = a / b;
        r = a - (q * b);
        x = x2 - (q * x1);
        y = y2 - (q * y1);
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    d = a;
    x = x2;
    y = y2;
    dataRes.push_back(d);
    dataRes.push_back(x);
    dataRes.push_back(y);

    return dataRes;
}

int inverse(int a, int b) {
    int result = euclideanExtended(a, b)[1];
    if (euclideanExtended(a, b)[1] < 0) {
        result = modulo(euclideanExtended(a, b)[1], b);
    }
    return result;
}


// int euclidesExtend(int num , int d){  
// }


#endif //TOOLS_H