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


void insertBottom(stack<int>&s,int x){
   if(s.empty())
       s.push(x);
   else{
        int y=s.top();s.pop();
        insertBottom(s,x);
        s.push(y);

    }
}
void reverseStack(stack<int>&s){
   if(s.empty())
    return;
   int x=s.top();s.pop();
   reverseStack(s);
   insertBottom(s,x);
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
   cout<<"GOING TO REVERSE"<<endl;
   reverseStack(s);
   showStack(s);
   return 0;
}
