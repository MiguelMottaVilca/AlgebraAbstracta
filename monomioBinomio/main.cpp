#include <iostream>
#include <string>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

class MonomioBinomio{
    string clave, mensaje , tabla;
    int num1 , num2;
    public:
    MonomioBinomio(string,string);
    string cifrado();
    string descifrado(string);
};

MonomioBinomio::MonomioBinomio(string key , string text){
    clave = key;
    mensaje = text;
}

string MonomioBinomio::cifrado(){
    // int num1 = 0 + rand()%(10-1), num2 = 0 + rand()%(10-1) , size = clave.size() ;
    num1 = 2 , num2 = 7 ;
    int size = clave.size();

    string  cifrado;
    int pos;

    for(int i = 0 ; i < size ; i++ ){
        if( ((i % 10) == num1 ) or ((i % 10) == num2) )
            tabla+=" ";
        tabla += clave[i];   
        pos = abc.find(clave[i]);
        abc.erase (pos,1);
    }
    size = abc.size();
    for( int i = 0 ; i < size ;i ++){
        tabla +=abc[i];
    }

    while( tabla.size() % 10 )
        tabla+="#";
    // dena rio sbcfghjklmpqtuvwxyz##
    size = mensaje.size();
    string tem;
    for(int i = 0 ; i < size ; i++){
        pos = tabla.find(mensaje[i]);
        if(( pos < 10)){
            cifrado+= to_string(pos);
        }
        if(( pos > 9) and (pos < 20 )){
            cifrado +=to_string(num1);
            tem =  to_string(pos % 10);
            cifrado +=tem;
        }
        if(( pos > 19) ){
            cifrado +=to_string(num2);
            tem =  to_string(pos % 10);
            cifrado +=tem;
        } 
    }

    return cifrado;
}

string MonomioBinomio::descifrado(string text){
    string descifrado , tem;
    int size = text.size() , aux;
    for(int  i = 0 ; i < size ; i++){
        tem = text[i];
        aux = stoi(tem);

        if(aux == num1){
            tem = text[i+1];
            aux = stoi(tem);
            aux +=10;
            i++;
        } 
        if(aux == num2){
            tem = text[i+1];
            aux = stoi(tem);
            aux +=20;
            i++;
        }

        cout << aux << " " ;
        descifrado += tabla[aux];
    }
    cout << endl;
    return descifrado;
}

int main (){

    MonomioBinomio a("denarios","esteeselmensaje");
    cout << a.cifrado() << endl;
    cout << a.descifrado("1971119127281394251") << endl;

    return 0;
}
