#include <iostream>
#include<conio.h>
#include<cstdlib>
#include<algorithm>
#include<math.h>
#define N 11
using namespace std;


struct heap{
   int arr[N];
   int size;//size points last element
};
void insert(struct heap *p,int val){
   int i=++(p->size);
   p->arr[i]=val;
   while(i/2!=0&&p->arr[i]>p->arr[i/2]){
      swap(p->arr[i],p->arr[i/2]);
      i/=2;
   }
   cout<<"inserted: "<<val<<endl;
}
bool remove(struct heap *p,int val){
  int i;
  cout<<"trying to remove "<<val<<endl;
  for(i=1;i<=p->size;i++)
     if(p->arr[i]==val)
            break;
  if(i==(p->size+1)){
  cout<<"elements is not present in the array\n";
  return false;
  }
  else
  {
        p->arr[i]=p->arr[p->size];
        p->size--;
        int rchild=2*i+1;
        int lchild=2*i;
        while(rchild<=p->size){
            if(p->arr[i]>=p->arr[rchild]&&p->arr[i]>=p->arr[lchild])
                break;
            else if(p->arr[rchild]<p->arr[lchild])
                    swap(p->arr[lchild],p->arr[i]),i=lchild;
            else
                swap(p->arr[rchild],p->arr[i]),i=rchild;
            rchild=2*i+1;
            lchild=2*i;

        }
        if(lchild==p->size&&p->arr[lchild]>p->arr[i])
            swap(p->arr[lchild],p->arr[i]);
   }
   return true;
}
void show(const heap &h){
for(int i=1;i<=h.size;i++)
        cout<<h.arr[i]<<" ";
        cout<<endl;
}
int main()
{
      heap h;
      h.size=0;
      for(int i=0;i<10;i++){
        insert(&h,rand()%20);
      }
      cout<<"showing heap "<<endl;
      show(h);
      for(int i=0;i<10;i++){
      if( remove(&h,18)){
       cout<<endl;
       cout<<"After removing "<<endl;
       show(h);
      }
      }
      return 0;
}
