#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;

using ll = long long;

int a[100][100], n, u, vs[100], e[100], s[10000], ce[10000];
int kt(int a[][], int n) {
    int n;
    for (v = 1; v <= n; v++) {
        vs[v] = 0;
        e[v] = 0;
    }
    DFS(1);
    int ok = 1;
    for (v = 1; v <= n; v++) {
        if (vs[v] == 0) {
            ok = 0;
            break;
        }
    }
    if (ok == 0) return 0;
    int bl = 0;
    for (v = 1; v <= n; v++) {
        int deg = 0;
        for (int i = 1; i <= n; i++)
            if (a[v][i] == 1) deg++;
    }
    if (deg % 2 == 1) {
        bl++;
    }
    if (bl > 2) return 0;
    if (bl == 1) {
        u = v; ok = 2;
    }
    return ok;
}

int a[100][100], n, u, vs[100], s[10000], ce[10000];
int kt(int a[][], int n) {
    int v, top = 0, dem = 0;
    top++;
    s[top] = 1;
    dem++;
    while (top > 0) {
        int v = s[top], ok = 1;
        for (int i = 1; i <= n; i++) {
            if ((a[v][i] == 1 || a[i][v] == 1) && vs[i] == 0) {
                top++;
                s[top] = i;
                vs[i] = 1;
                dem++;
                ok = 0;
                break;
            }
        }
        if (dem < n) return 0;
        int x = 0, y = 0;
        for (v = 1; v <= n; v++) {
            int d1 = 0, d2 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i][v] == 1) {
                    d1++;
                }
                if (a[v][i] == 1) {
                    d2++;
                }
            }
        }
        if (d1 != d2) {
            if (abs(d1 - d2) > 1) return 0;
            else {
                if (x > 0 && y > 0) return 0;
                else {
                    if (d2 > d1) {
                        x = v;
                    } else {
                        y = v;
                    }
                }
                if (x == 0 && y == 0) {
                    return 1;
                } else {
                    u = x;
                    return 2;
                }
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
    return 0;
}