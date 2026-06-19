vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> retV; 
    for (int i = 0; i < A.size(); i++) {
        retV.push_back(A[(i + B)%A.size()]);
    }
    return retV; 
}
