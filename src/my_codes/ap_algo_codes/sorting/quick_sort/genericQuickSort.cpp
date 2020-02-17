#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template<typename T>
void show(T arr[],int start, int end){
  cout<<" Elements in array are\n";
  for(int i=start;i<=end;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
_getch();
}

template<typename T>
void QuickSort(T arr[],int start,int end){
   if(start>=end) return;
   int i=start,j=end;
   int p=start;
    while(i<=j){
        while(j>=start&&arr[j]>arr[p]) j--;
        while(i<=end&&arr[i]<=arr[p]) i++;
    if(i<j)//if poora trace kar liya to nahi karna hai
        swap(arr[i],arr[j]);
    }
        swap(arr[p],arr[j]);
        QuickSort(arr,start,j-1);
        QuickSort(arr,i,end);
}
int main()
{
   menu:
       system("cls");
       cout<<"enter your choice\n1-Integers\n2-Decimals\n3-Characters\n";
       int choice;
       cin>>choice;
       int n;
        cout<<"enter the number of elements you want to sort\n";
           cin>>n;
        int arr[n];
        float frr[n];
        char crr[n];
       switch (choice)
       {
       case 1:
           cout<<"enter "<< n<<" numbers\n";
           for(int i=0;i<n;i++)
                cin>>arr[i];
           QuickSort(arr,0,n-1);
           show(arr,0,n-1);
           break;
        case 2:
           cout<<"enter "<< n<<" numbers\n";
           for(int i=0;i<n;i++) cin>>frr[i];
           QuickSort(frr,0,n-1);
           show(frr,0,n-1);

           break;
       case 3:
           cout<<"enter "<< n<<" numbers\n";
           for(int i=0;i<n;i++) cin>>crr[i];
           QuickSort(crr,0,n-1);
              show(crr,0,n-1);

           break;
       default:
           cout<<"you have entered a wrong choice\tPlease try again\n";
         _getch();
        //goto menu;
       }

    return 0;
}
