// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;
void gray3()
{
    string res = "";
    res += s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            if (res[i - 1] == '0')
                res += "1";
            else
                res += "0";
        }
        else
            res += res[i - 1];
    }
    cout << res << endl;
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
        gray3();
    }
    return 0;
}