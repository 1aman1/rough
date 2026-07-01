#include <iostream>
#include <vector>

using namespace std;

// TC O(N)
// SC O(1)
int solve(vector<int> nums)
{
    int curr = 0;
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        int currPick = nums[i];
        if (i > 1)
            currPick += prev2;
        int skipCurrPick = 0 + prev;

        curr = max(currPick, skipCurrPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    // vector<int> nums{10, 1, 1, 10}; // 11
    vector<int> nums{1, 3, 1, 3, 100}; // 103

    // vector<int> dp(nums.size(), -1);

    cout << max(solve(vector<int>(nums.begin(), nums.end() - 1)),
                solve(vector<int>(nums.begin() + 1, nums.end())));

    // cout << solve(nums);

    return 0;
}