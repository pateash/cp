#ifndef SAMPLE_STACK_H
#define SAMPLE_STACK_H

#include "CommonLibs.h"

// this version doesn't have top to manage and uses native vector functions, checkout other Lib Stack2.h
template <typename T>
class Stack{
    vector<T>v;
public:
    Stack(){}
    Stack(int size){v.resize(size);}
    void push(T value){v.push_back(value);}
    T pop(){
        T x=v.back();
        v.pop_back();
        return x;
    }//we have made pop which return value as well
    void clear(){v.clear();}
    int size(){return v.size();}
    void show(){
        if(v.empty()) {
            cout << "Empty Stack" << endl;
            return;
        }
        cout<<"the element of stack are"<<endl;
        for(auto x:v) {

            cout << x << "";
        }
        cout<<endl;
    }
    bool empty(){return v.empty();}
};

#endif
