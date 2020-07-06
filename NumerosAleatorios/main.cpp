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

using namespace std;
using namespace NTL;

string RC4(ZZ bits){
    Vec <long> s , k = vecRan() ;

    for(long i = 0 ; i < bits ; i++)
        s.append(i);

    long f = 0  , bar ;
    
    long tem = 0;
    for(long i = 0 ; i < bits ; i++ , tem++){
        if ( tem == k.length() )
            tem = 0;
        f = f + s[i] + k[tem] ;
        if (f >= 4)
            f = conv<long>(modulo(ZZ(f), bits));
        swap( s[i], s[f] );
    }

    string Or ;

    bitset<8> foo;
    long i = 0 ;
    f = 0 ;
    
    for( long it = 0 ; it < 8 ; it++ ){
        i =  conv<long>(modulo( ZZ(i + 1) , ZZ(256) )) ;
        f =  conv<long>(modulo( ZZ(f + s[i]) , ZZ(256) )) ;
        swap( s[i], s[f]);
        tem = conv<long>(modulo ( ZZ(s[i] + s[f])  , ZZ(256) )) ;
        foo = s[tem] ;
        stringstream buffer;
        buffer << foo;
        // cout << buffer.str() << endl;
        Or += buffer.str() ;
    }
    return Or;
}

string DES( string key , int bits ){

    string res;

    Vec <int> PC_1 ;
    PC_1.append(57);
    PC_1.append(49);
    PC_1.append(41);
    PC_1.append(33);
    PC_1.append(25);
    PC_1.append(17);
    PC_1.append(9);
    PC_1.append(1);
    PC_1.append(58);
    PC_1.append(50);
    PC_1.append(42);
    PC_1.append(34);
    PC_1.append(26);
    PC_1.append(18);
    PC_1.append(10);
    PC_1.append(2);
    PC_1.append(59);
    PC_1.append(51);
    PC_1.append(43);
    PC_1.append(35);
    PC_1.append(27);
    PC_1.append(19);
    PC_1.append(11);
    PC_1.append(3);
    PC_1.append(60);
    PC_1.append(52);
    PC_1.append(44);
    PC_1.append(36);
    PC_1.append(63);
    PC_1.append(55);
    PC_1.append(47);
    PC_1.append(39);
    PC_1.append(31);
    PC_1.append(23);
    PC_1.append(15);
    PC_1.append(7);
    PC_1.append(62);
    PC_1.append(54);
    PC_1.append(46);
    PC_1.append(38);
    PC_1.append(30);
    PC_1.append(22);
    PC_1.append(14);
    PC_1.append(6);
    PC_1.append(61);
    PC_1.append(53);
    PC_1.append(45);
    PC_1.append(37);
    PC_1.append(29);
    PC_1.append(21);
    PC_1.append(13);
    PC_1.append(5);
    PC_1.append(28);
    PC_1.append(20);
    PC_1.append(12);
    PC_1.append(4);

    Vec <int> PC_2 ;

    PC_2.append(14);
    PC_2.append(17);
    PC_2.append(11);
    PC_2.append(24);
    PC_2.append(1);
    PC_2.append(5);
    PC_2.append(3);
    PC_2.append(28);
    PC_2.append(15);
    PC_2.append(6);
    PC_2.append(21);
    PC_2.append(10);
    PC_2.append(23);
    PC_2.append(19);
    PC_2.append(12);
    PC_2.append(4);
    PC_2.append(26);
    PC_2.append(8);
    PC_2.append(16);
    PC_2.append(7);
    PC_2.append(27);
    PC_2.append(20);
    PC_2.append(13);
    PC_2.append(2);
    PC_2.append(41);
    PC_2.append(52);
    PC_2.append(31);
    PC_2.append(37);
    PC_2.append(47);
    PC_2.append(55);
    PC_2.append(30);
    PC_2.append(40);
    PC_2.append(51);
    PC_2.append(45);
    PC_2.append(33);
    PC_2.append(48);
    PC_2.append(44);
    PC_2.append(49);
    PC_2.append(39);
    PC_2.append(56);
    PC_2.append(34);
    PC_2.append(53);
    PC_2.append(46);
    PC_2.append(42);
    PC_2.append(50);
    PC_2.append(36);
    PC_2.append(29);
    PC_2.append(32);
    // cout << PC_1 << endl;
    // cout << PC_2 << endl;
    
    
    string C0 ,D0 ,K,tem;
    int j = 0;
    while(j < 3){
        int i = 0 ;
        while(i < 27 ){
            C0 += key[ PC_1[i] ];
            i++;
        }
        tem = C0[0];
        C0.erase(0,1);
        C0.push_back(tem[0]);

        while(i < 54 ){
            D0 += key[ PC_1[i] ];
            i++;
        }
        tem = D0[26];
        D0.insert(0,tem);
        D0.erase(27,1);

        tem.clear();
        tem += C0 ;
        tem += D0;
        i = 0;
        while( i < 48 ){
            K +=  tem[ PC_2[i] ];
            i++;
        }
        // cout << "K: " << K << endl;
        res += K; 
        // cout << K.size() << endl; 
        key = K;
        j++;
    }

    string n = "01" ;
    long pos = res.size();
    if(res[pos - 1] == n[0] ){
        res[pos - 1] = n[1];
    }

    return res;
        
}

int main(){

    // cout << RC4(ZZ(256)) << endl ;
    
    string num = DES( RC4(ZZ(1024)) , 84);

    // string num = "111";
   
    cout << num << endl;

    long size = num.size();

    string uno = "01";
    ZZ res , tem {size - 1 };
    for(long i = 0 ; i < size ; i++ ){
        if (num[i] == uno[1]){
            res += pow(ZZ( 2 ) , ZZ(tem));
            // cout << "tem :" << tem << endl;
            tem -= 1 ;
        }
    }

    cout << res << endl;
    

    return 0;
}