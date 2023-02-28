// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
int a[1005][1005], x[1005];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    init();
    vector<vector<int>> v;
    do
    {
        int sum = 0;
        vector<int> tmp;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i][x[i]];
            tmp.push_back(x[i]);
        }
        if (sum == k)
            v.push_back(tmp);
    } while (next_permutation(x + 1, x + n + 1));
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (auto x : v[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}