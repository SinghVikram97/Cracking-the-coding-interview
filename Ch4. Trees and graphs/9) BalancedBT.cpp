// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
pair<int,bool> isBalancedHelper(Node *root){
    
    if(root==NULL){
        return make_pair(0,true);
    }
    else if(root->left==NULL && root->right==NULL){
        return make_pair(1,true);
    }
    pair<int,bool> left=isBalancedHelper(root->left);
    pair<int,bool> right=isBalancedHelper(root->right);
    
    int height=1+max(left.first,right.first);
    
    if(left.second==true && right.second==true){
        if(abs(left.first-right.first)>1){
            return make_pair(height,false);
        }
        else{
            return make_pair(height,true);
        }
    }
    else{
        return make_pair(height,false);
    }
    
}
bool isBalanced(Node *root){
    pair<int,bool> p=isBalancedHelper(root);
    return p.second;
}
