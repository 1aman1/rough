#include <iostream>
#include <vector>

using namespace std;

// bcoz recursion tree branches into 2 calls at every level
// O(2^N)  
// O(N)

void genSubsequences(int idx, vector<int> &temp, const vector<int> &arr)
{
    if (idx >= arr.size())
    {
        if (temp.empty())
            cout << "NULL";
        else
        {
            for (const auto &e : temp)
                cout << e << "_";
        }
        cout << endl;
        return;
    }

    temp.push_back(arr[idx]);
    genSubsequences(idx + 1, temp, arr);

    temp.pop_back();
    genSubsequences(idx + 1, temp, arr);
}

int main()
{
    vector<int> arr{1, 3, 5, 7};
    vector<int> temp{};

    genSubsequences(0, temp, arr);

    return 0;
}