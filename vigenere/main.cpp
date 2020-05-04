#include <iostream>
#include <string>
#include <vector>
#include "tools.h"

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
//string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// string abc;

int abc_size = abc.size();

#include "cesar.h"
#include "vigenere.h"


void tres_e(string &mensaje){
    for (int i = 10 ; i < mensaje.size() ; i+=14)
       mensaje.insert(i,"AQUI"); 
    
    int aux = mensaje.size() % 4;
    if (!(aux))
        mensaje.append(aux,'W');
}



int main(){
    /*llenado de abc con ascii*/
    // for (int i = 32 ; i <= 126 ;i++ ){
    //     string aux(1,i);
    //     abc +=aux;
    // }
    // abc_size=abc.size();
    

    Vigenere emisor;
    Vigenere receptor;

    string mensaje = "Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.";
    string clave = "Pablo Neruda";


    /* ejercicio 3e */
    tres_e(mensaje);

    cout << mensaje << endl;

    // string mensaje = "NOFUEINDESCIFRABLE";
    // string clave = "PEROCASI";

    // cout << mensaje << endl << endl;
    // mensaje = emisor.cifrado(mensaje ,clave );
    // cout << mensaje << endl << endl;
    // mensaje  = receptor.descifrado(mensaje,clave);
    // cout << mensaje << endl << endl;

    return 0;
}
