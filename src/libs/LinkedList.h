//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_LINKEDLIST_H
#define SAMPLE_LINKEDLIST_H

#include "CommonLibs.h"

template <typename T>
class LinkedList{
public: // made every thing public so we could create loop and stuff for testing
    struct node {
        T value;
        node * next;

        node(T value){
            this->value=value;
            this->next= nullptr;
        }
    };

    node * start=nullptr;

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

    void display(int elementsToDisplay){  // used for linkedlists with loops
        if(start== nullptr){
            cout<<"Empty"<<endl;
            return;
        }

        node*temp=start;
        while(temp!= nullptr && elementsToDisplay--){
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

    bool detectAndBreakLoop(){

        if(this->start==nullptr || this->start->next==nullptr)
        {
            cout<<"List has less than 2 elements, so loop not possible.";
            return false;
        }

        node *tortoise, *hare;
        hare=tortoise=this->start;

        do{ // hare will always be ahead of tortoise so no worries, except for the first time initially, that's why we are using do while()
            tortoise=tortoise->next;
            hare=hare->next->next;
        }while(hare != nullptr && hare->next != nullptr && hare!=tortoise);

        if( hare != tortoise) { // loop not found
            cout<<"loop not found.";
            return false;
        }
        else{
            // loop found, set one of the pointer to starting and move both together both by 1

            tortoise=this->start;

            while(tortoise->next != hare->next) { // using next, so we can delete loop as when matched we will be standing to previous node
                tortoise=tortoise->next;
                hare=hare->next;
            }

            cout<<"loop found, starting at: "<< tortoise->next->value<<", removing.."<<endl;
            hare->next=nullptr; //breaking the loop
            return true;
        }
    }
};

#endif

/*
int main()
{
    cout<<"------------ LinkedList1"<<endl;
    LinkedList<int> linkedList;

    linkedList.append(10);
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

    cout<<"------------ LinkedList2"<<endl;

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

    // for testing detecting loop and breaking it

    cout<<"------------ LinkedList3"<<endl;

    LinkedList<int> linkedList3;

    linkedList3.append(10);
    linkedList3.append(20);
    linkedList3.append(30);
    linkedList3.append(0);

    linkedList3.display();

    LinkedList<int>::node* start= linkedList3.start;

    start->next->next->next->next = start->next;

    linkedList3.display(8);
    linkedList3.detectAndBreakLoop();
    linkedList3.display(8);
    return 0;
}
*/
/*
OUTPUT
----------
------------ LinkedList1
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
------------ LinkedList2
appended:10.25
appended:20.21
linked list
10.25 20.21
after reversing linked list
20.21 10.25
after deleting 20 and 10 linked list
10.25
------------ LinkedList3
appended:10
appended:20
appended:30
appended:0
10 20 30 0
10 20 30 0 20 30 0 20
loop found, starting at: 20, removing..
10 20 30 0

Process finished with exit code 0


 */
