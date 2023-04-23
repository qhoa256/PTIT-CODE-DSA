#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll max_area(ll a[], ll m)
{
    ll ans = -1;
    stack<int> st;
    for (ll i = 0; i < m; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (a[i] >= a[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && a[i] < a[st.top()])
                {
                    ll top = st.top();
                    st.pop();
                    if (st.empty())
                    {
                        ans = max(ans, a[top] * i);
                    }
                    else
                    {
                        ans = max(ans, a[top] * (i - st.top() - 1));
                    }
                }
                st.push(i);
            }
        }
    }
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        if (st.empty())
        {
            ans = max(ans, a[top] * m);
        }
        else
        {
            ans = max(ans, a[top] * (m - st.top() - 1));
        }
    }
    return ans;
}
int main()
{
    faster();
    ll n, m;
    cin >> n >> m;
    ll a[m], b[m], res = -1;
    for (auto &x : a)
        cin >> x;
    for (ll i = 0; i < m; i++)
    {
        b[i] = n - a[i];
    }
    res = max(res, max_area(a, m));
    res = max(res, max_area(b, m));
    cout << res << endl;
    return 0;
}