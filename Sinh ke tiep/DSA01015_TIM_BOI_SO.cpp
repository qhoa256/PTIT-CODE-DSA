// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, ok;
vector<ll> v;
string s;

void init()
{
    s = string(n, '0');
}

void sinh()
{
    int i = n - 1;
    while (i >= 1 && s[i] == '9')
    {
        s[i] = '0';
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        s[i] = '9';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 19; i++)
    {
        n = i;
        ok = 1;
        init();
        while (ok)
        {
            v.push_back(stoll(s));
            sinh();
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        for (auto x : v)
        {
            if (x % a == 0 && x != 0)
            {
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}