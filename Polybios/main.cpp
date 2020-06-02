#include <iostream>
#include <string>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

class Polybios{
    public:
    Polybios();
    string Cifrar(string);
    string Descifrar(string);
};

Polybios::Polybios(){}

string Polybios::Cifrar(string text){
    string cifrado;
    int size  = text.size() , pos ;
    for(int i = 0; i < size; i++){
        pos = abc.find(text[i]);
        cifrado += abc[pos / 5];
        cifrado += abc[pos % 5];
    }
    return cifrado;
}

string Polybios::Descifrar(string text){
    string descifrado;
    int size = text.size() , x , y ;
    for(int i = 0; i < size ; i+=2){
        x = abc.find(text[i]);
        y = abc.find(text[i+1]);
        descifrado += abc[( 5 * x ) + y];
    }
    return descifrado;
}

int main(){

    Polybios a;
    cout << a.Cifrar("holaamigo") << endl;
    cout << a.Descifrar("bccecbaaaaccbdbbce") << endl;

    return 0;
}