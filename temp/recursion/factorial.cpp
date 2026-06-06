#include <iostream>
using namespace std;

// parameterised
void fact(int res, int N)
{
    if (N == 0)
    {
        cout << res << endl;
        return;
    }

    fact(res * N, N - 1);
}

// functional
int fact(int N)
{
    if (N <= 0)
        return 1;
    return N * (fact(N - 1));
}

int main()
{
    int N = 5;
    int res = 1;

    // parameterised
    fact(res, N);

    // functional
    cout << fact(N);

    return 0;
}