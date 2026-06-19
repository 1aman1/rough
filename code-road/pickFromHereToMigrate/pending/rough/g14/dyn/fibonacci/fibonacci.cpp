#include <iostream>
#include <vector>
using namespace std;

// #1
// recomputes every subproblem, again and again, very inefficient
// O(2^N)
// O(N)

// int getNthFibonacci(int num)
// {
//     if (num <= 1)
//         return num;

//     return getNthFibonacci(num - 1) + getNthFibonacci(num - 2);
// }

// #2
// memoizes overlapping sub problems
// O(N)
// O(N) + O(N)

// int getNthFibonacci(int num, vector<int> &dp)
// {
//     if (num <= 1)
//     {
//         cout << "base case with " << num << "\n";
//         return dp[num] = num;
//     }

//     if (dp[num] != -1)
//     {
//         cout << "skipped subproblem with " << num << "\n";
//         return dp[num];
//     }

//     cout << "breaking further with " << num << "\n";
//     return dp[num] = getNthFibonacci(num - 1, dp) + getNthFibonacci(num - 2, dp);
// }

// #3
// tabulation
// O(N)
// O(N)

// int getNthFibonacci(int N)
// {
//     vector<int> dp(N, -1);

//     dp[0] = 1;
//     dp[1] = 1;

//     for (int i = 2; i < N; ++i)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[N - 1];
// }

// #4
// efficient tabulation
// O(N)
// O(1)

int getNthFibonacci(int N)
{
    int prev2 = 0;
    int prev = 1;
    int curr;

    for (int i = 2; i <= N; ++i)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

// 0 1 1 2 3 5 8 13 21 34 55
// 1 2 3 4 5 6 7  8  9 10 11

int main()
{
    const int N = 8;

    // cout << getNthFibonacci(N-1);

    // vector<int> dp(N, -1);
    // cout << getNthFibonacci(N - 1, dp);

    cout << getNthFibonacci(N - 1);

    return 0;
}