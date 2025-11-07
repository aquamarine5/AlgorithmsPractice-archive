#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool calculate()
{
    string p, s;
    cin >> p >> s;
    if (p[0] != s[0] || p.length() * 2 < s.length())
        return false;
    vector<pair<char, int>> a, b;
    int count = 0;
    char preChar = 0;
    for (char ch : p)
    {
        if (preChar == 0)
        {
            preChar = ch;
            count = 1;
        }
        else if (preChar == ch)
        {
            count++;
        }
        else
        {
            a.push_back({preChar, count});
            preChar = ch;
            count = 1;
        }
    }
    a.push_back({preChar, count});
    count = 0;
    preChar = 0;
    for (char ch : s)
    {
        if (preChar == 0)
        {
            preChar = ch;
            count = 1;
        }
        else if (preChar == ch)
        {
            count++;
        }
        else
        {
            b.push_back({preChar, count});
            preChar = ch;
            count = 1;
        }
    }
    b.push_back({preChar, count});
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i].first != b[i].first)
            return false;
        if (b[i].second < a[i].second || b[i].second > a[i].second * 2)
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        if (calculate())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}