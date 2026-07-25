#include <iostream>
using namespace std;

int popcount(int n) {
    int count = 0;

    while (n) {
        n = n & (n - 1);   // Remove one set bit
        count++;
    }

    return count;
}

// int popcount(int n) {
//     int count = 0;

//     while (n) {
//         count += (n & 1);
//         n >>= 1;
//     }

//     return count;
// }

int main()
{
  int number;
  cin >> number;

  // get the count of set bits in binary format
  cout << __builtin_popcount(number) << endl;
  cout << popcount(number) << endl;

  return 0;
}
