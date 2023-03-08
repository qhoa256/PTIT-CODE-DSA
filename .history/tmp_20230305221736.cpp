// tran quy dat // 10 dam ac
#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster() \ ios_base::sync_with_stdio(0); \ cin.tie(0); \ cout.tie(0);
using namespace std;
map<unsigned long long, bool> mp;
ll a[21]; string s; ll max1 = -1;
bool check() {
	for (ll i = 0; i < s.size(); i++) {
		if (a[i]) return false;
	} return true;
}
bool check2(ll n) {
	ll a = cbrt(n);
	if (a * a * a == n)
		return true; else
		return false;
}
void try_to(ll i) { for (ll j = 0; j <= 1; j++) { a[i] = j; if (i == s.size() - 1) { ll sum = 0; for (ll k = 0; k < s.size(); k++) { if (a[k] == 1) { sum = sum * 10 + (s[k] - '0'); } } if (!check() && sum > max1 && mp[sum] == true) { max1 = sum; } } else try_to(i + 1); } } void inp() { cin >> s; try_to(0); cout << max1 << endl; ms(a); max1 = -1; } int main() { faster(); for (ll i = 1; i < 100000; i++) { mp[i * i * i] = true; } ll t; cin >> t; cin.ignore(); while (t--) { inp(); } }