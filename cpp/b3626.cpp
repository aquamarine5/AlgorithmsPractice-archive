#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;

int main2()
{
    int n;
    scanf("%d", &n);
    deque<pair<int, int>> queue = {{1, 0}};
    unordered_set<int> visited = {1};
    int iter_count = 0;
    while (!queue.empty())
    {
        iter_count++;
        auto [position, steps] = queue.front();
        printf("%d %d\n", position, steps);
        queue.pop_front();
        if (position == n)
        {
            printf("%d", steps);
            break;
        }
        int possible_next_pos[3] = {position - 1, position + 1, position * 2};
        for (int next_pos : possible_next_pos)
        {
            if (next_pos > 0 && next_pos <= n && visited.find(next_pos) == visited.end())
            {
                queue.push_back({next_pos, steps + 1});
                visited.insert(next_pos);
            }
        }
    }
    printf("iter_count: %d\n", iter_count);
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    deque<pair<int, int>> queue = {{1, 0}};
    int iter_count = 0;
    while (!queue.empty())
    {
        iter_count++;
        auto [position, steps] = queue.front();
        queue.pop_front();
        if (position == n)
        {
            printf("%d", steps);
            break;
        }
        int possible_next_pos[3] = {position - 1, position + 1, position * 2};
        for (int next_pos : possible_next_pos)
        {
            if (next_pos > 0 && next_pos <= n)
                queue.push_back({next_pos, steps + 1});
        }
    }
    printf("iter_count: %d\n", iter_count);
    return 0;
}
