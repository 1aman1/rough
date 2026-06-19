int Solution::findMedian(vector<vector<int> > &A) {
    if ( A.size() >= 0 && A[0].size() >= 0 ) {
        vector<int> result;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                result.push_back(A[i][j]);
            }
        }
        sort(result.begin(), result.end());
        return result[(result.size() - 1) / 2];
    }
    else 
        return 0;
}
