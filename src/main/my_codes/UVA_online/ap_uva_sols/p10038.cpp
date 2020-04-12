#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
    while(cin>>n){
        if(n==0)
        {
            cout<<"Not jolly"<<endl;
            continue;
        }
        vector<int>v;
        repn(n){
            int temp;
            sc(temp);
            v.push_back(temp);
        }
        vector<int>hash;
        hash.resize(n,0);
        repn(n-1){
            hash[int(abs(v[i]-v[i+1]))]=1;
        }
        bool flag=true;
        for (int j = 1; j < n; ++j) {
            if(hash[j]==0)
            {flag=false;break;}
        }
   if(flag)
       cout<<"Jolly"<<endl;
        else
       cout<<"Not jolly"<<endl;
    }
    return 0;
}
