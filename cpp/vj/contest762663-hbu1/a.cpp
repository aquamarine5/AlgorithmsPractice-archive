#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int ab;
        cin >> ab;
        a[i] = a[i - 1] + ab;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
    }

    return 0;
}