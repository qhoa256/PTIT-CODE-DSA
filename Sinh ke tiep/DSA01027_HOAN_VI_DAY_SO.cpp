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
        cin >> x;
    sort(a, a + n);
    vector<string> v;
    do
    {
        for (auto x : a)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}