#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// #1
// TC O(2^(row+col))
// SC O(row+col)
// int minPathSum(const int row, const int col, const vector<vector<int>> &grid)
// {
//     if (row == 0 && col == 0)
//         return grid[0][0];

//     if (row < 0 || col < 0)
//         return 1e9;

//     int up = grid[row][col] + minPathSum(row - 1, col, grid);
//     int left = grid[row][col] + minPathSum(row, col - 1, grid);

//     return min(up, left);
// }

// #2
int minPathSum(const int row, const int col, const vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return dp[0][0] = grid[0][0];

    if (row < 0 || col < 0)
        return 1e9;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = grid[row][col] + minPathSum(row - 1, col, grid, dp);
    int left = grid[row][col] + minPathSum(row, col - 1, grid, dp);

    return dp[row][col] = min(up, left);
}

// #3
// TC O(row*col)
// SC O(row*col)

// int minPathSum(const int row, const int col, const vector<vector<int>> &grid)
// {
//     vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

//     for (int r = 0; r < row; ++r)
//     {
//         for (int c = 0; c < col; ++c)
//         {
//             if (r == 0 && c == 0)
//                 dp[0][0] = grid[0][0];
//             else
//             {
//                 int uppp = grid[r][c] + (r > 0 ? dp[r - 1][c] : 1e9);
//                 int left = grid[r][c] + (c > 0 ? dp[r][c - 1] : 1e9);

//                 dp[r][c] = min(uppp, left);
//             }
//         }
//     }

//     return dp[row - 1][col - 1];
// }

// #4
// TC O(row*col))
// SC O(col)
int minPathSum(const int row, const int col, const vector<vector<int>> &grid)
{
    vector<int> dp(grid[0].size(), -1);
    vector<int> currDp(dp.size(), -1);

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (r == 0 && c == 0)
                currDp[0] = grid[0][0];
            else
            {
                int uppp = grid[r][c] + (r > 0 ? dp[c] : 1e9);
                int left = grid[r][c] + (c > 0 ? currDp[c - 1] : 1e9);

                currDp[c] = min(uppp, left);
            }
        }
        dp = currDp;
    }

    return currDp[col - 1];
}

int main()
{
    int rows = 4;
    int cols = 4;

    vector<vector<int>> grid = {{1, 2, 3, 5},
                                {11, 2, 4, 12},
                                {3, 4, 6, 2},
                                {5, 2, 5, 1}};

    // #1
    // cout << minPathSum(rows - 1, cols - 1, grid)
    //      << endl;

    // #2
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

    cout << minPathSum(rows - 1, cols - 1, grid, dp)
         << endl;

    // #3 #4
    cout << minPathSum(rows, cols, grid)
         << endl;

    return 0;
}