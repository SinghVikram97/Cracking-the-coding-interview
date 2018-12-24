// https://leetcode.com/problems/add-two-numbers-ii/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        
        ListNode *ptr1=l1;
        ListNode *ptr2=l2;
        
        while(ptr1!=NULL){
            s1.push(ptr1->val);
            ptr1=ptr1->next;
        }
        
        while(ptr2!=NULL){
            s2.push(ptr2->val);
            ptr2=ptr2->next;
        }
        
        int sum=0,carry=0;
        ListNode *result=NULL;
        while(!s1.empty() || !s2.empty()){
            
            int v1=s1.empty()?0:s1.top();
            int v2=s2.empty()?0:s2.top();
            
            sum=(v1+v2+carry);
            carry=(sum/10);
            sum=(sum%10);
            
            ListNode *newNode=new ListNode(sum);
            
            if(result==NULL){
                result=newNode;
            }
            else{
                newNode->next=result;
                result=newNode;
            }
            if(!s1.empty()){
                s1.pop();
            }
            if(!s2.empty()){
                s2.pop();
            }
        }
        if(carry!=0){
            ListNode *newNode=new ListNode(carry);
            
            if(result==NULL){
                result=newNode;
            }
            else{
                newNode->next=result;
                result=newNode;
            }
            
        }
        return result;
    }
};