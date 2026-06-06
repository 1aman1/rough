#include <iostream>
#include <vector>

using namespace std;

// functional
bool isPalindrome(int idx, string str, const int N)
{
    if (idx >= N / 2)
        return true;
    if (str[idx] != str[N - idx - 1])
        return false;
    return isPalindrome(idx + 1, str, N);
}

int main()
{
    string str = "MADAM";

    if (isPalindrome(0, str, str.size()))
        cout << "yes";
    else
        cout << "no";

    return 0;
}