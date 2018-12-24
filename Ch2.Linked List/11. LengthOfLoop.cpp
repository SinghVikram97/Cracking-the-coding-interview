// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1/
int countNodesinLoop(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
           
           // Cycle exists
           Node *temp1=head;
           Node *temp2=slow;
           
           while(temp1!=temp2){
               temp1=temp1->next;
               temp2=temp2->next;
           }
           
           Node *startOfLoop=temp1;
           temp1=temp1->next;
           int count=1;
           while(temp1!=startOfLoop){
               temp1=temp1->next;
               count++;
           }
           
           return count;
           
        }
    }
    
    return 0;
    
}