#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
struct state
{
    int tx, ty, step;
};
int n, k;
bool mp[305][305];
bool vis[305][305];
// 四个方向：右、左、下、上
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

inline int getSize(int step)
{
    if (step < k)
        return 2;
    else if (step < 2 * k)
        return 1;
    else
        return 0;
}
// 检查在给定位置和大小下是否合法
bool check(int x, int y, int size)
{
    if (vis[x][y])
        return false;
    for (int i = x - size; i <= x + size; i++)
        for (int j = y - size; j <= y + size; j++)
            if (i < 1 || i > n || j < 1 || j > n || mp[i][j])
                return false;
    return true;
}

void bfs(int x, int y)
{
    queue<state> q; // 存储 x, y, step
    int ep = n - 2; // 终点坐标

    q.push({x, y, 0});
    vis[x][y] = true; // 初始是大胖子状态(size=2)

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        // 计算当前体型大小
        int size = getSize(curr.step);

        // 检查是否到达终点
        if (curr.tx == ep && curr.ty == ep)
        {
            cout << curr.step << endl;
            exit(0);
        }

        // 尝试四个方向移动
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.tx + dx[i];
            int ny = curr.ty + dy[i];

            // 提前检查是否到达终点
            if (nx == ep && ny == ep)
            {
                cout << curr.step + 1 << endl;
                exit(0);
            }

            // 检查移动是否合法且未访问过
            if (check(nx, ny, size) && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({nx, ny, curr.step + 1});
            }
        }

        // 如果当前非正常人，可以原地等待变瘦
        if (size > 0)
        {
            q.push({curr.tx, curr.ty, curr.step + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                mp[i][j] = 1;
            else
                mp[i][j] = 0;
        }

    // 从起点开始BFS
    bfs(3, 3);

    return 0;
}