// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
void removeTheLoop(Node *head)
{
     Node *fast=head;
     Node *slow=head;
     
     while(fast!=NULL && fast->next!=NULL){
         fast=fast->next->next;
         slow=slow->next;
         if(fast==slow){
             Node *ptr1=head;
             Node *ptr2=slow;
             
             while(ptr1->next!=ptr2->next){
                 ptr1=ptr1->next;
                 ptr2=ptr2->next;
             }
             ptr2->next=NULL;
             return;
         }
     }
     return;
}