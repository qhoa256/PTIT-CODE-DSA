// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, k, ok, a[1005], b[1005];

void init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

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
        for (int i = 1; i <= k; i++)
        {
            cin >> b[i];
        }
        ok = 1;
        init();
        int cnt = 0;
        while (ok)
        {
            cnt++;
            int yes = 1;
            for (int i = 1; i <= k; i++)
            {
                if (a[i] != b[i])
                {
                    yes = 0;
                    break;
                }
            }
            if (yes)
            {
                cout << cnt << endl;
                ok = 0;
            }
            sinh();
        }
    }
    return 0;
}