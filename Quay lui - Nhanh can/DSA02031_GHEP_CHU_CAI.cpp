#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string s = "";

bool vowel(char c) {
	return c == 'A' || c == 'E';
}
bool check() {
	for (int i = 1; i < s.size() - 1; i++) {
		if (vowel(s[i]) && !vowel(s[i - 1]) && !vowel(s[i + 1])) return false;
	}
	return true;
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
	char c;
	cin >> c;
	for (char x = 'A'; x <= c; x++) {
		s += x;
	}
	do {
		if (check()) cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}