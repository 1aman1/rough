#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// TC O(2^N + N(log N))
// SC (2^N)
void subsetsum(int idx, int sum, const int size, vector<int> &res,
               const vector<int> &arr)
{
    if (idx >= size)
    {
        res.emplace_back(sum);
        return;
    }

    subsetsum(idx + 1, sum + arr[idx], size, res, arr);

    subsetsum(idx + 1, sum, size, res, arr);
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> res;

    subsetsum(0, 0, arr.size(), res, arr);
    sort(begin(res), end(res));

    for (const auto &r : res)
    {
        cout << r << " ";
    }

    return 0;
}