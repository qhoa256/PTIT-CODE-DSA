// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, x[105], g[105], ok;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while (i >= 1 && x[i] == 1)
    {
        x[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        x[i] = 1;
}

void gray1()
{
    g[1] = x[1];
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == x[i - 1])
            g[i] = 0;
        else
            g[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << g[i];
    }
    cout << " ";
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
        cin >> n;
        ok = 1;
        init();
        while (ok)
        {
            gray1();
            sinh();
        }
        memset(x, 0, sizeof(x));
        memset(g, 0, sizeof(g));
        cout << endl;
    }
    return 0;
}