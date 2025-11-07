#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<pair<int, int>, int> mp1, mp2;
    int n, m, b, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> b;
            ans += mp1[{b, i - j}]++;
            ans += mp2[{b, i + j}]++;
        }
    printf("%d", ans * 2);
}