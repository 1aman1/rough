#include <iostream>

using namespace std;

// 1..N

void func(int i, const int N)
{
    if (i > N)
        return;
    func(i + 1, N);
    cout << i << endl;
}

int main()
{
    int N = 5;
    int i = 1;
    func(i, N);
    return 0;
}