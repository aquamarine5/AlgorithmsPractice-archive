#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    while (n--)
    {
        int m;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            string x;
            cin >> x;
            str.append(x);
            cout << str << endl;
            break;
        }
        case 2:
        {
            int x, y;
            cin >> x >> y;
            str = str.substr(x, y);
            cout << str << endl;
            break;
        }
        case 3:
        {
            int x;
            string s;
            cin >> x;
            cin >> s;
            str = str.insert(x, s);
            cout << str << endl;
            break;
        }
        case 4:
        {
            string p;
            cin >> p;
            int k = str.find(p);
            if (k == string::npos)
                k = -1;
            cout << k << endl;
            break;
        }
        }
    }
}