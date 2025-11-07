#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main()
{
    long long w[1000];
    int n, k, bu, bv;
    map<int, vector<int>> mp;
    queue<tuple<int, int, int>> tasks;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> bu >> bv;
        mp[bu].push_back(bv);
    }
    tasks.push({1, 0, 0});
    int maxstep = k * 2, maxvalue = 0, bw;
    while (!tasks.empty())
    {

        auto [node, weight, step] = tasks.front();
        cout << "Processing node: " << node << " with weight: " << weight << endl;
        tasks.pop();
        if (step++ >= maxstep)
        {
            continue;
        }
        for (int neighbor : mp[node])
        {
            bw = weight + w[neighbor - 1];
            if (bw > maxvalue)
            {
                maxvalue = bw;
            }
            tasks.push({neighbor, bw, step});
            cout << "Adding neighbor: " << neighbor << " with new weight: " << bw << endl;
        }
    }
    printf("%d\n", maxvalue);
}