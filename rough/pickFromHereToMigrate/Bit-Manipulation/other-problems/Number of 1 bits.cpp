int Solution::numSetBits(unsigned int A) {
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Using builtin functions always serves you giving an upper edge
    return __builtin_popcount(A);
}
