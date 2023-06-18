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
void inorder(node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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
	while (t--)
	{
		node *root = NULL;
		map<ll, ll> mp;
		ll n;
		cin >> n;
		ll u, v;
		char c;
		while (n--)
		{
			cin >> u >> v >> c;
			if (!mp[u])
				mp[u] = 1, root = insert_node(root, u);
			if (!mp[v])
				mp[v] = 1, root = insert_node(root, v);
		}
		inorder(root);
		cout << endl;
		root = NULL;
		delete root;
	}
	return 0;
}