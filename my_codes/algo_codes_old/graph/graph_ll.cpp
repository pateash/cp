#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node{
  int data;
  struct node*nnext;
  struct edge*enext;

};
struct edge{
     int data;
     struct edge*next;
};
void show(node*start);
void insert_edge(node*start,int eval,int val)
{
   while(start!=nullptr){
     if(start->data==eval){
        //cout<<eval <<" found\n";
        break;
     }
     start=start->nnext;
   }
   if(start==nullptr){
    cout<<"the node is not present "<<endl;
       return;
   }
   edge*eptr=start->enext;
   edge*newptr=new edge;
   newptr->data=val;
   newptr->next=NULL;
   if(eptr==NULL){
  //  cout<<"there was no element in the node "<<endl;
    start->enext=newptr;
   }
   else{
        edge*prev=NULL;
    while(eptr!=NULL){
        prev=eptr;
    //    cout<<"here eptr->next!=NULL and value "<<eptr->data<<endl;
       if(eptr->data==val){
        cout<<"duplicate value,can't be inserted "<<endl;
        return;
       }
       eptr=eptr->next;
     }
    prev->next=newptr;
   }
//    show(start);
}
void add_node(node**pstart,int eval){
   node*p=new node;
   p->data=eval;
   p->enext=NULL;
   p->nnext=NULL;
   if(*pstart==NULL){
     *pstart=p;
     return;
   }
   node*temp=*pstart;
   while(temp->nnext!=NULL){
    if(temp->data==eval)
    {
        cout<<"duplicate value,can't be inserted\n";
        return;
    }
    temp=temp->nnext;
   }
   temp->nnext=p;
  // show(*pstart);
}

void show(node*start){
   if(start==nullptr){
    cout<<"empty graph \n";
    return;
   }
   edge*eptr;
   while(start!=nullptr){
      cout<<start->data<<" ==> ";
      eptr=start->enext;
      while(eptr!=nullptr){
         cout<<eptr->data<<" -> ";
        eptr=eptr->next;
      }
      cout<<"NULL";
       start=start->nnext;
    cout<<endl;
    }
    cout<<"NULL";
}
int main()
{


    node*start=NULL;
    menu:
        system("cls");
    cout<<"enter your choice\n1-Insert node\n2-Insert Edge\n3-show\n";
    int choice;
    cin>>choice;
    int temp;
    switch(choice)
    {
    case 1:
        cout<<"Enter the element\n";
        cin>>temp;
        add_node(&start,temp);
        break;
    case 2:
        cout<<"Enter node and edge Elements\n";
        cin>>temp;
        int etemp;
        cin>>etemp;
        insert_edge(start,temp,etemp);
        break;
    case 3:
        show(start);

    }
    _getch();
    goto menu;

     return 0;
}
