#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)
// O(N)

int subseqSumK(int idx, int sum, const vector<int> &arr, const int K)
{
    if (idx >= arr.size())
    {
        if (sum == K)
            return 1;
        return 0;
    }

    sum += arr[idx];
    int picked = subseqSumK(idx + 1, sum, arr, K);

    sum -= arr[idx];
    int unpick = subseqSumK(idx + 1, sum, arr, K);

    return picked + unpick;
}

int main()
{
    vector<int> arr{0, 1, 2, 3};
    vector<int> temp{};
    const int K = 3;
    int sum = 0;

    cout << subseqSumK(0, sum, arr, K)
         << endl;

    return 0;
}