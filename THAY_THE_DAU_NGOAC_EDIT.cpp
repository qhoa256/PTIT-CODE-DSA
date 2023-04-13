#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<int>st;
		int a[1005]; 
		for (int i = 0; i < s.size(); i++) a[i] = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(i);
			} else if (s[i] == ')') {
				if (!st.empty() && s[st.top()] == '(') {
					a[i] = 1; a[st.top()] = 0;
					st.pop();
				} else {
					st.push(i);
				}
			}
		}
		while (!st.empty()) { //Trong stack toan vi tri ngoac sai
			int p = st.top();
			a[p] = -1;
			st.pop();
		}
		for (int i = 0; i < s.size(); i++) {
			cout << a[i];
		}
		cout << endl;
	}
}
/*2
((())(()()
((()())(

-10011-10101
-1001011-1

*/