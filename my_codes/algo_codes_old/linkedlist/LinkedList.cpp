#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
node*start=NULL;

void Reverse()
{

  if(start==NULL||(start->next)==NULL)
    return;
   node *temp,*first,*second;
   temp=start->next;
   first=NULL;
   second=start;
   int count=0;
    while(true)
    { if(count>0)
        break;
        if(temp==NULL)
            count++;
        second->next=first;
        first=second;
        second=temp;
        if(temp!=NULL)
        temp=temp->next;
    }
    start=first;
    cout<<"Elements of the linked list has been reversed\n";
    _getch();
}

void append(int x)
{

    node*temp,*prev;//temp has to be updated every time
    node*p=(node*)malloc(sizeof(node));
    p->data=x;
        if(start==NULL)
        {
             start=p;
             start->next=NULL;
             return;
        }
        temp=start;
		if(start->next==NULL)
		{
			if(x>(temp->data))
			{
				temp->next=p;
				p->next=NULL;
				return;
			}
			start=p;
			p->next=temp;
			return;
		}
		temp=start;
		int counter=0;
        while(temp!=NULL&&(x>temp->data))
        {
            counter++;
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            prev->next=p;
            p->next=NULL;
        }
        else
        {
            if(counter!=0)
            {
            prev->next=p;
            p->next=temp;
            }
            else
            {
                start=p;
                start->next=temp;
            }
        }
 cout<<"you have successfully appended "<<x <<"in the linked list\n";
}
void display()
{
    system("cls");
    cout<<"the element in the linked list are"<<endl;
    if(start==NULL)
    {
        cout<<"Empty list"<<endl;
        system("pause");
        return;
    }
    node*temp=start;
    while(temp!=NULL)
    {
        cout<<(temp->data)<<endl;
        temp=temp->next;
    }
 system("pause");
}
void del(int x)
{
    node*temp=start;
if(start==NULL)
{
    cout<<"Empty linked list"<<endl;
    system("pause");
    return ;
}
  if(start->data==x)
  {
      node*temp=start;
      start=start->next;
      free(temp);
      cout<<x<<"has been deleted"<<endl;
    system("pause");
      return;
  }
  node*prev;
  temp=start;
  while(temp!=NULL&&temp->data!=x)
  {
      prev=temp;
      temp=temp->next;
  }
    if(temp!=NULL&&temp->data==x)
    {
        prev->next=temp->next;
        free(temp);
      cout<<x<<"has been deleted"<<endl;
    system("pause");
        return;
    }
    else
    {
        cout<<x<<" is not found in the linked list\n";
        system("pause");
    }
}
int main()
{
    int x,choice;
    system("color 1b");
    menu:
       system("cls");
    cout<<"enter choice\n1-append\n2-delete\n3-display\n4-Reverse\n5-Quit\n.....";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"enter the number to be appended"<<endl;
        cin>>x;
        append(x);

        goto menu;
    case 2:
        cout<<"enter the number to be deleted"<<endl;
        cin>>x;
        del(x);

        goto menu;
    case 3:
        display();

        goto menu;
    case 5:
        cout<<"Click to exit"<<endl;
        exit(0);
    case 4:
        Reverse();
        goto menu;

    }
}
