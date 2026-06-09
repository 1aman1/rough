#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)
// O(N)

bool subseqSumK(int idx, int sum, vector<int> &candidates, const vector<int> &arr, const int K)
{
    if (idx >= arr.size())
    {
        if (sum == K)
        {
            for (const auto &e : candidates)
                cout << e << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    sum += arr[idx];
    candidates.emplace_back(arr[idx]);
    if (subseqSumK(idx + 1, sum, candidates, arr, K) == true)
        return true;

    sum -= arr[idx];
    candidates.pop_back();
    if (subseqSumK(idx + 1, sum, candidates, arr, K) == true)
        return true;

    return false;
}

int main()
{
    vector<int> arr{1, 2, 3};
    vector<int> candidates{};
    const int K = 3;
    int sum = 0;

    if (subseqSumK(0, sum, candidates, arr, K))
        cout << "success" << endl;
    else
        cout << "fail" << endl;

    return 0;
}