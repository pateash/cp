 /*
	PROGRAM TO CONVERT INFIX TO POSTFIX EXPRESSION
			USING STACK OF ARRAY
	**********************************************
						     */

// here $ represent exponential
#include <stdio.h>
#include<conio.h>
void push(struct stack *,char);
char pops(struct stack*);
int isempty(struct stack);
int isoperand(char );
void convert(char[],char[]);
int  prs(char );//defining a fn presidence which return the int corresponding to the presidence of a oper
struct stack
{
int tos;
char arr[20];
};
void main()
{
    char infix[20],postfix[20];

    printf("\n\nenter the  infix expression\n");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("the corresponding postfix expression is \t %s",postfix);
       getch();

}
void push(struct stack *p, char x){
    if(p->tos==20){
    printf("Overflow");

    return ;
    }
    p->tos++;
    p->arr[p->tos]=x;

    }
char pop(struct stack *p){
    char x;
    if(p->tos==-1){
	printf("Underflow");
	return 0;
    }
    x=p->arr[p->tos];
    p->tos--;
    return x;

}
int isempty(struct stack s){
    return(s.tos==-1);
}
int isoperand(char ch){
    return(ch<='9'&&ch>='0');
}
void convert(char infix[20],char postfix[20]){
    struct stack s;
    int i,j=0;
    char ch;
    char x;
   s.tos=-1;
    for(i=0;infix[i]!='\0';i++)
    {
	ch=infix[i];
	if(isoperand(ch)){
	    postfix[j]=ch;

	    j++;
	}
	 else{
		if(isempty(s))
		{
			push(&s,ch);
			continue;
		}
		while(prs(ch)<=prs(s.arr[s.tos]))
		{
		      x=  pop(&s);

		      postfix[j]=x;
		      j++;
		}
	     push(&s,ch);
	     }
}
while(s.tos!=-1)
{
x=pop(&s);
postfix[j]=x;
j++;
}
postfix[j]='\0';

    }
int prs(char op){
    switch(op){
	case '$':
	return 3;
	case '*':
	case'/' :
	case '%':
	return 2;
	case '+':
	case '-':
	return 1;
	default:
	return 0;
    }

}