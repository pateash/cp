/*
  algorithm for finding min and second min in an array using devide and conquer technique
*/
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
#define mp make_pair
using namespace std;
pair<int,int> min_first_second(int arr[],int start,int end)
{
    int min,smin;
    if(start==end){//at base case when only single element smin return infinity so that element of other part always provide smin
      min=arr[start];
      smin=INFI;//so that it could be updated later on
        return mp(min,smin);
    }
    int mid=(start+end)/2;
    auto pl=min_first_second(arr,start,mid);//returning pair
    auto pr=min_first_second(arr,mid+1,end);
    int minl=pl.first;
    int minr=pr.first;
    int sminr=pr.second;
    int sminl=pl.second;
    if(minl>minr)
    {
        min=minr;
        smin=std::min(minl,sminr);
     }
    else
    {
        min=minl;
        smin=std::min(sminl,minr);
    }
       return mp(min,smin);

}
int main()
{
   int arr[]={33,232,343,2343,23,34};
   auto p=min_first_second(arr,0,5);
   cout<<"min: "<<p.first;nl;
   cout<<"smin: "<<p.second<<endl;
    return 0;
}
