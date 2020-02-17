#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<vector>
using namespace std;
struct bst
{
    int data;
    struct bst*left,*right;
};
void traverse(struct bst* root)
{
    if(root==NULL)
        return;
    traverse(root->left);
    traverse(root->right);
    cout<<root->data<<" ";
}
void append(struct bst**pr,int x)
{
    struct bst*p=(struct bst*)malloc(sizeof(struct bst));
    p->left=p->right=NULL;
    p->data=x;
    if(*pr==NULL)
        *pr=p;
    else{
        struct bst*temp=*pr,*prev=NULL;
        while(temp!=NULL)
        {
            prev=temp;
            if(x>temp->data)
                temp=temp->right;
            else
                temp=temp->left;
        }
        if(x>prev->data)
            prev->right=p;
        else
            prev->left=p;
        }
}
int main()
{
    struct bst*root=NULL;
    int n;
    int x;
    cout<<"Enter the number of elements\n";
    cin>>n;
    vector<int>inorder,preorder;
    cout<<"Enter inorder sequence\n";
    for (int i=0;i<n ;i++ )
    {
        cin>>x;
        inorder.push_back(x);
    }
    cout<<"Enter preorder sequence\n";
    for (int i=0;i<n ;i++ )
    {
        cin>>x;
        preorder.push_back(x);
    }
    for(auto i:preorder)
        append(&root,i);

    cout<<"\n\nTree has been constructed \n";
    cout<<"\nPOST ORDER TRAVERSAL IS\n";
    cout<<"-----------------------\n";
    traverse(root);
        _getch();
    return 0;
}
