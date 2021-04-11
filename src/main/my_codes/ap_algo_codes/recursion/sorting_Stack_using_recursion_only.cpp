/*
  this program sorts(Largest at Top) a stack with recursion
  logic:1-hold all values
        2-push at appropriate place one by one
*/
#include <iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

void showStack(stack<int>s){//this function is going to show all content of stack
  cout<<"the content of stack is as follows"<<endl;
  while(!s.empty())
  {
      int x=s.top();
      s.pop();
      cout<<x<<endl;
  }
  cout<<endl;//the s we have is different from that we have in main
}


void insertSortedPosition(stack<int>&s,int x){
   if(s.empty())
       s.push(x);
   else{
        if(s.top()<=x)//the stack is already sorted till now if x is greater or equal then no need to pop
          s.push(x);
        else{//if top is less than pop top and again try the same procedure
          int y=s.top();s.pop();
          insertSortedPosition(s,x);
          s.push(y);
        }
    }
}
void sortStack(stack<int>&s){//this function hold all values
   if(s.empty())
    return;
   int x=s.top();s.pop();
   sortStack(s);
   insertSortedPosition(s,x);
}
int main()
{
   stack<int>s;
   cout<<"enter the number of elements to be pushed"<<endl;
   int n=5;
   cin>>n;
   cout<<"enter "<<n<<" elements"<<endl;
   while(n--){
     int temp;
     cin>>temp;
     s.push(temp);
   }
   showStack(s);
   cout<<"GOING TO SORT"<<endl;
   sortStack(s);
   showStack(s);
   return 0;
}
