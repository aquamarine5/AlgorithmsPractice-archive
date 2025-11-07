#include <iostream>

using namespace std;

const string SUCCESS = "YES";
const string FAILURE = "NO";

bool calculate()
{
    string p, s;
    cin >> p >> s;
    long long p_len = p.length();
    long long s_len = s.length();
    long long pIndex = 0;
    long long sIndex = 0;
    while (sIndex < s_len)
    {
        if (pIndex >= p_len)
        {
            return false;
        }
        if (p[pIndex] != s[sIndex])
        {
            return false;
        }

        char current_hit = p[pIndex];
        pIndex++;
        sIndex++;

        if (sIndex < s_len && s[sIndex] == current_hit)
        {
            sIndex++;
        }
    }

    return pIndex == p_len;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        if (calculate())
            cout << SUCCESS << endl;
        else
            cout << FAILURE << endl;
    }
}