// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, ok;
string s;

void init()
{
    s = string(n, 'H');
}

void sinh()
{
    int i = n - 1;
    while (i >= 0 && s[i] == 'A')
    {
        s[i] = 'H';
        --i;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = 'A';
}

bool check()
{
    if (s[0] != 'H' || s[s.size() - 1] != 'A')
        return false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'H' && s[i + 1] == 'H')
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> v;
        ok = 1;
        init();
        while (ok)
        {
            if (check())
                v.push_back(s);
            sinh();
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }
    return 0;
}