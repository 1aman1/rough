#include <iostream>
#include <vector>

using namespace std;

// paramterized 2 idx
// void Reverse(vector<int> &arr, int l, int r)
// {
//     if (l > r)
//         return;

//     swap(arr[l], arr[r]);
//     Reverse(arr, l + 1, r - 1);
// }

// paramterized 1 idx
void Reverse(int i, vector<int> &arr, const int N)
{
    if (i >= N / 2)
        return;
    swap(arr[i], arr[N - i - 1]);
    Reverse(i + 1, arr, N);
}

int main()
{
    vector<int> arr{1, 3, 5, 7};

    for (const auto &e : arr)
        cout << e << " ";
    cout << endl;

    // Reverse(arr, 0, arr.size() - 1);
    Reverse(0, arr, arr.size());

    for (const auto &e : arr)
        cout << e << " ";

    return 0;
}