class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
       if(root==NULL){
           return false;
       }
       else if(root->val==sum && root->right==NULL && root->left==NULL){
           return true;
       }
       else{
         if(hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val)){
           return true;
         }
         else{
           return false;
         }
       }
        
    }
};