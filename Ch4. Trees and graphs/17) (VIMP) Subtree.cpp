// Brute force --> For every node in tree take it as a root and see if trees match
// https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL){
          return true;
        }
        else if(p==NULL || q==NULL){
          return false;
        }
        if(p->val==q->val){
          if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right)){
            return true;
          }
          else{
            return false;
          }
        }
        else{
          return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if(s==NULL && t==NULL){
          return true;
        }
        else if(s==NULL || t==NULL){
          return false;
        }
        if(isSameTree(s,t)){
          return true;
        }
        else{
          if(isSubtree(s->left,t)){
            return true;
          }
          else if(isSubtree(s->right,t)){
            return true;
          }
          else{
            return false;
          }
        }
    }
};