#include <iostream>
#include <vector>

using namespace std;

// TC O(N)
// SC O(N)

// int solve(int idx, vector<int> &dp, const vector<int> &nums)
// {
//     if (idx == 0)
//         return dp[idx] = nums[idx];
//     if (idx < 0)
//         return 0;

//     if (dp[idx] != -1)
//         return dp[idx];

//     int currPick = nums[idx] + solve(idx - 2, dp, nums);
//     int skipCurrPick = 0 + solve(idx - 1, dp, nums);

//     return dp[idx] = max(currPick, skipCurrPick);
// }

// O()
// int solve(const vector<int> &nums)
// {
//     if (nums.empty())
//         return 0;

//     vector<int> dp(nums.size(), 0);

//     dp[0] = nums[0];

//     for (int i = 1; i < nums.size(); ++i)
//     {
//         int currPick = nums[i];
//         if (i > 1)
//             currPick += dp[i - 2];

//         int skipCurrPick = 0 + dp[i - 1];

//         dp[i] = max(currPick, skipCurrPick);
//     }

//     return dp[nums.size() - 1];
// }

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
    vector<int> nums{2, 1, 4, 9};  // 11
    // vector<int> nums{1, 2, 4}; // 5
    vector<int> dp(nums.size(), -1);

    // cout << solve(nums.size() - 1, dp, nums);

    cout << solve(nums);

    return 0;
}