#include <iostream>
#include <vector>

using namespace std;

long pow(long num ,long n){
    if (n == 0)
        return 1;

    long aux = num;
    for(int i = 1 ; i < n ;i++)
        aux *=num; 
    return num;
}

vector <long long> cribaEratostenes(long long num){
    vector <long long> vec;

    /*agregando del 1 al num   sin 2n y 5n */
   
    long long i = 2 ;
    vec.push_back(i);
    i++;

    while(i < num){   
        vec.push_back(i);
        i+=4;
        vec.push_back(i);
        i+=2;
        vec.push_back(i);
        i+=2;
        vec.push_back(i);
        i+=2;
    }

    vector<long long>::iterator it;

    it = vec.begin();
    it +=2;
    it = vec.insert ( it , 5 );

    /* quitar 3n */

    it = vec.begin();
    it += 2;
    while(it != vec.end()){
        if( (*it % 3) == 0){
            vec.erase(it);
        }
        it++;
    }
    

    /* quitar 7n */
    it = vec.begin();
    it += 4;
    while(it != vec.end()){
        if( (*it % 3) == 0){
            vec.erase(it);
        }
        it++;
    }

    it = vec.begin();
    long long  primo = *it;  // El primer primo es el 2
    vector<long long>::iterator it2 = it + 1;
    do
    {
        for(; it2 <= vec.end(); it2++)
            if(*it2 % primo == 0)
                vec.erase(it2);

        it++;
        primo = *it;
    } while (pow(primo, 2) < num );


    for (long long i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << " ";
    }
    cout << " TAM: " << vec.size() << endl;

    return vec;
}

int main(){

    cribaEratostenes(480000);

    return 0;
}