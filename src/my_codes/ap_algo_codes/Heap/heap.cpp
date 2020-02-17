#include <iostream>
#include<conio.h>
#include<stdlib.h>
#define size 20
using namespace std;
void swap_num(int &a, int&b);
void insert_heap(int arr[],int n,int x)
{
    n++;
    arr[n]=x;
    int i=n;
    while(i!=1&&arr[i]>arr[i/2])
    {
        swap_num(arr[i],arr[i/2]);
        i/=2;
    }
    cout<<x<<" has been added\n";
}
void show(int arr[],int n)
{
    for (int i=1;i<=n;i++)//start from 1 because elements are here from one, and that is why we have to goto that last index also
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    _getch();
}
void del_heap(int arr[],int n,int x)
{
    int i;
    for (i=1;i<=n ;i++ )
    {
        if(arr[i]==x)
        {
            break;
        }
    }
    cout<<x <<" is found at index "<<i<<endl;
    if(i>n)
    {
        cout<<x<<" is not found in the Heap";
        _getch();
        return;
    }
    int p=0;
    arr[i]=arr[n];
    while (true)
    {
        if(n==2*i||arr[2*i]>arr[2*i+1])//means child is greater than parent or only last element we are traversing
            p=2*i;
        else //means child is smaller than parent
            p=2*i+1;
        if(p>n)
            break;
        if(arr[p]>arr[i])
            swap_num(arr[p],arr[i]);
        i=p;
    }
}
void swap_num(int &p,int &q)
{
    int t=p;
    p=q;
    q=t;
}
int main()
{
 int x;
 int heap_array[size];
 int countnum=0;
    menu:
    system("cls");
 cout<<"Enter your choice\n1-Add\n2-Delete\n3-Show\n4-Quit\n";
 int choice;
 cin>>choice;
     cout<<"numbers: "<<countnum<<endl;
 switch (choice)
 {
 case 1:
     cout<<"Enter the number to be inserted\n";
     cin>>x;
     insert_heap(heap_array,countnum,x);
     countnum++;
     cout<<"numbers: "<<countnum<<endl;
     _getch();
     goto menu;
 case 2:
     cout<<"Enter the number to be deleted\n";
     cin>>x;
  del_heap(heap_array,countnum,x);
  countnum--;
    cout<<x<<" is deleted\n";
    cout<<"numbers: "<<countnum<<endl;
    _getch();
    goto menu;
 case 3:
    show(heap_array,countnum);
    goto menu;
  default:
     goto menu;
 }

 return 0;
}
