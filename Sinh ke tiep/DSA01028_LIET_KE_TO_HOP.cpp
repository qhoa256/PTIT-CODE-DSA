// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, ok = 1;
int a[1005], b[1005];
set<int> se;
vector<int> v;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (int i = 1; i <= k; i++)
    {
        b[i] = i;
    }
    v.push_back(0);
    for (auto it = se.begin(); it != se.end(); ++it)
    {
        v.push_back(*it);
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && b[i] == se.size() - k + i)
    {
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        b[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            b[j] = b[j - 1] + 1;
        }
    }
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
        for (int i = 1; i <= k; i++)
            cout << v[b[i]] << " ";
        cout << endl;
        sinh();
    }
    return 0;
}