vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> spiralSeq;
    // Corner cases

    if (A.size() == 0 || A[0].size() == 0) {
        return spiralSeq;
    }
    int top = 0, right = A[0].size() - 1, left = 0, bottom = A.size() - 1;
    int DIR; // direction

    while (top <= bottom && left <= right) {
        DIR = 0;
        if (DIR == 0) {
            for (int i = left; i <= right; i++) {
                spiralSeq.push_back(A[top][i]);
            }
            top++;
            if (top <= bottom) {
                DIR++;
            }
        }
        if (DIR == 1) {
            for (int i = top; i <= bottom; i++) {
                spiralSeq.push_back(A[i][right]);
            }
            right--;
            if (left <= right) {
                DIR++;
            }
        }
        if (DIR == 2) {
            for (int i = right; i >= left; i--) {
                spiralSeq.push_back(A[bottom][i]);
            }
            bottom--;
            if (top <= bottom) {
                DIR++;
            }
        }
        if (DIR == 3) {
            for (int i = bottom; i >= top; i--) {
                spiralSeq.push_back(A[i][left]);
            }
            left++;
            if (left <= right) {
                DIR++;
            }
        }
    }
    return spiralSeq;
}
