#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#define h 19
#define size 15
using namespace std;
int hash_function(int k)
{
    return(k%h);
}
void show(int arr[])
{
for (int i=0;i<h;i++)
{

        cout<<setw(3)<<arr[i]<<"  ";
}
cout<<endl;
}
void hash_and_show_linear(int h_table[h],int key)
{
    int add=hash_function(key);
    bool stored=false;
    while(stored==false)
    {

        if(h_table[add]==0)
        {
            cout<<"stored at index= "<<add<<endl<<endl;
            h_table[add]=key;
            stored=true;
            show(h_table);
        _getch();
        }
        add=(add+1)%h;
    }
}
void hash_and_show_quad(int h_table[h],int key)
{
    int add=hash_function(key);
    bool stored=false;
    int i=0;
      show(h_table);
        _getch();
    while(stored==false)
    {
        if(h_table[add]==0)
        {
              cout<<"  stored at index= "<<add<<endl<<endl<<endl;
              _getch();
            h_table[add]=key;
            stored=true;
        show(h_table);
        _getch();
        }
        i++;
        add=(add+i*i)%h;
    }
}
void set_zero(int h_table[])
{
    for(int i=0;i<h;i++)
        h_table[i]=0;
}
int main()
{
    system("color f9");
        int value[size]={112,130,156,173,197,150,166,140,123,143,167,189,193,117,176};
        int h_table[h]={0};
        cout<<"\t\t\t\t LINEAR PROBING\n";
        cout<<"\t\t\t\t-----------------\n"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<"\t"<<value[i]<<" comes";
         hash_and_show_linear(h_table,value[i]);

        }
        _getch();
        system("cls");
        set_zero(h_table);
        cout<<"\t\t\t\t QUADERATINC PROBING\n";
         cout<<"\t\t\t\t-----------------\n"<<endl;
        for(int i=0;i<size;i++)
        {

            cout<<value[i]<<" comes "<<endl;
            hash_and_show_quad(h_table,value[i]);
        }

       return 0;
}
