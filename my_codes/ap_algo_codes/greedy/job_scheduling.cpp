#include<bits/stdc++.h>
struct job{
char name;
 int deadline;
 int profit;

};
using namespace std;
bool comp(job j1,job j2){
  return j1.profit>j2.profit;
}
void printJobs(job arr[],int n){
sort(arr,arr+n,comp);
char time[10]={'\0'};

for(int  i=0;i<n;i++){
    job j=arr[i];
    int k=j.deadline;
    while(k>0){
        if(time[k]=='\0')
        {
            time[k]=j.name;
            break;
        }
        k--;
    }
  }
  cout<<"printing jobs"<<endl;
  for(int i=0;i<n;i++)
     cout<<time[i]<<" ";
  cout<<endl;
}
int main(){

job arr[5]={ {'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40},
                   {'d', 1, 30}};
int n=sizeof(arr)/sizeof(arr[0]);
printJobs(arr,n);
}
