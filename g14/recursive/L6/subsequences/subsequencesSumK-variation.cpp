#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)
// O(N)

void subseqSumK(int idx, int sum, vector<int> &candidates, const vector<int> &arr, const int K)
{
    if (idx >= arr.size())
    {
        if (sum == 0)
        {
            for (const auto &e : candidates)
                cout << e << " ";
            cout << endl;
        }
        return;
    }

    candidates.emplace_back(arr[idx]);
    subseqSumK(idx + 1, sum - arr[idx], candidates, arr, K);

    candidates.pop_back();
    subseqSumK(idx + 1, sum, candidates, arr, K);
}

int main()
{
    vector<int> arr{0, 1, 2, 3};
    vector<int> candidates{};
    const int K = 3;
    int sum = K;

    subseqSumK(0, sum, candidates, arr, K);

    return 0;
}