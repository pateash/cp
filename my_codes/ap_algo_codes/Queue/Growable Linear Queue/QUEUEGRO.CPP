#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
int size;
struct queue
{
	int *ptr;
	int front,rear;
};
void insert(struct queue*,int x);
int del(struct queue*);
void main()
{
	struct queue q;
	q.front=0;
	q.rear=-1;
	int x;
	clrscr();
	cout<<"Enter the size of Queue\n";
	cin>>size;
	q.ptr=(int*)malloc(size*sizeof(int));
	menu:
	clrscr();
	cout<<"Enter your choice\n1-inset\n2-delete\n3-exit\n";
	int choice;
	cin>>choice;
switch(choice)
{
	case 1:
	cout<<"enter the value to be inserted\n";
	cin>>x;
	insert(&q,x);
	getch();
	goto menu;
	case 2:
	x=del(&q);
	if(x!=-1111)
	cout<< x<<" has been deleted from the stack\n";
	getch();
	goto menu;
	case 3:
	cout<<"Click to exit\n";
	getch();
	exit(0);
}
}
void insert(struct queue *p,int x)
{
	if(p->rear==size-1)
	{
		cout<<"Queue Overflow\nsize of the Queue now is "<<size<<endl;
		cout<<"click to double the size of queue\n";
		getch();
		p->ptr=(int*)realloc(p->ptr,size*2);
		size*=2;
		cout<<"Size of Queue is "<<size;

		return;
	}
	p->rear++;
	*(p->ptr+p->rear)=x;
	cout<<x<<" has been inserted in to the queue\n";
}
int del(struct queue *p)
{
int x;
	if(p->front==p->rear+1)
	{
		cout<<"Queue Underflow\n";
		return -1111;
	}
       x=*(p->ptr+p->front);
       p->front++;
      return x;
}







