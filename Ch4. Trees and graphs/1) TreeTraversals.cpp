void inOrder(Node* root)
{
  /// Left-->Cur-->right
  if(root==NULL){
      return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void preorder(Node* root)
{
  // Visit root node before it's children
  if(root==NULL){
      return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postOrder(Node* root)
{
  if(root==NULL){
      return;
  }
  // Visit root node after it's children
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}