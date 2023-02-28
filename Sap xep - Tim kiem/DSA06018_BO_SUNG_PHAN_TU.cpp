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
        set<int> se;
        for (auto &x : a)
        {
            cin >> x;
            se.insert(x);
        }
        cout << (*se.rbegin()- *se.begin() + 1) - se.size() << endl;
    }
    return 0;
}