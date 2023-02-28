// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(a, a + n);
    cout << max({a[0] * a[1], a[n - 1] * a[n - 2], a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3]});
    return 0;
}