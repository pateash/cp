
/*
given a prime you have to find the next prime after it
*/

#include<bits/stdc++.h>
using namespace std;


 bool isprime(int n){
     if(n==2)
         return true;
     for(int i=2;i<=ceil(sqrt(n));i++){
         if(n%i==0)
             return false;
     }
     return  true;
 }

int next_prime(int p){
    if(p==2)
        return 3;
    for(int i=p+2;;i+=2){
        int j;
        bool flag=true;
        for(j=3;j<=int(sqrt(i));j+=2){
            if(i%j==0){
               flag=false;
                break;
            }
        }
        if(flag){
            return i;
        }
        //else look for another next
     }
}
int main(){
    int prime=2;
  for(int i=0;i<10;i++)
     {
        cout<<prime<<" ";
        prime=next_prime(prime);
     }
}
