#include <iostream>
#include <string>
#include <vector>
#include "tools.h"

using namespace std;

//string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
string abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
//string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int abc_size = abc.size();

#include "cesar.h"
#include "vigenere.h"
#include "afin.h"



int main(){

    Afin emisor;
    Afin receptor;

    string mensaje = "The MEgraph application used to display this network combines techniques such as topological range searching and motion highlighting to enable interactive exploration of complex network diagrams";
    int mul = 2 , aux = 3;


    cout << mensaje << endl <<endl;

    mensaje = emisor.cifrado(mensaje ,mul , aux );
    cout << mensaje << endl << endl;
    mensaje  = receptor.descifrado(mensaje ,mul , aux);
    cout << mensaje << endl << endl;

    return 0;
}