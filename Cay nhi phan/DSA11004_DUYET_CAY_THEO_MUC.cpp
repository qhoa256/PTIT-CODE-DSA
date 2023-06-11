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
		data = x;
		left = right = NULL;
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

void levelOrder(node *root) {
	if (root == NULL) return;
	queue<node *>q;
	q.push(root);
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			node *u = q.front();
			q.pop();
			cout << u->data << " ";
			if (u->left) q.push(u->left);
			if (u->right) q.push(u->right);
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
		levelOrder(root);
		cout << endl;
	}
	return 0;
}