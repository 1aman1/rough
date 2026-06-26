#include <iostream>
#include <vector>
using namespace std;

// TC  O(9 * 9^E)    E = number of empty cells
// SC 

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

private:
    bool solve(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                if (board[r][c] == '.')
                {
                    for (char digit = '1'; digit <= '9'; ++digit)
                    {
                        if (valid(digit, r, c, board))
                        {
                            board[r][c] = digit;

                            if (solve(board))
                                return true;

                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(char digit, int r, int c, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[r][i] == digit)
                return false;
            if (board[i][c] == digit)
                return false;

            int boxRow = 3 * (r / 3) + i / 3;
            int boxCol = 3 * (c / 3) + i % 3;

            if (board[boxRow][boxCol] == digit)
                return false;
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution obj;

    obj.solveSudoku(board);

    for (auto &row : board)
    {
        for (char ch : row)
        {
            cout << ch << ' ';
        }
        cout << '\n';
    }

    return 0;
}