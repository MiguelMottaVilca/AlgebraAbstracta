#ifndef RC4_H
#define RC4_H

using namespace std;
using namespace NTL;

string RC4(){
    Vec <long> s , k = vecRan() ;

    for(long i = 0 ; i < 256 ; i++)
        s.append(i);

    long f = 0  , bar ;
    
    long tem = 0;
    for(long i = 0 ; i < 256 ; i++ , tem++){
        if ( tem == k.length() )
            tem = 0;
        f = f + s[i] + k[tem] ;
        if (f >= 4)
            f = conv<long>(modulo(ZZ(f), ZZ(256) ));
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
        Or += buffer.str() ;
    }
    return Or;
}


#endif //RC4_H
