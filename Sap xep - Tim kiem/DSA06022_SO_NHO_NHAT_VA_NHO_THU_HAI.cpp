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
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n);
        if (a[0] != a[1])
            cout << a[0] << " " << a[1] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}