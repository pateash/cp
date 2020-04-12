#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<stdlib.h>
void header()
{

clrscr();
cout<<"                    STACK IMPLIMENTATION OF ARRAY"<<endl;
cout<<"                    _____________________________"<<endl;
cout<<endl;
}
void push(int ,int*,int ,int& );      //taking the value and getting it to be stored in the stack
int pop(int*,int&);//returning the retrieved value
int top;//initialising with -1 as the minimum index no. is 0
void view(int &top,int *p)
{
if (top==-1)  {
header();
cout<<"                   No element in array\n";
return ;       }
for (int i=0;i<=top;i++)
cout<<*(p+i)<<endl;
getch();
}

 // STARTING MAIN

 void main()
{
top=-1;
clrscr();
int max_size;
header();
cout<<"                  Enter the maximum size of array\n";
cin>>max_size;
int *p=(int*)malloc(max_size*sizeof(int));
cout<<"\n                Memory has been allocated to "<<max_size <<" integers"<<endl<<"Click to continue"<<endl;
tryagain:
cout<<"\n                Click to continue";
clrscr();
getch();
header();
cout<<"                   Enter your choice";
cout<<"\n                    1-push";
cout<<"\n                    2-pop";
cout<<"\n                    3-view";
cout<<"\n                    4-exit\n";
int choice;
cin>>choice;
switch(choice)
{
case 1:
int x;
header();
cout<<"                      Enter the value to be pushed\n";
cin>>x;
push(x,p,max_size,top);
goto tryagain;
case 2:
int y=pop(p,top);
header();
cout<<"                      The element deleted ="<<y;
getch();
goto tryagain;
case 3:
view(top,p);
getch();
goto tryagain;
case 4:
header();
cout<<"                      Thanks for using STACK";
cout<<"\n                    click to exit the program";
getch();
exit(0);
break;
default:
header();
cout<<"                      Sorry,  You have entered a wrong input";
cout<<"                      \nPlease try again\n";
getch();
goto tryagain;
}
getch();
}
void push(int x,int *p,int max_size,int &top)
{
clrscr();
if(top==max_size)// it means that the full array has been filled because upper most element ke index ko store karega top
{
header();
cout<<"\n                    Over flow, you can't add more elements to the array";
cout<<"\n                    Click to Grow your array and Continue\n";
p=(int*)realloc(p,max_size*2);
}
top++;     //jisme rakhna hai uske pass pahuch gaya top
*(p+top)=x;
header();
cout<<"                      The element has been stored in the stack";
getch();
}
int pop(int *p,int& top)
{
if(top==-1){// already no element in the stack top=-1 as we have initialised
header();
cout<<"\n                    Underflow,  there is no element to delete in stack ";
getch();
return NULL;   }
int n=*(p+top);
top--;
return n;
}

