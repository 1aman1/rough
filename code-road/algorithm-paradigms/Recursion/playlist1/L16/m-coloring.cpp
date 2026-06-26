#include <iostream>
#include <vector>
#include <algorithm>

constexpr int NO_COLOUR = 0;
using namespace std;

bool isColorable(int currNode, int color, vector<int> &nodeColor, vector<vector<int>> &graph, const int &noOfNodes)
{
    for (int k = 0; k < noOfNodes; ++k)
    {
        if (graph[currNode][k] == 1 &&
            color == nodeColor[k])
        {
            return false;
        }
    }

    return true;
}

bool solve(int currNode, vector<int> &nodeColor, vector<vector<int>> &graph, const int &noOfNodes, const int &M)
{
    if (currNode == noOfNodes)
    {
        return true;
    }

    for (int thisColor = 1; thisColor <= M; ++thisColor)
    {
        if (isColorable(currNode, thisColor, nodeColor, graph, noOfNodes))
        {
            nodeColor[currNode] = thisColor;

            if (solve(currNode + 1, nodeColor, graph, noOfNodes, M))
                return true;

            nodeColor[currNode] = NO_COLOUR;
        }
    }
    return false;
}

bool isColoringPossible(const int &M, vector<vector<int>> graph)
{
    const int noOfNodes = graph.size();
    vector<int> nodeColor(noOfNodes, NO_COLOUR);

    return solve(0, nodeColor, graph, noOfNodes, M);
}

int main()
{
    // TC 1
    const int M = 2; // not possible
    // const int M = 3; // possible
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};

    // TC 2
    // const int M = 3; // not possible
    // const int M = 4; // possible
    // vector<vector<int>> graph = {
    //     {0, 1, 1, 1},
    //     {1, 0, 1, 1},
    //     {1, 1, 0, 1},
    //     {1, 1, 1, 0}};

    // TC 3
    // const int M = 2; // not possible
    // const int M = 3; // possible
    // vector<vector<int>> graph = {
    //     {0, 1, 0, 0, 1},
    //     {1, 0, 1, 0, 0},
    //     {0, 1, 0, 1, 0},
    //     {0, 0, 1, 0, 1},
    //     {1, 0, 0, 1, 0}};

    if (isColoringPossible(M, graph))
        cout << "possible" << endl;
    else
        cout << "not possible" << endl;

    return 0;
}