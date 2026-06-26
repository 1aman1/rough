#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int row, int col, std::vector<std::vector<char>> &board)
{
    int _row = row;
    int _col = col;

    if (std::any_of(board[row].begin(), board[row].end(),
                    [](char cur)
                    { return cur == 'Q'; }))
    {
        return false;
    }

    if (std::any_of(board.begin(), board.end(),
                    [col](const std::vector<char> &r)
                    {
                        return r[col] == 'Q';
                    }))
    {
        return false;
    }

    while (_row >= 0 && _col >= 0)
    {
        if (board[_row][_col] == 'Q')
            return false;
        --_row;
        --_col;
    }

    _row = row;
    _col = col;

    while (_row < board.size() && _col >= 0)
    {
        if (board[_row][_col] == 'Q')
            return false;
        ++_row;
        --_col;
    }

    return true;
}

void solveNQueen(int col, vector<vector<char>> &board, const int &K, vector<vector<char>> &res)
{
    if (col == K)
    {
        res = board;
        return;
    }
    
    for (int row = 0; row < K; ++row)
    {
        if (isValid(row, col, board))
        {
            board[row][col] = 'Q';
            solveNQueen(col + 1, board, K, res);
            board[row][col] = ' ';
        }
    }
}

int main()
{
    const int K = 8;

    vector<vector<char>> board(K, vector<char>(K, ' '));
    vector<vector<char>> res(K, vector<char>(K, ' '));

    solveNQueen(0, board, K, res);

    for (auto &row : res)
    {
        for (char ch : row)
        {
            cout << ch << ' ';
        }
        cout << '\n';
    }

    return 0;
}