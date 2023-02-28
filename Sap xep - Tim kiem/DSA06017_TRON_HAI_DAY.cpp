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
        int n, m;
        cin >> n >> m;
        multiset<int> mset;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mset.insert(x);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            mset.insert(x);
        }
        for (auto x : mset)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}