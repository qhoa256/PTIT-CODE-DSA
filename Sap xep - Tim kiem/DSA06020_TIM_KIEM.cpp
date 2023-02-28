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
        int n, x;
        cin >> n >> x;
        int a[n];
        int ok = 0;
        for (auto &y : a)
        {
            cin >> y;
            if (y == x)
                ok = 1;
        }
        if (ok)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}