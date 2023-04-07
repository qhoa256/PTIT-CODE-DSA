#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, s;
        int k;
        cin >> n >> s >> k;
        int a[n+5], f[n+5];
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            f[i] = a[i];
            if(i > 1) f[i] += f[i-1];
        }

        int res = -1;
        if(f[s] <= k) res = 1;
        else 
        {
            for(int i = 1; i < s; ++i)
            {
                if(f[s] - f[i] <= k) 
                {
                    res = i+1;
                    break;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}