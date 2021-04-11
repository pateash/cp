#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

 void show(int arr[])
 {
     for(int i=0;i<20;i++)
        {
            if(arr[i]!=0)
                cout<<arr[i]<<" ";

        }
        cout<<endl;
        _getch();
 }
void append(int arr[],int x)
{

   int temp=arr[1];
    int i=1;
   while(temp!=0)
   {

        if(x>temp)
            i=i*2+1;
        else
            i=i*2;
              temp=arr[i];
   }
   arr[i]=x;
   cout<<x<< "  Appended! the current tree looks like\n";
   show(arr);

}
void del(int arr[],int x)
{
    for (int i=1;i<20;i++ )
    {
        if(arr[i]==x)
        {
            arr[i]=0;
             cout<<x<<  "  Deleted! the current tree looks like\n";
   show(arr);

        }
    }
   cout<<"not found\n";
   _getch();
}

int main()
{
    system("color f9");
    int x;
     int arr[20]={0};
    menu:
        system("cls");
    cout<<"Enter your choice\n1-Append\n2-Delete\n3-Traverse\n4-Quit\n";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter the number to be inserted\n";
        cin>>x;
        append(arr,x);
        goto menu;
    case 2:
        cout<<"Enter the number to be deleted\n";
        cin>>x;
        del(arr,x);
        goto menu;
    case 3:
        cout<<"LEVEL ORDER TRAVERSAL\n";
       show(arr);
        cout<<endl;
        _getch();
        goto menu;
    default:
     goto menu;
    case 4:
        cout<<"Click to exit\n";
        _getch();
        exit(0);
    }
return 0;
}
