#include <iostream>
#include <vector>
using namespace std;

// #1 Recursion
// TC : O(2^(m+n))
// SC : O(m+n)

int totalPathsRec(int row, int col, const vector<vector<int>> &grid)
{
    if (row < 0 || col < 0)
        return 0;

    if (grid[row][col] == -1)
        return 0;

    if (row == 0 && col == 0)
        return 1;

    int up = totalPathsRec(row - 1, col, grid);
    int left = totalPathsRec(row, col - 1, grid);

    return up + left;
}

// #2 Memoization
// TC : O(m*n)
// SC : O(m*n) + O(m+n)

int totalPathsMemo(int row,
                   int col,
                   const vector<vector<int>> &grid,
                   vector<vector<int>> &dp)
{
    if (row < 0 || col < 0)
        return 0;

    if (grid[row][col] == -1)
        return 0;

    if (row == 0 && col == 0)
        return 1;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = totalPathsMemo(row - 1, col, grid, dp);
    int left = totalPathsMemo(row, col - 1, grid, dp);

    return dp[row][col] = up + left;
}

// #3 Tabulation
// TC : O(m*n)
// SC : O(m*n)

int totalPathsTab(int row,
                  int col,
                  const vector<vector<int>> &grid)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));

    if (grid[0][0] == -1)
        return 0;

    dp[0][0] = 1;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (grid[r][c] == -1)
            {
                dp[r][c] = 0;
                continue;
            }

            if (r == 0 && c == 0)
                continue;

            int up = 0, left = 0;

            if (r > 0)
                up = dp[r - 1][c];

            if (c > 0)
                left = dp[r][c - 1];

            dp[r][c] = up + left;
        }
    }

    return dp[row - 1][col - 1];
}

// #4 Space Optimized
// TC : O(m*n)
// SC : O(n)

int totalPathsSpace(int row,
                    int col,
                    const vector<vector<int>> &grid)
{
    vector<int> dp(col, 0);

    dp[0] = (grid[0][0] == -1) ? 0 : 1;

    // First row
    for (int c = 1; c < col; c++)
    {
        if (grid[0][c] == -1)
            dp[c] = 0;
        else
            dp[c] = dp[c - 1];
    }

    // Remaining rows
    for (int r = 1; r < row; r++)
    {
        vector<int> temp(col, 0);

        for (int c = 0; c < col; c++)
        {
            if (grid[r][c] == -1)
            {
                temp[c] = 0;
                continue;
            }

            int up = dp[c];
            int left = (c > 0) ? temp[c - 1] : 0;

            temp[c] = up + left;
        }

        dp = temp;
    }

    return dp[col - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int rows = grid.size();
    int cols = grid[0].size();

    cout << totalPathsRec(rows - 1, cols - 1, grid)
         << endl;

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    cout << totalPathsMemo(rows - 1, cols - 1, grid, dp)
         << endl;

    cout << totalPathsTab(rows, cols, grid)
         << endl;

    cout << totalPathsSpace(rows, cols, grid)
         << endl;

    return 0;
}