#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
struct stack
{
char arr[size];
int tos;
};
void push(struct stack *p,char x);
char  pop(struct stack *p);
int isoperand(char ch);
int isempty(struct stack s);
void convert(char [],char[]);
int prs(char ch);
int main()
{

 char infix[size],postfix[size];
	system("cls");

printf("enter the infix expression with paranthesis\n");
scanf("%s",infix);
convert(infix,postfix);
printf("postfix expression = %s",postfix);
getch();
}
void push(struct stack *p,char x)
{
	if(p->tos==size-1){
		printf("Overflow\n" );
		getch();
		return;
	}
	p->tos++;
	p->arr[p->tos]=x;
	printf("%c has been pushed in stack\n",x);
}
char pop(struct stack *p)
{
	char x;
	if(p->tos==-1)
	{
		printf("Underflow");
		getch();
		return -1;
	}
	x=p->arr[p->tos];
	p->tos--;
	printf("%c has been poped\n",x);
	return x;
}
int isempty(struct stack s)
{
	return(s.tos==-1);
}
int isoperand(char ch)
{
	return ((ch<='Z'&&ch>='A')||(ch<='9'&&ch>='0'));
}
void convert(char infix[],char postfix[])
{
 struct stack s;
 s.tos=-1;
 char ch,x;
 int j=0,count=0;
 for(int i=0;infix[i]!='\0';i++)
 {
	ch=infix[i];
	if(isoperand(ch))
	{
		postfix[j++]=ch;
		printf("%c has been copied to postfix\n",ch);
	}
	else
	{
		if(isempty(s))
		{
			if(ch=='(')
				count++;
			push(&s,ch);
		}
		else if(ch=='(')
		{
			count++;
			push(&s,ch);
		}
		else if(ch==')')
		{
			x=pop(&s);
			while(x!='(')
			{
				postfix[j++]=x;
					printf("%c has been copied to postfix\n",ch);
				x=pop(&s);
			}

		}
		else
		{
			if(count>0)
			{
				push(&s,ch);
				count--;
				continue;
			}
			while(prs(ch)<=prs(s.arr[s.tos]))//( aane par khud ruk jayega kyoki uski 0 presidence hai default in switch
			{
				x=pop(&s);
				postfix[j++]=x;
					printf("%c has been copied to postfix\n",ch);
			}
			push(&s,ch);

		}
	}
 }
 while(s.tos!=-1)
 {
x=pop(&s);
postfix[j++]=x;
	printf("%c has been copied to postfix\n",ch);
}
postfix[j]='\0';
	printf("null has been copied to postfix\n");
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
