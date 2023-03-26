#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int F[100005][100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int>mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] != 0) {
                t += s[i];
                mp[s[i]] = 0;
            }
        }
        int n = s.size(), m = t.size();
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    F[i][j] = 0;
                }
                else
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        F[i][j] = F[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                    }
                }
            }
        }
        cout << F[n][m] << endl;
    }
    return 0;
}

