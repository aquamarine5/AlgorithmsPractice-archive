/*
 * @Author: aquamarine5 && aquamarine5_@outlook.com
 * Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
 * lovely lonely, but be a quokka.
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define int long long
signed main()
{
    int n, k, buffer1, buffer2;
    cin >> n >> k;
    int w[100008];
    vector<vector<int>> uvtree(n + 10, vector<int>());
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> buffer1 >> buffer2;
        uvtree[buffer1].push_back(buffer2);
        uvtree[buffer2].push_back(buffer1);
    }
    queue<pair<int, int>> pd;
    pair<int, int> x;
    set<int> result;
    pd.push({1, 0});
    result.insert(1);
    while (!pd.empty())
    {
        x = pd.front();
        pd.pop();
        result.insert(x.first);
        for (int z : uvtree[x.first])
        {
            if (x.second + 1 <= k * 2 && result.find(z) == result.end())
            {
                pd.push({z, x.second + 1});
            }
        }
    }
    int ans = 0;
    for (int ik : result)
    {
        ans += w[ik];
    }
    cout << ans;
}