#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
/*
PROBLEM-Find the sum of elements from index l to r where 0 <= l <= r <= n-1
Change value of a specified element of the array arr[i] = x
where 0 <= i <= n-1.
SOLUTION- segment tree allows us to update in log(n) and also query in log(n)
time so if n queries need to be done it could be done in nlog(n)
*/
using namespace std;
int STsize;
vector<int>lazy;//for storing lazy tree
vector<int>st;//for storing segment tree
int constructSTUtil(int arr[],int start,int end,int index){
    //index represent the index of st
    //start and end are index of array from which we have
    //to generate the st
    if(start==end)
    {
        st[index]=arr[start];
        return st[index];
    }
    int mid=(start+end)/2;
    int left=constructSTUtil(arr,start,mid,2*index);
    int right=constructSTUtil(arr,mid+1,end,2*index+1);
    st[index]=left+right;
    return st[index];
    //returning the value so that the parent node could able to get value of both nodes
    //by summing them together
}
void constructST(int arr[],int n){
    int h=ceil(log2(n));//max height of tree with n elements
    //ST will always be a complete Binary tree
    STsize=pow(2,h+1);//max number of elements possible
    st.resize(STsize,0);
    lazy.resize(STsize,0);//lazy tree of same size all set to 0
    //0 will be leaved as we do in heap and also it will not be destroyed when we leave the function
    constructSTUtil(arr,0,n-1,1);
    //returning the tree made
}

int getSumUtil(int rstart,int rend,int qstart,int qend,int index ){
    // printf("called for rs: %d , re: %d ,start: %d ,end: %d\n",rstart,rend,qstart,qend);
    //rstart and rangeEnd represents the range corrospoinding to a node
    //qstart and qend represents the sequence required(query start and query end)

    /*
     * extra work needed to be done if lazy flag for this node
     * is not 0
     */
    if(lazy[index]!=0){
        //perform pending request and
        //propogate the pending to childs
        st[index]+=(rend-rstart+1)*lazy[index];
        /*
         * now here rend-rstart+1 will be no. of elements
         * repersents by it(its child) so value will be added to all
         * so its value will increased by (rend-rstart+1)*lazy[index]
         */

        /*if more than 1 elements are represented by it then
         * have to update child(min 2 ki range ko represent to childs honge)
         * */
        if(rstart!=rend){
            //min 2 elements be in range of node to have childrens
            lazy[index<<1]+=lazy[index];
            lazy[(index<<1)+1]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(rstart==qstart&&rend==qend)
        return st[index];
    int rmid=(rstart+rend)/2;
    if(qend<=rmid)
        return getSumUtil(rstart,rmid,qstart,qend,2*index);
    else if(qstart>=rmid+1)
        return getSumUtil(rmid+1,rend,qstart,qend,2*index+1);
    return getSumUtil(rstart,rmid,qstart,rmid,2*index)+
           getSumUtil(rmid+1,rend,rmid+1,qend,2*index+1);
}
int getSum(int n,int start,int end){
    //start and end are index of sequence for which
    //we have to calculate the sum
    //n is length of array
    if(start<0||end>n-1||start>end)
        return -1;
    else
        return getSumUtil(0,n-1,start,end,1);

}
// Driver program to test above functions

void updateRangeUtil(int rstart,int rend,int updateIndexStart,int updateIndexEnd,int delta,int index) {
    //here delta represents the value to be added
    //if check it any lazy propogation is there for this node
    if(lazy[index]!=0){

        st[index]+=(rend-rstart+1)*lazy[index];
        if(rstart!=rend){
            //propagate lazy to children
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(rstart==updateIndexStart&&rend==updateIndexEnd){
       st[index]+=(rend-rstart+1)*delta;
        if(rstart!=rend){
            //propagate lazy to children
            lazy[2*index]+=delta;
            lazy[2*index+1]+=delta;
        }
        lazy[index]=0;//already
      return;
    }
    int rmid=(rstart+rend)/2;
    if(updateIndexEnd<=rmid)
        updateRangeUtil(rstart,rmid,updateIndexStart,rmid,delta,2*index);
    else if(updateIndexStart>=rmid+1)
        updateRangeUtil(rmid+1,rend,rmid+1,updateIndexEnd,delta,2*index+1);
    else{
        updateRangeUtil(rstart,rmid,updateIndexStart,rmid,delta,2*index);
        updateRangeUtil(rmid+1,rend,rmid+1,updateIndexEnd,delta,2*index+1);
    }
    st[index]=st[index<<1]+st[(index<<1)+1];
}
int updateRange(int n,int updateIndexStart,int updateIndexEnd,int value)
{

    //value is value to be given to range
    if(updateIndexStart<0||updateIndexEnd>=n)
        return -1;
    else{
        //we have to update value and also update the nodes affected by it
        updateRangeUtil(0,n-1,updateIndexStart,updateIndexEnd,value,1);
        //we add delta to each node to get desired change in this
        //in this case else we may have to recurse back to
        //do the desired changes
    }
}

template <typename T>
void show_1d(T container){

    for(auto it=container.begin();it!=container.end();it++){
        cout<<*it<<" ";

    }
    cout<<endl;
}

template <typename  T>
void show_arr(T arr[],int size){
    cout<<"content in array is here"<<endl;
    for (int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    constructST(arr, n);

    cout<<"st is "<<endl;
    show_1d(st);
    cout<<"lazy is "<<endl;
    show_1d(lazy);
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           getSum( n, 1, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateRange(n,1,5,10);
    cout<<"AFTER UPDATING"<<endl;
    cout<<"st is "<<endl;
    show_1d(st);
    cout<<"lazy is "<<endl;
    show_1d(lazy);

    /*
     * here we donot update the value of arr because this will
     * lead to O(n) time so we are just changing in tree
     */
    printf("Updated sum of values in given range = %d\n",
           getSum(n, 1, 3));

    return 0;
}
