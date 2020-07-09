#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <string>
#include <sstream>
#include <bitset> 
#include <cstdlib>
#include <cstdio>
#include <array>

#include "tools.h"
#include "aleatotios.h"
#include "RC4.h"
#include "DES.h"

using namespace std;
using namespace NTL;


int main(){ 
    
    unsigned t0, t1;

    t0=clock();
    ZZ num ;
    for(int i = 0 ;i < 10 ; i++){
        num = DES( RC4()  , 84) ;
        // cout << num << endl;
    }
    t1 = clock();
    double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time 1: " << time1 << endl;
     
    return 0;
}
