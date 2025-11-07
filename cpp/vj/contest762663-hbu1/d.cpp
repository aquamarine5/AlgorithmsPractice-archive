#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{

    cin.tie(NULL);
    int n;
    n = read();
    vector<int> prefix(n + 1, 0);
    for (register int i = 1; i <= n; ++i)
    {
        int id = read();
        prefix[i] = (prefix[i - 1] + id) % 7;
    }

    for (register int len = n; len >= 1; --len)
    {
        for (register int i = 0; i <= n - len; ++i)
        {
            if ((prefix[i + len] - prefix[i]) % 7 == 0)
            {
                cout << len << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}