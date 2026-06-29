#include <iostream>
#include <vector>

using namespace std;

void solve(int row, int col, auto &vis, auto way, auto &res, const auto &maze, const auto &size)
{
    if (row == size - 1 && col == size - 1)
    {
        res.push_back(way);
        return;
    }

    if (row + 1 < size &&
        !(vis[row + 1][col]) &&
        maze[row + 1][col])
    {
        vis[row + 1][col] = 1;
        solve(row + 1, col, vis, way + "D", res, maze, size);
        vis[row + 1][col] = 0;
    }

    if (col + 1 < size &&
        !(vis[row][col + 1]) &&
        maze[row][col + 1])
    {
        vis[row][col + 1] = 1;
        solve(row, col + 1, vis, way + "R", res, maze, size);
        vis[row][col + 1] = 0;
    }

    if (row - 1 >= 0 &&
        !(vis[row - 1][col]) &&
        maze[row - 1][col])
    {
        vis[row - 1][col] = 1;
        solve(row - 1, col, vis, way + "U", res, maze, size);
        vis[row - 1][col] = 0;
    }

    if (col - 1 >= 0 &&
        !(vis[row][col - 1]) &&
        maze[row][col - 1])
    {
        vis[row][col - 1] = 1;
        solve(row, col - 1, vis, way + "L", res, maze, size);
        vis[row][col - 1] = 0;
    }
}

vector<string> possibleWays(vector<vector<int>> &maze, const int &size)
{
    // what if maze[0][0] is 0, skip solving
    // what if maze rightbottom is 0, skip solving

    vector<string> res;
    vector<vector<int>> vis(size, vector<int>(size, 0)); // mark 1 for visited
    string way;

    way = "";
    vis[0][0] = 1;
    solve(0, 0, vis, way, res, maze, size);

    return res;
}

int main()
{
    const int size = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    for (const auto &w : possibleWays(maze, size))
    {
        cout << w << endl;
    }

    return 0;
}