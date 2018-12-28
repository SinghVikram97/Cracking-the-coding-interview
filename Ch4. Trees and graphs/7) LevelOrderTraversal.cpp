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