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
    vector<int> c, l;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
            l.push_back(a[i]);
        else
            c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    sort(l.begin(), l.end(), greater<int>());
    for (int i = 0; i < min(c.size(), l.size()); i++)
    {
        cout << c[i] << " " << l[i] << " ";
    }
    if (n % 2)
        cout << c[c.size() - 1];
    return 0;
}