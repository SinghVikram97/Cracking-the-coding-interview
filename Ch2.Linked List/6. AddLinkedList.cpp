// https://leetcode.com/problems/add-two-numbers/submissions/
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
        
        ListNode *newHead=NULL;
        ListNode *ptr1=l1;
        ListNode *ptr2=l2;
        
        int sum=0,carry=0;
        
        while(ptr1!=NULL || ptr2!=NULL){
            int v1=ptr1==NULL?0:ptr1->val;
            int v2=ptr2==NULL?0:ptr2->val;
            
            sum=(v1+v2+carry);
            carry=sum/10;
            sum=sum%10;
            
            if(newHead==NULL){
                ListNode *newNode=new ListNode(sum);
                newHead=newNode;
            }
            else{
                ListNode *newNode=new ListNode(sum);
                
                ListNode *temp=newHead;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newNode;
            }
            if(ptr1!=NULL){
                ptr1=ptr1->next;
            }
            if(ptr2!=NULL){
                ptr2=ptr2->next;
            }
            
        }
        if(carry!=0){
           ListNode *newNode=new ListNode(carry);
                
                ListNode *temp=newHead;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newNode;
        }
        
        return newHead;
    }
};