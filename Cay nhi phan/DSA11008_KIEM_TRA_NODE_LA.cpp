#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct node {
	int data;
	node *left;
	node *right;
	node(int x) {
		this->data = x;
		this->left = this->right = NULL;
	}
};

void makeRoot(node *root, int u, int v, char c) {
	if (c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c) {
	if (root == NULL) return;
	if (root->data == u) {
		makeRoot(root, u, v, c);
	} else {
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

int height(node *root) {
	if (root == NULL) return 0;
	else return 1 + max(height(root->left), height(root->right));
}

bool check_leaf(node *root, int cnt, int h) {
	if (root == NULL) return true;
	if (root->left == NULL && root->right == NULL) return cnt == h;
	return check_leaf(root->left, cnt + 1, h) && check_leaf(root->right, cnt + 1, h);
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
		node *root = NULL;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;
			if (root == NULL) {
				root = new node(u);
				makeRoot(root, u, v, c);
			} else {
				insertNode(root, u, v, c);
			}
		}
		int h = height(root);
		if (check_leaf(root, 1, h)) cout << 1;
		else cout << 0;
		cout << endl;
	}
	return 0;
}