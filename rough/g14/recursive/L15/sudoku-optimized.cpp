#include <iostream>
#include <vector>
using namespace std;

// TC  O(9^E)    E = number of empty cells

class Solution
{
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> box;

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        row.assign(9, vector<bool>(10, false));
        col.assign(9, vector<bool>(10, false));
        box.assign(9, vector<bool>(10, false));

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] != '.')
                {
                    int digit = board[r][c] - '0';
                    int boxId = (r / 3) * 3 + (c / 3);

                    row[r][digit] = true;
                    col[c][digit] = true;
                    box[boxId][digit] = true;
                }
            }
        }

        solve(board);
    }

private:

    bool solve(vector<vector<char>>& board)
    {
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    int boxId = (r / 3) * 3 + (c / 3);

                    for(int digit = 1; digit <= 9; digit++)
                    {
                        if(row[r][digit] ||
                           col[c][digit] ||
                           box[boxId][digit])
                        {
                            continue;
                        }

                        board[r][c] = digit + '0';

                        row[r][digit] = true;
                        col[c][digit] = true;
                        box[boxId][digit] = true;

                        if(solve(board))
                            return true;

                        board[r][c] = '.';

                        row[r][digit] = false;
                        col[c][digit] = false;
                        box[boxId][digit] = false;
                    }

                    return false;
                }
            }
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