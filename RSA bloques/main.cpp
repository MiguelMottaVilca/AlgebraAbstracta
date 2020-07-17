#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <string>
#include <sstream>
#include <bitset> 
#include <cstdlib>
#include <cstdio>
#include <array>

#include "tools.h"
#include "restoChino.h"
#include "aleatotios.h"
#include "RC4.h"
#include "DES.h"
#include "millerRabin.h"


using namespace std;
using namespace NTL;

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
//string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
// string abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
// string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string abc = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int abc_size = abc.size() ; 

#include "rsaBloques.h"

int main(){

    RSA receptor( 1024 ); 
    RSA emisor( receptor.e , receptor.n ); //  e  , n   
    string cifrado = emisor.cifrado("Miguel Alberto Motta Vilca 72210866 CampoVerdeA33Sachaca") ;
    cout <<"CIFRADO  : \n" << cifrado  << endl;

    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;


    string descifrado = receptor.descifrado(cifrado);
    cout << "DESCIFRADO  : \n" << descifrado << endl;
    
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    
    string cifradoProtocolo = emisor.cifradoConProtocolo("Miguel Alberto Motta Vilca 72210866 CampoVerdeA33Sachaca") ;
    cout <<"CIFRADO  : \n" << cifradoProtocolo << endl;

    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;

    string descifradoProtocolo = receptor.descifradoConProtocolo(cifradoProtocolo);
    cout << "DESCIFRADO  : \n" << descifradoProtocolo << endl;

    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    

    return 0;
}
