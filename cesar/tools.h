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
        num = d;
        d = r;
        r = modulo(num,d);
    }
    return d;
}

vector <int> euclideanExtended(int a, int b) {
    int d , x , y;
    vector <int> res ;
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        res.push_back(d);
        res.push_back(x);
        res.push_back(y);
        return res;
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
    res.push_back(d);
    res.push_back(x);
    res.push_back(y);

    return res;
}


#endif //TOOLS_H
