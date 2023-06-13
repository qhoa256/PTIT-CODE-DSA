#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    stack<char> st1, st2;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else
        {
            if (s[i] == '>')
            {
                if (st2.size())
                {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else
            {
                if (s[i] == '-')
                {
                    if (st1.size())
                    {
                        st1.pop();
                    }
                }
                else
                    st1.push(s[i]);
            }
        }
    }
    while (st1.size())
    {
        st2.push(st1.top());
        st1.pop();
    }
    while (st2.size())
    {
        cout << st2.top();
        st2.pop();
    }
    return 0;
}