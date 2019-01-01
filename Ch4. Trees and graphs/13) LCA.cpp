// Method 1. It works even if one node not present in tree
Node * LCA(Node* root ,int n1 ,int n2 )
{
   if(root==NULL){
     return NULL;
   }
   
   if(root->data==n1 || root->data==n2){
     return root;
   }

   Node *left=LCA(root->left,n1,n2);
   Node *right=LCA(root->right,n1,n2);

   if(left && right){
     return root;
   }
   else if(left){
     return left;
   }
   else if(right){
     return right;
   }
   else{
     return NULL;
   }

}

