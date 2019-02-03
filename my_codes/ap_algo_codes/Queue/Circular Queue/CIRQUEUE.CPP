#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#define size 3
struct queue
{
	int arr[size];
	int front,rear;

};
void insert(struct queue*,int );
int del(struct queue*);
void view(struct queue);
void main(){
		int choice;
		struct queue q;
		q.front=-1;
		q.rear=-1;
		int x;
		menu:
		clrscr();
		cout<<"enter your choice\n1-insert\n2-delete\n3-view\n4-exit\n";
		cin>>choice;
		switch(choice){
			case 1:
			cout<<"enter no. to be inserted\n ";
			cin>>x;
			insert(&q,x);
			goto menu;
			case 2:
			x=del(&q);
			goto menu;
			case 3:
			view(q);
			goto menu;
			case 4:
			cout<<"Click to exit"<<endl;
			getch();
			exit(0);
			default:
			cout<<"You have entered wrong input \nTry again........";
			getch();
			goto menu;
		}

}
int isempty(struct queue*p){
	return(p->rear==-1&&p->front==-1);//or return(p->front==-1), because if p->front will be one -1 then automatically other will be on -1 and vice versa
}
void insert(struct queue*p,int x)
{
	if(p->front==(p->rear+1)%size){
		cout<<"CQueue Overflow\n";
		getch();
		return;
	}
	if(isempty(p)){// if the queue is empty then we have to make both front and rear to come on 0
		p->front++;p->rear++;
	}
	else{
	//Adjust the rear
		p->rear=(p->rear+1)%size;
	}
	p->arr[p->rear]=x;
	cout<<x<<" has been inserted to CQueue"<<endl;
}
int del(struct queue *p){
	if(isempty(p))
	{
		cout<<"CQueue Underflow\n";
		getch();
		return -111;
	}
	int x=p->arr[p->front];
	if(p->front==p->rear)// if this was last element then we have to shift both to -1
	{
		p->front=p->rear=-1;
	}
	else{
		p->front=(p->front+1)%size;
	}
	if(x!=-111)
		cout<<x<<" is deleted"<<endl;
		getch();
	return x;
}
void view(struct queue q){
	if(isempty(&q) )
	{
	cout<<"The CQueue is empty";
	 getch();return;
	 }
	cout<<"The Elements in CQueue are\n";
for(int i=q.front;i!=q.rear;i=(i+1)%size) {
cout<<q.arr[i]<<endl;
}
cout<<q.arr[i]<<endl;
getch();
}