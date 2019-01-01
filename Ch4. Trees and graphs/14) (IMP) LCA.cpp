// Doesn't work for https://github.com/SinghVikram97/Interview-Prep/blob/master/Trees/Binary%20Tree/14(3).(VIMP)%20LCA.cpp
// Improved method returns 2 things one is a node and other is a flag indicating whether this node is a common ancestor
// Node *---> Ancestor
// Bool ---> isAncestor

pair<Node *,bool> LCA_Helper(Node *root,int n1,int n2){

  if(root==NULL){
    return make_pair(root,false);
  }
  if(root->data==n1 && root->data==n2){
    return make_pair(root,true);
  }

  pair<Node *,bool> left=LCA_Helper(root->left,n1,n2);
  pair<Node *,bool> right=LCA_Helper(root->right,n1,n2);

  if(left.second){
    return left;
  }
  if(right.second){
    return right;
  }

  if(left.first && right.first){
    return make_pair(root,true);
  }
  else if(root->data==n1 || root->data==n2){
    if(left.first || right.first){
      return make_pair(root,true);
    }
    else{
      return make_pair(root,false);
    }
  }
  else{
    if(left.first!=NULL){
      return make_pair(left.first,false);
    }
    else if(right.first!=NULL){
      return make_pair(right.first,false);
    }
    else{
      Node *n=NULL;
      return make_pair(n,false);
    }
  }
}
Node * LCA(Node* root ,int n1 ,int n2 )
{
  pair<Node *,bool> p=LCA_Helper(root,n1,n2);
  if(p.second){
    return p.first;
  }
  else{
    return NULL;
  }
}