#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// TC O(N*log(N) + 2^N * N)
// SC O(2^N)

void subsets(const vector<int> &arr, vector<vector<int>> &res)
{
    // 3,1,2
    // 0,0,0
    // 0,0,1   1
    // 0,1,0   2
    // 0,1,1  3
    // 1,0,0  4
    // 1,0,1    5
    // 1,1,0
    // 1,1,1    2^N-1

    vector<int> tempBuff{};

    for (int i = 0; i < (1 << arr.size()); ++i)
    {
        for (int ithBit = 0; ithBit < arr.size(); ++ithBit)
        {
            if (i & (1 << ithBit))
            {
                tempBuff.emplace_back(arr[ithBit]);
            }
        }
        res.emplace_back(tempBuff);
        tempBuff.assign({});
    }
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<vector<int>> res;

    sort(begin(arr), end(arr));
    subsets(arr, res);

    for (const auto &r : res)
    {
        cout << accumulate(r.begin(), r.end(), 0) << endl;
    }

    return 0;
}