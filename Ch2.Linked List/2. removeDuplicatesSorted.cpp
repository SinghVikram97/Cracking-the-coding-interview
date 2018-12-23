// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur=head;
        while(cur!=NULL){
            int data=cur->val;
            ListNode *start=cur;
            while(cur!=NULL && cur->val==data){
                cur=cur->next;
            }
            start->next=cur;            
        }
        return head;
    }
};