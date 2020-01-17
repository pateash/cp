//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_STACK2_H
#define SAMPLE_STACK2_H

#include "CommonLibs.h"

template <typename T>
class Stack{
    vector<T> array; //we can't allow access to array, as we only want it to be accessed via top
    int top;

public:

    Stack(int size){
        array.resize(size);
        top=-1;
    }

    void push(T val){

        if(top==array.size()){
            cout<<"Stack full, can't push"<<endl;
            return;
        }
        array[++top]=val;
        cout<<"pushed: "<<array[top]<<endl;

    }

    T pop(){
        if(top==-1) {
            cout << "Stack Empty, can't pop" << endl;
            return -1;
        }
        cout<<"poping: "<<array[top]<<endl;
        return array[top--];
    }

    int size(){
        return top+1; // top is an index
    }

    void display(){
        if(top==-1) {
            cout << "Stack Empty" << endl;
            return;
        }

        cout<<"Showing from top to bottom"<<endl;
        for(int i=top;i>=0;i--)
            cout<<array[i]<<endl;
        cout<<endl;
    }
};

#endif


int main()
{
    cout<<"------------ LinkedList1"<<endl;
    Stack<int> stack(100);

    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(0);

    stack.display();

    stack.pop();
    stack.pop();

    cout<<"after poping 2 elements"<<endl;
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();

    return 0;
}

/*
OUTPUT
/Users/ashish/Desktop/code/cmake-build-debug/Sample
------------ LinkedList1
pushed: 5
pushed: 10
pushed: 20
pushed: 30
pushed: 0
Showing from top to bottom
0
30
20
10
5

poping: 0
poping: 30
after poping 2 elements
Showing from top to bottom
20
10
5

poping: 20
poping: 10
poping: 5
Stack Empty, can't pop
Stack Empty

Process finished with exit code 0
 */
