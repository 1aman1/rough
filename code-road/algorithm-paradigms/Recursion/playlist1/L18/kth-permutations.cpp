#include <iostream>
#include <vector>

using namespace std;

string getKthPerm(int k, int N)
{
    vector<int> numbers;

    int fact = 1;
    k--;

    for (int i = 1; i < N; ++i)
    {
        fact *= i;
        numbers.push_back(i);
    }

    numbers.push_back(N);
    string ans = "";

    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));

        if (numbers.size() == 0)
            break;

        k %= fact;
        fact = fact / numbers.size();
    }

    return ans;
}

int main()
{
    int N = 3;
    int K = 3;

    cout << getKthPerm(K, N);

    return 0;
}