#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct doubly
{
    int data;
    struct doubly*next,*prev;
};
void append(struct doubly**ps,int x)
{
    struct doubly*p=(struct doubly*)malloc(sizeof(struct doubly));
    p->next=p->prev=NULL;
    p->data=x;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    struct doubly*temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
}
void show(struct doubly *temp)
{
    if(temp==NULL)
    {
        cout<<"Empty list";
        _getch();
        return;
    }
    cout<<"Elements in the Doubly are\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    _getch();
}
void del_last(struct doubly**ps)
{
    if((*ps)==NULL)
    {
        cout<<"Empty list";
        _getch();
        return;
    }
    if((*ps)->next==NULL)//is case me start ko update karna hoga
    {
        free(*ps);
        (*ps)=NULL;
        return;
    }
    struct doubly*temp=*ps;
    while(temp->next!=NULL){
    temp=temp->next;
    }
        temp->prev->next=NULL;
        free(temp);
}
void del_first(struct doubly**ps)
{
    if((*ps)==NULL)
    {
        cout<<"Empty list";
        _getch();
        return;
    }
if((*ps)->next==NULL)//is case me start ko update karna hoga
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    struct doubly*temp=(*ps);
   *ps=temp->next;
   (*ps)->prev=NULL;//bracket lagana padega kyo  ki * ki precedence -> se kam hoti hai
   free(temp);
}
void del_any(struct doubly**ps,int x)
{
struct doubly*temp=(*ps);
    if((*ps)==NULL)
    {
        cout<<"empty list"<<endl;
        _getch();
        return;
    }
    if((*ps)->data==x)
    {
        if((*ps)->next==NULL)//because if we consider this case then we could not access (*ps)->prev after shifting *ps because it will became NULL
        {
            free(*ps);
            *ps=NULL;
            return;
        }
       (*ps)=temp->next;
       (*ps)->prev=NULL;
       free(temp);
       return;
    }
    struct doubly*prev;
    while(temp->data!=x&&temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==x)
    {
        prev->next=temp->next;
        if(temp->next!=NULL)
        temp->next->prev=prev;
        free(temp);
    }
    else{
        cout<<x<<" is not found in the list"<<endl;
    }
    _getch();
}
int main()
{
    struct doubly*start=NULL;
    int x;
    menu:
        system("cls");
    cout<<"Enter your choice\n1-append\n2-delete first\n3-delete last\n4-delete any\n5-show\nAny other to Quit\n";
    size_t choice;
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"enter the data to be appended\n";
        cin>>x;
        append(&start,x);
        goto menu;
    case 2:
        del_first(&start);
        goto menu;
    case 3:
        del_last(&start);
        goto menu;

    case 5:
       show(start);
        goto menu;
    case 4:
        cout<<"enter the number to be deleted\n";
        cin>>x;
        del_any(&start,x);
        goto menu;
    default:
        cout<<"\nClick to exit\n";
        _getch();
        exit(EXIT_SUCCESS);
    }
return 0;
}
