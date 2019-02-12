#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node{
  int data;
  struct node*next;

};
void show(struct node*start){
  if(start==NULL){
    puts("The list is empty\n");
    return;
  }
  while(start!=NULL){
    printf("%d ",start->data);
    start=start->next;
  }
  puts("\n\n");
}
void append(struct node**ps, int val){
     struct node*temp=*ps;
   struct node*p=(struct node*)malloc(sizeof(struct node));
   if(p==NULL){
    puts("can't able to allocate memory for new node\n");
   }
   p->data=val;
   p->next=NULL;
   if(*ps==NULL){
   *ps=p;
   }
   else{
      while(temp->next!=NULL)
        temp=temp->next;
      temp->next=p;
    }
}
int del_first(struct node**ps){
  if(*ps==NULL){
    puts("Empty Linked List\n");
     return -999;
    }
  if((*ps)->next==NULL){
    int val=(*ps)->data;
    free(*ps);
    *ps=NULL;
    return val;
  }
  struct node*temp=*ps;
  *ps=temp->next;
  int val=temp->data;
  free(temp);
  return val;
}
int del_last(struct node**ps){
  if(*ps==NULL){
    puts("Empty Linked List\n");
     return -999;
    }
  if((*ps)->next==NULL){
    int val=(*ps)->data;
    free(*ps);
    *ps=NULL;
    return val;
  }
  struct node*temp=*ps;
  struct node*prev=NULL;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  int val=temp->data;
  prev->next=NULL;
  free(temp);
  return val;
}
struct node* find_key(struct node*start,int key){
   while(start!=NULL){
      if(start->data==key)
        return start;
      start=start->next;
   }
   return NULL;

}
int del_key(struct node**ps,int key){
  if(*ps==NULL){
    puts("Empty Linked List\n");
     return 0;
    }
    struct node*temp=find_key(*ps,key);
    if(!temp){
        return 0;
    }
    if(temp==(*ps)){
          *ps=temp->next;
          free(temp);
    }
    else{
       struct node*p=*ps;
       while(p->next!=temp)
                p=p->next;
       p->next=temp->next;
       free(temp);
    }
    return 1;
}
void append_sorted(struct node**ps,int val){
   struct node*p=(struct node*)malloc(sizeof(struct node));
   if(p==NULL){
    puts("memory can't be allocated\n");
    return;
   }
   p->data=val;
   p->next=NULL;
   if(*ps==NULL){
    *ps=p;
    puts("start is null\n");
    }
    else if((*ps)->data>val){
        p->next=*ps;
        puts("start's value is greater than coming\n");
        *ps=p;
    }
    else {
            struct node*temp=*ps,*prev=NULL;
            while(temp!=NULL&&temp->data<val){
                     prev=temp;
                    temp=temp->next;
            }
            prev->next=p;
            p->next=temp;
    }
}

void reverse(struct node**ps){
    if(*ps==NULL||(*ps)->next==NULL)
        return;
   struct node*cur=*ps,*prev=NULL,*nextp;
        while(cur!=NULL){
            nextp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextp;
        }
        *ps=prev;
}
int main()
{
    struct node*start=NULL;
    menu:
        puts("\n\nEnter choice\n1-Append\n2-DelLast\n3-DelFirst\n4-DelKey\n5-Show\n6-Append sorted\n7-Reverse\n");
      int choice,temp;
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
          puts("enter value to be appended\n");
          scanf("%d",&temp);
          append(&start,temp);
          goto menu;
      case 6:
          puts("enter value to be appended\n");
          scanf("%d",&temp);
          append_sorted(&start,temp);
          goto menu;
      case 5:
        show(start);_getch();
        goto menu;
      case 3:
          temp=del_first(&start);
          if(temp!=-999)
           printf("the value deleted: %d\n",temp);
           goto menu;
     case 2:
          temp=del_last(&start);
          if(temp!=-999)
           printf("the value deleted: %d\n",temp);
           goto menu;
     case 4:
         puts("enter the value to be deleted");
         scanf("%d",&temp);
          if(del_key(&start,temp))
           printf("the value deleted: %d\n",temp);
          else
            puts("value is not found\n");
           goto menu;
     case 7:
         reverse(&start);
         goto menu;

      default:
          break;
      }

     return 0;
}
