#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;


struct node {
	int data;
	node *left;
	node *right;
	node (int val) {
		data = val;
		left = right = NULL;
	}
};

node *insert_node(node *root, int u) {
	if (root == NULL) root = new node(u);
	else {
		if (u < root->data) root->left = insert_node(root->left, u);
		else root->right = insert_node(root->right, u);
	}
	return root;
}

void postOrder(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	postOrder(root->left);
	postOrder(root->right);
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
			int x;
			cin >> x;
			root = insert_node(root, x);
		}
		postOrder(root);
		cout << endl;
	}
	return 0;
}