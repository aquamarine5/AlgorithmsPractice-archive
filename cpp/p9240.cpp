/*
 * @Author: aquamarine5 && aquamarine5_@outlook.com
 * Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
 * lovely lonely, but be a quokka.
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, buf1, buf2;
    cin >> n;
    vector<pair<int, int>> records(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> buf1 >> buf2;
        records[i] = {buf1, buf2};
    }
    int maxr = 0x3f3f3f3f, minr = -1;
    for (int i = 0; i < n; ++i)
    {
        maxr = min(maxr, records[i].first / records[i].second);
        // 75/3=25
        // 75/4
        minr = max(minr, 1 + (records[i].first / (1 + records[i].second)));
    }
    printf("%d %d", minr, maxr);
}