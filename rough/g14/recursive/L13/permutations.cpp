#include <iostream>
#include <vector>

using namespace std;

// TC O(N * N!)
// SC O(N)

void Permutations(int idx, vector<vector<int>> &res, vector<int> &nums)
{
    if (idx == nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); ++i)
    {
        swap(nums[idx], nums[i]);
        Permutations(idx + 1, res, nums);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res;

    Permutations(0, res, nums);

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