// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[10005], t, n;

void Try(int i) {
    if (i == 0) return;

    // Xay dung dong tiep theo
    for (int j = 1; j < i; j++) {
        a[j] += a[j + 1];
    }

    Try(i - 1);

    // In mang
    cout << "[";
    for (int j = 1; j <= i; j++) {
        cout << a[j];
        if (j != i) cout << " ";
    }
    cout << "] ";

    // Xay dung lai mang
    for (int j = i; j >= 1; j--) {
        a[j] -= a[j + 1];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Try(n);
        cout << endl;
    }
    return 0;
}