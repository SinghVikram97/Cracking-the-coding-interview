// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
bool isPalindrome(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    int length=0;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        length++;
    }
    
    Node *mid=slow;
    
    stack<int> s;
    while(slow!=NULL){
        s.push(slow->data);
        slow=slow->next;
    }
    
    Node *temp=head;
    while(temp!=mid){
        if(!s.empty()){
            if(s.top()!=temp->data){
                return false;
            }
            else{
                s.pop();
            }
        }
        temp=temp->next;
    }
    return true;
}