// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int cnt[1000005];

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
        for (auto &x : a)
        {
            cin >> x;
            cnt[x]++;
        }
        sort(a, a + n, [](int a, int b) -> bool
             {if(cnt[a]!=cnt[b]) return cnt[a]>cnt[b]; else return a<b; });
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout<<endl;
        memset(cnt,0,sizeof(cnt));
    }
    return 0;
}