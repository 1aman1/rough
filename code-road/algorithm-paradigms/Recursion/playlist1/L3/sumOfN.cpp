#include <iostream>
using namespace std;

// parameterised
void sumOfN(int i, int sum)
{
    if (i < 0)
    {
        cout << sum << endl;
        return;
    }
    sumOfN(i - 1, i + sum);
}

// functional
int sumOfN(int i)
{
    if (i <= 0)
        return 0;
    return i + sumOfN(i - 1);
}

int main()
{
    int N = 5;
    int i = 0;

    // parameterised
    sumOfN(N, 0);

    // functional
    cout << sumOfN(N);

    return 0;
}