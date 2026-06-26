int Solution::isBalanced(TreeNode* root) {
    if( root == NULL || root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left != NULL && root->right != NULL){
        return min(isBalanced(root->right), isBalanced(root->left));
    }
    else if(root->left == NULL) {
        if(root->right != NULL) {
            TreeNode* temp = root->right;
            if(temp->right != NULL || temp->left != NULL){
                return 0;
            }
        }
        return 1;
    }
    else if(root->right == NULL) {
        if(root->left != NULL) {
            TreeNode* temp = root->left;
            if(temp->right != NULL || temp->left != NULL){
                return 0;
            }
        }
        return 1;
    }
    return 1;
}
