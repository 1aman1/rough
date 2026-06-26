#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveNQueen(int col,
                 vector<vector<char>> &board,
                 vector<int> &leftRow,
                 vector<int> upperLeftDiag,
                 vector<int> lowerLeftDiag,
                 const int &K,
                 vector<vector<char>> &res)
{
    if (col == K)
    {
        res = board;
        return;
    }
    
    for (int row = 0; row < K; ++row)
    {
        if (leftRow[row] == 0 &&
            upperLeftDiag[K - 1 + col - row] == 0 &&
            lowerLeftDiag[row + col] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperLeftDiag[K - 1 + col - row] = 1;
            lowerLeftDiag[row + col] = 1;

            solveNQueen(col + 1, board, leftRow, upperLeftDiag, lowerLeftDiag, K, res);

            board[row][col] = ' ';
            leftRow[row] = 0;
            upperLeftDiag[K - 1 + col - row] = 0;
            lowerLeftDiag[row + col] = 0;
        }
    }
}

int main()
{
    const int K = 8;

    vector<vector<char>> board(K, vector<char>(K, ' '));
    vector<vector<char>> res(K, vector<char>(K, ' '));

    vector<int> leftRow(K, 0);
    vector<int> upperLeftDiag(2 * K, 0);
    vector<int> lowerLeftDiag(2 * K, 0);

    solveNQueen(0, board, leftRow, upperLeftDiag, lowerLeftDiag, K, res);

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