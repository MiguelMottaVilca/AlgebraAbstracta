#include <iostream>
#include <string>
#include <vector>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";
int size_abc = abc.size();

//ejercicio 7

string Rot13(string mensaje , int key ){
    string cifrado ;
    for(int i = 0 ; i <= cifrado.size() ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos += key;
        pos %= size_abc;
        cifrado = abc[pos];
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

void ahorcado1(string palabra){
    string tem = palabra;
    tem.append(palabra.size(),'X');
    cout << tem << endl;

    int vida = 7;
    bool perder_vida = true; 
    while ( vida != 0 or tem == palabra){
        string aux;
        cout <<"ingresar una letra: ";cin >> aux;
        for(int i = 0 ; i < palabra.size() ; i++ ){
            if( palabra[i] == aux[0] ){
                tem[i] = palabra[i];
                perder_vida = false;
            }    
        }
        if (perder_vida == true){
            vida --;
            dibujo(vida);
        }
        else {
            cout << endl << "SI" << endl;
        }        
    }
    if (vida > 0 ){
        string aux;
        cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no" << endl; cin >> aux;
            if (aux == "si" )
                ahorcado("palabra"); //añadir buscador
    }
}

void ahorcado2(string palabra){
    string oculto , copia = palabra ;
    oculto.append(palabra.size(),'X');
   
    int vida = 7 ;
    
    while(vida != 0 or (copia == oculto) ){
        string tem;
        cout <<"Digite letra: "; cin>>tem;
        bool perder_vida = true;
        int pos = palabra.find(tem) ;
        
        while( pos + 1 ){
            oculto[pos] = copia[pos];
            palabra.erase(pos,1);
            
            pos = copia.find(tem);
            perder_vida = false;
        }
        if (perder_vida == true){
            vida--;
        }
        cout <<"adivinar:" <<oculto << endl;
        cout <<"copia: " <<copia << endl ;
        cout <<"palabra: "<<palabra << endl;
        cout << endl;
    }
    if (vida > 0)
        cout << "ganaste" <<endl;
    else
        cout <<"perdiste" << endl; 
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
