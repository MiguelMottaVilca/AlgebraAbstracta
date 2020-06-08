#include <iostream>
#include <string>
#include <vector>
#include "tools.h"
#include "criba.h"

using namespace std;

string abc ="abcdefghijklmnopqrstuvwxyz";
//string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
//string abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
//string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string abc = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int abc_size = abc.size();

#include "cesar.h"
#include "vigenere.h"
#include "afin.h"



int main(){

    Afin a;
    Afin b(25,24);

    cout << a.cifrado("hola") << endl;
    cout << b.descifrado("rkny") << endl;
    
    return 0;
}