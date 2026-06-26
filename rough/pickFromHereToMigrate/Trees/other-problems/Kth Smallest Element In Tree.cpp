void inOrder(TreeNode* A, vector<int> &temp) {
    if (A == NULL) {
        return;
    }
    inOrder(A -> left, temp);
    temp.push_back(A -> val);
    inOrder(A -> right, temp);
    return;
}
int Solution::kthsmallest(TreeNode* A, int B) {
// inorder traversal gives the sorted order, hence we can organize them into sequence, and get the kth element
    vector<int> temp;
    inOrder(A, temp);
    return temp[B - 1];
}
