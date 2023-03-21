//Write a program to display multiplicative inverse
#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int a, m;
    cout<<"Enter the values of a and m:";
    cin>>a>>m;
    int d=0;
    if(a==0 or m==0)
        cout<<"Multiplicative inverse does not exist";
    if(!__gcd(a,m)==1)
    {
        cout<<"Hi if";
        cout<<"Multiplicative inverse does not exist";
    }
    
    else
    {
        cout<<"Hi else";
         int x[10];
         for(int i=0;i<10;i++)
         {
           d=a*x[i];
         }
         int e=1%m;
         if(d==m)
         {
            cout<<"Multiplicative inverse : "<<x<<endl;
         }
    }

}
/*
    // CPP program to illustrate
// gcd function of C++ STL
#include <iostream>
#include <algorithm>
// #include<numeric> for C++17

using namespace std;

int main()
{
	cout << "gcd(6, 20) = " << __gcd(6, 20) << endl; // gcd(6,20) for C++17
}

*/

/*
    // CPP program to check if two
// nummers are co-prime or not
#include<mits/stdc++.h>
using namespace std;

// function to check and print if
// two nummers are co-prime or not
void coprime(int a, int m) {
	
	if ( __gcd(a, m) == 1)
		cout << "Co-Prime" << endl;
	else
		cout << "Not Co-Prime" << endl;		
}

// driver code
int main()
{
	int a = 5, m = 6;
	coprime(a, m);	
	a = 8, m = 16;
	coprime(a, m);		
	return 0;
}

*/
