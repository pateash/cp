	 /*
	     PROGRAM TO EVALUATE POSTFIX EXPRESSION USING
	     STACK OF ARRAYS
	     ********************************************

						      */



#include<stdio.h>
#include<conio.h>
#include<math.h>
struct stack
{
	float arr[20];
	int tos;
};
void push(struct stack *p,float n);
float pop(struct stack *p);
int is_operand(char ch);
float solve(char postfix[20]);
float evaluate(float op1,float op2,char ch);
void main()
{

	char postfix[20];
	float answer;
	printf("enter the expression\n");
	scanf("%s",&postfix);
	answer=solve(postfix);
	printf("Answer of the postfix expression= %3.2f",answer);
	getch();
	printf("\n\n");
}
void push(struct stack *p,float n)
{
	if(p->tos==20){
	printf("stack is full\n");
	getch();
	return;
	}
	else
	{
	p->tos++;
	p->arr[p->tos]=n;

	}
}
float pop(struct stack *p)
{
float n;
	if(p->tos==-1)
	{
		printf("nothing is there in the stack to pop\n");
		getch();
		return 0.0;
	}
	else
	{
		n=p->arr[p->tos];
		p->tos--;

		return n;
	}
}
int is_operand(char ch)
{
	return(ch>='0'&&ch<='9');
}
float evaluate(float op1,float op2,char ch)
{
	switch(ch)
	{
		case '+':
		return (op1+op2);
		case '-':
		return (op1-op2);
		case '*':
		return (op1*op2);
		case '/':
		return (op1/op2);
		case '$':      /* here $ denotes exponential operator*/
		return (pow(op1,op2));
		default:
		return 0.0;

	}
}
float solve(char postfix[20])
{
	int i;
	float op1,op2,ans;
	struct stack s;
	s.tos=-1;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(is_operand(postfix[i])==1)
		{

			push(&s,postfix[i]-48);

		}
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			ans=evaluate(op1,op2,postfix[i]);
			push(&s,ans);
		}
	}
	return ans;
}












