#include <iostream>
#include <vector>
using namespace std;

// #1
// recomputes every subproblem, again and again, very inefficient
// TC O(2^N)
// SC O(N)

int waysToClimbStairs(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }

    return waysToClimbStairs(num - 1) + waysToClimbStairs(num - 2);
}

// #2
// memoizes overlapping sub problems
// O(2^N)
// O(N) + O(N)

// int waysToClimbStairs(int num, vector<int> &dp)
// {
//     if (num == 1 || num == 0)
//     {
//         return dp[num] = 1;
//     }

//     if (dp[num] != -1)
//     {
//         return dp[num];
//     }

//     return dp[num] = waysToClimbStairs(num - 1, dp) + waysToClimbStairs(num - 2, dp);
// }

// #3
// tabulation
// O(N)
// O(N)

// int waysToClimbStairs(int num)
// {
//     vector<int> dp(num + 1, -1);

//     dp[0] = 1;
//     dp[1] = 1;

//     for (int i = 2; i <= num; ++i)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[num];
// }

// #4
// efficient tabulation
// O(N)
// O(1)

// int waysToClimbStairs(int num)
// {
//     int prev2 = 1;
//     int prev = 1;
//     int curr;

//     for (int i = 2; i <= num; ++i)
//     {
//         curr = prev + prev2;
//         prev2 = prev;
//         prev = curr;
//     }

//     return prev;
// }

int main()
{
    int stairs = 2;

    cout << waysToClimbStairs(stairs)
         << endl;

    // vector<int> dp(stairs + 1, -1);
    // cout << waysToClimbStairs(stairs, dp)
    //      << endl;

    // cout << waysToClimbStairs(stairs)
    //      << endl;

    return 0;
}