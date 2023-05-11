#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int dem = 0;
        char x = s[0];
        for (int i = 0; i < s.size(); i++)
            if (s[i] == x) dem++;
        if (dem == s.size()) cout << "-1";
        else cout << s.size() - 1;
        cout << endl;
    }
    return 0;
}