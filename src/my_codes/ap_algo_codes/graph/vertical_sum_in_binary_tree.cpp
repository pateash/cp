#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

struct bst{//simple binary ,not binary search tree
  int data;
  bst *left,*right;
  int hdist;//to storing the distance from root(root taken as 0)
  bst(int data,bst*par,bool isleft){//for adding a new node in the tree
      if(par==nullptr)
          hdist=0;
      else
          hdist=(isleft)?par->hdist-1:par->hdist+1;
      this->data=data;
      this->left=this->right=nullptr;
   }
}*root=nullptr;
vector<bst>v;
#include<conio.h>

void inorder(bst*root){
//going to traverse as well as adding nodes in vector so that we can print  sum of nodes which has same vertical distance
 if(root==nullptr){
    return;
 }
// cout<<"inorder"<<endl;
 v.push_back(*root);
 //_getch();
 inorder(root->left);
 cout<<root->data<<" => "<<root->hdist<<endl;
 inorder(root->right);
}
bool comp(bst v1,bst v2){
  return v1.hdist<v2.hdist;
}



void show(vector<bst>v){
   for(auto x:v){
    cout<<x.data<<"-->"<<x.hdist<<endl;
   }
cout<<endl;
}
int main() {
  root=new bst(1,nullptr,true);
  root->left=new bst(2,root,true);

  root->right=new bst(3,root,false);

  root->left->left=new bst(4,root->left,true);

  root->left->right=new bst(5,root->left,false);

  root->right->left=new bst(6,root->right,true);

  root->right->right=new bst(7,root->right,false);
 cout<<"all added";
 //_getch();
     inorder(root);
  //   _getch();
 cout<<"vertical sum"<<endl;
 cout<<"size of v is "<<v.size()<<endl;
 sort(v.begin(),v.end(),comp);
 show(v);_getch();
 for(int i=0;i<v.size()-1;){
        int tsum=v[i].data;
    while(i<v.size()-1&&v[i].hdist==v[i+1].hdist)
    {
        tsum+=v[i+1].data;
        i++;
    }
    cout<<tsum<<" ";
    i++;
}
if(v[v.size()-1].hdist!=v[v.size()-2].hdist)
    cout<<v[v.size()-1].data<<" ";
cout<<endl;

}


