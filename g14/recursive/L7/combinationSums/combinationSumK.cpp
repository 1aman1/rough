#include <iostream>
#include <vector>

using namespace std;

void combinations(int idx, vector<int> &candidates, int target, const vector<int> &arr)
{
    if (target == 0)
    {
        for (const auto &e : candidates)
            cout << e << " ";
        cout << "\n";
    }

    if (idx >= arr.size())
        return;

    if (target >= arr[idx])
    {
        candidates.emplace_back(arr[idx]);
        combinations(idx, candidates, target - arr[idx], arr);
        candidates.pop_back();
    }

    combinations(idx + 1, candidates, target, arr);
}

int main()
{
    vector<int> arr{2, 2, 3, 5, 8};
    const int K = 8;
    vector<int> candidates{};
    int target = K;

    combinations(0, candidates, target, arr);

    return 0;
}