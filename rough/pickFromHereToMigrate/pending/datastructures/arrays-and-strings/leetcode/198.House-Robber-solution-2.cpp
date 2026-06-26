// dynamic programming
class Solution
{
    int start(const vector<int> &nums, const int n)
    {
        int prev2Prev = nums[0];
        int prev = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i)
        {
            int curr = max(prev, nums[i] + prev2Prev);
            prev2Prev = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int robbedMoney = start(nums, n);

        return robbedMoney;
    }
};