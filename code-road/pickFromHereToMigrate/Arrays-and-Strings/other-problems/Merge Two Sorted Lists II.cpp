void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> result;
	
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] > B[j])
			result.push_back(B[j++]);
		else if (B[j] > A[i])
			result.push_back(A[i++]);
		else {
			result.push_back(A[i++]);
			result.push_back(B[j++]);
		}
	}
	
	if (i == A.size())
		for (; j < B.size() ;)
			result.push_back(B[j++]);
	
	else if (j == B.size())
		for (; i < A.size() ;)
			result.push_back(A[i++]);
	else
		{}	// if (i == A.size() && j == B.size())
	A = result;	// modify A also
}
