#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<cctype>
using namespace std;
struct poly
{
    int exp,coef;
    struct poly*next;
};
void append(struct poly**ps,int c,int e)
{
    struct poly*p=(struct poly*)malloc(sizeof(struct poly));
    p->coef=c;
    p->exp=e;
    p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;return;
    }
    struct poly*temp=*ps;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
void display(struct poly*start)
{
    if(start==NULL)
    {
            cout<<"there is no element in the polynomial\n";
            _getch();
            return;
    }
    cout<<"the polynomials is "<<endl;
    while(start!=NULL)
    {
        cout<<start->coef<<"x^"<<start->exp;
        if(start->next!=NULL)
            cout<<"+ ";
        start=start->next;
    }
    _getch();
}
void add(struct poly*first,struct poly*second,struct poly**pt)
{
   if(first==NULL&&second==NULL)
   {
       cout<<"Polynomial can't be added because both are empty\n";
       _getch();
       return;
    }
    _getch();
    struct poly*temp=NULL;
    while(first!=NULL&&second!=NULL)
    {
        struct poly*p=(struct poly*)malloc(sizeof(struct poly));
        p->next=NULL;//a new node is created every time
        if(*pt==NULL)//it is the first node
        {
            *pt=p;
            temp=*pt;//temp will point to the node which is the last node of created polynomial
        }
        else
        {
            temp->next=p;//last node start pointing to the newly formed node
            temp=p;//temp now come to that node it self so that it could point the last node again
        }
        //NOW START COMPARING
        if(first->exp==second->exp)//if both has same exponent
        {
            temp->exp=first->exp;
            temp->coef=first->coef+second->coef;
            first=first->next;
            second=second->next;
        }
        else if(first->exp<second->exp)
        {
              temp->exp=second->exp;
            temp->coef=second->coef;
            second=second->next;
        }
        else
        {
            temp->exp=first->exp;//copy first to temp
            temp->coef=first->coef;
            first=first->next;//here second will not change because further first will be again compared with it


        }

    }//end of while it means any one has left to traverse(koi ek khatam ho gaya)

  struct poly*t=NULL;
  if(first==NULL)//jo null nahi hai woh dal do
    t=second;
  else
    t=first;
    while(t!=NULL)
    {//form new node

     struct poly*  p=(struct poly*)malloc(sizeof(struct poly));
       p->next=NULL;
       p->coef=t->coef;//copy pt in to p
       p->exp=t->exp;
       t=t->next;
       //now add p to temp
       if(*pt==NULL)//no node is yet formed(it will required when there is no node in one polynomial
        {
            *pt=p;
            temp=*pt;
        }
        else
        {
            temp->next=p;
            temp=p;//temp start pointing to the last node
        }

    }//end of while

}//end of function
int main()
{
    struct poly*first=NULL;
    struct poly*second=NULL;
    struct poly*third=NULL;
    int c,e;
    for(int i=0;i<2;i++)
    {
        e=1;
        cout<<endl<<"Enter the polynomial elements of polynomial in descending order"<<i+1<<endl;
        while(e!=0)
        {
            cout<<"coef: ";
            cin>>c;
            cout<<endl<<"exp: ";
            cin>>e;
            cout<<endl;
        if(i==0)
            append(&first,c,e);
        else
            append(&second,c,e);
        }
    }
    cout<<"\n\nFirst polynomial\n";
    display(first);
    cout<<"\n\n\nSecond polynomial\n";
    display(second);
    add(first,second,&third);
    cout<<"\nResultant polynomial\n";
    display(third);
    _getch();
    return 0;
}
