#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

struct bst{
  int data;
  bst *left,*right;
  int hdist;
  bst(int data,bst*par,bool isleft){
      if(par==nullptr)
          hdist=0;
      else
          hdist=(isleft)?par->hdist-1:par->hdist+1;
      this->data=data;
      this->left=this->right=nullptr;
   }
}*root=nullptr;
#include<conio.h>
#include<queue>
queue<bst*>q1,q2;
int find_lsum(bool isFirst=true){
  int ans=0;
  if(isFirst){
  while(!q1.empty()){
    bst* x=q1.front();q1.pop();
    ans+=x->data;
    if(x->left!=nullptr)
        q2.push(x->left);
    if(x->right!=nullptr)
        q2.push(x->right);
  }
  cout<<ans<<endl;
  if(!q2.empty())
  find_lsum(false);
  }
  else{
   while(!q2.empty()){
    bst* x=q2.front();q2.pop();
    ans+=x->data;
    if(x->left!=nullptr)
        q1.push(x->left);
    if(x->right!=nullptr)
        q1.push(x->right);
  }

  cout<<ans<<endl;
  if(!q1.empty())
  find_lsum();
  }
}
int main() {
  root=new bst(1,nullptr,true);
  root->left=new bst(2,root,true);
root->right=new bst(3,root,false);

// root->left->left=new bst(4,root->left,true);
// root->left->left->left=new bst(5,root->left->left,true);
//
//
//  root->left->right=new bst(5,root->left,false);
//
//  root->right->left=new bst(6,root->right,true);
//root->right->left=new bst(6,root->right,true);
//
// root->right->right=new bst(7,root->right,false);
 q1.push(root);
 cout<<"vertical sum is "<<endl;
find_lsum(root);
cout<<endl;

}


