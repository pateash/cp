
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node
{
    int data;
    struct node* next;
};


/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
bool detectAndRemoveLoop(struct node *start)
{
   if(start==nullptr||start->next==nullptr||start->next->next==nullptr)
   {
        //we have to handle two element as we are using hare->next->next
        //if we have loop then we could always able to find and solve
       cout<<"empty list"<<endl;
       return false;
   }



    node*tor,*hare;
    hare=tor=start;
    do{
        hare=hare->next->next;
        tor=tor->next;
    }while(hare->next!=NULL&&hare->next->next!=NULL&&hare!=tor);


    cout<<"hare: "<<hare->data<<"  Tort:"<<tor->data<<endl;
    /* Return 0 to indeciate that ther is no loop*/
   if(hare!=tor)//if end comes
     return false;//return false
   tor=start;//again starting from start
   while(hare->next!=tor->next)
    //next used so that tor can stop before the node and able to remove the loop link
   {
    //move both forward one by one
    hare=hare->next;
    tor=tor->next;//tortorise coming from starting
    //hare will stop at just before the node where loop starts
   }
  hare->next=NULL;
 return true;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

struct node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

/* Drier program to test above function*/
int main()
{
    struct node *head = newNode(50);

    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);


   head->next->next->next->next->next = head->next->next;


 cout<<"before removal of loop"<<endl;
  node*temp=head;
  for (int i = 0; temp!=nullptr&&i < 20; ++i)
 {//for checking values
  cout<<temp->data<<" ";
  temp=temp->next;
 }
 cout<<endl;
    if(detectAndRemoveLoop(head))
    {
      cout<<"loop removed";

     printf("Linked List after removing loop \n");
     printList(head);
    }
    else
      cout<<"No loop found"<<endl;

    return 0;
}
