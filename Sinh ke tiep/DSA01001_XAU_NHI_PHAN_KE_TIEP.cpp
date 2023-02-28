// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, ok;
string s, tmp;
void sinh()
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = '1';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        ok = 1;
        sinh();
        if (!ok)
        {
            for (int i = 0; i < s.size(); i++)
            {
                cout << 0;
            }
        }
        else
        {
            cout << s;
        }
        cout << endl;
    }
    return 0;
}