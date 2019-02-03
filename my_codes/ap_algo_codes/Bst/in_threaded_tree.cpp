#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    struct node*left,*right;
    int data;
    int lthread,rthread;

};
struct node*in_succ(struct node*temp);
struct node*in_pred(struct node*temp);
void insert(struct node**pr,int key);
void del(struct node**pr,int key);
int search(struct node*root,int key,struct node**pchild,struct node**ppar);
void inorder(struct node*root);
int main()
{
    system("color f9");
  int choice;
   int x;
   struct node*root=NULL;
 while(true)
 {
    system("cls");
  cout<<"Enter your choice\n1-Insert \n2-Delete\n3-Inorder Traversal\n4-Quit\n";
  cin>>choice;
  switch (choice)
  {
  case 1:
      cout<<"enter the number to be inserted\n";
      cin>>x;
      insert(&root,x);
      cout<<"inserted "<<x<<endl<<"root: "<<root<<endl;
      _getch();
      break;
  case 2:
    cout<<"enter the number to be deleted\n";
    cin>>x;
    del(&root,x);
      break;
  case 3:
    cout<<"INORDER TRAVERSAL OF THE THREADED BINARY TREE\n";
    inorder(root);
    _getch();
    break;
  case 4:
    cout<<"click to exit\n";
    _getch();
    exit(EXIT_SUCCESS);
  default:
      break;
  }
 }
       return 0;
}
struct node*in_succ(struct node*temp)
{
  if(temp->rthread==true)
    return temp->right;
    temp=temp->right;
    while(temp->lthread==false)
        temp=temp->left;
        return temp;

}
struct node*in_pred(struct node*temp)
{
   if(temp->lthread==1)
    return temp->left;
    temp=temp->left;
    while(temp->rthread==0)
        temp=temp->right;
        return temp;
}
void insert(struct node**pr,int key)
{
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->lthread=p->rthread=true;
    p->data=key;
    p->left=p->right=NULL;
    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    struct node*temp=*pr;
    while(temp->right!=NULL)//jab tak akhiri wale tak na pahuch jaye akhiri par pahunch kar ruk jayenge
    {
        if(key<temp->data)
        {
            if(temp->lthread==false)
                temp=temp->left;
            else
                break;
        }
        else if(key>temp->data)
        {
            if(temp->rthread==false)
                temp=temp->right;
            else
                break;
        }
    }
    //waha pahunch gaye jiske neeche add karna hai
    if(key<temp->data)
    {
        p->left=temp->left;
        p->right=temp;
        temp->left=p;
        temp->lthread=false;
    }
    else if(key>temp->data)
    {
        p->right=temp->right;
        p->left=temp;
        temp->right=p;
        temp->rthread=false;
    }

}
void del(struct node**pr,int key)
{
    if(*pr==NULL)
    {
        cout<<"Empty tree\n";
        _getch();
        return;
    }
    struct node*temp=*pr;
    struct node*child,*par;
    child=par=NULL;
    int result=search(*pr,key,&child,&par);
    if(result==0)
    {
        cout<<"key is not found in the tree\n";
        _getch();
        return;
    }
    //key is found
    if(child->lthread==false&&child->rthread==false)
    {
        cout<<"case 1- both child\n";
        _getch();
        struct node*xsucc;
        xsucc=child->right;
        par=child;
        while(xsucc->lthread==false)//jab tak child milte rahe
        {   par=xsucc;
            xsucc=xsucc->left;
        }
        child->data=xsucc->data;
        child=xsucc;
    }
    if(child->lthread==true&&child->rthread==true)//case for leaf node
    {
        cout<<"case 2- no child\n";
        _getch();

      if(par==NULL)//if node is needed to be deleted and it has no childs
          *pr=NULL;
      else if(par->left==child)//here for left and right child process will be different as thread needs to be updated accordingly
      {
          struct node*xpred=in_pred(child);
          par->left=xpred;
          par->lthread=true;//now parent is having thread as the leaf node is deleting
      }
       else if(par->right==child)//here for left and right child process will be different as thread needs to be updated accordingly
      {
          struct node*xsucc=in_succ(child);
          par->right=xsucc;
          par->rthread=true;//now parent is having thread as the leaf node is deleting
      }
        free(child);
    }
    else if(child->lthread==false&&child->rthread==true)//keval left child ho
    {
        cout<<"case 3- left child\n";
        _getch();

        if(par==NULL)                                          //agar rthread wala jata hai to uska right thread samhalega child ka predecessor
        {
            struct node*xpred=in_pred(child);
            *pr=child->left;
            xpred->right=*pr;
            free(child);
            return;
        }
          struct node*xpred=in_pred(child);
          xpred->right=child->right;
          if(par->right==child)
                   par->right=child->left;                                     //agar lthread wala jata hai to uska left thread samhalega child ka successor
          else
                   par->left=child->left;
        free(child);
    }
    else if(child->lthread==true&&child->rthread==false)//right child matlab left thread , use lene ayega xsucc
    {cout<<"case 4- right child\n";
        _getch();

        if(par==NULL)
        {
            struct node*xsucc=in_succ(child);
            *pr=child->right;
            xsucc->left=*pr;
            free(child);
            return;
        }
        struct node*xsucc=in_succ(child);
        xsucc->left=child->left;
        if(par->right==child)
            par->right=child->right;
        else
            par->left=child->right;
        free(child);
    }

}
int search(struct node*root,int key,struct node**pchild,struct node**ppar)
{
    if(root==NULL)
    {
        cout<<"Empty tree\n";
        _getch();
        return 0;
    }
    *ppar=*pchild=NULL;
    struct node*temp=root;
    while(temp!=NULL)//last wala bhi check kar lo
    {
        if(key==temp->data)
        {
            *pchild=temp;
            cout<<key<<"  is found"<<endl;
            return 1;
        }
        *ppar=temp;
        if(key<temp->data)
        {
            if(temp->lthread==false)
                temp=temp->left;
            else
                break;

        }
        else// key>temp->data;
        {
           if(temp->rthread==false)
                temp=temp->right;
           else
                break;
        }
    }
    cout<<key<<" not found"<<endl;
     _getch();
          return 0;

}
void inorder(struct node*root)
{
    if(root==NULL)
    {
        cout<<"Empty Tree\n";
        _getch();
        return;
    }
    struct node*temp=root;
    while(temp->lthread==false)
        temp=temp->left;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=in_succ(temp);
    }
}
