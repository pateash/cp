#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
using namespace std;
struct bst
{
    int data;
    struct bst*left,*right;
    short flag;
};
struct stack
{
    int tos;
    struct bst*arr[size];
};
void push(struct stack*p,struct bst*x)
{
    if(p->tos==size-1)
    {
        cout<<"Overflow";
        _getch();
        return;
    }
    p->tos++;
    p->arr[p->tos]=x;
}
struct bst* pop(struct stack *p)
{
 if(p->tos==-1)
 {
     cout<<"Undefflow\n";
     _getch();
     return NULL;
 }
 struct bst*x=p->arr[p->tos];
 p->tos--;
 return x;
}
void preorder(struct bst*root)
{
    cout<<"PREORDER TRAVERSAL";
    cout<<endl<<"-----------------"<<endl;
    if(root==NULL)
    {
        cout<<"Empty tree";
    }
     struct stack s;
     s.tos=-1;
     struct bst*temp=root;
     push(&s,temp);
     while(s.tos!=-1)
     {
         temp=pop(&s);//har push hone wale ke saath yahi hogi kyoki root pahle hi print ho chuka hai no problem because we get problem when
         cout<<temp->data<<"  ";
         if(temp->right!=NULL)
             push(&s,temp->right);

         //both can be there at a time therefore we can't apply else or else if
         if(temp->left!=NULL)
             push(&s,temp->left);
     }
}
void inorder(struct bst*root)
{
    cout<<"INORDER TRAVERSAL";
    cout<<endl<<"-----------------"<<endl;
    if(root==NULL)
    {
        cout<<"Empty tree";
    }
     struct stack s;
     s.tos=-1;
     struct bst*temp=root;
    inorder:
         while(temp!=NULL)
     {
         push(&s,temp);
         temp=temp->left;
     }
     while(s.tos!=-1)
     {
        temp=pop(&s);//ek ko utao print karo right hai to us par jao wahi algo
        cout<<temp->data<<"  ";
        if(temp->right!=NULL)
        {
            temp=temp->right;
            goto inorder;
        }
    }
    }
void postorder(struct bst*root)
{
    cout<<"POSTORDER TRAVERSAL";
    cout<<endl<<"-----------------"<<endl;
    if(root==NULL)
    {
        cout<<"Empty tree";
    }
     struct stack s;
     s.tos=-1;
     struct bst*temp=root;
     postorder:
     push(&s,temp);
     while(temp!=NULL)
     {
         if(temp->right!=NULL)//right pahle push so that we can get left when poping always
         {
                temp->right->flag=-1;//right ko negative karke daal do
                push(&s,temp->right);
        }
        if(temp->left!=NULL)
            push(&s,temp->left);//left ko aise hi daal do
        temp=temp->left;
     }//end of while reached after to left last
    while(s.tos!=-1)
    {
        temp=pop(&s);
        if(temp->flag==1)//here we have pushed all left as well as right so we will check if flag(address) is positive or negative
            cout<<temp->data<<"  ";
        else
        {//if ad                                                                                                                                                                                                                                                                             dress is negative positive kar do same algo
            temp->flag=1;
            goto postorder;//postorder parchale jao woh khud hi push kar lega


        }
    }
}

void append(struct bst**pr,int x)
{
    struct bst*p=(struct bst*)malloc(sizeof(struct bst));
    p->left=p->right=NULL;
    p->data=x;
    p->flag=1;//used in post order otherwise not required
    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    struct bst*temp,*prev;
    temp=*pr;
    prev=NULL;//if not initialised no problem but here we do not ever want anything to contain garbage adress
    while(temp!=NULL)
    {
        prev=temp;
        if(x<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    //prev is at the last where node is to be appended
    if(x<prev->data)
        prev->left=p;
    else
        prev->right=p;
}
int search(struct bst*temp,int x, struct bst**ppar,struct bst**pchild)//search will be called only when there are some nodes in the tree
{
    while(temp!=NULL)
  {
      if(temp->data==x)
      {
          *pchild=temp;
          return 1;
      }
      *ppar=temp;
    if(x<temp->data)
        temp=temp->left;
    else
        temp=temp->right;
    }
    return 0;
}

void del(struct bst**pr,int x)
{
    if(*pr==NULL)
    {
        cout<<"Empty Tree\n";
        _getch();
        return;
    }
    struct bst*par,*child;
     par=child=NULL;
    int ans=search(*pr,x,&par,&child);
    if(ans==0)
    {
            cout<<"the element is not present in the tree"<<endl;
            _getch();
            return;
    }

    cout<<"the element is present in the tree child: "<<child->data;
    if(par!=NULL)
    cout<<"  parent: "<<par->data<<endl;
_getch();
    if(child->left!=NULL&&child->right!=NULL)
    {
        struct bst*xsucc=child->right;
        par=child;//parent xsucc ke just peechhe
        while(xsucc->left!=NULL)
        {
            par=xsucc;
            xsucc=xsucc->left;
        }
        child->data=xsucc->data;
        child=xsucc;
    }
    if(child->left==NULL&&child->right==NULL)
    {
        if(par==NULL)//if we are going to delete root node
            *pr=NULL;
       else if(par->left==child)
            par->left=NULL;
        else if(par->right==child)
            par->right==NULL;
        free(child);
    }
    else if(child->left!=NULL&&child->right==NULL)
    {
        if(par==NULL)
            *pr=child->left;
       else if(par->left==child)
           par->left=child->left;
        else if(par->right==child)
            par->right=child->left;
            free(child);
    }
   else if(child->left==NULL&&child->right!=NULL)
    {
        if(par==NULL)
          *pr=child->right;
      else if(par->left==child)
           par->left=child->right;
        else
            par->right=child->right;
            free(child);
    }
    cout<<x<< " has been deleted"<<endl;
    _getch();
}
int get_height(struct bst*temp)
{
    if(temp==NULL)
        return 0;
    int h_left=get_height(temp->left);
    int h_right=get_height(temp->right);
   if(h_right>h_left)
    return h_right+1;
   else
    return h_left+1;
}
int main()
{
    system("color f9");
    int x;
    struct bst*root;
    root=NULL;
    menu:
        system("cls");
    cout<<"Enter your choice\n1-Append\n2-Preorder\n3-Inorder\n4-Postorder\n5-Delete\n6-Height of Tree\n7-Quit\n";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter the number to be inserted\n";
        cin>>x;
        append(&root,x);
        goto menu;
    case 2:
        preorder(root);
        _getch();
        goto menu;
      case 3:
        inorder(root);
        _getch();
        goto menu;
      case 4:
        postorder(root);
        _getch();
        goto menu;
       case 5:
        cout<<"Enter the element to be deleted\n";
        cin>>x;
        del(&root,x);
        _getch();
        goto menu;
      case 6:
          cout<<"Height of tree is :"<<get_height(root)<<endl;
          _getch();
          goto menu;
      case 7:
        cout<<"Click to exit\n";
        _getch();
        exit(EXIT_SUCCESS);

    default:
     goto menu;
    }
return 0;
}
