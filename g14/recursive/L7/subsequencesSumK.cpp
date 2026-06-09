#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)
// O(N)

void subseqSumK(int idx, int sum, vector<int> &temp, const vector<int> &arr, const int K)
{
    if (idx >= arr.size())
    {
        if (sum == K)
        {
            for (const auto &e : temp)
                cout << e << " ";
            cout << endl;
        }
        return;
    }

    sum += arr[idx];
    temp.emplace_back(arr[idx]);
    subseqSumK(idx + 1, sum, temp, arr, K);

    sum -= arr[idx];
    temp.pop_back();
    subseqSumK(idx + 1, sum, temp, arr, K);
}

int main()
{
    vector<int> arr{0, 1, 2, 3};
    vector<int> temp{};
    const int K = 3;
    int sum = 0;

    subseqSumK(0, sum, temp, arr, K);

    return 0;
}