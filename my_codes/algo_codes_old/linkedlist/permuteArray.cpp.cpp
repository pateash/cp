#include <iostream>
#include<conio.h>
#include<stdlib.h>
#define size 5
using namespace std;
void showArray(int arr[]){
for (int i=0;i<size ;i++ ) cout<<arr[i]<<"  ";
cout<<endl;
_getch();
}
void permute(int arr[])
{
    int first=arr[0];
    for (int i=0;i<size-1 ;i++ ) arr[i]=arr[i+1];
    arr[size-1]=first;
}
int main()
{
    system("color f9");
   int arr[]={1,2,3,4,5,6,7,8,9,10};
   menu:
system("cls");

   cout<<"Enter your choice\n1-show Array\n2-permute Array\n3-Quit\n";
   int choice;
   cin>>choice;
   switch (choice)
   {
   case 1:
       showArray(arr);
       goto menu;
       break;
   case 2:
        permute(arr);
        goto menu;
        break;
   case 3:
    cout<<"Click to exit\n";
    _getch();
    exit(EXIT_SUCCESS);
   }

    return 0;
}
