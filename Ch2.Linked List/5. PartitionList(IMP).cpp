// https://www.interviewbit.com/problems/partition-list/
ListNode* Solution::partition(ListNode* head, int B) {
    
    if(head==NULL){
        return NULL;
    }
    ListNode *beforeStart=NULL;
    ListNode *beforeEnd=NULL;
    ListNode *afterStart=NULL;
    ListNode *afterEnd=NULL;
    
    ListNode *temp=head;
    while(temp!=NULL){
      if(temp->val<B){
         // Insert at end of list
         ListNode *newNode=new ListNode(temp->val);
         if(beforeStart==NULL){
             beforeStart=newNode;
             beforeEnd=newNode;
         }
         else{
             beforeEnd->next=newNode;
             beforeEnd=newNode;
         }
      }   
      else{
          ListNode *newNode=new ListNode(temp->val);
          if(afterStart==NULL){
              afterStart=newNode;
              afterEnd=newNode;
          }
          else{
              afterEnd->next=newNode;
              afterEnd=newNode;
          }
      }
      temp=temp->next;
    }
    // Merge 2 lists
    if(beforeStart==NULL){
      return afterStart;
    }
    else{
      beforeEnd->next=afterStart;
      return beforeStart;
    }
}