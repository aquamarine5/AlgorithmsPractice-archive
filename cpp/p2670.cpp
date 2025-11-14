/*
 * @Author: aquamarine5 && aquamarine5_@outlook.com
 * Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
 * lovely lonely, but be a quokka.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> area(n, vector<bool>(m));
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            area[i][j] = s[j] == '*';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (area[i][j])
            {
                printf("*");
                continue;
            };
            int r = 0;
            for (int x = -1; x <= 1; ++x)
                for (int y = -1; y <= 1; ++y)
                {
                    if (x == 0 && y == 0)
                        continue;
                    if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m)
                        continue;
                    r += area[x + i][y + j] ? 1 : 0;
                }
            printf("%d", r);
        }
        printf("\n");
    }
}