//Diffie Hellmann Key Exchange 
//R1 = g^x mod p     R2 = g^y mod p    k = R2^x mod p = R1^y mod p

#include<iostream>
using namespace std;

int power(int a, int b, int p)
{
    int res =1;
    a = a%p;
    while(b>0)
    {
        if(b&1)
            res = (res*a)%p;
            b=b>>1;
            a = (a*a)%p;
    }
    return res;
}

int main()
{
    int p,g,x,y;
    cout<<"Enter the value of p and g: ";
    cin>>p>>g;
    cout<<"Enter the value of x and y: ";
    cin>>x>>y;
    int R1 = power(g,x,p);
    int R2 = power(g,y,p);
    int k1 = power(R2,x,p);
    int k2 = power(R1,y,p);
    cout<<"R1 = "<<R1<<endl;
    cout<<"R2 = "<<R2<<endl;
    cout<<"k1 = "<<k1<<endl;
    cout<<"k2 = "<<k2<<endl;
    return 0;
}
