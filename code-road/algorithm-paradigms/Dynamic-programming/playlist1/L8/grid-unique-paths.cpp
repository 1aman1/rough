#include <iostream>
#include <vector>
using namespace std;

// #1
// TC O(2^(row*col))
// SC O(row+col)

int totalPaths(int row, int col)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    int left = totalPaths(row, col - 1);
    int up = totalPaths(row - 1, col);

    return left + up;
}

// #2
// TC O(row*col)
// SC O(row*col) + O(row+col)

// int totalPaths(int row, int col, auto &dp)
// {
//     if (row == 0 && col == 0)
//         return 1;
//     if (row < 0 || col < 0)
//         return 0;

//     if (dp[row][col] != -1)
//     {
//         return dp[row][col];
//     }

//     int left = totalPaths(row, col - 1, dp);
//     int up = totalPaths(row - 1, col, dp);

//     return dp[row][col] = left + up;
// }

// #3
// TC O(row*col)
// SC O(row*col)

// int totalPaths(int row, int col)
// {
//     vector<vector<int>> dp(row, vector<int>(col, 0));

//     dp[0][0] = 1;

//     for (int r = 0; r < row; ++r)
//     {
//         for (int c = 0; c < col; ++c)
//         {
//             if (r == 0 && c == 0)
//                 continue;

//             int up = 0, left = 0;

//             if (r >= 1)
//             {
//                 up = dp[r - 1][c];
//             }
//             if (c >= 1)
//             {
//                 left = dp[r][c - 1];
//             }

//             dp[r][c] = up + left;
//         }
//     }

//     return dp[row - 1][col - 1];
// }

// #4
// TC O(row*col)
// SC O(row+col)

// int totalPaths(int row, int col)
// {
//     vector<int> prev(col, 1);
//     vector<int> dp(col, 0);

//     for (int r = 1; r < row; ++r)
//     {
//         for (int c = 0; c < col; ++c)
//         {
//             int up, left = 0;

//             up = prev[c];
//             if (c > 0)
//                 left = dp[c - 1];
//             dp[c] = up + left;
//         }

//         prev.swap(dp);
//     }

//     return prev[col - 1];
// }

int main()
{
    int row = 4;
    int col = 4;

    vector<vector<int>> grid(row, vector<int>(col, 0));

    // #1
    cout << totalPaths(row - 1, col - 1)
         << endl;

    // #2
    // vector<vector<int>> dp(row, vector<int>(col, -1));
    // cout << totalPaths(row - 1, col - 1, dp)
    //      << endl;

    // #3 #4
    // cout << totalPaths(row, col)
    //      << endl;

    return 0;
}