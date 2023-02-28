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
        int a[n + 1];
        multiset<int> mset;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= k; i++)
        {
            mset.insert(a[i]);
        }
        cout << *mset.rbegin() << " ";
        for (int i = 2; i <= n - k + 1; i++)
        {
            mset.erase(mset.find(a[i - 1]));
            mset.insert(a[k + i - 1]);
            cout << *mset.rbegin() << " ";
        }
        cout << endl;
    }
    return 0;
}