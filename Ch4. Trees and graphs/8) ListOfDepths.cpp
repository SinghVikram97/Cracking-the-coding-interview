// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
void connect(Node *head){

  if(head==NULL){
    return;
  }
  
  queue<Node *> myQueue;
  myQueue.push(head);
  myQueue.push(NULL);
  Node *prev=NULL;
  while(!myQueue.empty()){
    Node *frontElement=myQueue.front();
    myQueue.pop();
    if(frontElement!=NULL){
      if(prev!=NULL){
        prev->nextRight=frontElement;
      }
      prev=frontElement;
      if(frontElement->left!=NULL){
        myQueue.push(frontElement->left);
      }
      if(frontElement->right!=NULL){
        myQueue.push(frontElement->right);
      }
    }
    else{
      if(prev!=NULL){
          prev->nextRight=NULL;
      }
      prev=NULL;
      if(!myQueue.empty()){
        myQueue.push(NULL);
      }
    } 
  }
}
