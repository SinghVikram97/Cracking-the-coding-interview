#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};
void preOrder(Node* root)
{
  // Visit root node before it's children
  if(root==NULL){
      return;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
Node* createBst(vector<int> v,int start,int end){
  /// Select middle element as root
  /// First construct left and right subtree from array
  /// Then connect root of left and right subtree to parent
  if(start>end){
    return NULL;
  }
  if(start==end){
    Node* newNode=new Node(v[start]);
    return newNode;
  }
  int mid=(start+end)/2;
  Node *newNode=new Node(v[mid]);
  newNode->left=createBst(v,start,mid-1);
  newNode->right=createBst(v,mid+1,end);
  return newNode;
}
int main(){

  int n;
  cout<<"Enter the number of elements in array"<<endl;
  cin>>n;
  vector<int> v(n);
  cout<<"Enter array elements"<<endl;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  cout<<"Elements of array are "<<endl;
  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  Node *root=NULL;
  root=createBst(v,0,n-1);
  preOrder(root);

}
