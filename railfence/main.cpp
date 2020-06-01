#include <iostream>
#include <string>

using namespace std;

class RailFence{
    int clave ;
    string mensaje;
    public:
    RailFence(string);
    string cifrado();
    string descifrado();
};
RailFence::RailFence(string text){
    clave = 3;
    mensaje = text;
}

string RailFence::cifrado(){
    string aux;
    int cont = mensaje.size();

    for(int i = 0;i <= cont ; i+=4)
        aux +=mensaje[i]; 
    for(int i = 1;i <= cont ; i+=2)
        aux +=mensaje[i]; 
    for(int i = 2;i <= cont ; i+=4)
        aux +=mensaje[i]; 
    
    return aux;
}

string RailFence::descifrado(){
    string aux;
    int cont = mensaje.size();
    for(int i = 0;i <= cont ; i+=4)
        aux +=mensaje[i]; 
    for(int i = 1;i <= cont ; i+=2)
        aux +=mensaje[i]; 
    for(int i = 2;i <= cont ; i+=4)
        aux +=mensaje[i]; 

    return aux;
}

int main (){

    RailFence a("RailFenceCipher");
    cout << a.cifrado() << endl;
    RailFence b("RFehalecCpeinir");
    cout << b.descifrado() << endl;

    return 0;
}
//rail fence ,playFair y monomio binomio