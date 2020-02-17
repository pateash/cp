#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
void append(node**ps,int x)
{ node*p=new node;
p->data=x;
p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    node*temp=*ps;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
/*void count(node*start)
{int c=0;
    while(start!=NULL)
    {
            c++;
    start=start->next;
    }
    return c;
}*/
node* traverse_to_nth_element(node*start,int mid)
{
    mid--;//because start is already pointing to the first it is not on the oth position
    while(mid)
    {
start=start->next;
    mid--;
    }
    return start;
}
void show_middle(node*start,int n)// n is no. of elements in linkeed list
{
    int mid;
   if((n%2)!=0) mid=(n+1)/2;
    else mid=n/2;
node*temp= traverse_to_nth_element(start,mid);
if(n%2!=0)
   cout<<"\nAs n is Odd\nthe middle element is\n"<<temp->data;
   else
   {
       cout<<"\n\nAs n is even \nthe middle elements are\n";
       cout<<temp->data;
       cout<<"  "<<temp->next->data;
   }
}
void show_ll(node*start)
{
    if(start==NULL){
            cout<<"empty list"<<endl;
        return;
    }
    cout<<endl<<endl<<"Elements in the liked list are\n";
    while(start!=NULL)
    {
        cout<<start->data<<"  ";
        start=start->next;

    }

    _getch();
}
int main()
{
    system("color f9");
 node*start=NULL;
    cout<<"Enter the no. of element,\nyou want to insert in the linked list\n "<<endl;
    int n,x;
    cin>>n;
    for (int i=0;i<n ;i++ )
    {
        cout<<"enter the number "<<i+1<<" : ";
        cin>>x;
        append(&start,x);
       // cout<<x<<" has been appended to the linked list"<<endl;
    }
    show_ll(start);
    int middle=(n%2==0)?(n/2):((n+1)/2);//if even no. of elements are there then we have to take two elements
   show_middle(start,n);
   _getch();
    return 0;
}
