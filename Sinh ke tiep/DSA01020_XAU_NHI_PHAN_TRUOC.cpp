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
        string s;
        cin >> s;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0')
        {
            s[i] = '1';
            --i;
        }
        if (i == -1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                cout << 1;
            }
        }
        else
        {
            s[i] = '0';
            cout << s;
        }
        cout << endl;
    }
    return 0;
}