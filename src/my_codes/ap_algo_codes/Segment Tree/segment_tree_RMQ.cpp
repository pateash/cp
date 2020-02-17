
#include<bits/stdc++.h>
using namespace std;
/*
PROBLEM-
Range Minimum Query problem is discussed as another example where Segment Tree can be used.
Following is problem statement.
We have an array arr[0 . . . n-1]. We should be able to efficiently find the minimum value from index qs (query start) to qe (query end)
where 0 <= qstart <= qend <= n-1.

 WE CAN ALSO ADD SOME UPDATE METHOD (if required in question) AND THEN
 UPDATE SUCH THAT st[index]=min(st[index],value);//NEW VALUE will be inserted if it is less than existing

*/
int pow(int a,int b){//log(b) power function
    if(b==0)
        return 1;
    int ans=pow(a,b/2);
    if(b&1)
        return ans*ans*b;
    else
        return ans*ans;
}
int constructSTUtil(int arr[],int st[],int rstart,int rend,int index){
    if(rstart==rend) {
        st[index] = arr[rstart];//because min of 1 element will always be itself
        return arr[rstart];
    }
    int rmid=(rstart+rend)/2;
    int leftMin=constructSTUtil(arr,st,rstart,rmid,index<<1);
    int rightMin=constructSTUtil(arr,st,rmid+1,rend,(index<<1)+1);
    st[index]=min(leftMin,rightMin);
    return st[index]
}
int* constructST(int arr[],int n){
    int height=ceil(log2(n));//height
    int size=pow(2,height+1);
    int*st=new int[size];
    constructSTUtil(arr,st,0,n-1,1);
    return st;
}

int RMQ(int st[],int rstart,int rend,int qstart,int qend,int index)
{//we have to find the min. of given range
    if(rstart==qstart&&rend==qend)
        //completely matches,if there is only one element than also it will satisfy
        return st[index];


    int rmid=(rstart+rend)/2;
    if(qend<=rmid)
        return RMQ(st,rstart,rmid,qstart,qend,index<<1);
    else if(qstart>=rmid+1)
        return RMQ(st,rmid+1,rend,qstart,qend,(index<<1)+1);
    else{
        //from both sides
        int leftMin=RMQ(st,rstart,rmid,qstart,rmid,index<<1);
        int rightMin=RMQ(st,rmid+1,rend,rmid+1,qend,(index<<1)+1);
        return min(leftMin,rightMin);
    }
}

int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range

    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
           qs, qe, RMQ(st,0,n-1, qs, qe,1));

    return 0;
}
