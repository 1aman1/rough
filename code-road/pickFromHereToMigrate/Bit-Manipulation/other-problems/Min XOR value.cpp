int Solution::findMinXor(vector<int> &A) {
    //sorting can help here, difference would work out to be the least between two adjacent values
    if (A.size() <= 1) {
        return 0;
    }
    sort(A.begin(), A.end());
    size_t min = INT_MAX; // EDITED
    for (int i = 0; i < A.size() - 1; i ++) {
        if ((A[i] ^ A[i + 1]) < min) {
            min = (A[i] ^ A[i + 1]);
        }
    }
    return min;
}
