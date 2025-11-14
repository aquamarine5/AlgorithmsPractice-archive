#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> box;
    while (q--)
    {
        int l;
        cin >> l;
        if (l == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            box[{i, j}] = k;
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << box[{i, j}] << endl;
        }
    }
}