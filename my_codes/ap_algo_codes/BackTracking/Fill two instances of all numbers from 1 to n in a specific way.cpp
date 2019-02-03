/*Fill two instances of all numbers from 1 to n in a specific way
Q.Given a number n, create an array of size 2n such that the array contains 2 instances of every number from 1 to n,
 and the number of elements between two instances of a number i is equal to i.
If such a configuration is not possible, then print the same.?
Input: n=3
Output : [3,1,2,1,3,2]
Input: n=2
Output: Not possible
*/


#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;//using aliasing

void printVect(vi &vect){
    for(auto x:vect){
    cout<<x<<" ";
 }
 cout<<endl;
}

bool solve(vi&vect,int n,int np){
    //function for trying putting a number(np==Number Putting)
    //n is maximum integer to be used ,size =2*n
    //vect for storing the vector as we done
  if(np>n)
    //as the number we want to put is more than max we return
    // true indicates that we are done and we have to return to main
    return true;

  for(int i=0;i<2*n-np-1;i++){
      //trying to put a pair at appropriate position
      // and go on next step, if it does not work then we backtrack
    if(vect[i]==0&&vect[i+np+1]==0)//both places need to be empty
    {
        vect[i]=np;
        vect[i+np+1]=np;
        if(solve(vect,n,np+1))
            return true;//if fun return true then we have to stop our work
        vect[i]=vect[i+np+1]=0;
    }
  }
  return false;
}
int main()
{
  int n;
  cin>>n;
  vector<int>vect(2*n);
  if(solve(vect,n,1))//1 is the starting number we will be trying to put
    printVect(vect);
  else
    cout<<"not possible";

    return 0;
}
