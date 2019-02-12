
#include<bits/stdc++.h>
using namespace std;

struct eNode{
    char data;
    eNode *left,*right;
};
eNode* make_node(char par){
     eNode *p=new eNode();
     p->data=par;
     p->left=p->right=NULL;
     return p;
}
void postorder(eNode* root){
  if(root==NULL)
    return ;
  else{
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}
int main()
{
    eNode *root;
    root=NULL;
    string postfix;
    cout<<"enter postfix\n"<<endl;
    cin>>postfix;
    stack<eNode *>s;
    eNode *temp;
      for(auto c: postfix){
         if(!isalpha(c)){
                     eNode *temp2=s.top();
                     s.pop();
                     temp=s.top();
                     s.pop();
                     eNode *par=make_node(c);
                     par->left=temp;
                     par->right=temp2;
                     s.push(par);
         } else{
                temp=make_node(c);
                s.push(temp);
            }
    }
    if(s.size()==1){
      root=s.top();
      s.pop();
    }
    else{
        cout<<"algo is not right size: "<<s.size()<<endl;
    }
    cout<<"postorder expression of the tree is"<<endl;
    postorder(root);
    return 0;
}
