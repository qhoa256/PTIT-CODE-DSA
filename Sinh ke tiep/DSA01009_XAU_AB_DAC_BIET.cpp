// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, ok = 1;
string s;
vector<string> v;

void init()
{
    s = string(n, 'A');
}

void sinh()
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == 'B')
    {
        s[i] = 'A';
        --i;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = 'B';
}

bool check()
{
    int cntA = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            cntA++;
        }
        else
        {
            if (cntA > k)
                return false;
            if (cntA == k)
                cnt++;
            cntA = 0;
        }
    }
    if (cntA == k)
        cnt++;
    if (cntA > k)
        return false;
    return cnt == 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    init();
    while (ok)
    {
        if (check())
            v.push_back(s);
        sinh();
    }
    cout << v.size() << endl;
    for (auto x : v)
    {
        cout << x << endl;
    }
    return 0;
}