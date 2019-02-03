/*
  1-this algorithm solves famous rod cutting dp problem
  using top down approach
  2-it is an extended version of simple algorithm which also finds the length of subparts
*/

#include <iostream>
#define MAX_SIZE 9
using namespace std;
//taking for max size 8
int optimum_price_for_size_i[MAX_SIZE][3]={0,0};//size of rod will be from 0 to n(if size 0 then we have to return 0)
/*
  now the dp table will also store the 2 parts in which the length to be devided for
  optimum solution, smaller parts will be founded by the finding the parts in which part two will be devided,
  because part one is fixed (Rm=max(1 to n){pi+Rm-i})//pi is fixed
*/


int rod_cutting_dp(int price[],int size_of_rod){


  int temp[3];//store the details
  /*
  temp also has been modified in array of three elements to store the optimum price as well as the
    the parts in which it is going to be devided
  */
  temp[0]=INT_MIN;//to be used if not computed yet
  if(optimum_price_for_size_i[size_of_rod][0]!=0)//if already computed
    return optimum_price_for_size_i[size_of_rod][0];
 else if(size_of_rod<=1){
     if(size_of_rod==0)
        return 0;
     else{
          optimum_price_for_size_i[1][0]=price[1];
          optimum_price_for_size_i[1][1]=1;//only one segment is formed which is of length 1
          optimum_price_for_size_i[1][2]=0;//no second part formed
        return optimum_price_for_size_i[1][0];
     }
  }

  else//if not computed yet
  {
      for(int i=1;i<=size_of_rod;i++){
         if(temp[0]<price[i]+rod_cutting_dp(price,size_of_rod-i)){
                temp[0]=price[i]+rod_cutting_dp(price,size_of_rod-i);
                temp[1]=i;
                temp[2]=size_of_rod-i;
         }
      }
      optimum_price_for_size_i[size_of_rod][0]=temp[0];
      optimum_price_for_size_i[size_of_rod][1]=temp[1];
      optimum_price_for_size_i[size_of_rod][2]=temp[2];
  }
    return  optimum_price_for_size_i[size_of_rod][0];
}
void show_dp()
{
    for(int i=0;i<MAX_SIZE;i++)
        cout<<optimum_price_for_size_i[i][0]<<"-->"<< optimum_price_for_size_i[i][1]<<"-->"<<optimum_price_for_size_i[i][2]<<endl;
    cout<<endl;
}
void show_part_formed(int length){
  /*this function show the parts in which rod will be cutted down
    part are stored in dp_table in 1 and 2 index, in them 1 index has fixed part
    so only 2 need to be found recursively
   */
   int first_part=optimum_price_for_size_i[length][1] ;
   int second_part=optimum_price_for_size_i[length][2] ;

     cout<<first_part<<" ";//we have to print 1st as it is and recursively find for 2nd
   if(second_part!=0){
    show_part_formed(second_part);
   }
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
   cout<<"parts in which the rod need to be devided are"<<endl;
   show_part_formed(n);//finding and printing recursively
     return 0;
}
