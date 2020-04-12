#include <iostream>
#include <cmath>
#include <cstdio>
/*
PROBLEM-Find the sum of elements from index l to r where 0 <= l <= r <= n-1
Change value of a specified element of the array arr[i] = x
where 0 <= i <= n-1.
SOLUTION- segment tree allows us to update in log(n) and also query in log(n)
time so if n queries need to be done it could be done in nlog(n)
*/
using namespace std;
int STsize;
int constructSTUtil(int arr[],int st[],int start,int end,int index){
    //index represent the index of st
    //start and end are index of array from which we have
    //to generate the st
  if(start==end)
  {
      st[index]=arr[start];
      return st[index];
  }
  int mid=(start+end)/2;
  int left=constructSTUtil(arr,st,start,mid,2*index);
  int right=constructSTUtil(arr,st,mid+1,end,2*index+1);
  st[index]=left+right;
  return st[index];
 //returning the value so that the parent node could able to get value of both nodes
 //by summing them together
}
int *constructST(int arr[],int n){
  int h=ceil(log2(n));//max height of tree with n elements
  //ST will always be a complete Binary tree
  STsize=pow(2,h+1);//max number of elements possible
  int *st=new int[STsize+1];
  //0 will be leaved as we do in heap and also it will not be destroyed when we leave the function
  constructSTUtil(arr,st,0,n-1,1);
 return st;//returning the tree made
}

int getSumUtil(int st[],int rstart,int rend,int qstart,int qend,int index ){
  // printf("called for rs: %d , re: %d ,start: %d ,end: %d\n",rstart,rend,qstart,qend);
    //rstart and rangeEnd represents the range corrospoinding to a node
    //qstart and qend represents the sequence required(query start and query end)
    if(rstart==qstart&&rend==qend)
        return st[index];
    int rmid=(rstart+rend)/2;
    if(qend<=rmid)
        return getSumUtil(st,rstart,rmid,qstart,qend,2*index);
    else if(qstart>=rmid+1)
        return getSumUtil(st,rmid+1,rend,qstart,qend,2*index+1);
    return getSumUtil(st,rstart,rmid,qstart,rmid,2*index)+
           getSumUtil(st,rmid+1,rend,rmid+1,qend,2*index+1);
}
int getSum(int st[],int n,int start,int end){
    //start and end are index of sequence for which
    //we have to calculate the sum
    //n is length of array
  if(start<0||end>n-1||start>end)
    return -1;
  else
    return getSumUtil(st,0,n-1,start,end,1);

}
// Driver program to test above functions

void updateValueUtil(int st[],int rstart,int rend,int updateIndex,int diff,int index){
   //nothing is needed to return as we are changing while going downward
   st[index]+=diff;//update the node
   if(rstart==rend)
     return;
   int rmid=(rstart+rend)/2;
   if(updateIndex<=rmid)
     updateValueUtil(st,rstart,rmid,updateIndex,diff,index<<1);
   else
     updateValueUtil(st,rmid+1,rend,updateIndex,diff,(index<<1)+1);//+ is of much presedence that <<
}
int updateValue(int arr[],int st[],int n,int updateIndex,int value)
{
    if(updateIndex<0||updateIndex>=n)
        return -1;
    else{
    //we have to update value and also update the nodes affected by it
    int diff=value-arr[updateIndex];
    arr[updateIndex]=value;
    updateValueUtil(st,0,n-1,updateIndex,diff,1);
    //we add diff to each node to get desired change in this
    //in this case else we may have to recurse back to
    //do the desired changes
    }
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
            getSum(st, n, 2, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr,st,n,2,100);
     printf("Updated sum of values in given range = %d\n",
             getSum(st, n, 2, 3));

    return 0;
}
