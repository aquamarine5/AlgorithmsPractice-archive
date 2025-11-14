#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string x;
    cin >> x;
    stack<pair<char, int>> st;
    vector<bool> matched(x.length(), false);

    for (int i = 0; i < x.length(); ++i)
    {
        char c = x[i];
        if (c == '(' || c == '[')
        {
            st.push({c, i});
        }
        else if (c == ')' || c == ']')
        {
            if (!st.empty())
            {
                char top_char = st.top().first;
                int top_index = st.top().second;

                if ((c == ')' && top_char == '(') || (c == ']' && top_char == '['))
                {
                    matched[i] = true;
                    matched[top_index] = true;
                    st.pop();
                }
            }
        }
    }

    string r = "";
    for (int i = 0; i < x.length(); ++i)
    {
        if (matched[i])
        {
            r += x[i];
        }
        else
        {
            if (x[i] == '(' || x[i] == ')')
            {
                r += "()";
            }
            else if (x[i] == '[' || x[i] == ']')
            {
                r += "[]";
            }
        }
    }
    cout << r << endl;
    return 0;
}
