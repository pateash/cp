#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#define max_size 40
void main()
{
 clrscr();
	cout<<"enter expression\n";
	char q[max_size];
	cin.getline(q,max_size);
int b1=0,b2=0,b3=0;
	for(int i=0;q[i]!='\0';i++)
    {

	 if(q[i]=='(')
	      b1++;
	else if(q[i]=='{')
	      b2++;
	 else if(q[i]=='[')
	      b3++;
	  else if(q[i]==')')
	      b1--;
	    else if(q[i]=='}')
	      b2--;
	      else if(q[i]==']')
	      b3--;
      }
      if(b1==0&&b2==0&&b3==0)
	cout<<"Balanced Paranthesis\n";
     else
	cout<<"Not Balanced Paranthesis\n";
    getch();
}