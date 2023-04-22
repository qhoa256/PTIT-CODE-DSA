#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<pair<int, int>>adj[1005];
int route[1005];
int n, m, s;
int d[1005];
void Dijsktra(int s) {
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({d[s], s});
    route[1] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du > d[u]) continue;
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (d[v] < d[u] + w) continue;
            if (d[v] == d[u] + w) {
                route[v] += route[u];
            }
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                route[v] = route[u];
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    Dijsktra(1);
    cout << d[n] << " " << route[n];
    return 0;
}
// // C++ program for the above approach
// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// const int MAXN = 1e5 + 1;
// vector<vector<pair<int, int> > > g(MAXN);
// vector<int> dist(MAXN);
// vector<int> route(MAXN);

// // Function to count number of shortest
// // paths from node 1 to node N
// void countDistinctShortestPaths(
//     int n, int m, int edges[][3])
// {
//     // Storing the graph
//     for (int i = 0; i < m; ++i) {
//         int u = edges[i][0],
//             v = edges[i][1],
//             c = edges[i][2];
//         g[u].push_back({ v, c });
//     }

//     // Initializing dis array to a
//     // large value
//     for (int i = 2; i <= n; ++i) {
//         dist[i] = INF;
//     }

//     // Initialize a priority queue
//     priority_queue<pair<int, int>,
//                    vector<pair<int, int> >,
//                    greater<pair<int, int> > >
//                    pq;
//     pq.push({ 0, 1 });

//     // Base Cases
//     dist[1] = 0;
//     route[1] = 1;

//     // Loop while priority queue is
//     // not empty
//     while (!pq.empty()) {
//         int d = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();

//         // if d is greater than distance
//         // of the node
//         if (d > dist[u])
//             continue;

//         // Traversing all its neighbours
//         for (auto e : g[u]) {
//             int v = e.first;
//             int c = e.second;
//             if (c + d > dist[v])
//                 continue;

//             // Path found of same distance
//             if (c + d == dist[v]) {
//                 route[v] += route[u];
//             }

//             // New path found for lesser
//             // distance
//             if (c + d < dist[v]) {
//                 dist[v] = c + d;
//                 route[v] = route[u];

//                 // Pushing in priority
//                 // queue
//                 pq.push({ dist[v], v });
//             }
//         }
//     }
// }

// // Driver Code
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     // Given Input
//     int n = 5;
//     int m = 6;
//     int edges[m][3] = { { 1, 2, 6 },
//         { 1, 3, 7 },
//         { 2, 4, 2 },
//         { 3, 4, 9 },
//         { 3, 5, 3 },
//         {4, 5, 2}
//     };

//     // Function Call
//     countDistinctShortestPaths(n, m, edges);
//     cout << route[n] << endl;

//     return 0;
// }