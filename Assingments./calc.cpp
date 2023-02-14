#include<iostream>
using namespace std;

int main()
{
    int num1,num2,num3;
    int dividend, divisor, quotient, remainder;

    cout<<"Enter the values of a,b and c(where c is the required mod value): ";
    cin>>num1>>num2>>num3;

    
    dividend=num1+num2;

    divisor=num3;
    
    quotient=dividend/num3;
    remainder=dividend - (divisor*quotient);

    cout<<"The result is : "<<remainder;

}


//(a+b) mod x

//dividend=divisior*quotient +remainder