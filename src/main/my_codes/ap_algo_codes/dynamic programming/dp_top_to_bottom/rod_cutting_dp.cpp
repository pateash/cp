/*
  this algorithm solves famous rod cutting dp problem
  using top down approach
*/

#include <iostream>
#define MAX_SIZE 101
using namespace std;
//taking for max size 8
int optimum_price_for_size_i[MAX_SIZE]={0};//size of rod will be from 0 to n(if size 0 then we have to return 0)
int rod_cutting_dp(int price[],int size_of_rod){
  int temp=INT_MIN;//to be used if not computed yet
  if(optimum_price_for_size_i[size_of_rod]!=0)//if already computed
    return optimum_price_for_size_i[size_of_rod];
 else if(size_of_rod<=1){
     if(size_of_rod==0) return 0;
     else{
          optimum_price_for_size_i[1]=price[1];
        return optimum_price_for_size_i[1];
     }
  }

  else//if not computed yet
  {
      for(int i=1;i<=size_of_rod;i++)
         temp=max(temp,price[i]+rod_cutting_dp(price,size_of_rod-i));
      optimum_price_for_size_i[size_of_rod]=temp;
  }
    return  optimum_price_for_size_i[size_of_rod];
}
int main()
{
   int n;
   cout<<"enter the length of rod"<<endl;
   cin>>n;
   int price[n+1]={0};//following 1 based indexing
   cout<<"enter price of each part from 1 to n\n";
   for(int i=1;i<=n;i++){
    cin>>price[i];
   }
   int max_price=rod_cutting_dp(price,n);
   cout<<"max price possible "<<max_price<<endl;
     return 0;
}
