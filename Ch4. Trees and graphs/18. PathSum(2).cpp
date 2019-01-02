// https://leetcode.com/problems/path-sum-ii/submissions/
class Solution {
public:
    void pathSumHelper(TreeNode *root,int sum,vector<int> v,vector<vector<int> > &ans){
      if(root==NULL){
        return;
      }
      else if(root->val==sum && root->left==NULL && root->right==NULL){
        v.push_back(root->val);
        ans.push_back(v);
        return;
      }
      else{
        v.push_back(root->val);
        pathSumHelper(root->left,sum-root->val,v,ans);
        pathSumHelper(root->right,sum-root->val,v,ans);
      }
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> v;
        pathSumHelper(root,sum,v,ans);
        return ans;
    }
};