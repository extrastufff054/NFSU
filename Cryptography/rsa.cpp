//Implement RSA algorithm
#include<bits/stdc++.h>
using namespace std;
int findCoprimePair(int N)
{
    // We iterate upto sqrt(N)
    // as we can find all the
    // divisors of N in this
    // time
    for (int x = 2; x <= sqrt(N); x++) {
        if (N % x == 0) {
            // If x is a divisor of N
            // keep dividing as long
            // as possible
            while (N % x == 0) {
                N /= x;
            }
            if (N > 1) {
                // We have found a
                // required pair
                cout << x << " "<< N << endl;
                return x;
            }
        }
    }
    // No such pair of divisors
    // of N was found, hence
    // print -1
    cout << -1 << endl;
}
int main()
{
    float p,q;        //prime numbers
    // cout<<"Enter two prime numbers :";
    // cin>>p>>q;          
    int n = p*q;        //modulus  
    cout<<"Enter the value of n : ";
    cin>>n;
    p=findCoprimePair(n);
    q=n/p;
    int phi = (p-1)*(q-1);      //Euler's totient function
    int e;          //public key -> e < n such that n and phi are co-prime i.e. gcd(n,phi) = 1
    cout<<"Enter the value of e : ";
    cin>>e;
    int d;      //private key
    for(int i=1;i<phi;i++)      //d*e mod phi = 1 ->Determining private key -> gcd(e,phi) = 1
    {
        if((i*e)%phi==1)
        {
            d = i;  
            break;
        }

    }

    cout<<"Public key : ("<<e<<","<<n<<")"<<endl;
    cout<<"Private key : ("<<d<<","<<n<<")"<<endl;
    int msg;        //message
    cout<<"Enter the message : ";
    cin>>msg;
    int c = (msg^e)%n;              //c = msg^e mod n -> Encryption
    cout<<"Encrypted message : "<<c<<endl;
    int m = (c^d)%n;                //m = c^d mod n -> Decryption
    cout<<"Decrypted message : "<<m<<endl;
    return 0;
}

/*n=12091  -> 
e=13
this is tough
00 to 26 encoding scheme*/
