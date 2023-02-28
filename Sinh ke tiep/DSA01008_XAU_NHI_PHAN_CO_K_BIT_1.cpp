// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, ok, a[1005];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

bool check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
            cnt++;
    }
    return cnt == k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        init();
        vector<vector<int>> v;
        ok = 1;
        while (ok)
        {
            if (check())
            {
                vector<int> tmp(a + 1, a + n + 1);
                v.push_back(tmp);
            }
            sinh();
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            for (auto x : v[i])
                cout << x;
            cout << endl;
        }
    }
    return 0;
}