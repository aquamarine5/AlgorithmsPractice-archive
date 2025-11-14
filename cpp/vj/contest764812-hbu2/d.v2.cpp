#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string x, r = "";
    cin >> x;
    stack<pair<char, int>> st;
    vector<bool> matched(x.length(), false);
    for (int i = 0; i < x.length(); ++i)
    {
        char c = x[i];
        if (c == '(' || c == '[')
            st.push({c, i});
        else if (c == ')' || c == ']')
        {
            if (!st.empty())
            {
                char tc = st.top().first;
                int ti = st.top().second;
                if ((c == ')' && tc == '(') || (c == ']' && tc == '['))
                {
                    matched[ti] = true;
                    matched[i] = true;
                    st.pop();
                }
            }
        }
    }
    for (int i = 0; i < x.length(); ++i)
    {
        if (matched[i])
            r += x[i];
        else
        {
            if (x[i] == '(' || x[i] == ')')
                r += "()";
            if (x[i] == '[' || x[i] == ']')
                r += "[]";
        }
    }
    cout << r << endl;
    return 0;
}