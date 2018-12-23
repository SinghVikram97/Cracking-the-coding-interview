// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
// Double traversal solution
int getNthFromLast(Node *head, int n)
{
     Node *cur=head;
     int length=0;
     while(cur!=NULL){
         cur=cur->next;
         length++;
     }
     // Nth from last is (length-n+1) from begining
     int counter=length-n+1;
     cur=head;
     while(counter!=1 && cur!=NULL){
         counter--;
         cur=cur->next;
     }
     if(cur==NULL){
         return -1;
     }
     else{
         return cur->data;
     }
     
}

// Single traversal solution
int getNthFromLast(Node *head, int n)
{
    // Using single traversal
    Node *ptr1=head;
    Node *ptr2=head;
    while(ptr2!=NULL && n!=0){
        ptr2=ptr2->next;
        n--;
    }
    while(ptr2!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(ptr2==NULL && n!=0){
        return -1;
    }
    else{
        return ptr1->data;
    }
}