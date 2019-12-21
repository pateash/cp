//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_LINKEDLIST_H
#define SAMPLE_LINKEDLIST_H

#include "CommonLibs.h"


template <typename T>
class LinkedList{
private:
    struct node {
        T value;
        node * next;

        node(T value){
            this->value=value;
            this->next= nullptr;
        }
    };

    node * start=nullptr;

public:

    void append(T i) {
        if(start == nullptr){
            start = new node(i);
            cout<<"appended:"<<i<<endl;
            return;
        }

        node*temp=start;
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=new node(i);
        cout<<"appended:"<<i<<endl;
    }

    void append(vector<T> v) {
        for( auto x: v){
            append(x);
        }
    }

    void display(){
        if(start== nullptr){
            cout<<"Empty"<<endl;
            return;
        }

        node*temp=start;
        while(temp!= nullptr){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverse(){
        if(start == nullptr || start->next == nullptr){
            cout<<" size is less than 2, nothing is needed"<<endl;
            return;
        }
        node *cur,*next,*prev;

        prev= nullptr;
        cur=start;

        while(cur!=nullptr){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        start=prev;
    }

    void remove(T val){

        if(start== nullptr){
            cout<<"empty list";
            return;
        }

        node* tmp=nullptr;

        if(start->value == val){ // if first element is matched value
            tmp=start;
            start=start->next;
        } else {
            node *prev= nullptr;
            tmp=start;
            while(tmp!=nullptr && tmp->value!=val){
                prev=tmp;
                tmp=tmp->next;
            }

            if(tmp== nullptr){
                cout<<val<< " Not found"<<endl;
                return;
            }

            // if found, connect prev and next
            prev->next=tmp->next;

        }
        delete tmp;
    }
};

#endif


int main()
{

    LinkedList<int> linkedList;

    linkedList.append(10);

//   display();
    linkedList.append(10);
    linkedList.append(20);
    linkedList.append(30);
    linkedList.append(0);


    cout<<"linked list"<<endl;
    linkedList.display();

    linkedList.reverse();

    cout<<"after reversing linked list"<<endl;
    linkedList.display();

    linkedList.remove(20);
    linkedList.remove(20);
    linkedList.remove(10);
    linkedList.remove(0);
    cout<<"after deleting 20 and 10 linked list"<<endl;
    linkedList.display();

    cout<<"------------"<<endl;

    LinkedList<float> linkedList2;

    linkedList2.append(10.25);
    linkedList2.append(20.21);


    cout<<"linked list"<<endl;
    linkedList2.display();

    linkedList2.reverse();

    cout<<"after reversing linked list"<<endl;
    linkedList2.display();

    linkedList2.remove(20.21);
    cout<<"after deleting 20 and 10 linked list"<<endl;
    linkedList2.display();

    return 0;
}

/*
OUTPUT
----------
appended:10
appended:10
appended:20
appended:30
appended:0
linked list
10 10 20 30 0
after reversing linked list
0 30 20 10 10
20 Not found
after deleting 20 and 10 linked list
30 10
------------
appended:10.25
appended:20.21
linked list
10.25 20.21
after reversing linked list
20.21 10.25
after deleting 20 and 10 linked list
10.25
*/
