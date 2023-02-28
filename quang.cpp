#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9 + 7;
struct matran {
    ll a[2][2];
    friend matran operator *(matran b, matran c) {
        matran kq;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                kq.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    kq.a[i][j] += b.a[i][k] * c.a[k][j];
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};
matran ans(matran a, ll k) {
    if (k == 1) return a;
    matran b = ans(a, k / 2);
    if (k % 2) return b * b * a;
    else return b * b;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        matran c;
        c.a[0][0] = 1; c.a[0][1] = 1; c.a[1][0] = 1; c.a[1][1] = 0;
        matran d = ans(c, n);
        cout << d.a[0][1] << endl;
    }
}