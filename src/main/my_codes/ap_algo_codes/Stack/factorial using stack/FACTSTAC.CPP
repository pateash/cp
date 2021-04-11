/* 	PROGRAM TO FIND FACTORIAL USING STACK
	WITHOUT USING LOOP AND RECURSION
	**********************************/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#define size 20
struct stack
{
int arr[size];
int tos;
};
void push(struct stack*p,int x)
{
if(p->tos==size-1)
cout<<"overflow";
else
{
 p->tos++;
 p->arr[p->tos]=x;
}
}
int pop(struct stack*p)
{
int x=-1;
if(p->tos==-1)
{
cout<<"underflow\n";
}
else
{
x=p->arr[p->tos];
p->tos--;
}
return x;
}
int fact(int n)
{
int f=1;
struct stack s;
s.tos=-1;
if(n==0)
return 1;
again_push:
push(&s,n);
n--;
if(n!=1)
goto again_push;
again_pop:
int x=pop(&s);
f*=x;
if(s.tos!=-1)
goto again_pop;
return f;
}
void main()
{
clrscr();
int n;
cout<<"enter the number \n";
cin>>n;
int ans=fact(n);
cout<<"factorial of "<<n<<" = "<<ans<<endl;
getch();
}