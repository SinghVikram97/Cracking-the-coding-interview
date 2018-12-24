// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
int detectloop(Node *head)
{
   Node *fast=head;
   Node *slow=head;
   
   while(fast!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow){
           return 1;
       }
   }
   return 0;
}