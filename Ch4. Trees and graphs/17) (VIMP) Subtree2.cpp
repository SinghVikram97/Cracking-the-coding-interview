// https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
public:
    void getPreOrder(TreeNode *root,string &s){
      if(root==NULL){
        s.append("X");
        return;
      }
      s.append("#"); // Very imp add # before each value so that ["12"] and ["2"] don't match ie. "2" substr of "12"
      s.append(to_string(root->val));
      getPreOrder(root->left,s);
      getPreOrder(root->right,s);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {

      // Store preorder traversals of both trees in a string
      string s1,s2;
      getPreOrder(s,s1);
      getPreOrder(t,s2);

      // See if s2 is a subtring of s1
      if(s1.find(s2)!=string::npos){
        return true;
      }
      else{
        return false;
      }
    }
};