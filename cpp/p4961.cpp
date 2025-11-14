/*
 * @Author: aquamarine5 && aquamarine5_@outlook.com
 * Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
 * lovely lonely, but be a quokka.
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, buffer, result = 0;

int dfsCount = 0;
void dfs(int i, int j, vector<vector<int>> *nmarea)
{
    (*nmarea)[i][j] = 1;
    for (int x = -1; x <= 1; ++x)
        for (int y = -1; y <= 1; ++y)
        {
            if (x == 0 && y == 0)
                continue;
            if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m)
                continue;
            if ((*nmarea)[i + x][j + y] == 0)
                dfs(i + x, j + y, nmarea);
        }
}

int find(vector<vector<bool>> *narea, int i, int j)
{
    for (int x = -1; x <= 1; ++x)
        for (int y = -1; y <= 1; ++y)
        {
            if (x == 0 && y == 0)
                continue;
            if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m)
                continue;
            if (!(*narea)[i + x][y + j])
            {
                return 0;
            }
        }
    return 1;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<bool>> area(n, vector<bool>(m, false)), narea(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> buffer;
            area[i][j] = buffer == 1;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (area[i][j])
            {
                for (int x = -1; x <= 1; ++x)
                    for (int y = -1; y <= 1; ++y)
                    {
                        if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m)
                            continue;
                        narea[i + x][j + y] = true;
                    }
            }
        }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!area[i][j] && narea[i][j])
            {
                int k = find(&narea, i, j);
                result += k;
            }
        }
    }
    vector<vector<int>> nmarea(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (narea[i][j])
                nmarea[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (nmarea[i][j] == 0)
            {
                dfs(i, j, &nmarea);
                dfsCount++;
            }
        }
    }
    cout << result + dfsCount << endl;
}