Node *removeDuplicates(Node *head)
{
  unordered_set<int> mySet;
  Node *prev=NULL;
  Node *cur=head;
  while(cur!=NULL){
      if(mySet.find(cur->data)!=mySet.end()){
          prev->next=cur->next;
          cur=prev->next;
      }
      else{
          mySet.insert(cur->data);
          prev=cur;
          cur=cur->next;
      }
  }
  return head;
}