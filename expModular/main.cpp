#include <iostream>

using namespace std;

int modulo(int a, int b) {
    if (a >= 0)
        return a - (a / b) * b;
    else
        return a - ((a / b) - 1) * b;
}

int mcd(int a, int b)
{
    cout<<a<<" = "<<b<<"("<<a/b<<")";
    int r=modulo(a,b);
    cout<<" + "<<r<<endl;

    if(r==0)
    {
        return b;
    }
    else
    {
        a=b;
        b=r;
    }
    return mcd(a,b);
}

void Inversas_Add(int conjuntoZ)
{
    for(int i=0; i<conjuntoZ; i++)
    {
        for(int j=0; j<conjuntoZ; j++)
        {
            if (modulo(i+j,conjuntoZ)==0)
            {
                cout<<"{"<<i<<","<<j<<"}\n";
            }
        }
    }
}

void Inversas_Mult(int conjuntoZ)
{
    for(int i=0; i<conjuntoZ; i++)
    {
        for(int j=0; j<conjuntoZ; j++)
        {
            if (modulo(i*j,conjuntoZ)==1)
            {
                cout<<"{"<<i<<","<<j<<"}\n";
            }
        }
    }
}


int main()
{
    int Z,a,b;
    // cout<<"Z: ";cin>>Z;
    // cout<<"Inv_ADD: \n";

    // Inversas_Add(Z);
    // cout<<"\n\nInv_MULT: \n";
    // Inversas_Mult(Z);


    cout<<"a: ";cin>>a;
    cout<<"\nb: ";cin>>b;

    cout<<"\n\nMCD("<<a<<" , "<<b<<")\n";
    cout<<"mcd: "<<mcd(a,b)<<endl;
}