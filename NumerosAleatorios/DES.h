#ifndef DES_H
#define DES_H

using namespace std;
using namespace NTL;

ZZ DES( string key , int bits ){

    string res;

    int PC_1[56] = {56,48,40,32,24,16,8,0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,60,52,44,36,28,20,12,4,27,19,11,3};
    int PC_2[48] = {13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,3,25,7,15,6,26,19,12,1,40,51,30,36,46,54,29,39,50,44,32,47,43,48,38,55,33,52,45,41,49,35,28,31};
    
    string C0 ,D0 ,K,tem;

    
    int i = 0 ;
    while(i <= 28 ){
        C0 += key[ PC_1[i] ];
        i++;
    }

    while(i < 56 ){
        D0 += key[ PC_1[i] ];
        i++;
    }

    int j = 1;
    while(j < 22){
        tem = C0[0];
        C0.erase(0,1);
        C0.push_back(tem[0]);
        tem.clear();

        tem = D0[26];
        D0.insert(0,tem);
        D0.erase(27,1);

        tem += C0 ;
        tem += D0;
        i = 0;
        while( i < 48 ){
            K +=  tem[ PC_2[i] ];
            i++;
        }
        res += K; 
        j++;
    }

    string n = "01" ;
    long pos = res.size();
    if(res[pos - 1] == n[0] ){
        res[pos - 1] = n[1];
    }

    ZZ num;
    num = stringBits_ZZ(res);

    return num;       
}

#endif //DES_H