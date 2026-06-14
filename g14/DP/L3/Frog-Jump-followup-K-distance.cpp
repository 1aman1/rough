#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

// #1
// recomputes every subproblem, again and again, very inefficient
// TC O(K^N)
// SC O(N)

// int frogjump(int idx, const int &K, const vector<int> &energy)
// {
//     if (idx == 0)
//         return 0;

//     int minJumpEnergy = INT_MAX;
//     for (int j = 1; j <= K; ++j)
//     {
//         if (idx - j >= 0)
//         {
//             int thisJumpEnergy = abs(energy[idx] - energy[idx - j]) + frogjump(idx - j, K, energy);
//             minJumpEnergy = min(minJumpEnergy, thisJumpEnergy);
//         }
//     }

//     return minJumpEnergy;
// }

// #2
// memoizes overlapping sub problems
// TC O(N*K)
// O(N) + O(N)

// int frogjump(int idx, const vector<int> &energy, vector<int> &dp, const int &K)
// {
//     if (idx == 0)
//         return dp[idx] = 0;

//     if (dp[idx] != -1)
//     {
//         cout << idx << "skipped\n ";
//         return dp[idx];
//     }

//     int minJumpEnergy = INT_MAX;
//     for (int j = 1; j <= K; ++j)
//     {
//         if (idx - j >= 0)
//         {
//             int thisJumpEnergy = abs(energy[idx] - energy[idx - j]) + frogjump(idx - j, energy, dp, K);
//             minJumpEnergy = min(minJumpEnergy, thisJumpEnergy);
//         }
//     }

//     return dp[idx] = minJumpEnergy;
// }

// #3
// tabulation
// TC O(N*K)
// SC O(N)

// int frogjump(int idx, const vector<int> &energy, const int &K)
// {
//     vector<int> dp(idx + 1, -1);

//     dp[0] = 0;

//     for (int i = 1; i <= idx; ++i)
//     {
//         int minJumpEnergy = INT_MAX;

//         for (int j = 1; j <= K; ++j)
//         {
//             if (i - j >= 0)
//             {
//                 int thisJumpEnergy = abs(energy[i] - energy[i - j]) + dp[i - j];
//                 minJumpEnergy = min(minJumpEnergy, thisJumpEnergy);
//             }
//         }
//         dp[i] = minJumpEnergy;
//     }

//     return dp[idx];
// }

// #4
// efficient tabulation
// O(N)
// O(1)

int frogjump(int idx, const vector<int> &energy)
{
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < idx; ++i)
    {
        int leftJump = -1, rightJump = 1000;

        leftJump = abs(energy[i] - energy[i - 1]) + prev;
        if (i > 1)
        {
            rightJump = abs(energy[i] - energy[i - 2]) + prev2;
        }

        int curr = min(leftJump, rightJump);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    vector<int> energy{30, 10, 60, 10, 60, 50};

    int N = energy.size();
    int K = 2;

    // cout << frogjump(N - 1, K, energy)
    //      << endl;

    // vector<int> dp(N, -1);
    // cout << frogjump(N - 1, energy, dp, K)
    //      << endl;

    // cout << frogjump(N, energy)
    //      << endl;

    cout << frogjump(N - 1, energy, K)
         << endl;

    return 0;
}