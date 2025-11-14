#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    while (p--)
    {
        if (isValid())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}