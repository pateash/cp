
void hareAndTortorise(node*start){
 //we have to find the middle element
  if(start==nullptr)
  {
    cout<<"empty linked list"<<endl;
    return;
  }
  node*hare=start,*tort=start;
  while(hare->next!=nullptr&&hare->next->next!=nullptr){
      tort=tort->next;
      hare=hare->next->next;
}
 cout<<"middle element is"<<tort->data<<endl;

}