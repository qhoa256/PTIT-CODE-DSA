#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct node {
	char data;
	node *left;
	node *right;
	node(char c) {
		data = c;
		left = right = NULL;
	}
};

void inOrder(node *root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->data;
	inOrder(root->right);
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
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<node *> st;
		for (auto &x : s) {
			if (isalpha(x)) {
				st.push(new node(x));
			} else {
				node *tmp = new node(x);
				tmp->right = st.top();
				st.pop();
				tmp->left = st.top();
				st.pop();
				st.push(tmp);
			}
		}
		inOrder(st.top());
		cout << endl;
	}
	return 0;
}