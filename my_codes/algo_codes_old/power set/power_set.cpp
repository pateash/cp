#include<bits/stdc++.h>
using namespace std;

void power_set(vector<int>v){
   for(int i=0;i<pow(2,v.size());i++){
   	   if(i==0){
   	   	cout<<"EMPTY SET"<<endl;
        continue;
   	   }
   	    for (int j = 0; j < v.size(); ++j)
   	    {
   	    	if(i&(1<<j))
   	    		cout<<v[j]<<" ";
   	    }
   	    cout<<endl;
   }
}

int main(){
  vector<int>v;
  for(int i=0;i<4;i++)
  	 v.push_back(i+1);
  	  power_set(v);

}