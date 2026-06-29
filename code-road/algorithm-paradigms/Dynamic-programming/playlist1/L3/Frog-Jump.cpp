#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// #1
// recomputes every subproblem, again and again, very inefficient
// TC O(2^N)
// SC O(N)

int frogjump(int idx, const vector<int> &energy)
{
    if (idx == 0)
        return 0;

    int smallJump;
    int biggerJump = INT_MAX;

    smallJump = abs(energy[idx] - energy[idx - 1]) + frogjump(idx - 1, energy);
    if (idx > 1)
    {
        biggerJump = abs(energy[idx] - energy[idx - 2]) + frogjump(idx - 2, energy);
    }

    return min(smallJump, biggerJump);
}

// #2
// memoizes overlapping sub problems
// TC O(N)
// O(N) + O(N)

// int frogjump(int idx, const vector<int> &energy, vector<int> &dp)
// {
//     if (idx == 0)
//         return dp[idx] = 0;

//     if (dp[idx] != -1)
//     {
//         // cout << idx << " energy saved\n";
//         return dp[idx];
//     }

//     int smallJump = -1, biggerJump = INT_MAX;

//     smallJump = abs(energy[idx] - energy[idx - 1]) + frogjump(idx - 1, energy, dp);
//     if (idx > 1)
//     {
//         biggerJump = abs(energy[idx] - energy[idx - 2]) + frogjump(idx - 2, energy, dp);
//     }

//     return dp[idx] = min(smallJump, biggerJump);
// }

// #3
// tabulation
// TC O(N)
// SC O(N)

// int frogjump(int idx, const vector<int> &energy)
// {
//     vector<int> dp(idx, -1);

//     dp[0] = 0;

//     for (int i = 1; i < idx; ++i)
//     {
//         int smallJump = -1, biggerJump = INT_MAX;

//         smallJump = abs(energy[i] - energy[i - 1]) + dp[i - 1];
//         if (i > 1)
//         {
//             biggerJump = abs(energy[i] - energy[i - 2]) + dp[i - 2];
//         }
//         dp[i] = min(smallJump, biggerJump);
//     }

//     return dp[idx - 1];
// }

// #4
// efficient tabulation
// O(N)
// O(1)

// int frogjump(int N, const vector<int> &energy)
// {
//     int curr = 0;
//     int prev = 0;
//     int prev2 = 0;

//     for (int i = 1; i < N; i++)
//     {
//         int smallJump = abs(energy[i] - energy[i - 1]) + prev;

//         int biggerJump = INT_MAX;
//         if (i > 1)
//             biggerJump = abs(energy[i] - energy[i - 2]) + prev2;

//         curr = min(smallJump, biggerJump);

//         prev2 = prev;
//         prev = curr;
//     }

//     return prev;
// }

int main()
{
    // vector<int> energy{30, 10, 60, 10, 60, 50};
    vector<int> energy{30, 10};

    int N = energy.size();

    // cout << frogjump(N - 1, energy)
    //      << endl;

    vector<int> dp(N, -1);
    cout << frogjump(N - 1, energy, dp)
         << endl;

    // cout << frogjump(N, energy)
    //      << endl;

    return 0;
}