// towerOfHanoi.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
void towerOfHanoi(int n,char start,char temp,char end)
{
	if(n==1)
		cout<<start<<"->"<<end<<endl;
	else
	{
		towerOfHanoi(n-1,start,end,temp);
		cout<<start<<"->"<<end<<endl;
		towerOfHanoi(n-1,temp,start,end);

	}

}
void main()
{
	int n;
cout<<"enter the number of disks\n";
cin>>n;
towerOfHanoi(n,'A','B','C');
getch();
}