#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// TC pending
// SC (2^N)

void subsetsum(int idx, const int size, vector<int> &temp, vector<vector<int>> &res,
               const vector<int> &arr)
{
    for (int i = idx; i < size; ++i)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        temp.emplace_back(arr[i]);
        res.emplace_back(temp);
        subsetsum(i + 1, size, temp, res, arr);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<vector<int>> res;
    vector<int> temp;

    sort(begin(arr), end(arr));

    subsetsum(0, arr.size(), temp, res, arr);

    for (const auto &r : res)
    {
        for (const auto &c : r)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}