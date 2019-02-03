// this algorithm uses devide and conquer technique to minimize the no. of comparisons fo
// finding the min and max in a array
//
#include<bits/stdc++.h>
#define llu long long unsigned int
#define ll long long int
#define mp make_pair
#define pr(n)  printf("%d",n)
#define prl(n) printf("%lld",n)
#define prf(n) printf("%f",n)
#define nl printf("\n")
#define sp printf(" ")
#define sc(n)  scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define INFI 1e9
using namespace std;

void max_min(int arr[],int &min,int &max,int start,int end)//stritly nearly n comparisons
{
    if(start==end){
      min=max=arr[start];
        return;
    }
    int minl,maxl,minr,maxr;
    int mid=(start+end)/2;
    max_min(arr,minl,maxl,start,mid);
    max_min(arr,minr,maxr,mid+1,end);
    min=std::min(minl,minr);//so that we could able to use min same
    max=std::max(maxl,maxr);
}
int main()
{
   int arr[]={33,232,343,2,3,34};
   int min=INFI,max=-1;
   max_min(arr,min,max,0,5);
   cout<<"min: "<<min;nl;
   cout<<"max: "<<max<<endl;
    return 0;
}
