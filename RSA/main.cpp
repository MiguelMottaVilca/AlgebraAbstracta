#include <NTL/ZZ.h>
#include <string>
#include <sstream>
#include <vector>
#include "tools.h"
// #include "criba.h"


using namespace std;
using namespace NTL;

// string abc ="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
//string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
//string abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string abc = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int aux = abc.size() ; 
ZZ abc_size{aux};

#include "rsa.h"

int main(){

    // RSA receptor;
    // RSA emisor(receptor.n,receptor.e);
    // cout <<"cifrado :" << emisor.cifrado("NO") << endl;
    // cout << receptor.descifrado("122482 38146 ") << endl;



    return 0;
}
