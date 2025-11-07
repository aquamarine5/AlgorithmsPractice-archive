#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool calculate()
{
    int n, buffer;
    cin >> n;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> buffer;
        prefix[i + 1] = prefix[i] + buffer;
    }
    bool flag = false;
    for (int j = 1; j <= n; ++j)
    {
        //
        // 2 3 1 4 ?   (a)
        // 0 2 5 6 10  (prefix)
        // 0 1 2 3 4   (index, 0-based)
        if (prefix[n] - prefix[j] == prefix[j])
        {
            if (flag)
                return false;
            else
                flag = true;
        }
    }
    return flag;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        if (calculate())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}