// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1=head;
        ListNode *ptr2=head;
        
        while(ptr2!=NULL && n!=0){
            ptr2=ptr2->next;
            n--;
        }
        if(ptr2==NULL && n!=0){
            return NULL;
        }
        ListNode *cur=head;
        ListNode *prev=NULL;
        while(ptr2!=NULL){
            ptr2=ptr2->next;
            prev=cur;
            cur=cur->next;
        }
        if(prev==NULL){
            // Head Changes
            head=head->next;
        }
        else{
            prev->next=cur->next;
        }
        return head;
    }
};