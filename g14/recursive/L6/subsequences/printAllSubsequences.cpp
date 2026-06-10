#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)  
// O(N)

void genSubsequences(int idx, vector<int> &candidates, const vector<int> &arr)
{
    if (idx >= arr.size())
    {
        if (candidates.empty())
            cout << "NULL";
        else
        {
            for (const auto &e : candidates)
                cout << e << "_";
        }
        cout << endl;
        return;
    }

    candidates.push_back(arr[idx]);
    genSubsequences(idx + 1, candidates, arr);

    candidates.pop_back();
    genSubsequences(idx + 1, candidates, arr);
}

int main()
{
    vector<int> arr{1, 3, 5, 7};
    vector<int> candidates{};

    genSubsequences(0, candidates, arr);

    return 0;
}