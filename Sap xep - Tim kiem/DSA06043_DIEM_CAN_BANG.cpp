// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        int F[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == 1)
                F[i] = a[i];
            else
                F[i] = F[i - 1] + a[i];
        }
        int ok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (F[i] == (F[n] - F[i - 1]))
            {
                cout << i << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << -1 << endl;
    }
    return 0;
}