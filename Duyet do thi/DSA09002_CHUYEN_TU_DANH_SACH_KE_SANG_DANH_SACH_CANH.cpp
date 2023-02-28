// Nguyen Huu Quang Hoa - B21DCCN379
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            adj[i].push_back(stoi(tmp));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        for (auto x : adj[i])
        {
            if (x > i)
                cout << i << " " << x << endl;
        }
    }
    return 0;
}