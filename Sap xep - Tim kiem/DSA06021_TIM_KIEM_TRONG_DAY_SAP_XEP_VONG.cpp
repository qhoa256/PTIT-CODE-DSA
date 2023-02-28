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
        int a[n + 1];
        int pos = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == x)
                pos = i;
        }
        cout << pos << endl;
    }
    return 0;
}