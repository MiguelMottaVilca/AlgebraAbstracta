#include <iostream>
#include <string>

using namespace std;

int abs(int num){
    if(num >= 0)
        return num;
    else 
        return num * -1;
}

string abc = "abcdefghijklmnopqrstuvwxyz"; 

class PlayFair{
    string clave , mensaje;
    public:
    PlayFair(string , string);
    string cifrado();
    string descifrado();
};

PlayFair::PlayFair(string key , string text){
    clave = key;
    mensaje = text;
}

string PlayFair::cifrado(){
    string cifrado , tem;
    int size = clave.size() , aux , aux2;
    for(int i = 0 ; i < size ;i++){
        aux = tem.find(clave[i]);
        if( aux == -1){
            tem += clave[i];
            aux = abc.find(clave[i]);
            abc.erase(aux,1);
        }
    }
    size = abc.size();
    for(int i = 0 ; i < size ;i++ )
        tem+=abc[i];

    cout << tem << endl;

    size = mensaje.size() / 2;
    for(int i = 0 ; i < size ; i++){
        aux = tem.find(mensaje[i]); 
        aux2 = tem.find(mensaje[i+1]);
        if( abs(aux - aux2) <= 4 ){
            if((aux % 5) == 4) 
                aux -= 5;
            if((aux2 % 5) == 4)
                aux2 -= 5; 
            cifrado += mensaje[aux+1];
            cifrado += mensaje[aux2+1];
        }
        else if (abs(aux - aux2) == 5 ){
            if( aux >= 20 )
                aux -= 20;
            if( aux2 > 20)
                aux2 -= 20;
            cifrado += mensaje[aux+5];
            cifrado += mensaje[aux2+5];
        }
        else{

        }    
    }

    return cifrado;
}

string PlayFair::descifrado(){
    string descifrado , tem;
    int size = clave.size() , aux , aux2;
    for(int i = 0 ; i < size ;i++){
        aux = tem.find(clave[i]);
        if( aux == -1){
            tem += clave[i];
            aux = abc.find(clave[i]);
            abc.erase(aux,1);
        }
    }
    size = abc.size();
    for(int i = 0 ; i < size ;i++ )
        tem+=abc[i];

    cout << tem << endl;

    size = mensaje.size() / 2;
    for(int i = 0 ; i < size ; i++){
        aux = tem.find(mensaje[i]); 
        aux2 = tem.find(mensaje[i+1]);
        if( abs(aux - aux2) <= 4 ){
            if((aux % 5) == 4) 
                aux -= 5;
            if((aux2 % 5) == 4)
                aux2 -= 5; 
            descifrado += mensaje[aux-1];
            descifrado += mensaje[aux2-1];
        }
        else if (abs(aux - aux2) == 5 ){
            if( aux >= 20 )
                aux -= 20;
            if( aux2 > 20)
                aux2 -= 20;
            descifrado += mensaje[aux-5];
            descifrado += mensaje[aux2-5];
        }
        else{

        }    
    }


    return descifrado;
}

int main(){

    PlayFair a("playfairexample","hidethegoldinthetreestump");
    cout << a.cifrado() << endl;
    cout << a.descifrado() << endl;

    return 0;
}