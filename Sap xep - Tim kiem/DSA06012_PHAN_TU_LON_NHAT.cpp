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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(a, a + n, greater<int>());
        for (int i = 0; i < k; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}