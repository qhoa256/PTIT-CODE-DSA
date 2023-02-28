// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, k, a[1005], ok;

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        set<int> se;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            se.insert(a[i]);
        }
        ok = 1;
        sinh();
        if (!ok)
            cout << k << endl;
        else
        {
            int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (se.count(a[i]) == 0)
                    ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}