// 1.Using parent pointer
Node * inOrderSuccessor(Node *root, Node *n)
{
    // 2 cases based on right subtree

    // 1. If right subtree not empty ans is leftmost child or min value in right subtree
    if(n->right!=NULL){
      return minValue(n->right);
    }

    // 2. If right subtree NULL then ans is a parent who is a left child of it's parent
    Node *p=n->parent;
    while(p!=NULL && n!=p->left){
      n=p;
      p=p->parent;
    }
    return p;
}
Node *minValue(Node *root){
 while(root->left!=NULL){
     root=root->left;
 }
 return root;
}

// 2. Without parent pointer
// If right subtree not NULL then return minValue in right subtree
// Else go down the tree from Root and if node->data < root->data update sucessor
Node *minValue(Node *root){
 while(root->left!=NULL){
     root=root->left;
 }
 return root;
}

Node * inOrderSuccessor(Node *root, Node *x)
{
   if(x->right!=NULL){
     return minValue(x->right);
   }
   Node *succ=NULL;
   while(root!=NULL){
     if(x->data<root->data){
       succ=root;
       root=root->left;
     }
     else{
       root=root->right;
     }
   }
   return succ;
}
