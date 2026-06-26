#include <iostream>

using namespace std;

// 1..N

void func(int i, const int N)
{
    if (i > N)
        return;
    cout << i << endl;
    func(i + 1, N);
}

int main()
{
    int N = 5;
    int i = 1;
    func(i, N);
    return 0;
}