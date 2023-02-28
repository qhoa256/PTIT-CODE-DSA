// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

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
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            pq.push(x);
        }
        ll ans = 0;
        while (pq.size() > 1)
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ans += x % mod + y % mod;
            ans %= mod;
            pq.push((x % mod + y % mod) % mod);
        }
        cout << ans % mod << endl;
    }
    return 0;
}

