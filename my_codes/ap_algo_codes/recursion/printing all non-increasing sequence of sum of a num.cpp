/*GFG/recursion/Question
 *******************
 this is Program prints the all possible non-increasing sequences of  a num
   ex-sum=3
      OP-1 1 1
         2 1
         3
*/
#include <bits/stdc++.h>
using namespace std;

void print(int arr[],int index){
 for(int i=1;i<=index;i++)//we are using 1 based indexing,because index is 1 based
    cout<<arr[i]<<" ";
 cout<<endl;
}
//this function going to store sequence in array and print
void printSequence(int arr[],int sum,int index,int cur_sum){
   if(cur_sum==sum){
     print(arr,index-1);//till previous index we have to print (ye aange wala hai)
     return;
   }
   for(int n=1;n<=sum;n++){//trying to put all numbers from 1 to sum at a index
       if(n+cur_sum<=sum&&(index==1||n<=arr[index-1])){
        /*1-if a number can be inserted (that is cur_sum does not become more than sum)
          2-also we can insert if the number is less than previous and index should not be starting(shuru wala nahi i.e. index should exist)
        */
        arr[index]=n;
        printSequence(arr,sum,index+1,cur_sum+n);
       }
       else//if a number fails to insert it means greater than this will also fail
        break;
   }
}
int main()
{
   cout<<"enter the number"<<endl;
   int n;
   cin>>n;
 int arr[n+1]={0};//array to store sequence
   printSequence(arr,n,1,0);
    return 0;
}
