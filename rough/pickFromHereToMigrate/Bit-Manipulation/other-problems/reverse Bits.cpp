unsigned int Solution::reverse(unsigned int A) {
    size_t num = 0, rev = 0;
    int i = 0;
    while(A) {
        num = num + pow(2, 31-i) * (A%2);
        A /= 2;
        i++;
    }
    return num;
}
