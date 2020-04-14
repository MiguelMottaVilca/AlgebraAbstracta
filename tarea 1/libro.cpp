#include <iostream>
#include <string>
#include <vector>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

//ejercicio 7

string Rot13(string mensaje , int key ){
    string cifrado = mensaje;
    for(int i = 0 ; i <= cifrado.size() ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos += key;
        pos %= 26;
        cifrado[i] = abc[pos];
    }
    return cifrado;
}

//ejercicio 11

void concatenar(){
    string nombre , apellido ;
    cout <<"Digite nombre: "; cin >> nombre ;
    cout <<"Digite apellido: "; cin >> apellido ;

    string res( nombre + apellido );
    cout << res << endl;
}

//ejercicio 12

void dibujo(int num){
    if (num == 1){
        cout <<"  o   "<<endl;
    }
    if (num == 2){
        cout <<"   o   "<<endl;
        cout <<"  /    "<<endl;
    }
    if (num == 3){
        cout <<"   o   "<<endl;
        cout <<"  /|  "<<endl;
    }
    if (num == 4){
        cout <<"   o/   "<<endl;
        cout <<"  /|   "<<endl;
    }
    if (num == 5){
        cout <<"   o/  "<<endl;
        cout <<"  /|   "<<endl;
        cout <<"   |   "<<endl;
    }
    if (num == 6){
        cout <<"   o/  "<<endl;
        cout <<"  /|   "<<endl;
        cout <<"   |   "<<endl;
        cout <<"  /    "<<endl;
    }
    if (num == 7){
        cout <<"   o/  "<<endl;
        cout <<"  /|   "<<endl;
        cout <<"   |/   "<<endl;
        cout <<"  /   "<<endl;
    }
}

void ahorcado(){
    string palabra = "hola" , tem;
    tem = palabra;

    for (int i = 0 ; i < palabra.size() ; i++)
        tem[i] = abc[23] ;
    
    cout << tem << endl;

    int contador = 0;
    while ( contador < 7){
        string aux;
        cout <<"ingresar una letra: ";cin >> aux;
        for(int i = 0 ; i < palabra.size() ; i++ ){
            if( aux[0] == palabra[i]){
                tem[i] = palabra[i];
                cout <<'\n'<< tem << endl;
                cout <<"si"<< endl;
                contador--;
            }    
        }
        if(palabra == tem ){
            string aux;
            cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no" << endl; cin >> aux;
            if (aux == "si" )
                ahorcado();
            else
                break;
        }
        contador++;
        dibujo(contador);
    }
}

//ejercicio 19 

void insertar(string texto){
    int size = texto.size();
      
    texto.insert(size/2, "******");

    cout << texto <<endl;
}

//ejercicio 21 Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
//la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).

void ejercicio21(){

    string texto = "hola ,esta es la 'prueba' veremos si funciona!!!!!....XD " ;
    string signos = ".;,:!?'"
    //getline(cin,texto);

    string::iterator i = texto.begin();

    while( i != texto.end()){
        
        i++;
    }

}

//ejercicio 22 

void ejercicio22(){

    string frase;
    cout<< "digite frase: " ; getline(cin,frase);

    string::iterator i = frase.end();
    while(i != frase.begin()){
        cout<< *i ;
        i--;
    }
    cout <<'\n';

}

//ejercicio 27 

void ordenamientoSeleccion(vector <string> myVector){
    
    for (int i = 0 ; i < myVector.size() ; i++){
        int num = i;
        string menor = myVector[num];
        for(int j = i + 1 ; j < myVector.size() ; j++){
            if( myVector[j] < menor ){
                num = j;
                menor = myVector[j];
            }
        }
        string aux = myVector[i];
        myVector[i] = myVector[num];
        myVector[num] = aux; 
    }

    int i = 0 ;
    while(i < myVector.size() ){
        cout<<myVector[i]<<" ";
        i++;
    }
    cout <<endl;
}

int main(){
    //cout << Rot13("ubynnzvtbfpbzbrfgna" , 13) <<endl;
    //concatenar();
    //ahorcado();
    //insertar("hola");
    //ejercicio21();
    //ejercicio22();
    /*     ejercicio27     */
    //vector <string> myVector = { "nada" , "amigo" , "barril"} ;
    //ordenamientoSeleccion(myVector);

    return 0;
}
