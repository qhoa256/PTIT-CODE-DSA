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
	node(ll x)
	{
		data = x;
		left = right = NULL;
	}
};
void insert_node(node* &root, ll u, ll v, char c)
{
	if (root == NULL)
	{
		root = new node(u);
		if (c == 'L') root->left = new node(v);
		else root->right = new node(v);
		return;
	}
	else
	{
		if (root->data == u)
		{
			if (c == 'L') root->left = new node(v);
			else root->right = new node(v);
			return;
		}
		else
		{
			if (root->left) insert_node(root->left, u, v, c);
			if (root->right) insert_node(root->right, u, v, c);
		}
	}
}

ll maxh = 0;

bool check(node* root, node* root2)
{
	if (root == NULL && root2 == NULL) return true;
	if (root != NULL && root2 != NULL)
	{
		return (root->data == root2->data) && check(root->left, root2->left) && (check(root->right, root2->right));
	}
	return false;
}

void inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
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
	ll t; cin >> t;
	while (t--)
	{
		node* root = NULL;
		node* root2 = NULL;
		ll n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			ll u, v;
			char c;
			cin >> u >> v >> c;
			insert_node(root, u, v, c);
		}
		ll m; cin >> m;
		for (int i = 1; i <= m; i++)
		{
			ll u, v;
			char c;
			cin >> u >> v >> c;
			insert_node(root2, u, v, c);
		}
		if (check(root, root2)) cout << 1 << endl;
		else cout << 0 << endl;
		maxh = 0;
		delete root;
	}
	return 0;
}