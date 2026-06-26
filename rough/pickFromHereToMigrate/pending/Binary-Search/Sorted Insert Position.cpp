int Solution::searchInsert(vector<int> &A, int B) {
    int beg = 0, end = A.size() - 1;
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            end = mid - 1;
        } else if (A[mid] < B) {
            beg = mid + 1;
        }
    }
    return beg;
}
