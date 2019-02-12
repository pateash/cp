#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"enter a and b"<<endl;
    cin>>a>>b;
    while(a%b!=0)//as soon as b devides a it will be gcd 
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    cout<<"gcd is "<<b<<endl;
    return 0;
}

