// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, a[1005], x[1005], ok = 1;

void init()
{
    for (int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && x[i] == n - k + i)
        --i;
    if (i == 0)
        ok = 0;
    else
    {
        x[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

bool check()
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (a[x[i]] >= a[x[i + 1]])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    while (ok)
    {
        if (check())
            ans++;
        sinh();
    }
    cout << ans;
    return 0;
}