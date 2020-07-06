#ifndef ALEATORIOS_H
#define ALEATORIOS_H

// #include <iostream>
using namespace std;
using namespace NTL;


Vec <long> vecRan(){

    string command("istats");
    array<char, 128> buffer;
    string result;
    
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
        cerr << "Couldn't start command." <<endl;
    
    while (fgets(buffer.data(), 128, pipe) != NULL)
        result += buffer.data();
    
    auto returnCode = pclose(pipe);
    /*
    cout << "--------------------"<< endl;
    cout << result << endl;
    cout << "--------------------"<< endl;
    cout << returnCode << endl;
    */
    Vec <long> numeros;
    string tem;

    // cout << "---------- temperatura CPU ----------" << endl;
    long pos = result.find("°");
    pos -=5;
    for ( long i = 0 ; i < 5 ; i++ ){
        tem += result[pos + i];
    }
    pos = tem.find(".");
    if(pos != - 1)
        tem.erase (pos,1);
    numeros.append(  stoi(tem) );
    // cout << tem <<endl;
    tem.clear();

    // cout << "---------- rpm ----------"<< endl;
    pos = result.find("RPM");
    pos -=5;
    for ( long i = 0 ; i < 5 ; i++ ){
        tem += result[pos + i];
    }
    numeros.append(  stoi(tem) );
    // cout << tem <<endl;
    tem.clear();

    // cout << "---------- bateria ciclos % ----------"<< endl;
    pos = result.find("%");
    pos -=5;
    for ( long i = 0 ; i < 5 ; i++ ){
        tem +=  result[pos + i];
    }
    pos = tem.find(".");
    if(pos != - 1)
        tem.erase (pos,1);
    numeros.append(  stoi(tem) );
    // cout << tem <<endl;
    tem.clear();

    // cout << "---------- bateria mAh ----------"<< endl;
    pos = result.find("mAh");
    pos -=5;
    for ( long i = 0 ; i < 5 ; i++ ){
        tem +=  result[pos + i];
    }
    numeros.append(  stoi(tem) );
    // cout << tem <<endl;
    tem.clear();

    // cout << "----------  temperatura bateria  ----------"<< endl;
    pos = result.rfind("°");
    pos -=5;
    for ( long i = 0 ; i < 5 ; i++ ){
        tem +=  result[pos + i];
    }
    pos = tem.find(".");
    if(pos != - 1)
        tem.erase (pos,1);
    numeros.append(  stoi(tem) );
    // cout << tem <<endl;
    tem.clear();
    
    return numeros;
}




#endif //ALEATORIOS_H