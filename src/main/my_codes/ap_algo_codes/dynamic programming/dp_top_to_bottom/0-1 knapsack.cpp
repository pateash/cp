#include <bits/stdc++.h>
#define MAX 5//this is max index (size of arraysdd)
#define MAX_CAPACITY 100
using namespace std;
/*
  the problem can be broken into no. of elements the
  right side , and capacity remaining
 first convert into non dp recursive solution then convert into dp
*/
int profits[MAX];
int weights[MAX];
int dp_table[MAX][MAX_CAPACITY];
void initialise_dptable()
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX_CAPACITY;j++)
        dp_table[i][j]=-1;//if not anything
}
int find_max_profit(int index,int capacity)//brute profit recursion O(2^n)
{
    //function checking if an object can be included in knapsack
  if(index==MAX)//if all are done
        return 0;
  if(capacity<weights[index])//check for ith object
        return find_max_profit(index+1,capacity);
  //if capacity is more
  //there are two possibilities either add or not
  return max(find_max_profit(index+1,capacity),profits[index]+find_max_profit(index+1,capacity-weights[index]));
}

// dynamic programming implementation
int find_max_profit_dp(int index,int capacity)//using dp O(C*MAX) we just need to save values to 
{
    //function checking if an object can be included in knapsack
  if(index==MAX)//if all are done
  {
      dp_table[index][capacity]=0;
        return 0;
  }
  if(capacity<weights[index])//check for ith object
        {
            if(dp_table[index+1][capacity]==-1)//har jagah pahle pata agar nahi karo store karo ange ke liye
            dp_table[index+1][capacity]=find_max_profit_dp(index+1,capacity);
            return dp_table[index+1][capacity];
        }
  //if capacity is more
  //there are two possibilities either add or not
   if(dp_table[index+1][capacity]==-1)
    dp_table[index+1][capacity]=find_max_profit_dp(index+1,capacity);
   if(dp_table[index+1][capacity-weights[index]]==-1)
   dp_table[index+1][capacity-weights[index]]=find_max_profit_dp(index+1,capacity-weights[index]);
  return max( dp_table[index+1][capacity],profits[index]+dp_table[index+1][capacity-weights[index]]);
}int main()
{
    initialise_dptable();
    cout<<"Enter the profit and corresponding weight for "
    <<MAX<<" values\n";
    for(int i=0;i<MAX;i++)
        cin>>profits[i]>>weights[i];
    cout<<"enter the capacity"<<endl;
    int total_capacity;
    cin>>total_capacity;
    int max_profit=find_max_profit_dp(0,total_capacity);//start from index 0 and c capacity
    cout<<"maximum profit is "<<max_profit<<endl;


     return 0;
}
