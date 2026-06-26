int Solution::bulbs(vector<int> &A) {
    int count = 0;
    int size = A.size();
    int result = 0; 
    for (int i = 0; i < size; i++)  {  
        if ((A[i] == 1 && count % 2 != 0) || (A[i] == 0 && count % 2 == 0)) {
            result++; 
            count++; 
        }
    }
    return result; 
}
