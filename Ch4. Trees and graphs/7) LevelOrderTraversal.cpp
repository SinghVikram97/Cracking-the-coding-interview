// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
void levelOrder(Node* head)
{
  if(head==NULL){
      return;
  }  
  queue<Node *> myQueue;
  myQueue.push(head);
  while(!myQueue.empty()){
      Node *front=myQueue.front();
      cout<<front->data<<" ";
      myQueue.pop();
      if(front->left!=NULL){
          myQueue.push(front->left);
      }
      if(front->right!=NULL){
          myQueue.push(front->right);
      }
  }
}
// https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1
void levelOrderLineByLine(Node* head)
{
  if(head==NULL){
    return;
  }
  
  queue<Node *> myQueue;
  myQueue.push(head);
  myQueue.push(NULL);

  while(!myQueue.empty()){
    Node *frontElement=myQueue.front();
    myQueue.pop();
    if(frontElement!=NULL){
      cout<<frontElement->data<<" ";
      if(frontElement->left!=NULL){
        myQueue.push(frontElement->left);
      }
      if(frontElement->right!=NULL){
        myQueue.push(frontElement->right);
      }
    }
    else{
      cout<<"$"<<" ";
      if(!myQueue.empty()){
        myQueue.push(NULL);
      }
    }
    
  }
}
