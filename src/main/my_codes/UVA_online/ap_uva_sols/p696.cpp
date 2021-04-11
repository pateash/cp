#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int a,b;
    while(cin>>a>>b){
        int ans;
        /*
        three spacial cases
        1- any one 1 ans= other (if both 1 also work)
        2- both 2 ans=4
            **
            **
        3- one 2 other odd

        */

        if(a || b){
            if(a==1||b==1)
                ans=(a==1)?b:a;
            else if(a==2&&b==2)
                ans=4;
            //when any of them is 2
            else if(a==2){
                if(b%4==0);
                else if(b%4==1)
                ans=(b/4)*4;
                    ans+=2;
                else
                    ans+=4;
            }
             else if(b==2){
                ans=(a/4)*4;
                if(a%4==0);
                else if(a%4==1)
                    ans+=2;
                else
                    ans+=4;
            }
           //end of any of them 2
            else
                ans=ceil(a*b/2.0);
            cout<<ans<<" ";
            cout<<"knights ";
            cout<<"may be placed on a "<<a<<" row "<<b<<" column board."<<endl;

        }else
            break;
    }

    return 0;
}
