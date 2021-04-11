#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct node {
    int data;
    node*next;

    node(int value){
        data=value;
        next=nullptr;
    }
};

node* start= nullptr;

void display(){
    if(start==nullptr)
    {
        cout<<"empty linkedlist"<<endl;
        return;
    }
    node* temp=start;
    while(temp!= nullptr){
        cout<<temp->data;
        if(temp->next!=nullptr)
            cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
void append(int value){
    if(start==nullptr){
        start=new node(value);
        cout<<"first node:"<<value<<endl;
        return;
    }
    node*temp=start;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new node(value);

    cout<<"appended:"<<value<<endl;
//    display();
}

void del(int value){
    if(start==nullptr)
    {
        cout<<"empty list";
        return;
    }
    bool flag=false;
    node*temp=start;
    node*prev=nullptr;
    while(temp!=nullptr){
        if(temp->data== value)
        {
            flag=true;
            if(start==temp) // if first element needs to be deleted
                start=temp->next;
            else
                prev->next=temp->next;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(flag) {
        cout<<"deleted: "<<value<<endl;
        delete temp;
    }
    else
        cout<<value<<" not found"<<endl;
//    display();
}
void reverse() {

    cout<<"reversing the linked List"<<endl;
    if(start== nullptr || start->next==nullptr){
        cout<<"no need to do reverse"<<endl;
    }

    node * cur,*prev,*next;
    prev=nullptr;
    cur=start;
    next=cur;

    while(cur!=nullptr){
        next=cur->next; //we must have this line here or we have to check the condition
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    start=prev;
//    display();
}

int main()
{
//   display();
    append(10);
    append(20);
    append(30);
    append(0);


    cout<<"linked list"<<endl;
    display();

    reverse();

    cout<<"after reversing linked list"<<endl;
    display();


    del(20);
    del(10);
    cout<<"after deleting 20 and 10 linked list"<<endl;
    display();


    return 0;
}

