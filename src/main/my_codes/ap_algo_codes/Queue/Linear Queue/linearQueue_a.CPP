// queue.cpp : Defines the entry point for the console application.
//

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//#include "stdafx.h"
#define size 5
//using namespace std;
struct queue{
	int arr[size];
	int front,rear;

};
void insertion(struct queue *p,int x)
{
	if(p->rear==size-1)
		cout<<"overflow";
	else
	{
		p->rear++;
		p->arr[p->rear]=x;
		cout<< x<<" has been inserted\trear= "<<p->rear<<endl;

	}
}
int  deletion(struct queue*p)
{
	int x;
	if(p->rear==p->front-1)
	{
		cout<<"Underflow \t Queue is empty";
		return -99;
	}
	else
	{
		x=p->arr[p->front];
		p->front++;
		cout<<x <<" has been deleted\tfront= "<<p->front;
		return x;
	}


}
int main()
{
	int x;
		struct queue q;
	q.rear=-1;
	q.front=0;

	again:
	system("cls");

	cout<<"Enter your choice\n1-insert\n2-delete\n3-view\n4-exit\n";
	int choice;
	cin>>choice;
	switch(choice)
	{
	case 1:
		cout<<"enter the number to be inserted\n";
		cin>>x;
		insertion(&q,x);
		break;
	case 2:
		x=deletion(&q);
		break;
	case 3:
		if(q.rear==-1||q.front==q.rear+1)
		{	cout<<"queue is empty";
			break;
		}

		for(int i=q.front;i<=q.rear;i++)
		cout<<q.arr[i]<<endl;
		break;
	case 4:
		cout<<"click to exit";
		getch();
		exit(0);

}
	getch();
	goto again;
       //	getch();
	return 0;
}

