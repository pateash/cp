#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 20
struct stack
{
char arr[size];
int tos;
};
void push(struct stack *p,char x)
{
	if(p->tos==size-1)
	{
	printf("over flow");
	 return ;
	 }
	p->tos++;
	p->arr[p->tos]=x;
	printf("%c is pushed\n",x);
}
char pop(struct stack *p)
{
	if(p->tos==-1)
	{
	printf("underflow");
	return -10;
	}
	char x=p->arr[p->tos];
	p->tos--;
	printf("%c is poped\n",x);
	return x;

}
int isoperand(char ch)
{
return (ch<='9'&&ch>='0');
}
int isempty(struct stack s)
{
return (s.tos==-1);
}
int prs(char ch)
{
switch(ch)
{
case '^':
return 3;
case '*':case'/':case'%':
return 2;
case '+':case '-':
return 1;
default:
return 0;
}
}

void convert(char infix[size],char prefix[size])
{
struct stack s;
s.tos=-1;
char ch,x;
int j=0;
for(int i=strlen(infix)-1;i>=0;i--)
{
	ch=infix[i];
	if(isoperand(ch))
	{
	prefix[j]=ch;
	j++;
	}
	else
	{
		if(isempty(s))
		push(&s,ch);
		else
		{
			while(prs(ch)<prs(s.arr[s.tos]))
			{
				x=pop(&s);
				prefix[j]=x;
				j++;
			}
			push(&s,ch);
		}

       }
}

while(s.tos!=-1)
{
x=pop(&s);
prefix[j]=x;
j++;
}
strrev(prefix);
}
void main()
{
clrscr();
char infix[size],prefix[size];
printf("enter infix\n");
gets(infix);
convert(infix,prefix);
printf("ans is %s",prefix);
getch();
}