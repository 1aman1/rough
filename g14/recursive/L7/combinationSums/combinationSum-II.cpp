#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinations(int idx, vector<int> &candidates, int target, const vector<int> &arr, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.emplace_back(candidates);
        return;
    }

    if (idx >= arr.size())
        return;

    for (int i = idx; i < arr.size(); ++i)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        candidates.emplace_back(arr[i]);
        combinations(i + 1, candidates, target - arr[i], arr, res);
        candidates.pop_back();
    }
}

int main()
{
    // vector<int> arr{2, 3, 2};
    // const int K = 7;
    vector<int> arr{1, 1, 1, 2, 2};
    const int K = 4;
    vector<vector<int>> res;
    vector<int> candidates;

    sort(begin(arr), end(arr));
    combinations(0, candidates, K, arr, res);

    for (const auto &r : res)
    {
        for (const auto &c : r)
        {
            cout << c << "_";
        }
        cout << "\n";
    }

    return 0;
}