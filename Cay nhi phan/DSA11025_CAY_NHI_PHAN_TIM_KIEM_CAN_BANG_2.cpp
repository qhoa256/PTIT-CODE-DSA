#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct node
{
	ll data;
	node *left;
	node *right;
	node(ll value)
	{
		data = value;
		left = right = NULL;
	}
};
node *insert_node(node *root, ll u)
{
	if (root == NULL)
	{
		root = new node(u);
	}
	else
	{
		if (u < root->data)
			root->left = insert_node(root->left, u);
		else
			root->right = insert_node(root->right, u);
	}
	return root;
}
void preorder(node *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void Build_Tree(node *&root, ll a[], ll l, ll r)
{
	if (l > r)
		return;
	ll mid = (l + r) / 2;
	root = insert_node(root, a[mid]);
	Build_Tree(root, a, l, mid - 1);
	Build_Tree(root, a, mid + 1, r);
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
	ll t;
	cin >> t;
	while (t--)
	{
		node *root = NULL;
		ll n;
		cin >> n;
		ll a[n];
		for (auto &x : a)
			cin >> x;
		sort(a, a + n);
		Build_Tree(root, a, 0, n - 1);
		preorder(root);
		cout << endl;
		root = NULL;
		delete root;
	}
	return 0;
}