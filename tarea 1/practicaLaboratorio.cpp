#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


//ejercicio 1

string charAstring( char *ptr ,int size){
    string text;

    for (int i = 0 ; i < size ;i++ )
        text += ptr[i];

    return text;
}

void stringAchar(string text ){

    int size = text.size();
    char arr[size -1] ;

    for(int i = 0 ; i < size ; i++)
        arr[i] =  text[i];
    
    for(int i = 0 ; i < size ; i++)
        cout << arr[i];  
}

//ejercicio 3

void minusculaAmayuscula(string text){

    string::iterator a = text.begin();

    while(a != text.end()){
        *a = char(int(*a) - 32);
        a++;
    }

    cout << text << endl;
}

void mayusculaAminuscula(string text){

    string::iterator a = text.begin();

    while(a != text.end()){
        *a = char(int(*a) + 32);
        a++;
    }

    cout << text << endl;
}

//ejercicio 4

void ejercicio4(void){
    int x , y ;
    cout << "numero: "; cin >> x;
    cout << "numero: "; cin >> y;

    string a = to_string(x) ;
    string b = to_string(y) ;

    string c( a + b );
    cout << c << '\n';

    int num = stoi(c) * 2;
    cout << num << '\n';
}

//ejercicio 5 

void ejercicio5(){

    string x ;
    x.append(1000u , 'a');

    cout << x << endl;
    cout << x.size() << endl;

}

//ejercicio 6  

void ejercicio6(){

    string frase = "Yo desaprobe el curso de Algebra Abstracta";
    int pos = frase.find("desaprobe");

    frase.erase(pos,9);
    cout << frase << endl;

    frase.insert(pos , "aprobe");
    cout << frase << endl;

}

//ejercicio 7 

void ejercicio7(){
    string frase , palabra ;
    cout << "digite frase: " ;getline(cin,frase);
    cout << "digite palabra: " ;cin>>palabra;
    
    int contador = 0 , size_palabra = palabra.size();
    cout << "palabra: " << size_palabra << endl;

    for (int i = 0 ; i < frase.size() ; i++){
        if (frase.compare(i,size_palabra,palabra) == 0)
            contador++;
    }
    cout << contador << endl;
}

//ejercicio 8

void ejercicio8(){
    string texto ;
    cout << "digite frase: " ; getline(cin,texto);

    string::iterator i = texto.begin();

    while( i != texto.end() ){
        cout << *i << '\n';
        i++;
    }
        
}

//ejercicio 9

void ejercicio9(){
    string x , y ;

    cout << "digite palabra: " ;cin >> x;
    cout << "digite palabra: " ;cin >> y;

    int size = x.size();
    x.insert(size/2, y);

    cout << x << endl;    
}

//ejercicio 10

void ejercicio10(){
    string frase ="Cuando te diga que te creo, no me creas, porque ya no creo lo que creo.", palabra1 , palabra2;
    
    //cout << "digite frase: " ;getline(cin,frase);
    cout << "digite palabra a buscar: " ;cin >> palabra1;
    cout << "digite palabra de reemplazo: " ;cin >> palabra2;

    for (int i = 0 ; i < frase.size() ; i++){
        if (frase.compare(i,palabra1.size(),palabra1) == 0 ){
            frase.erase(i,palabra1.size());
            frase.insert(i,palabra2);
        }
    }
    cout<< frase <<endl;
}

//ejercicio 11

void ejercicio11(){
    string palabra1 , palabra2 , mayor;
    cout <<"digite palabra: " ; cin >> palabra1;
    cout <<"digite otra palabra: " ; cin >> palabra2;

    mayor = (palabra1 > palabra2)? palabra1 : palabra2;
    cout << mayor << endl;
}

//ejercicio 12

void escribir(int num){

    ostringstream aux; //sstream
    string text;
    aux << num << "-" ;

    text = aux.str();

    ofstream archivo; //fstream

    archivo.open("numeros.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<'\n';

    archivo<< text ;

    archivo.close();
}


void ejercicio12(){
    int num , numeroAleatorio;
    cout << "digite un numero del 1 a 10: " ; cin >> num ;
    // srand(time(NULL));

    for(int i = 0 ; i < num ; i++){
        numeroAleatorio = 1 + rand() % (1001 - 1);
        cout << numeroAleatorio << endl;
        escribir(numeroAleatorio);
    }
}

//ejercicio 13

string lectura(void){

    ifstream archivo; //fstream
    string texto;

    archivo.open("numeros.txt",ios::in);

    if (archivo.fail())
        cout<<"No se  abrir el archivo"<<endl;

    string tem;
    while (getline(archivo,tem)) 
        texto +=tem;
    
    return texto ;
}

void ejercicio13(string numeros){

    int suma = 0 , size = numeros.size() ;
    string tem ;
    string::iterator i = numeros.begin();

    while(i != numeros.end()){
        if (*i != '-' )
            tem += *i;
        if (*i == '-'){
            int num = stoi(tem);
            suma += num;
            tem.clear();
        }
        i++;
    }
    cout << suma <<endl; 
}

int main(){

    //cout << charAstring(y,4) <<endl;
    //stringAchar("hola");
    /*   ejercicio 3   */
    //minusculaAmayuscula("hola");
    //mayusculaAminuscula("HOLA");
    //ejercicio4();
    //ejercicio5();
    //ejercicio6();
    //ejercicio7();
    //ejercicio8();
    //ejercicio9();
    //ejercicio10();
    //ejercicio11();
    //ejercicio12();
    /*   ejercicio13   */
    //ejercicio13(lectura());


    return 0;
}