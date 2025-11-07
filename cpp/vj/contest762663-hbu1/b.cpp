#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<long long> a(n);
    vector<long long> diff(n + 1, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int j = 0; j < p; ++j)
    {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        diff[x - 1] += z;
        diff[y] -= z;
    }

    long long minvalue = a[0] + diff[0];
    long long current_increase = 0;
    for (int i = 0; i < n; ++i)
    {
        current_increase += diff[i];
        minvalue = min(minvalue, a[i] + current_increase);
    }
    cout << minvalue;
}