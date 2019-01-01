// p.first is whether subtree rooted at curNode is BST or not
// p.second.first is maximum value in tree rooted at left subtree (if root>max then automatically greater than all in left subtree)
// p.second.second is minimum value in tree rooted at right subtree (if root<min then automatically less than all in right subtree)
#define ll long long int
pair<bool,pair<ll,ll> > isBSTHelper(Node *root){
  
  if(root==NULL){
    return make_pair(true,make_pair(INT_MIN,INT_MAX));
  }

  pair<bool,pair<ll,ll> > left=isBSTHelper(root->left);
  pair<bool,pair<ll,ll> > right=isBSTHelper(root->right);

  //Return max and min values of tree rooted at root
  int maximum=max((ll)root->data,max(left.second.first,right.second.first));
  int minimum=min((ll)root->data,min(left.second.second,right.second.second));

  if(left.first==true && right.first=true){
    if(root->data>left.second.first && root->data<right.second.second){
      return make_pair(true,make_pair(maximum,minimum));
    }
    else{
      return make_pair(false,make_pair(maximum,minimum));
    }
  }
  else{
    return make_pair(false,make_pair(maximum,minimum));
  }
}
bool isBST(Node *root){
  pair<bool,pair<int,int> > p=isBSTHelper(root);
  return p.first;
}