#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    long long n, l, r;
    cin >> n >> l >> r;

    if (l / n == r / n)
    {
        cout << r % n;
    }
    else
    {
        cout << n - 1;
    }
}