#include <iostream>
#include <vector>
#include "tools.h"

using namespace std;

int restoChino(){

    int n  ,tem ;
    cout <<"Numero de ecuaciones: ";cin >> n;

    vector <int> vec ;

    for(int i = 0 ; i < n ; i++){
        cout << "x = " ;cin >> tem;
        vec.push_back(tem);
        cout << "mod = ";cin >> tem;
        vec.push_back(tem);
    }
    int m = 1;

    for(int i = 1 ; i < n * 2 ; i+=2)
         m *= vec[i];

    cout << "M : " << m << endl;

    int res  = 0 ;
    for(int i = 0 ; i <= n ; i+=2){
        tem = vec[i] * ( m / vec[i+1] ) * inversa( m/vec[i+1] , vec[i+1]) ;
        res +=tem;
    }
    cout << "x = "<< res << "(mod " << m << ")" << endl;

    res = modulo(res , m);

    return res ;
}

int main(){

    cout << restoChino() << endl;

    return 0;
}