#ifndef DES_H
#define DES_H

using namespace std;
using namespace NTL;

void moverIzq(string &cadena){
    char tem = cadena[0];
    cadena.erase(0,1);
    cadena.push_back(tem);
}

ZZ DES( string key , int bits ){

    int PC_1[56] = {56,48,40,32,24,16,8,0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,60,52,44,36,28,20,12,4,27,19,11,3};
    int PC_2[48] = {13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,3,25,7,15,6,26,19,12,1,40,51,30,36,46,54,29,39,50,44,32,47,43,48,38,55,33,52,45,41,49,35,28,31};
    
    string C0 , D0 , K ,tem , aux , res;

    for(int i = 0 ; i < 56; i++ )
        tem += key[ PC_1[i] ];

    for(int i = 0 ; i < 28; i++ )
        C0 += tem[i];
      
    for(int i = 28 ; i < 56; i++ )
        D0 += tem[i];


    int j = 1 , p = (bits / 48) + 1;
    while(j <= p){

        if( (j > 2) and  ((j % 7) - 2 == 0) ){
            moverIzq(C0);
            moverIzq(D0);
        }

        moverIzq(C0);
        moverIzq(D0);

        aux += C0 ;
        aux += D0;
        
        for(int i = 0 ; i < 48 ;i++)
            K +=  aux[ PC_2[i] ];
            
        tem = K;
        res += K; 
        K.clear();

        j++;
    }
    long tam = res.size();

    if(tam != bits){
        tam -= bits;
        res.erase(0,tam);
    }

    tam = res.size();

    string n = "01" ;
    if(res[tam - 1] == n[0] )
        res[tam - 1] = n[1];

    ZZ num;
    num = stringBits_ZZ(res);

    return num;    
}

#endif //DES_H

