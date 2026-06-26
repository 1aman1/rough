#include <iostream>
#include <vector>

using namespace std;

// TC O(N * N!)
// SC O(N) + O(N) + O(N!)

void generatePermutations(vector<int> tempBuf, vector<int> lookupCache, vector<vector<int>> &res, const vector<int> &nums)
{
    if (tempBuf.size() == nums.size())
    {
        res.emplace_back(tempBuf);
        return;
    }

    for (int idx = 0; idx < nums.size(); ++idx)
    {
        if (not lookupCache[idx])
        {
            lookupCache[idx] = 1;
            tempBuf.emplace_back(nums[idx]);

            generatePermutations(tempBuf, lookupCache, res, nums);

            lookupCache[idx] = 0;
            tempBuf.pop_back();
        }
    }
}

vector<vector<int>> Permutations(const vector<int> &nums)
{
    vector<int> lookupCache(nums.size(), 0);
    vector<int> tempBuf;
    vector<vector<int>> res;
    generatePermutations(tempBuf, lookupCache, res, nums);
    
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3};

    vector<vector<int>> res = Permutations(nums);

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